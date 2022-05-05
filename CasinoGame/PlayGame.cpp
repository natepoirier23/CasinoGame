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
                else if(s != "play"){
                    cout << "Invalid entry. \n \n";
                }
                else{
                    cout << "\nEnter your bet: \n";
                    int bet = 0;
                    cin >> bet;
                    if(bet <= casino.checkMoney() && bet >= 1){
                        cout << "Enter what you would like to bet on! (b or r, 1-38) You can leave either field empty by entering a '.' or include both. \n";
                        char color;
                        int guess;
                        cin >> color >> guess;
                        if(color == 'r' || color == 'b' && guess <= 38 && guess > 0){
                            vector<bool> result = roulette.playGame(color,guess);
                            if(result[0] == true && result[1] == true){
                                casino.winMoney(bet * 5);
                                cout << "\nYou win $" << bet*5 << "!\n";
                            }
                            else{
                                casino.loseMoney(bet);
                                cout << "\nYou lose $" << bet << "! Better luck next time.\n";
                            }
                        }
                        else if(color == '.' && guess <= 38 && guess > 0){
                            bool result = roulette.playGame(guess);
                            if(result == true){
                                casino.winMoney(bet * 3);
                                cout << "\nYou win $" << bet*3 << "!\n";
                            }
                            else{
                                casino.loseMoney(bet);
                                cout << "\nYou lose $" << bet << "! Better luck next time.\n";
                            }
                        }
                        else if(color == 'r' || color == 'b' && guess == '.'){
                            bool result = roulette.playGame(color);
                            if(result == true){
                                casino.winMoney(bet * 1.5);
                                cout << "\nYou win $" << bet*1.5 << "!\n";
                            }
                            else{
                                casino.loseMoney(bet);
                                cout << "\nYou lose $" << bet << "! Better luck next time.\n";
                            }
                        }
                        else{
                            cout << "\nInvalid entry. Please re-enter bet and what you are betting on.\n\n";
                        }
                    }
                    else{
                        cout << "\nInvalid money amount.\n";
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