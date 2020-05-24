#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include "Hand.h"
#include "Deck.h"

class Blackjack {
  public: 
    Blackjack();
    int playGame(Deck* deck, Hand hand, int* money, int bet);
    void pay(int result, int* money, int bet);
  private:
    Hand hand;
    Hand dealer;
    int activeHands;
};

#endif // BLACKJACK_H