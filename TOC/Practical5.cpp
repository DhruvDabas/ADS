#include <iostream>
#include <string>

using namespace std;

bool simulateFA(const string& input) {
    int state = 0;

    for (char ch : input){
        if (state == 0){
            if (ch == 'a'){
                state = 1;
            } 
            else if (ch == 'b'){
                state = 2;
            } 
            else{
                return false;
            }
        } 
        else if (state == 1){
            if (ch == 'a'){
                state = 0;
            } 
            else if (ch == 'b'){
                state = 3;
            } 
            else{
                return false;
            }
        }
        else if (state == 2) {
            if (ch == 'a'){
                state = 3;
            } 
            else if (ch == 'b'){
                state = 0;
            } 
            else{
                return false;
            }
        }
        else if (state == 3) {
            if (ch == 'a'){
                state = 2;
            } 
            else if (ch == 'b'){
                state = 1;
            } else {
                return false;
            }
        }
    }
    return state == 0;
}

int main() {
    string input;
    cout << "Enter the string to check: ";
    cin >> input;

    // Check if the string is accepted by the FA
    if (simulateFA(input)) {
        cout << "The string is accepted by the FA." << endl;
    } else {
        cout << "The string is rejected by the FA." << endl;
    }
}
