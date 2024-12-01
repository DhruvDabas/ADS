#include <iostream>
#include <string>
#include <vector>
using namespace std;
//a^n.b^n.c^n
void state0(vector<char>,int w);
void state1(vector<char>,int w);
void state2(vector<char>,int w);
void state3(vector<char>,int w);
void state4(vector<char>,int w);
void state5(vector<char>,int w);
void state6(vector<char>,int w);

void state0(vector<char> w, int i){
	cout<<"In state0"<<endl;
	if(w[i]=='a'){
		w[i]='x';
		state1(w,i+1); //replace by x, move right
	}
	else if(w[i]=='b'){
		state6(w,i);  //reject
	}
	else if(w[i]=='c'){
		state6(w,i);  //reject
	}
	else if(w[i]=='x'){
		state6(w,i);  //reject
	}
	else if(w[i]=='y'){
		state4(w,i+1); //unchanged move to right
		//accepted
	}
	else if(w[i]=='z'){
		state6(w,i);  //reject
	}
	else{  //e is read
		state5(w,i);  //empty string is aacepted
	}
}
void state1(vector<char> w, int i){
	cout<<"In state1"<<endl;
	if(w[i]=='a'){
		state1(w,i+1); //unchanged move to right
	}
	else if(w[i]=='b'){
		w[i]='y';
		state2(w,i+1); //replace by y, move right
	}
	else if(w[i]=='c'){
		state6(w,i);  //reject
	}
	else if(w[i]=='x'){
		state6(w,i);  //reject
	}
	else if(w[i]=='y'){
		state1(w,i+1); //unchanged move to right
	}
	else if(w[i]=='z'){
		state6(w,i);  //reject
	}
	else{  //e is read
		state6(w,i);  //reject
	}
}
void state2(vector<char> w, int i){
	cout<<"In state2"<<endl;
	if(w[i]=='a'){
		state6(w,i);  //reject
	}
	else if(w[i]=='b'){
		state2(w,i+1);  //unchanged move to right
	}
	else if(w[i]=='c'){
		w[i]='z';
		state3(w,i-1); //replace by z, move left
	}
	else if(w[i]=='x'){
		state6(w,i);  //reject
	}
	else if(w[i]=='y'){
		state6(w,i);  //reject
	}
	else if(w[i]=='z'){
		state2(w,i+1);  //unchanged move to right
	}
	else{  //e is read
		state6(w,i);  //reject
	}
}
void state3(vector<char> w, int i){
	cout<<"In state3"<<endl;
	if(w[i]=='a'){
		state3(w,i-1);  //unchanged move to left
	}
	else if(w[i]=='b'){
		state3(w,i-1);  //unchanged move to left
	}
	else if(w[i]=='c'){
		state6(w,i);  //reject
	}
	else if(w[i]=='x'){
		state0(w,i+1);  //move right, jump to start
	}
	else if(w[i]=='y'){
		state3(w,i-1);  //unchanged move to left
	}
	else if(w[i]=='z'){
		state3(w,i-1);  //unchanged move to left
	}
	else{  //e is read
		state6(w,i);  //reject
	}
}
void state4(vector<char> w, int i){
	cout<<"In state4"<<endl;
	if(w[i]=='a'){
		state6(w,i);  //reject
	}
	else if(w[i]=='b'){
		state6(w,i);  //reject
	}
	else if(w[i]=='c'){
		state6(w,i);  //reject
	}
	else if(w[i]=='x'){
		state6(w,i);  //reject
	}
	else if(w[i]=='y'){
		state4(w,i+1);  //unchanged move to right
	}
	else if(w[i]=='z'){
		state4(w,i+1);  //unchanged move to right
	}
	else{  //e is read
		state5(w,i);
	}
}
void state5(vector<char> w, int i){
	cout<<"In state5"<<endl;
	cout<<"String Accepted"<<endl;
}
void state6(vector<char> w, int i){
	cout<<"In state6"<<endl;
	cout<<"String Rejected"<<endl;
}
int main(){
	string st;
	bool flag=1;
	do{
		flag=1;
		cout<<"Enter the string: ";
		cin>>st;
		for(int i=0;i<st.length();i++){
			if(st[i]!='a' and st[i]!='b' and st[i]!='c')flag=0;
		}
	}while(flag==0);
	st=st+"e";
	vector<char> w;
	for(int i=0;i<st.length();i++){
		w.push_back(st[i]);
	}
	state0(w,0);
}
