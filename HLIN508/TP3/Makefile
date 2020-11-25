DOT=$(wildcard *.dot)

TP3: TP3.cc Couples.cc
	g++ $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
