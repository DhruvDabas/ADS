#include <iostream>
#include <string>
using namespace std;
//three consecutive one must be in string
void state1(string,int w);
void state2(string,int w);
void state3(string,int w);
void state4(string,int w);

void state1(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='0') state1(w,i+1);
		else if(w[i]=='1') state2(w,i+1);
	}
}
void state2(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='0') state1(w,i+1);
		else if(w[i]=='1') state3(w,i+1);
	}
}
void state3(string w, int i){
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='0') state1(w,i+1);
		else if(w[i]=='1') state4(w,i+1);
	}
}
void state4(string w, int i){
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='0') state4(w,i+1);
		else if(w[i]=='1') state4(w,i+1);
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
			if(w[i]!='0' and w[i]!='1')flag=0;
		}
	}while(flag==0);
	state1(w,0);
}
