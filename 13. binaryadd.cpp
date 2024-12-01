#include <iostream>
#include <string>
#include <vector>
using namespace std;
//addition to a binary number
void state0(vector<char>,int w);
void state1(vector<char>,int w);
void state2(vector<char>,int w);
void state3(vector<char>,int w);
void state4(vector<char>,int w);

void state0(vector<char> w, int i){
	cout<<"In state0"<<endl;
	if(w[i]=='0'){
		state0(w,i+1); //move right
	}
	else if(w[i]=='1'){
		state0(w,i+1);  //move right
	}
	else{  //e is read
		state1(w,i-1);  //move to left n start adding
	}
}
void state1(vector<char> w, int i){
	cout<<"In state1"<<endl;
	if(w[i]=='0'){
		w[i]='1';
		state2(w,i-1); //change 0 by 1, carry used up
	}
	else if(w[i]=='1'){
		w[i]='0';
		state1(w,i-1);  //change all 1's to 0,moving left
	}
	else{  //e is read
		w[i]='1';  //carry use
		state3(w,i);  //done
	}
}
void state2(vector<char> w, int i){
	cout<<"In state2"<<endl;
	if(w[i]=='0'){
		state2(w,i-1); //move left
	}
	else if(w[i]=='1'){
		state2(w,i-1);  //move left
	}
	else{  //e is read
		state3(w,i);  //done
	}
}
void state3(vector<char> w, int i){
	cout<<"In state3"<<endl;
	cout<<"Done"<<endl;
	string res="";
	for(int j=0;j<w.size();j++){
		if(w[j]!='e') res+=w[j];
	}
	cout<<res;
}
int main(){
	string st;
	bool flag=1;
	do{
		flag=1;
		cout<<"Enter the string: ";
		cin>>st;
		for(int i=0;i<st.length();i++){
			if(st[i]!='0' and st[i]!='1')flag=0;
		}
	}while(flag==0);
	st="e"+st+"e";
	vector<char> w;
	for(int i=0;i<st.length();i++){
		w.push_back(st[i]);
	}
	state0(w,1);
}
