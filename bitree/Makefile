CC:=gcc
LD:=gcc
CFLAGS:=-g
LDFLAGS:=

LIB:=bitree.o

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@



OUT:=reconstruct

all:$(OUT)
	

reconstruct: reconstruct.o $(LIB)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o $(OUT)

