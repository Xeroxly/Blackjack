#include <iostream>
#include "Hand.h"

Hand::Hand(){
    count = 0;
    hasAce= false;
    soft= false;
}

Hand::Hand(Card card){
    count = 0;
    addCard(card);
}

void Hand::showHand(){
    for(int i=0; i<hand.size(); i++){
        if(hand[i].number==1){
            std::cout << "Ace";
        } else if(hand[i].number==11){
            std::cout << "Jack";
        } else if(hand[i].number==12){
            std::cout << "Queen";
        } else if(hand[i].number==13){
            std::cout << "King";
        } else{
            std::cout << hand[i].number;
        }

        std::cout << " of " << hand[i].suit << std::endl;
    }
}

void Hand::addCard(Card card){
    hand.push_back(card);
    if(card.number==1){
        if(hasAce){
            count+=1;
        } else{
            count+=11;
            soft= true;
            hasAce== true;
        }
    } else if(card.number>=10){
        count += 10;
    } else {
        count += card.number;
    }
}

int Hand::getCount(){
    return count;
}

int Hand::getLength(){
    return hand.size();
}

bool Hand::checkSplit(){
    return ((getLength()==2) && (hand[0].number==hand[1].number));
}

bool Hand::isSoft(){
    return soft;
}

void Hand::makeHard(){
    count-=10;
    soft= false;
}

void Hand::dealerCard(){
    if(hand[1].number==1){
        std::cout << "Ace";
    } else if(hand[1].number==11){
        std::cout << "Jack";
    } else if(hand[1].number==12){
        std::cout << "Queen";
    } else if(hand[1].number==13){
        std::cout << "King";
    } else{
        std::cout << hand[1].number;
    }
    std::cout << " of " << hand[1].suit << std::endl;
}

Card Hand::getCard(int number){
    return hand[number];
}