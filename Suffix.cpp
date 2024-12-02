#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node{
	public:
	vector<char> chars;
	vector<Node*> children;
	
	Node* getchild(char c){
		for(int i=0;i<chars.size();i++){
			if(chars[i]==c) return children[i];
		}
		return NULL;
	}
	void addchild(char c, Node* node){
		chars.push_back(c);
		children.push_back(node);
	}
};
class Trie{
	public:
		Node* root;
		Trie(string text){
			root= new Node();
			buildtree(text);
		}
		~Trie(){
			delnode(root);
		}
		void print(){
			print(root);
		}
	private:
		void buildtree(string text){
			int n=text.size();
			for(int i=n-1;i>0;i--){
				Node* node=root;
				int j=i;  //adding i to n, searching if some are already in the tree or not
				//iterate the node until matchs found
				while(j<n){
					//search for the char
					Node* child= node->getchild(text[j]);
					if(child==NULL) break; //not found, that is add the remaining
					node=child;
					j++;
				}
				//add the leftover
				for(int k=j;k<n;k++){  //leftover is added recursively
					Node* newnode=new Node();
					node->addchild(text[k],newnode);
					node=newnode;
				}
			}
		}
		void delnode(Node* x){
			for(int i=0;i<x->children.size();i++){
				delnode(x->children[i]);
			}
			delete x;
		}
		void print(Node* node, string temp=""){
			if(node->chars.size()==0){
				cout<<temp<<endl;
			}
			for(int i=0;i<node->chars.size();i++){
				print(node->children[i],temp+node->chars[i]);
			}whatsapp
};
int main(){
	string text="caracas";
	Trie obj(text);
	cout<<"The Suffix Tree is: "<<endl;
	obj.print();
	return 0;
}
