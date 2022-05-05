#include <random>
#include <vector>

using namespace std;

//class to create the roulette game
class Roulette{
    private:
        vector<char> color = {'r','b'};
    public:
        Roulette(){}

        char randomColor(){
            //0 is red, 1 is black
            int ran = rand() % 2;
            return color[ran];
        }
        int randomNumber(){
            //returns a number 1-36
            return rand() % 36 + 1;
        }
        bool playGame(char c){
            //True is a win, false is a loss
            if(c == randomColor()){
                return true;
            }
            return false;
        }
        bool playGame(int n){
            //True is a win, false is a loss
            if(n == randomNumber()){
                return true;
            }
            return false;
        }
        vector<bool> playGame(char c,int n){
            //True is a win, false is a loss
            if(playGame(n) && playGame(c)){
                return {true,true};
            }
            else if(playGame(n) && !playGame(c)){
                return {true,false};
            }
            else if((!playGame(n) && playGame(c))){
                return {false,true};
            }
            else{
                return {false,false};
            }
        }
};