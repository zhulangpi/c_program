CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

OUT:=sort

all:$(OUT)
	

sort: sort.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o $(OUT)

