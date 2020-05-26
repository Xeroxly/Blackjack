#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include "Hand.h"
#include "Deck.h"

class Blackjack {
  public: 
    Blackjack();
    Blackjack(Deck* deck, Hand* dealer);
    int playGame(Hand* hand, int* money, int* bet);
    void pay(int result, int* money, int* bet);
    void deal(Hand* hand);
    int playHand(Hand* hand, int* money, int* bet);
    int dealerHand();
  private:
    Deck* deck;
    Hand* dealer;
};

#endif // BLACKJACK_H