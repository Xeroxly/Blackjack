#include "Deck.h"

Deck::Deck(){
    for(int i=0; i<52; i++){
        if(i<13){
            deck[i].suit= "Hearts";
        } else if(i>=13 && i<26){
            deck[i].suit= "Diamonds";
        } else if(i>=26 && i<39){
            deck[i].suit= "Clubs";
        } else{
            deck[i].suit= "Spades";
        }

        deck[i].number= ((i%13)+1);
        
    }
    position= 0;
}

void Deck::ShowDeck(){
    for(int i=0; i<52; i++){
        std::cout << deck[i].number << " of " << deck[i].suit << std::endl;
    }
}

void Deck::Shuffle(){
    Card temp;
    int rand1, rand2;
    srand (time(NULL));

    std::cout << std::endl << "SHUFFLING" << std::endl << std::endl;

    for(int i=0; i<200; i++){
        rand1= rand()%52;
        rand2= rand()%52;
        temp=deck[rand1];
        deck[rand1]= deck[rand2];
        deck[rand2]= temp;
    }

    position= 0;
}

Card Deck::getTop(){
    Card temp= deck[position];
    position++;
    if(position==51){
        Shuffle();
    }
    return temp;
}
