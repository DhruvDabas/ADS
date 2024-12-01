#include <iostream>
#include <string>
using namespace std;
//three consecutive one must be in string
void state0(string,int w);
void state1(string,int w);
void state2(string,int w);
void state3(string,int w);
void state4(string,int w);
void state5(string,int w);
void state6(string,int w);
void state7(string,int w);
void state8(string,int w);
void state9(string,int w);
void state10(string,int w);
void state11(string,int w);
void state12(string,int w);
void state13(string,int w);
void state14(string,int w);

void state0(string w, int i){
	cout<<"In state0"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state1(w,i+1);
		else if(w[i]=='b') state8(w,i+1);
	}
}
void state1(string w, int i){
	cout<<"In state1"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state2(w,i+1);
		else if(w[i]=='b') state5(w,i+1);
	}
}
void state2(string w, int i){
	cout<<"In state2"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state3(w,i+1);
		else if(w[i]=='b') state2(w,i+1);
	}
}
void state3(string w, int i){
	cout<<"In state3"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state4(w,i+1);
		else if(w[i]=='b') state2(w,i+1);
	}
}
void state4(string w, int i){
	cout<<"In state4"<<endl;
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state4(w,i+1);
		else if(w[i]=='b') state2(w,i+1);
	}
}
void state5(string w, int i){
	cout<<"In state5"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state6(w,i+1);
		else if(w[i]=='b') state5(w,i+1);
	}
}
void state6(string w, int i){
	cout<<"In state6"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state6(w,i+1);
		else if(w[i]=='b') state7(w,i+1);
	}
}
void state7(string w, int i){
	cout<<"In state7"<<endl;
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state6(w,i+1);
		else if(w[i]=='b') state5(w,i+1);
	}
}
void state8(string w, int i){
	cout<<"In state8"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state12(w,i+1);
		else if(w[i]=='b') state9(w,i+1);
	}
}
void state9(string w, int i){
	cout<<"In state9"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state9(w,i+1);
		else if(w[i]=='b') state10(w,i+1);
	}
}
void state10(string w, int i){
	cout<<"In state10"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state9(w,i+1);
		else if(w[i]=='b') state11(w,i+1);
	}
}
void state11(string w, int i){
	cout<<"In state11"<<endl;
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state9(w,i+1);
		else if(w[i]=='b') state11(w,i+1);
	}
}
void state12(string w, int i){
	cout<<"In state12"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state12(w,i+1);
		else if(w[i]=='b') state13(w,i+1);
	}
}
void state13(string w, int i){
	cout<<"In state13"<<endl;
	if(i==w.length()){
		cout<<"String Rejected"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state14(w,i+1);
		else if(w[i]=='b') state13(w,i+1);
	}
}
void state14(string w, int i){
	cout<<"In state14"<<endl;
	if(i==w.length()){
		cout<<"String Accepted"<<endl;
		return;
	}
	else{
		if(w[i]=='a') state12(w,i+1);
		else if(w[i]=='b') state13(w,i+1);
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
			if(w.length()<4)flag=0;
		}
	}while(flag==0);
	state0(w,0);
}
