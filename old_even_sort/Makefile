src := $(shell ls *.c)
obj := $(patsubst %.c, %.o ,$(src))

sort:$(obj)
	gcc $^ -o $@
$(obj):$(src)
	gcc $^ -c -o $@

clean:
	rm sort *.o -f 
