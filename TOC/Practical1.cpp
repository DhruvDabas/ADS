#include <iostream>
#include <string>
using namespace std;

bool exactly_3_1s(const string& input){
    int curr = 0; // Starting state is q0

    for (char c : input){
        switch (curr){
            case 0: // q0: No consecutive 1's
                if (c=='1'){
                    curr = 1; // Transition to q1
                }
                else{
                    curr = 0; // Stay in q0
                }
                break;
            case 1: // q1: One consecutive 1
                if (c =='1'){
                    curr = 2; // Transition to q2
                }
                else{
                    curr = 0; // Transition to q0
                }
                break;
            case 2: // q2: Two consecutive 1's
                if(c =='1'){
                    curr = 3; // Transition to q3 accept state
                }
                else {
                    curr = 0; // Transition to q0
                }
                break;
            case 3: // q3 is accepting state if in q3, stay in q3
                curr = 3;
                break;
            default:
                cout <<"Invalid state!"<<endl;
                return false;
        }
    }

    // DFA accepts the string if it reaches the accepting state q3
    return curr== 3;
}

int main() {
    string input;
    cout<< "enter a string: ";
    cin >>input;

    if (exactly_3_1s(input)){
        cout << "The string is accepted" << endl;
    } 
    else{
        cout << "The string is not accepted" << endl;
    }
}