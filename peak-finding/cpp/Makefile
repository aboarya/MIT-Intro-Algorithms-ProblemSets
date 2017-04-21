.PHONY: all oned

all: clean oned

clean:
	rm -rf *.out

_oned:
	g++ -std=c++11 1darray.cpp -o 1darray.out
	./1darray.out

oned: clean _oned

