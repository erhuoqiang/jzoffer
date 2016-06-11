src := $(shell ls *.cpp)
obj := $(patsubst %.cpp,%.o,$(src))
CC := g++
sp_q:$(obj)
	$(CC) $^ -o $@
$(obj):$(src)
	$(CC) $(src) -c -o $(obj)  -Wall

clean:
	rm -f sp_q *.o   
