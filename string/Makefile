CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=-g

LIB:=

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@


all:max_same_substring
	

max_same_substring: max_same_substring.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@


clean:
	rm -rf *.o max_same_substring

