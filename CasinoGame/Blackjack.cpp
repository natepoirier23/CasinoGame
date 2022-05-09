#include<iostream>
//#include<vector>

using namespace std;

class Blackjack{
    private:
        char deck[52];
        char numbers[9] = {'2','3','4','5','6','7','8','9','10'};
        char faceCards[4] = {'J','Q','K','A'};
    public:
        Blackjack(){}

        void createDeck(){
            int counter = 0;
            for(int i = 0;i<9;i++){
                deck[i] = numbers[i];
                cout << deck[i];
            }
            for(int i = 0;i<4;i++){
                deck[i+9] = faceCards[i];
            }
            for(int i = 0;i<9;i++){
                deck[i+13] = numbers[i];
                cout << deck[i];
            }
            for(int i = 0;i<4;i++){
                deck[i+22] = faceCards[i];
            }
            for(int i = 0;i<9;i++){
                deck[i+26] = numbers[i];
                cout << deck[i];
            }
            for(int i = 0;i<4;i++){
                deck[i+35] = faceCards[i];
            }
            for(int i = 0;i<9;i++){
                deck[i+39] = numbers[i];
                cout << deck[i];
            }
            for(int i = 0;i<4;i++){
                deck[i+48] = faceCards[i];
            }
        }
};
