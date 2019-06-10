CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@


all:sort
	

sort: sort.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o sort

