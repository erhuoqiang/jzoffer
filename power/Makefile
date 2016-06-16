src := $(shell ls *.c)
obj := $(patsubst %.c,%.o,$(src))
CC := gcc
power:$(obj)
	$(CC) $^ -o $@
$(obj):$(src)
	$(CC) $(src) -c -o $(obj)  -Wall

clean:
	rm -f power *.o   
