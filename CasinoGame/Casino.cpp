#include "Roulette.cpp"
using namespace std;

class Casino{
    private:
        int balance;
    public:
        Casino(){
            balance = 500;
        }
        int checkMoney(){
            return balance;
        }
        void loseMoney(int amount){
            balance -= amount;
        }
        void winMoney(int amount){
            balance += amount;
        }
        bool gameOver(){
            if(balance == 0){
                return true;
            }
            return false;
        }
        bool checkForExit(string s){
            if(s == "exit"){
                return true;
            }
            return false;
        }

        Roulette createRoulette(){
            return Roulette();
        }
};