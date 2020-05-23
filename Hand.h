#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
  public:
    Hand();
    Hand(Card card);
    void showHand();
    void addCard(Card card);
    int getCount();
  private:
    std::vector<Card> hand;
    int count;
    bool soft;
    bool hasAce;
};

#endif // HAND_H