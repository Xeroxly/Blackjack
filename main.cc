#include "Deck.h"

int main(){
    Deck decky= Deck();
    decky.ShowDeck();
    decky.Shuffle();
    std::cout << std::endl << std::endl;
    decky.ShowDeck();

    return 0;
}