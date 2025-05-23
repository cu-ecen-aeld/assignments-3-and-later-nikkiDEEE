# Variables
TARGET := writer
SRC := writer.c
OBJ := writer.o
CFLAGS := -Wall -Werror
CC := $(CROSS_COMPILE)gcc

# Default target
all: $(TARGET)

# Link the object to produce the binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source to object
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)
