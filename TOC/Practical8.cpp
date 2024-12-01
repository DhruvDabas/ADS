#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool reverse_wxr(const string& input){
    stack<char> st;
    int n = input.length();
    int i = 0;

    // push 'w' in stack
    while(i <n &&(input[i]== 'a'|| input[i]=='b')){
        st.push(input[i]);
        i++;
    }
    // check for symbol X
    if(i < n && input[i]== 'X'){
        i++;
    }
    else {
        return false; // no X
    }

    // Step 3: Pop and compare with 'w^r' part
    while(i < n){
        if(st.empty()) {
            return false; // underflow
        }
        // Pop from stack and check if it matches the current char
        char top = st.top();
        if(top != input[i]){
            return false; // mismatch between w and w^r
        }
        st.pop();
        i++;
    }
    // if stack is empty the string is accepted by PDA
    return st.empty();
}
int main(){
    string input;
    cout<<"Enter string: ";
    cin>>input;

    if (reverse_wxr(input)){
        cout << "The string is accepted."<<endl;
    }
    else{
        cout << "The string is rejected."<<endl;
    }
}