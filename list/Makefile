CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=list.o

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@


OUT:=list_reverse list_swap_pairs list_sort list_hoop

all:$(OUT)
	

list_reverse: list_reverse.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

list_swap_pairs: list_swap_pairs.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

list_sort: list_sort.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

list_hoop: list_hoop.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o $(OUT)

