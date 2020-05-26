blackjack: deck.o main.o hand.o blackjack.o
	g++ deck.o main.o hand.o blackjack.o -o blackjack

main.o: main.cc
	g++ -c main.cc

deck.o: deck.cc deck.h
	g++ -c deck.cc

hand.o: hand.cc hand.h
	g++ -c hand.cc

blackjack.o: blackjack.cc blackjack.h
	g++ -c blackjack.cc

clean: 
	-rm *.o blackjack