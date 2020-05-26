#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include "Hand.h"
#include "Deck.h"

class Blackjack {
  public: 
    Blackjack();
    Blackjack(Deck* deck, Hand* hand, Hand* dealer);
    int playGame(int* money, int* bet);
    void pay(int result, int* money, int* bet);
    void deal();
    int playHand(int* money, int* bet);
    int dealerHand();
    void setHand(Hand* hand_);
  private:
    Deck* deck;
    Hand* hand;
    Hand* dealer;
};

#endif // BLACKJACK_H