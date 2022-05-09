#include<iostream>
//#include<vector>

using namespace std;

class Blackjack{
    private:
        char deck[52];
        //1 stands for 10
        char numbers[9] = {'2','3','4','5','6','7','8','9','1'};
        char faceCards[4] = {'J','Q','K','A'};
    public:
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
        
};
