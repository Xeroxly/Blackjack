#include "Deck.h"

int main(){
    Deck decky= Deck();
    decky.ShowDeck();
    decky.Shuffle();
    decky.ShowDeck();

    return 0;
}