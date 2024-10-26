CC=g++
BINARY=atm_machine
SRCDIR=src
SOURCES=$(shell find $(SRCDIR) -name "*.cpp")
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)

TEST_BINARY=atm_machine_tests
TESTDIR=tests
TEST_SOURCES=$(shell find $(TESTDIR) -name "*.cpp")
OBJECTS=$(SOURCES:$(TESTDIR)/%.cpp=$(TESTDIR)/%.o)

CFLAGS= -Wall -Wextra -g

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

test: 
	echo "hello"
	make atm_machine_tests

atm_machine_tests: tests/test.cpp
	g++ tests/test.cpp -o atm_machine_tests

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(BINARY) $(OBJECTS)
