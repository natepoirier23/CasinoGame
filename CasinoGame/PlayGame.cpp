//This is the file to play the casino games.
#include <iostream>
#include "Casino.cpp"
#include <string>


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
                cout << "Or, you can bet both for a chance at x5. \n" << "You have $" << casino.checkMoney() << ". Enter 'play', or enter hub or exit to leave : \n\n";
                string s;
                cin >> s;
                if(roulette.checkForHub(s)){
                    break;
                }
                else if(s != "play"){
                    cout << "Invalid entry. \n \n";
                }
                else{
                    int bet;
                    while (true) // Loop until user enters a valid input
                    {
                        cout << "\nEnter your bet: \n";
                        cin >> bet;

                        // Check whether the user entered meaningful input
                        if(bet <= casino.checkMoney() && bet >= 1){
                            break;
                        }
                        else{ // otherwise tell the user what went wrong
                            cout << "\nInvalid money amount.\n\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                       
                    char color;
                    while (true) // Loop until user enters a valid input
                    {
                        cout << "Enter what you would like to bet on! (b or r) You can enter an 'x' for color to skip. \n";
                        cin >> color;

                        // Check whether the user entered meaningful input
                        if(color == 'r' || color =='b' || color =='x'){
                            break; //here is the issue
                        }
                        else{ // otherwise tell the user what went wrong
                            cout << "\nInvalid entry/entries.\n\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    string guess;
                    int guessS; //variable for conversion
                    bool check;
                    while (true) // Loop until user enters a valid input
                    {
                        check = true;
                        cout << "Enter what you would like to bet on! (1-38) You can enter a '0' to skip. \n";
                        cin >> guess;
                        try {
                            guessS = stoi(guess);
                        }
                        catch (const std::invalid_argument& ia) {
                            //std::cerr << "Invalid argument: " << ia.what() << std::endl;
                            check = false;
                        }
                        
                        // Check whether the user entered meaningful input
                        if(guessS <=36 && guessS >=0 && check){
                            break;
                        }
                        else{ // otherwise tell the user what went wrong
                            cout << "\nInvalid entry/entries.\n\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    if((color == 'r' || color == 'b') && guessS <= 38 && guessS > 0){
                        vector<bool> result = roulette.playGame(color,guessS);
                        if(result[0] == true && result[1] == true){
                            casino.winMoney(bet * 5);
                            cout << "\nYou win $" << bet*5 << "!\n";
                        }
                        else{
                            casino.loseMoney(bet);
                            cout << "\nYou lose $" << bet << "! Better luck next time.\n";
                        }
                    }
                    else if(color == 'x' && guessS <= 38 && guessS > 0){
                        bool result = roulette.playGame(guessS);
                        if(result == true){
                            casino.winMoney(bet * 3);
                            cout << "\nYou win $" << bet*3 << "!\n";
                        }
                        else{
                            casino.loseMoney(bet);
                            cout << "\nYou lose $" << bet << "! Better luck next time.\n";
                        }
                    }
                    else if((color == 'r' || color == 'b') && guessS == 0){
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
            }
            cout << "Heading back to the lobby... \n\n";
        }
        else if(input == "slots"){
            Slots slots = casino.createSlots();
            while(!casino.gameOver()){
                cout << "Welcome to slots! You can pick a roll a chance to earn x3 or \n" << "you can get lucky 7's to win x10!\n";
                cout << "You have $" << casino.checkMoney() << ". Enter 'play', or enter hub or exit to leave : \n\n";
                string s;
                cin >> s;
                if(slots.checkForHub(s)){
                    break;
                }
                else if(s != "play"){
                    cout << "Invalid entry. \n \n";
                }
                else{
                    int bet;
                    while (true) // Loop until user enters a valid input
                    {
                        cout << "\nEnter your bet: \n";
                        cin >> bet;

                        // Check whether the user entered meaningful input
                        if(bet <= casino.checkMoney() && bet >= 1){
                            break;
                        }
                        else{ // otherwise tell the user what went wrong
                            cout << "\nInvalid money amount.\n\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    int result = slots.playGame();
                    if(result == 0){
                        casino.loseMoney(bet);
                    }
                    else if(result == 1){
                        casino.winMoney(bet*3);
                    }
                    else if(result == 7){
                        casino.winMoney(bet*10);
                    }
                }
            }
        }
        else if(input == "blackjack"){

        }
        else{
            cout << "Invalid option. Please select a game, or type exit to leave.\n";
        }
             
        

    }
    
    cout << "Thanks for playing!"; 
}