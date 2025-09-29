# Compiler prefix for cross-compilation (can be empty for native build)
CROSS_COMPILE ?=

# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror

# Source and target
SRC := finder-app/writer.c
TARGET := finder-app/writer

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(TARGET) finder-app/$(TARGET) *.o
