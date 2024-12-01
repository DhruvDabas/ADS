#include <iostream>
#include <string>
#include <stack>
using namespace std;
//w.c.w'
//w is a string of a and b symbols
stack<char> st;
void state0(string,int w);
void state1(string,int w);
void state2(string,int w);
void state3(string,int w);

void state0(string w, int i){
	cout<<"In state0"<<endl;
	if(w[i]=='a'){
		st.push(w[i]);
		state0(w,i+1);
	}
	else if(w[i]=='b'){
		st.push(w[i]);
		state0(w,i+1);
	}
	else if(w[i]=='c'){
		state1(w,i+1);
	}
	else{ //e is read
		state3(w,i+1);
	}
}
void state1(string w, int i){
	cout<<"In state1"<<endl;
	if(w[i]=='a'){
		if(st.top()=='a'){
			st.pop();
			state1(w,i+1);
		}
		else state3(w,i+1);
	}
	else if(w[i]=='b'){
		if(st.top()=='b'){
			st.pop();
			state1(w,i+1);
		}
		else state3(w,i+1);
	}
	else if(w[i]=='c'){
		state3(w,i+1);
	}
	else{  //e is read
		if(st.top()=='z')state2(w,i+1);
		else state3(w,i+1);
	}
}
void state2(string w, int i){
	cout<<"In state2"<<endl;
	cout<<"String Accepted"<<endl;
}
void state3(string w, int i){
	cout<<"In state3"<<endl;
	cout<<"String Rejected"<<endl;
}
int main(){
	string w;
	bool flag=1;
	do{
		flag=1;
		cout<<"Enter the string: ";
		cin>>w;
		for(int i=0;i<w.length();i++){
			if(w[i]!='a' and w[i]!='b' and w[i]!='c')flag=0;
		}
	}while(flag==0);
	w=w+"e";
	st.push('z');
	state0(w,0);
}
