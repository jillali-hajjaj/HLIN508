DOT=$(wildcard *.dot)

TP2: TP2.cc ArbreBinaire.cc
	g++ $^ -o $@

clean:
	rm -f $(DOT) $(DOT:.dot=.pdf)
