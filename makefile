CC=g++
BINARY=atm_machine
OBJECTS=main.o io/input.o io/print.o menu.o login.o create_account.o actions.o users.o
CFLAGS= -Wall -Wextra -g

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(BINARY) $(OBJECTS)
