#include <random>
#include <vector>
#include <iostream>

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
            cout << "\nThe color is: " << color[ran];
            return color[ran];
        }
        int randomNumber(){
            //returns a number 1-36
            int x = rand() % 36 + 1;
            cout << "\nThe number is: " << x;
            return x;
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
        bool checkForHub(string s){
            if(s == "hub" || s == "exit"){
                return true;
            }
            return false;
        }
        vector<bool> playGame(char c,int n){
            //True is a win, false is a loss
            bool co = playGame(c);
            bool nu = playGame(n);
            if(nu && co){
                return {true,true};
            }
            else if(nu && !co){
                return {true,false};
            }
            else if((!nu && co)){
                return {false,true};
            }
            else{
                return {false,false};
            }
        }
};