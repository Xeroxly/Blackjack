#include "deck.h"

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

        if(i%13==0){
            deck[i].number= "A";
        } else if(i%13==10){
            deck[i].number= "J";
        } else if(i%13==11){
            deck[i].number= "Q";
        } else if(i%13==12){
            deck[i].number= "K";
        } else{
            deck[i].number= std::to_string((i%13)+1);
        }
    }
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

    for(int i=0; i<200; i++){
        rand1= rand()%52;
        rand2= rand()%52;
        temp=deck[rand1];
        deck[rand1]= deck[rand2];
        deck[rand2]= temp;
    }
}
