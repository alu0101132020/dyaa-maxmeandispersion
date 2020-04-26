IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = edge.o node.o graph.o solution.o algorithm.o greedy-constructive.o greedy.o grasp.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: max-mean-dispersion

$(ODIR)/edge.o: $(ODIR)/edge.cpp $(IDIR)/edge.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/node.o: $(ODIR)/node.cpp $(IDIR)/node.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/graph.o: $(ODIR)/graph.cpp $(IDIR)/graph.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/solution.o: $(ODIR)/solution.cpp $(IDIR)/solution.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algorithm.o: $(ODIR)/algorithm.cpp $(IDIR)/algorithm.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy-constructive.o: $(ODIR)/greedy-constructive.cpp $(IDIR)/greedy-constructive.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy.o: $(ODIR)/greedy.cpp $(IDIR)/greedy.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grasp.o: $(ODIR)/grasp.cpp $(IDIR)/grasp.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


max-mean-dispersion: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./src