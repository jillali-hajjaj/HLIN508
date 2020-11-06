DOT=$(wildcard *.dot)

TP2: TP3.cc Couples.cc
	g++ $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
