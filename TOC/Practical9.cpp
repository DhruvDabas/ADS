#include <iostream>
#include <string>
using namespace std;

bool turingMachine(string tape) {
    int head = 0;
    int len = tape.length();
    bool found;

    // Check if the tape contains at least one 'a', 'b', 'c'
    if (len < 3 || tape[0] != 'a') return false;

    while (true) {
        // Mark an 'a' (replace with 'X')
        found = false;
        for (int i = 0; i < len; ++i) {
            if (tape[i] == 'a') {
                tape[i] = 'X';
                found = true;
                break;
            }
        }
        if (!found) break; // No 'a's

        // Find and mark the first unmarked 'b' replace with 'Y'
        found = false;
        for (int i = 0; i < len; ++i) {
            if (tape[i] == 'b') {
                tape[i] = 'Y';
                found = true;
                break;
            }
        }
        if (!found) return false; // No matching 'b' for an 'a'

        // Find and mark the first unmarked 'c' replace with 'Z'
        found = false;
        for (int i = 0; i < len; ++i) {
            if (tape[i] == 'c') {
                tape[i] = 'Z';
                found = true;
                break;
            }
        }
        if (!found) return false; // No matching 'c' for an 'a' and 'b'
    }

    // Ensure all symbols are marked (X, Y, Z)
    for (int i = 0; i < len; ++i) {
        if (tape[i] != 'X' && tape[i] != 'Y' && tape[i] != 'Z') {
            return false; // Extra symbols found
        }
    }

    return true; // Accepted
}

int main() {
    string input;
    cout << "Enter a string (a^n b^n c^n): ";
    cin >> input;

    if (turingMachine(input)) {
        cout << "Accepted: The string is in the language a^n b^n c^n where n > 0." << endl;
    } else {
        cout << "Rejected: The string is not in the language." << endl;
    }

    return 0;
}