#include <iostream>
#include <string>
using namespace std;

string incrementBinary(string tape){
    int head = tape.length() - 1;
    bool carry = true;

    // Process the binary number right to left
    while (head >= 0 && carry){
        if (tape[head] == '0'){
            tape[head] = '1'; // No carry needed
            carry = false;
        } 
        else if (tape[head] == '1'){
            tape[head] = '0'; // Propagate carry
        }
        --head; // left
    }

    // If carry is true, add '1' at start
    if (carry){
        tape = '1' + tape;
    }
    return tape;
}

int main() {
    string binaryNumber;

    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    // Validate input
    for (char c : binaryNumber) {
        if (c != '0' && c != '1') {
            cout << "Invalid input. Please enter a binary number." << endl;
            return 1;
        }
    }

    string incrementedBinary = incrementBinary(binaryNumber);

    cout << "Incremented binary number: " << incrementedBinary << endl;

    return 0;
}
