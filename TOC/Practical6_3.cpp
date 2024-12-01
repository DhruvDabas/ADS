#include <iostream>
#include <string>
using namespace std;

void state1(string w, int i);
void state2(string w,int i);
void state3(string w,int i);
void state4(string w,int i);

void state1(string w , int i){

	if(i==w.length()){
		cout<<"String is not accepted"<<endl;
		return;
	}
	else{
		if (w[i]=='b'){
			state4(w,i+1);
		}
		else if (w[i]=='a'){
			state2(w,i+1);
			}
	}
}
void state2(string w , int i){
	if(i==w.length()){
		cout<<"String is not accepted"<<endl;
		return;
	}
	else {
		if(w[i]=='a'){
			state2(w,i+1);
		}
		else if(w[i]=='b'){
			state3(w,i+1);
		}
	}
}
void state3(string w , int i){
	if(i==w.length()){
		cout<<"String is not accepted"<<endl;
		return;
	}
	else {
		if(w[i]=='a'){
			state2(w,i+1);
		}
		else if(w[i]=='b'){
			state3(w,i+1);
		}
	}
}
void state4(string w , int i){
	if(i==w.length()){
		cout<<"String is accepted"<<endl;
		return;
	}
	else {
		if(w[i]=='a'){
			state4(w,i+1);
		}
		else if(w[i]=='b'){
			state4(w,i+1);
		}
	}
}

int main(){
 string input;
 cout <<"Enter the string"<<endl;
 cin>>input;
 state1(input,0);
 return 0;
}