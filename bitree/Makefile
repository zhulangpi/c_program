CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=bitree.o

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@


all:bitree
	

bitree: bitree.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o bitree

