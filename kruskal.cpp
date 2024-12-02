#include<iostream>
#include<vector>
using namespace std;

class Node{
	char u;
	char v;
	int w;
	public:
		Node(char a, char b, int n){
			u=a;
			v=b;
			w=n;
		}
		void print(){
			cout<<u<<"->"<<v<<"="<<w<<endl;
		}
		int weight()const{
			return w;
		}
		char start()const{
			return u;
		}
		char end()const{
			return v;
		}
};
class Graph{
	vector<Node*> G; //graph
	vector<Node*> T; //MST
	vector<char> var;
	int* parent;
	int* size;
	public:
		bool search(char a, char b){
			for(int i=0;i<G.size();i++){
				if(G[i]->start()==a and G[i]->end()==b) return 1;
				else if (G[i]->start()==b and G[i]->end()==a) return 1;
			}
			return 0;
		}
		int index(char a){
			for(int i = 0; i< G.size(); i++){
				if(a == var[i]) return i;
			}
			return -1;
		}
		Graph(int n){
			char variable;
			for(int i=0; i<n; i++){
				cout<<"Insert Var Symbol "<<i+1<<"th: ";
				cin>>variable;
				var.push_back(variable);
			}
			int weight;
			for (int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(!search(var[i],var[j]) and var[i]!=var[j]){
						cout<<"Enter edge weight of "<<var[i]<<" and "<<var[j]<<": ";
						cin>>weight;
						Node* temp=new Node(var[i],var[j],weight);
						G.push_back(temp);
					}
				}
			}
			this->bubbleSort();  // increasing weight
			for (int i = 0; i < G.size(); i++){
				if(G[i]->weight()>0){
					G.erase(G.begin(),G.begin()+i);
					break;
				}
			}
			parent = new int[G.size()];
			size = new int[G.size()];
  			//i 0 1 2 3 4 5
  			//parent[i] 0 1 2 3 4 5
  			for (int i = 0; i < G.size(); i++){
    			parent[i] = i;
    			size[i]=0;
    		}
		}
		void bubbleSort() {
    		int n = G.size();
    		for (int i = 0; i < n - 1; ++i) {
        		for (int j = 0; j < n - i - 1; ++j) {
            		if (G[j]->weight() > G[j + 1]->weight()) {
                		swap(G[j], G[j + 1]);
            		}
        		}
    		}
		}
		int find_set(int i) {
  			if (i == parent[i])
    			return i;
  			else
    			find_set(parent[i]);
		}
		void union_set(int u, int v) {
  			u = find_set(u);
    		v = find_set(v);

    		if (size[u] < size[v]){
        		parent[u] = v;
    		} 
    		else if (size[v] < size[u]){
        		parent[v] = u;
    		} 
    		else{
        		parent[v] = u;
        		size[u]++;
    		}
		}
		void kruskal() {
  			int i;
			int uRep, vRep;
  			this->bubbleSort();  // increasing weight
  			for (i = 0; i < G.size(); i++) {
    			uRep = find_set(index(G[i]->start()));
    			vRep = find_set(index(G[i]->end()));
    			if (uRep != vRep) {
      				T.push_back(G[i]);  // add to tree
      				union_set(uRep, vRep);
    			}
  			}
		}
		void print(){
			for(int i=0;i<G.size();i++){
				G[i]->print();
			}
		}
		void printMST(){
			for(int i=0;i<T.size();i++){
				T[i]->print();
			}
		}
};
int main(){
	int n;
	cout<<"Enter number of nodes: ";
	cin>>n;
	Graph G(n);
	cout<<"The Tree is: \n";
	G.print();
	G.kruskal();
	cout<<"\nThe MST is: \n";
	G.printMST();
	
}

