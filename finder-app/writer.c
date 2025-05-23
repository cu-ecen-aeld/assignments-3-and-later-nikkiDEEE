#include <stdio.h>
#include <errno.h>
#include <syslog.h>
#include <stdlib.h>
#include <string.h>

void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file: %s - %s", filename, strerror(errno));
        return;
    }

    syslog(LOG_DEBUG, "Writing '%s' to file '%s'", content, filename);

    if (fputs(content, file) == EOF) {
        syslog(LOG_ERR, "Error writing to file: %s - %s", filename, strerror(errno));
        fclose(file); // Close even if fputs fails
        return;
    }

    if (fclose(file) != 0) {
        syslog(LOG_ERR, "Error closing file: %s - %s", filename, strerror(errno));
    }
}

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments. Usage: ./writer <file> <string>");
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *filename = argv[1];
    const char *content = argv[2];

    write_to_file(filename, content);

    closelog();
    return 0;
}
