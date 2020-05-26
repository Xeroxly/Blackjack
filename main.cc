#include <iostream>

#include "Deck.h"
#include "Blackjack.h"

using namespace std;

int main(){
    int bet;
    int game = -1;
    int money= 500;
    bool atCasino= true;
    Deck deck= Deck();
    deck.Shuffle();

    while(atCasino){
        cout << "Welcome to Trevor's Casino" << endl;
        cout << "You have " << money << " dollars." << endl;
        cout << "Please give me your money" << endl << endl;

        cout << "What game would you like to play?" << endl;
        cout << "0. Leave" << endl;
        cout << "1. Blackjack" << endl;

        cin >> game;

        if(game==1){
            Hand hand, dealer;
            Blackjack table= Blackjack(&deck, &dealer);
            cout << "\033[2J\033[1;1H" << "\033[2J\033[1;1H"; //clear the screen with ANSI escape codes
            while(1){
                hand= Hand();
                dealer= Hand();

                std::cout << "You have " << money << " Dollars" << std::endl;
                std::cout << "Please enter your bet" << std::endl;
                std::cout << "Enter -1 to leave table" << std::endl;
                std::cin >> bet;

                std::cout << "\033[2J\033[1;1H" << "\033[2J\033[1;1H"; //clear the screen with ANSI escape codes

                if(bet<=0 && bet!=-1 || bet>money){
                    std::cout << "Try again idiot" << std::endl;
                    continue;
                }

                if(bet==-1){
                    std::cout << "\033[2J\033[1;1H << \033[2J\033[1;1H"; //clear the screen with ANSI escape codes
                    break;
                }
                table.pay(table.playGame(&hand, &money, &bet), &money, &bet);
            }
        } else if(game==0){
            cout << "Come back with more money" << endl;
            return 0;
        } else {
            cout << "Try a better input" << endl;
        }
    }
}
