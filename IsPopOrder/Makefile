src := $(shell ls  *.cpp)
des := $(patsubst %.cpp,%.o,$(src))
GCC := g++

IsPopOrder:$(des)
	$(GCC) $^ -o $@

$(des):$(src)
	$(GCC) $^ -c  -o $@ -Wall

clean:
	rm *~ *.o IsPopOrder	
