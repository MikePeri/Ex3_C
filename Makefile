 # -*- MakeFile -*-
CC=gcc
AR=ar
FLAGS=-Wall -g
OBJECTS_LIB=txtFind.o
OBJECTS_MAIN=txt.o
OBJECTS2_LIB=insertionSort.o
OBJECTS2_MAIN=sort.o


all: libMyTxt.a  txtfind insertionSort.a  isort 

isort: $(OBJECTS2_MAIN) insertionSort.a
	$(CC) $(FLAGS) -o isort $(OBJECTS2_MAIN) libInsertion.a -lm
insertionSort.a: $(OBJECTS2_LIB)
	$(AR) -rcs libInsertion.a $(OBJECTS2_LIB)
main.o: insertionSort.h sort.c
	$(CC) $(FLAGES) -c sort.c
insertionSort.o: insertionSort.h insertionSort.c
	$(CC) $(FLAGES) -c insertionSort.c


txtfind: $(OBJECTS_MAIN) libMyTxt.a
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN) libMyTxt.a -lm
libMyTxt.a: $(OBJECTS_LIB)
	$(AR) -rcs libMyTxt.a $(OBJECTS_LIB)
txt.o: txtFind.h txt.c
	$(CC) $(FLAGES) -c txt.c
txtFind.o: txtFind.h txtFind.c
	$(CC) $(FLAGES) -c txtFind.c

clean:
	rm -f *.o *.a *.so txtfind isort
.PHONY: clean all