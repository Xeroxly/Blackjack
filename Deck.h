#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdlib>
#include "Card.h"

class Deck {
  public: 
    Deck();
    void Shuffle();
    void ShowDeck();
    Card getTop();
  private:
    Card deck[52];
    int position;
};

#endif // DECK_H