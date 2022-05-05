//This is the file to play the casino games.
#include <iostream>
#include "Casino.cpp"

using namespace std;

int main(){
    Casino casino = Casino();
    cout << "Hello and welcome to the casino! \n";
    cout << "********************************************\n";
    cout << "There are a total of 3 games you can choose from! They are as follows: ";
    cout << "Roulette, blackjack, slots.\n";
    //while(!casino.gameOver()){
    cout << "********************************************\n";
    cout << "What game are you going to play? \n\n";
    //cin >>
    Roulette roulette = casino.createRoulette();
    if(roulette.playGame('b')){
        cout << "Hooray!\n";
    }
    else{
        cout << "Booooo...\n";
    }
    if(roulette.playGame(15)){
        cout << "Hooray!\n";
    }
    else{
        cout << "Booooo...\n";
    }

    //}
}