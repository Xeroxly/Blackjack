#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <cstdlib>

struct Card {
    int number;
    std::string suit;
};

class Deck {
  public: 
    Deck();
    void Shuffle();
    void ShowDeck();
  private:
    Card deck[52];
};

#endif // DECK_H