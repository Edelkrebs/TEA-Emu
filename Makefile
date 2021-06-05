SOURCES := $(shell find -name *.c)
OBJECTS := $(SOURCES:.c=.o)

CC = gcc

EXEC = tea-emu

run: all
	./$(EXEC)

all: $(OBJECTS)
	$(CC) $^ -o $(EXEC) -Iinclude -lgcc -Werror -Wall

%.o:%.c
	$(CC) -c $^ -o $@ -Iinclude -lgcc -Wall -Werror

clean:
	rm -rf $(OBJECTS) $(EXEC)