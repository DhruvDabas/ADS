#include <iostream>
#include <string>
using namespace std;
//even a and b
void state0(string,int w);
void state1(string,int w);
void state2(string,int w);
void state3(string,int w);

void state0(string w, int i){
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state1(w,i+1);
		else if(w[i]=='b') state3(w,i+1);
	}
}
void state1(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state0(w,i+1);
		else if(w[i]=='b') state2(w,i+1);
	}
}
void state2(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state3(w,i+1);
		else if(w[i]=='b') state1(w,i+1);
	}
}
void state3(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state2(w,i+1);
		else if(w[i]=='b') state0(w,i+1);
	}
}
int main(){
	string w;
	bool flag=1;
	do{
		flag=1;
		cout<<"Enter the string: ";
		cin>>w;
		for(int i=0;i<w.length();i++){
			if(w[i]!='a' and w[i]!='b')flag=0;
		}
	}while(flag==0);
	state0(w,0);
}
