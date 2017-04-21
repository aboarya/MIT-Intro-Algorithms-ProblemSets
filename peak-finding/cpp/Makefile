.PHONY: all oned twod

all: clean oned twod

clean:
	rm -rf *.out

_oned:
	g++ -std=c++11 1darray.cpp -o 1darray.out
	./1darray.out

oned: clean _oned

_twod:
	g++ -std=c++11 2darray.cpp -o 2darray.out
	./2darray.out

twod: clean _twod

