#include <iostream>
#include <vector>

using namespace std;

//class to create the slots game
class Slots{
    private:
        int row1,row2,row3;
        vector<char> characters = {'x','y','1','2','7'};
        char answerBoard[3][3];
    public:
        Slots(){}

        char randomChar(){
            //returns either x,y,1,2,7
            int x = rand() % 5;
            return characters[x];
        }

        bool checkForHub(string s){
            if(s == "hub" || s == "exit"){
                return true;
            }
            return false;
        }

        void createBoard(){
            for(int i=0;i < 3;i++){
                for(int x=0;x<3;x++){
                    answerBoard[i][x] = randomChar();
                }
            }
        }

        void printBoard(){
            for(int i=0;i < 3;i++){
                for(int x=0;x<3;x++){
                    cout << "[" << answerBoard[i][x] << "]";
                }
                cout << "\n";
            }
        }

        int playGame(){
            //0 is a loss, 1 is a win, and 7 is a jackpot
            createBoard();
            printBoard();

            //first row match
            if((answerBoard[0][0] == answerBoard[0][1]) && (answerBoard[0][0] == answerBoard[0][2])){
                if(answerBoard[0][0] == '7'){
                    return 7;
                }
                return 1;
            }
            //second row match
            else if((answerBoard[1][0] == answerBoard[1][1]) && (answerBoard[1][0] == answerBoard[1][2])){
                if(answerBoard[1][0] == '7'){
                    return 7;
                }
                return 1;
            }
            //third row match
            else if((answerBoard[2][0] == answerBoard[2][1]) && (answerBoard[2][0] == answerBoard[2][2])){
                if(answerBoard[2][0] == '7'){
                    return 7;
                }
                return 1;
            }
            //diagonal top left to bottom right match
            else if((answerBoard[0][0] == answerBoard[1][1]) && (answerBoard[0][0] == answerBoard[2][2])){
                if(answerBoard[0][0] == '7'){
                    return 7;
                }
                return 1;
            }
            //diagonal top right to bottom left match
            else if((answerBoard[0][2] == answerBoard[1][1]) && (answerBoard[0][2] == answerBoard[2][0])){
                if(answerBoard[0][2] == '7'){
                    return 7;
                }
                return 1;
            }
            else{
                return 0;
            }
        }
};
