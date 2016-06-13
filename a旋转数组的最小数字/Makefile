src := $(shell ls *.c)
obj := $(patsubst %.c,%.o,$(src))


code:$(obj)
	gcc $^ -o $@
$(obj):$(src)
	gcc $^ -c  -o $@
clean:
	rm -f *.o code 
