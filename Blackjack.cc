#include "Blackjack.h"

Blackjack::Blackjack(){
    hand= Hand();
    dealer= Hand();
    activeHands= 1;
}

int Blackjack::playGame(Deck* deck, Hand hand, int* money, int bet){
    dealer= Hand();
    
    std::cout << "Welcome to Blackjack" << std::endl;
    std::cout << std::string( 100, '-' ) << std::endl;

    if(hand.getLength()){
        dealer.addCard(deck->getTop());
    } else{
        hand.addCard(deck->getTop());
        dealer.addCard(deck->getTop());
    }
    hand.addCard(deck->getTop());
    dealer.addCard(deck->getTop());

   int action= -1;
        while(1){
            if(hand.isSoft() && hand.getCount()>21){
                hand.makeHard();
            }

            std::cout << std::endl << "Dealer has: " << std::endl;
            dealer.dealerCard();
            std::cout << std::endl;

            std::cout << "You have: " << std::endl;
            hand.showHand();
            std::cout << std::endl << "Your total is: " << hand.getCount() << std::endl << std::endl;

            if(hand.getCount()==21 && hand.getLength()==2){
                return 2;
            }

            if(hand.getCount()>21 && hand.isSoft()==false){
                return 0;
            }

            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1. Hit" << std::endl;
            std::cout << "2. Stand" << std::endl;
            if(hand.getLength()==2){
                std::cout << "3. Double Down" << std::endl;
            }
            if(hand.checkSplit()){
                std::cout << "4. Split" << std::endl;
            }

            std::cin >> action;
            std::cout << std::endl;

            if(action==1){
                hand.addCard(deck->getTop());
                std::cout << "You hit" << std::endl;
                std::cout <<  std::string( 100, '-' ) << std::endl;
            } else if(action==2){
                std::cout << "You stayed" << std::endl;
                break;
            } else if(action==3){
                hand.addCard(deck->getTop());
                std::cout << "You doubled down" << std::endl;
                std::cout <<  std::string( 100, '-' ) << std::endl;
                hand.showHand();
                std::cout << std::endl << "Your total is: " << hand.getCount() << std::endl;
                break;
            } else if(action==4){
                std::cout << "You Split" << std::endl;
                std::cout <<  std::string( 100, '-' ) << std::endl;
                Hand split1= Hand(hand.getCard(0));
                Hand split2= Hand(hand.getCard(1));
                pay(playGame(deck, split1, money, bet), money, bet);
                pay(playGame(deck, split2, money, bet), money, bet);
                return -1;
            } else{
                std::cout << "Try a real thing" << std::endl;
            }
        }
        std::cout <<  std::string( 100, '-' ) << std::endl;

        std::cout << "Dealer has:" << std::endl;
        dealer.showHand();

        std::cout << "Dealer's total is: " <<  dealer.getCount() << std::endl << std::endl;
        std::cout <<  std::string( 100, '-' ) << std::endl << std::endl;
        while(dealer.getCount()<17){
            std::cout << "Dealer hit" << std::endl;
            dealer.addCard(deck->getTop());
            dealer.showHand();
            std::cout << std::endl;
            std::cout << "Dealer's total is: " <<  dealer.getCount() << std::endl;
            std::cout <<  std::string( 100, '-' ) << std::endl << std::endl;
            if(dealer.isSoft() && dealer.getCount()==17){
                dealer.makeHard();
            }
            if(dealer.getCount()>21){
                return 1;
            }
        }
        if(dealer.getCount()==hand.getCount()){
            return 3;
        } else if(dealer.getCount()>hand.getCount()){
            return 0;
        } else{
            return 1;
        }
return -1;
}

void Blackjack::pay(int result, int* money, int bet){
    if(result==1){ //regular win
        *money+=bet;
        std::cout << "Winner!" << std::endl << std::endl;
    } else if(result==2){ //blackjack
        *money+=(bet*1.5);
        std::cout << "BLACKJACK!!!" << std::endl << std::endl;
    } else if(result==3){ //push
        std::cout << "Push" << std::endl << std::endl;
    } else if(result==0){ //loss
        *money-=bet;
        std::cout << "Loser.." << std::endl << std::endl;
    }
    std::cout << std::string( 100, '-' ) << std::endl;
}