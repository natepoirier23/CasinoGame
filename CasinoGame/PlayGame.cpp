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
        cout << "What game are you going to play? Or type exit to leave. \n\n";
        string input;
        cin >> input;
        if(casino.checkForExit(input)){
            break;
        }
        else if(input == "roulette"){
            Roulette roulette = casino.createRoulette();
            while(!casino.gameOver()){
                cout << "Welcome to roulette! You can pick a number 1-36 for a chance to earn x3 or \n" << "you can pick black or red to earn x1.5.\n";
                cout << "Or, you can bet both for a chance at x5. \n" << "You have $" << casino.checkMoney() << ". Enter play to play, or enter hub or exit to leave : ";
                string s;
                cin >> s;
                if(roulette.checkForHub(s)){
                    break;
                }
                else{
                    cout << "\nEnter your bet: ";
                    int bet;
                    cin >> bet;
                    if(bet > casino.checkMoney() || bet < 1){
                        cout << "\nInvalid money amount.\n";
                    }
                    else{
                        cout << "Enter what you would like to bet on! (b or r";
                    }
                }
            }
            cout << "Heading back to the lobby... \n\n";
        }
        else if(input == "slots"){

        }
        else if(input == "blackjack"){

        }
        else{
            cout << "Invalid option. Please select a game, or type exit to leave.\n";
        }
    }

    cout << "Thanks for playing!";
}