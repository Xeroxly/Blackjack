blackjack: deck.o main.o
	g++ deck.o main.o -o blackjack

main.o: main.cc
	g++ -c main.cc

deck.o: deck.cc deck.h
	g++ -c deck.cc

clean: 
	-rm *.o blackjack