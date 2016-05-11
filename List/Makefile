OBJ = main.o List.o
SRC = main.c List.c
list:$(OBJ)
	gcc -o list $(OBJ)
$(OBJ):$(SRC)
	gcc -c  $(SRC) 
.PHONY:clean
clean:
	-rm *.o* list *.c~ *.h~   
