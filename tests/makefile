CC=g++
BINARY=fileIO
OBJECTS=testFileIo.o ../create_account.o ../users.o ../io/input.o ../io/print.o
CFLAGS= -Wall -Wextra -g

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(BINARY) $(OBJECTS)
