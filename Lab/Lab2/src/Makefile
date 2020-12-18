CC=gcc
CFLAGS=-c
LFLAGS=-o
DEPS=findsubstr.h readline.h
SRC=main.c findsubstr.c readline.c
OBJS=$(SRC:.c=.o)
TAG=mygrep

all: $(SRC) $(TAG)

$(TAG): $(OBJS)
	$(CC) $^ $(LFLAGS) $@

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	@echo "Cleaning up ..."
	rm -rf *.o $(TAG)
