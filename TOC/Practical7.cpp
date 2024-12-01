#include<iostream>
#include<string>
#include<stack>
using namespace std;
void state1(stack<char>s,string w,int i);
void state2(stack<char>s,string w,int i);
void state3(stack<char>s,string w,int i);
void state4(stack<char>s,string w,int i);

void state4(stack<char>s,string w,int i){
	cout<<"string accepted";
}
void state3(stack<char>s,string w,int i){
	cout<<"String rejected\n";
	return;
}
void state2(stack<char>s,string w,int i){
	cout<<"IN State 2\n";
	if(w.length()==i){
		if(s.top()=='z')
			state4(s,w,i);
		else
			state3(s,w,i);
	}
	else{
		if(w[i]=='a'){
			state3(s,w,i);
		}
		else if(w[i]=='b'){
			if(s.top()!='z'){
				s.pop();
				i++;
				state2(s,w,i);
			}
			else{
				state3(s,w,i);
			}			
		}
	}
}
void state1(stack<char>s,string w,int i){
	cout<<"IN State 1\n";
	if(w.length()==i){
		cout<<"Rejected string";
		return;
	}
	else{
		if(w[i]=='a'){
			s.push('a');
			i++;
			state1(s,w,i);
		}
		else if(w[i]=='b'){
			if(s.top()!='z'){
				s.pop();
				i++;
				state2(s,w,i);
			}
			else{
				state3(s,w,i);
			}
		}
	}
}
int main(){
	string w;
	stack<char>s;
	s.push('z');
	cout<<"Enter string=";
	cin>>w;
	state1(s,w,0);
}

