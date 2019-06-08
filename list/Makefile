CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=list.o

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@


all:list_reverse list_swap_pairs
	

list_reverse: list_reverse.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

list_swap_pairs: list_swap_pairs.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@


clean:
	rm -rf *.o list_reverse list_swap_pairs

