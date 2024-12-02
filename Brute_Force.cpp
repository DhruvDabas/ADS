#include <iostream>
#include <string>
using namespace std;

void Force(const string& text, const string& pattern){
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(text[i + j] != pattern[j]){
                break;
            }
        }
        if (j == m){
            cout << "Pattern found at "<<i<< endl;
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
    
    Force(text, pattern);
}