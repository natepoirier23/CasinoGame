//This is the file to play the casino games.
#include <iostream>
#include "Casino.cpp"

using namespace std;

int main(){
    Casino casino = Casino();
    cout << "Hello and welcome to the casino! \n";
    cout << "********************************************\n";
    cout << "There are a total of 3 games you can choose from! You start with 500 dollars, and they are as follows: ";
    cout << "Roulette, blackjack, slots.\n";

    while(!casino.gameOver()){
        cout << "********************************************\n";
        cout << "What game are you going to play? \n\n";
        string input;
        cin >> input;
        if(casino.checkForExit(input)){
            break;
        }
        else if(input == "roulette"){
            Roulette roulette = casino.createRoulette();
            
        }
        else if(input == "slots"){

        }
        else if(input == "blackjack"){

        }
        


    }
}