#include "Roulette.cpp"
using namespace std;

class Casino{
    private:
        int balance;
    public:
        Casino(){
            balance = 500;
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
        Roulette createRoulette(){
            return Roulette();
        }
};