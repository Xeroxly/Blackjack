blackjack: deck.o
	g++ deck.o -o blackjack

deck.o: deck.cc deck.h
	g++ -c deck.cc deck.h

clean: 
	-rm *.o blackjack