TARGET = liblinkedlist.a

CC = gcc
CCFLAGS = -c -Iinclude -Wall

INCLUDE_DIR_PATH = include
SRC_DIR_PATH = src

SOURCES = $(wildcard $(SRC_DIR_PATH)/*.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	@ar rs $(TARGET) $(OBJECTS)

.c.o:
	@$(CC) $(CCFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS) $(TARGET)