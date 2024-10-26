CC=g++
BINARY=fileIO
OBJECTS=testFileIo.o ../src/accounts/create_account.o ../src/accounts/users.o ../src/io/input.o ../src/io/print.o
CFLAGS= -Wall -Wextra -g

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(BINARY) $(OBJECTS)
