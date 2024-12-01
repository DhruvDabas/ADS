#include <iostream>
#include <string>
using namespace std;

bool exactly_2_or_3_1s(const string& input){
    int curr = 0; // Starting state is q0

    for (char c : input){
        switch (curr){
            case 0: // q0: No '1' 
                if (c =='1'){
                    curr = 1; // Transition to q1
                }
                else{
                    curr = 0; // Stay in q0
                }
                break;
            case 1: // q1: One '1' found
                if (c =='1'){
                    curr = 2; // Transition to q2 (2 '1's)
                }
                else{
                    curr = 1; // Stay in q1
                }
                break;
            case 2: // q2: Two '1's fond // accepting state
                if(c == '1'){
                    curr = 3; // Transition to q3
                }
                else{
                    curr = 2; // Stay in q2
                }
                break;
            case 3: // q3: Three '1's found (accepting state)
                if (c == '1') {
                    curr = 4; // Transition to dead state q4 
                } else {
                    curr = 3; // Stay in q3
                }
                break;
            case 4: // q4: Dead state
                curr = 4; // Stay in q4 regardless of input
                break;
            default:
                cout <<"invalid state!"<< endl;
                return false;
        }
    }
    return curr == 2 || curr == 3;
}
int main(){
    string input;
    cout<<"enter string: ";
    cin >>input;

    if (exactly_2_or_3_1s(input)){
        cout<<"The string is accepted "<< endl;
    } 
    else{
        cout<<"The string is not accepted "<<endl;
    }
}