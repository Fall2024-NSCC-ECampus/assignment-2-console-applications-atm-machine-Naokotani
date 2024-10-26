CC=g++
BINARY=atm_machine
SRCDIR=src
SOURCES= $(shell find $(SRCDIR) -name "*.cpp")
OBJECTS= $(patsubst %.c, %.o, $(SOURCES))

CFLAGS= -Wall -Wextra -g

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(BINARY)
