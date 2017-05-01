.PHONY: all doc

all: clean doc

clean:
	rm -rf *.out

doc:
	g++ -std=c++11 docdist.cpp -o docdist.out
	./docdist.out
