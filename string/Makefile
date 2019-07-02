CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=-g

LIB:=

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

OUT:=max_same_substring

all:$(OUT)
	

max_same_substring: max_same_substring.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@


clean:
	rm -rf *.o $(OUT)

