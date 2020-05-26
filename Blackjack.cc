#include "Blackjack.h"

Blackjack::Blackjack(){
    *deck= Deck();
    *dealer= Hand();
}

Blackjack::Blackjack(Deck* deck_, Hand* dealer_){
    deck= deck_;
    dealer= dealer_;
}

int Blackjack::playGame(Hand* hand, int* money, int* bet){
    deal(hand);
    int handResult= playHand(hand, money, bet);
    int dealerResult;
    if(handResult==2){
        return 2;
    } else if(handResult==0){
        return 0;
    } else if(handResult==100){
        return 100;
    } else{
        dealerResult= dealerHand();
        if(dealerResult==1){
            return 1;
        }
    }

    if(handResult>dealerResult){
        return 1;
    } else if(handResult<dealerResult){
        return 0;
    } else{
        return 3;
    }
    
}

void Blackjack::pay(int result, int* money, int* bet){
    if(result==1){ //regular win
        *money+=*bet;
        std::cout << std::endl << "Winner!" << std::endl << std::endl;
    } else if(result==2){ //blackjack
        *money+=(*bet*1.5);
        std::cout << std::endl << "BLACKJACK!!!" << std::endl << std::endl;
    } else if(result==3){ //push
        std::cout << std::endl << "Push" << std::endl << std::endl;
    } else if(result==0){ //loss
        *money-=*bet;
        std::cout << std::endl << "Loser.." << std::endl << std::endl;
    }
}

void Blackjack::deal(Hand* hand){
    std::cout << "Welcome to Blackjack" << std::endl;
    std::cout << std::string( 100, '-' ) << std::endl;

    if(hand->getLength()){
        dealer->addCard(deck->getTop());
    } else{
        hand->addCard(deck->getTop());
        dealer->addCard(deck->getTop());
    }
    hand->addCard(deck->getTop());
    dealer->addCard(deck->getTop());
}

int Blackjack::playHand(Hand* hand, int* money, int* bet){
    int action= -1;
    bool insurance= false;
    while(1){
        if(hand->isSoft() && hand->getCount()>21){
            hand->makeHard();
        }

        std::cout << "Dealer has: " << std::endl;
        dealer->dealerCard();
        std::cout << std::endl;

        std::cout << "You have: " << std::endl;
        hand->showHand();
        std::cout << std::endl << "Your total is: " << hand->getCount() << std::endl << std::endl;

        if(hand->getCount()==21){
            if(hand->getLength()==2){
                return 2;
            } else{
                return 21;
            }
        }

        if(hand->getCount()>21 && hand->isSoft()==false){
            return 0;
        }

        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Hit" << std::endl;
        std::cout << "2. Stand" << std::endl;
        if(hand->getLength()==2){
            std::cout << "3. Double Down" << std::endl;
        }
        if(hand->checkSplit()){
            std::cout << "4. Split" << std::endl;
        }
        if(dealer->getCard(1).number==1 && hand->getLength()==2){
            std::cout << "5. Buy Insurance" << std::endl;
        }

        std::cin >> action;
        std::cout << std::endl;

        if(action==1){
            hand->addCard(deck->getTop());
            std::cout << "You hit" << std::endl;
            std::cout << std::string( 100, '-' ) << std::endl;
        } else if(action==2){
            std::cout << "You stayed" << std::endl;
            std::cout << std::string( 100, '-' ) << std::endl;
            return hand->getCount();
        } else if(action==3){
            if(*bet>(*bet-*money)){
                std::cout << "You dont have enough money for that!" << std::endl;
            } else{
                hand->addCard(deck->getTop());
                std::cout << "You doubled down" << std::endl;
                std::cout << std::string( 100, '-' ) << std::endl;
                (*bet)*=2;
                hand->doubleDown();
                hand->showHand();
                std::cout << "Your total is: " << hand->getCount() << std::endl << std::endl;
                if(hand->getCount()>21){
                    if(hand->isSoft()){
                        hand->makeHard();
                        return hand->getCount();
                    } else{
                        return 0;
                    }
                } else{
                    return hand->getCount();
                }
            }
        } else if(action==4){
            std::cout << "You Split" << std::endl;
            std::cout << std::string( 100, '-' ) << std::endl;
            Hand split1= Hand(hand->getCard(0));
            Hand split2= Hand(hand->getCard(1));
            split1.addCard(deck->getTop());
            split2.addCard(deck->getTop());
            bool payed1= false;
            bool payed2= false;

            int result1= playHand(&split1, money, bet);
            if(result1==2){
                pay(2, money, bet);
                payed1= true;
            } else if(result1==0){
                pay(0, money, bet);
                payed1= true;
            }

            if(split1.getDoubled()){
                (*bet)/=2;
            } 

            int result2= playHand(&split2, money, bet);
            if(result2==2){
                pay(2, money, bet);
                payed2= true;
            } else if(result2==0){
                pay(0, money, bet);
                payed2= true;
            }

            if(split2.getDoubled()){
                (*bet)/=2;
            }

            int dealerResult= dealerHand(); 
            if(dealerResult==1){
                if(!payed1){
                    if(split1.getDoubled()){
                        (*bet)*=2;
                        pay(1, money, bet);
                    } else{
                        pay(1, money, bet);
                    }
                    payed1= true;
                }
                if(!payed2){
                    if(split2.getDoubled()){
                        (*bet)*=2;
                        pay(1, money, bet);
                    } else{
                        pay(1, money, bet);
                    }
                    payed2= true;
                }
            }

            if(result1>dealerResult || result2>dealerResult){
                if(!payed1){
                    if(split1.getDoubled()){
                        (*bet)*=2;
                        pay(1, money, bet);
                    } else{
                        pay(1, money, bet);
                    }
                    payed1= true;
                }
                if(!payed2){
                    if(split2.getDoubled()){
                        (*bet)*=2;
                        pay(1, money, bet);
                    } else{
                        pay(1, money, bet);
                    }
                    payed2= true;
                }
            } else if(result1<dealerResult || result2<dealerResult){
                if(!payed1){
                    if(split1.getDoubled()){
                        (*bet)*=2;
                        pay(0, money, bet);
                    } else{
                        pay(0, money, bet);
                    }
                    payed1= true;
                }
                if(!payed2){
                    if(split2.getDoubled()){
                        (*bet)*=2;
                        pay(0, money, bet);
                    } else{
                        pay(0, money, bet);
                    }
                    payed2= true;
                }
            } else{
                if(!payed1){
                    if(split1.getDoubled()){
                        (*bet)*=2;
                        pay(3, money, bet);
                    } else{
                        pay(3, money, bet);
                    }
                    payed1= true;
                }
                if(!payed2){
                    if(split2.getDoubled()){
                        (*bet)*=2;
                        pay(3, money, bet);
                    } else{
                        pay(3, money, bet);
                    }
                    payed2= true;
                }
            }
            return 100;
        } else if(action==5){
            insurance= true;
            *money-=((*bet)*.5);
            std::cout << "You bought insurace" << std::endl;
            std::cout << std::string( 100, '-' ) << std::endl;
        } else{
            std::cout << "Try a real thing" << std::endl;
        }

        if(dealer->getCard(1).number==1 && dealer->getCount()==21 && dealer->getLength()==2){
            std::cout << "Dealer has:" << std::endl;
            dealer->showHand();
            std::cout << std::endl;
            if(insurance){
                *money+=(*bet);
                return 0;
            } else{
                return 0;
            }
        }
    }
}

int Blackjack::dealerHand(){
    std::cout << "Dealer has:" << std::endl;
    dealer->showHand();
    std::cout << std::endl;

    std::cout << "Dealer's total is: " <<  dealer->getCount() << std::endl;
    while(dealer->getCount()<17){
        std::cout << "Dealer hit" << std::endl;
        std::cout << std::string( 100, '-' ) << std::endl;
        dealer->addCard(deck->getTop());
        std::cout << "Dealer has:" << std::endl;
        dealer->showHand();
        std::cout << std::endl;
        std::cout << "Dealer's total is: " <<  dealer->getCount() << std::endl;
        if(dealer->isSoft() && dealer->getCount()==17){
            dealer->makeHard();
        }
        if(dealer->getCount()>21){
            return 1;
        }
    }
    std::cout << "Dealer stayed" << std::endl;
    std::cout << std::string( 100, '-' ) << std::endl;
    return dealer->getCount();
}
