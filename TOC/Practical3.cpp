#include <iostream>
#include <string>
using namespace std;

bool first_2_same_as_last_2(const string& input){
    int curr = 0;  // Starting state 

    if(input.length() < 4){
        return false;  // false for strings < 4 char
    }

    for (size_t i = 0; i < input.length(); ++i){
        char c = input[i];

        switch (curr){
            case 0: // q0: Initial state
                if (c == 'a'||c == 'b'){
                    curr = 1; // Transition to q1 
                }
                else{
                    curr = 6; // invalid 
                }
                break;

            case 1: // q1: After reading first character
                if(c == 'a' || c == 'b'){
                    curr = 2; // Transition to q2
                } else {
                    curr = 6; // invalid 
                }
                break;

            case 2: // q2: 
                if(c == 'a' || c == 'b'){
                    curr = 3; // Transition to q3 (start comparing)
                }
                else{
                    curr = 6; // invalid
                }
                break;

            case 3: // q3
                if (c == input[0]){
                    curr = 4; // If third == first, transition to q4
                }
                else{
                    curr = 6; // reject
                }
                break;

            case 4: // q4
                if (c == input[1]){
                    curr = 5; // If fourth == second, transition to q5
                }
                else{
                    curr = 6; //reject
                }
                break;

            case 5: // q5: Accepting state 
                curr = 5;
                break;

            case 6: // q6: Rejecting state
                curr = 6; // Stay in rejecting state
                break;

            default:
                curr = 6; // invalid 
                break;
        }
    }
    return curr == 5;
}
int main() {
    string input;
    cout<< "Enter a string of {a, b}: ";
    cin >>input;

    if (first_2_same_as_last_2(input)){
        cout << "The string is accepted" << endl;
    }
    else{
        cout << "The string is not accepted" << endl;
    }
}