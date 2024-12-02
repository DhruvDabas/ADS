#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> FailureFunc(const string& pattern){
    int m = pattern.size();
    vector<int> failure(m, 0);
    int j = 0; // length of the previous longest prefix suffix

    for (int i = 1; i < m; i++){
        while (j > 0 && pattern[i] != pattern[j]){
            j = failure[j - 1];
        }
        if (pattern[i] == pattern[j]){
            j++;
        }
        failure[i] = j;
    }
    return failure;
}

void KMP(const string& text, const string& pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> failure = FailureFunc(pattern);

    int j = 0;

    for (int i = 0; i < n; i++){
        while (j > 0 && text[i] != pattern[j]){
            j = failure[j - 1];
        }
        if (text[i] == pattern[j]){
            j++;
        }
        if (j == m){ // found
            cout << "Pattern found at " <<(i - m + 1)<<endl;
            j = failure[j - 1]; // continue
        }
    }
}

int main(){
    string text;
    string pattern;
    
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);
    
    KMP(text, pattern);
}
