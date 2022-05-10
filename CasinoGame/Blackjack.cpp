#include<iostream>
#include<vector>
#include<random>
#include<time.h>

using namespace std;

class Blackjack{
    private:
        char deck[52];
        //1 stands for 10
        char numbers[9] = {'2','3','4','5','6','7','8','9','1'};
        char faceCards[4] = {'J','Q','K','A'};
    public:
        bool bust;
        bool hold;
        bool won;
        vector<char> hand;
        vector<char> dHand;
        bool dBust;
        bool dHold;
        bool dWon;

        Blackjack(){
            createDeck();
        }

        void createDeck(){
            int counter = 0;
            for(int i = 0;i<9;i++){
                deck[counter] = numbers[i];
                counter++;
            }
            for(int i = 0;i<4;i++){
                deck[counter] = faceCards[i];
                counter++;
            }
            for(int i = 0;i<9;i++){
                deck[counter] = numbers[i];
                counter++;
            }
            for(int i = 0;i<4;i++){
                deck[counter] = faceCards[i];
                counter++;
            }
            for(int i = 0;i<9;i++){
                deck[counter] = numbers[i];
                counter++;
            }
            for(int i = 0;i<4;i++){
                deck[counter] = faceCards[i];
                counter++;
            }
            for(int i = 0;i<9;i++){
                deck[counter] = numbers[i];
                counter++;
            }
            for(int i = 0;i<4;i++){
                deck[counter] = faceCards[i];
                counter++;
            }
        }

        bool checkForHub(string s){
            if(s == "hub" || s == "exit"){
                return true;
            }
            return false;
        }

        char randomCard(){
            //returns a random card from deck.
            int x = rand() % 52;
            return deck[x];
        }

        void printHand(){
            for(char c:hand){
                if(c == '1'){
                    cout << "10" << " ";
                }
                else{
                    cout << c << " ";
                }
            }
        }

        void printDHand(){
            for(char c:dHand){
                if(c == '1'){
                    cout << "10" << " ";
                }
                else{
                    cout << c << " ";
                }
            }
        }
        int convertDHand(){
            int temp = 0;
            for(int i=0;i < dHand.size();i++){
                if(dHand[i] == '1'){
                    temp +=10;
                }
                else if(dHand[i] == 'A'){
                    temp+=11;
                }
                else if(dHand[i] == 'J' || dHand[i] == 'Q' || dHand[i] == 'K'){
                    temp+=10;
                }
                else{
                    temp += (int)dHand[i]-48;
                }
            }
            return temp;
        }

        int convertHand(){
            int temp = 0;
            for(int i=0;i < hand.size();i++){
                if(hand[i] == '1'){
                    temp +=10;
                }
                else if(hand[i] == 'A'){
                    temp+=11;
                }
                else if(hand[i] == 'J' || hand[i] == 'Q' || hand[i] == 'K'){
                    temp+=10;
                }
                else{
                    temp += (int)hand[i]-48;
                }
            }
            return temp;
        }

        void playGame(){
            srand(time(0));
            bust = false;
            hold = false;
            won = false;
            hand.clear();
            dBust = false;
            dHold = false;
            dWon = false;
            dHand.clear();
        }
};
