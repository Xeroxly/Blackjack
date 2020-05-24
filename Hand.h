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
    int getLength();
    bool checkSplit();
    bool isSoft();
    void makeHard();
    void dealerCard();
    Card getCard(int number);
  private:
    std::vector<Card> hand;
    int count;
    bool soft;
    bool hasAce;
};

#endif // HAND_H