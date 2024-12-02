# include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


class Node{
	private:
		int *key;
		Node **children;
		int count;
		bool leaf;
		
	public:
		Node(int order, bool isleaf);	// Constructor.
		~Node();						// Destructor.
		
		friend class BTree;
};

// Constructor.
Node::Node(int order, bool isleaf) : count(0), leaf(isleaf)	// ' : ' is a faster and prefered way to initialize static data members.
{
	this->key = new int[order];
	this->children = new Node *[order+1];
	
	for(int i = 0; i < order+1; i++)
	{
		children[i] = NULL;
	}
}

// Destructor.
Node::~Node()
{
	delete[] key; // Delete The Node's key.
	
	if(!leaf)
	{
		for(int i = 0; i <= count; i++)
			delete children[i];
	}
	
	delete[] children;	// Delete The Node's children array after all the children's kill button is activated.
}


class BTree{
	private:
		Node *Root;
		int order;
		int half;
		
		void SplitRoot();
		void SplitChild(Node *Parent, const int ChildIndex);
		void DeleteLeaf(Node *X, const int DeleteIndex);
		void DeleteNonLeaf(Node *Parent, Node *X, const int DeleteIndex, char Side);
		void Repair(Node *X, const int Index);
		
		void InsertNonFull(Node *X, const int KeyValue);
		void TraverseRecursion(Node *X, int lev);
		void SearchRecursion(Node *X, const int SearchValue);
		void DeleteRecursion(Node *X, const int DeleteValue);
		void PrintRecursion(Node *Queue[], int Depth, int Size);
		
	public:
		BTree(int order);
		~BTree();
		
		void Insert(const int KeyValue);
		void Delete(const int DeleteValue);
		void Traverse();
		void Search(const int SearchValue);
		void Print();
};

// Constructor.
BTree::BTree(int order)
{
	this->order = order;
	this->Root = NULL;
	this->half = (order-1)/2;
}

// Destructor.
BTree::~BTree()
{
	delete Root;
}

/*
	> Insertion Related Functions.
*/
void BTree::SplitRoot()
{
	Node *NewRoot = new Node(order, false);
	
	NewRoot->children[0] = this->Root;
	
	Root = NewRoot;
	
	SplitChild(Root, 0);
}

//

void BTree::SplitChild(Node *Parent, int ChildIndex)
{
	Node *Child_1 = Parent->children[ChildIndex];
	Node *Child_2 = new Node(order, Child_1->leaf);
	
	int half = order - (order-1)/2 - 1;
	
	Child_2->count = half;
	
	for(int i = 0; i < half; i++)
		Child_2->key[i] = Child_1->key[(order-1)/2 + i + 1];
	

	if(!Child_1->leaf)
	{
		for(int i = 0; i < half+1; i++)
			Child_2->children[i] = Child_1->children[(order-1)/2 + i + 1];
	}
	
	Child_1->count = (order-1)/2;
	
	for(int i = Parent->count; i > ChildIndex; i--)
		Parent->children[i+1] = Parent->children[i];
	
	
	Parent->children[ChildIndex+1] = Child_2;
	
	
	for(int i = Parent->count-1; i > ChildIndex-1; i--)
			Parent->key[i+1] = Parent->key[i];
	
	
	Parent->key[ChildIndex] = Child_1->key[(order-1)/2];
	
	Parent->count += 1;
}

//

void BTree::InsertNonFull(Node *X, const int KeyValue)
{
	int i = X->count;
	if(X->leaf)
	{
		while(i >= 1 and KeyValue < X->key[i-1])
		{
			X->key[i] = X->key[i-1];
			i--;
		}
		
		X->key[i] = KeyValue;
		X->count += 1;
		
		cout << "Value [" << KeyValue << "] Inserted Successfully!" << endl;
	}
	else
	{
		while(i >= 1 and KeyValue < X->key[i-1])
			i--;
			
		InsertNonFull(X->children[i], KeyValue);

		if(X->children[i]->count == order)
			SplitChild(X, i);
	}
}

//

void BTree::Insert(const int KeyValue)
{
	if(Root == NULL)
	{
		Root = new Node(order, true);
		InsertNonFull(Root, KeyValue);
	}
	else
		InsertNonFull(Root, KeyValue);
		
	if(Root->count == order)
		SplitRoot();
}

/*
	> Traverse Related Functions.
*/
void BTree::TraverseRecursion(Node *X, int lev)
{
	int i;
	int level = lev;
	
	for(i = 0; i < X->count; i++)
	{
		if(X->leaf == false and X->children[i] != NULL)
			TraverseRecursion(X->children[i], level+1);
			
		cout << X->key[i] << " (" << level <<")" << ", ";
	}
	
	if(X->leaf == false)
		TraverseRecursion(X->children[i], level+1);
}

//

void BTree::Traverse()
{
	if(Root != NULL)
		TraverseRecursion(Root, 0);
}

/*
	> Search Related Functions.
*/
void BTree::SearchRecursion(Node *X, const int SearchValue)
{
	int i = X->count;
	while(i >= 1 and SearchValue < X->key[i-1])
		i--;
	
	if(SearchValue == X->key[i-1])
		cout << "Value [" << SearchValue << "] Exist in B-Tree!!" << endl;
	else if(!X->leaf)
		SearchRecursion(X->children[i], SearchValue);
	else
		cout << "Value [" << SearchValue << "] Doesn't Exist in B-Tree." << endl;
}

//

void BTree::Search(const int SearchValue)
{
	if(Root == NULL)
		cout << "B-Tree Is Empty!!" << endl;
	else
		SearchRecursion(Root, SearchValue);
}


/*
	> Deletion Related Functions.
*/
void BTree::DeleteLeaf(Node *X, const int DeleteIndex)
{
	cout << "Value [" << X->key[DeleteIndex] << "] Deleted." << endl;
	
	for(int i = DeleteIndex; i < X->count-1; i++)
		X->key[i] = X->key[i+1];
		
	X->count--;
}

//

void BTree::DeleteNonLeaf(Node *Parent, Node *X, const int DeleteIndex, char Side = 'M')
{
	if(Side == 'L')
	{
		if(X->leaf)
		{
			cout << "Value [" << Parent->key[DeleteIndex] << "] Deleted." << endl;
			
			Parent->key[DeleteIndex] = X->key[X->count-1];
			X->count--;
			
		}
		else
		{
			DeleteNonLeaf(Parent, X->children[X->count], DeleteIndex, 'L');
			Repair(X, X->count-1);
		}
	}
	else if(Side == 'R')
	{
		if(X->leaf)
		{
			cout << "Value [" << Parent->key[DeleteIndex] << "] Deleted." << endl;
			
			Parent->key[DeleteIndex] = X->key[0];
	
			for(int i = 0; i < X->count-1; i++)
				X->key[i] = X->key[i+1];
				
			X->count--;
		}
		else
		{
			DeleteNonLeaf(Parent, X->children[0], DeleteIndex);
			Repair(X, 0);
		}
	}
	else
	{
		if(Parent->children[DeleteIndex]->count >= (order-1)/2)
			DeleteNonLeaf(Parent, X->children[DeleteIndex], DeleteIndex, 'L');
		
		else if(Parent->children[DeleteIndex+1]->count >= (order-1)/2)
			DeleteNonLeaf(Parent, X->children[DeleteIndex+1], DeleteIndex, 'R');
	}
}

//

void BTree::Repair(Node *X, const int Index)
{
	Node *Left_Child = X->children[Index];
	Node *Right_Child = X->children[Index+1];

	int Left_Count = Left_Child->count;
	int Right_Count = Right_Child->count;
	
// If Left_Child has less than (order-1)/2 (Minimum Limit) Element but Right_Child Has Then.

	if(Left_Count < (order-1)/2 and Right_Count > (order-1)/2)
	{
		Left_Child->key[Left_Count-1] = X->key[Index];
		Left_Child->count++;
		
		X->key[Index] = Right_Child->key[0];
		
		for(int i = 0; i < Right_Count-1; i++)
			Right_Child->key[i] = Right_Child->key[i+1];
			
		Right_Child->count--;
	}

// If Right_Child has less than (order-1)/2 (Minimum Limit) Element but Left_Child Has Then.

	else if(Right_Count < (order-1)/2 and Left_Count > (order-1)/2)
	{
	// Make space for New Element in Right_Child.
	
		int i = Right_Count;
		while(i >= 1)
		{
			X->key[i] = X->key[i-1];
			i--;
		}
		
	// Shift Key in Right_Child and Increase Count.
	
		Right_Child->key[0] = X->key[Index];
		Right_Child->count++;
		
	// Take a key from Left_Child and Give it to parent then Decrease the Count of Left_Child.
	
		X->key[Index] = Left_Child->key[Left_Count - 1];
		Left_Child->count--;
	}

// If Both Left_Child And Right_Child don't have (order-1)/2 (Minimum Limit) Elements Then.

	else if(Left_Count <= (order-1)/2 and Right_Count <= (order-1)/2)
	{	
	// Take the Parent Key Element and add it to the Left_Child.
	
		Left_Child->key[Left_Count] = X->key[Index];
		
	// Increase The Count of Left_Child and Decrease the Count of Parent (X).
	
		Left_Child->count++;
		X->count--;
		
	// Shift all the Elements of Right_Child in Left_Child.
	
		for(int i = 0; i < Right_Count; i++)
			Left_Child->key[Left_Child->count + i] = Right_Child->key[i];
		
	// If The Childs are not Leaf, Shift Right_Child's Children to Left_Child.
	
		if(!Left_Child->leaf)
		{
			for(int i = 0; i <= Right_Count; i++)
				Left_Child->children[Left_Child->count + i] = Right_Child->children[i];
		}
		
	// Add RIght_Child's Count to Left_Child's Count.
	
		Left_Child->count = Left_Child->count + Right_Child->count;
		
	// Set The 0 Index children to NULL so The Destructor Doesn't Delete it, then Delete the Right_Child.
	
		Right_Child->children[0] = NULL;
		delete Right_Child;
	}
}

//

void BTree::DeleteRecursion(Node *X, const int DeleteValue)
{
	int i = X->count-1;
	if(X->leaf)
	{
		while(i >= 1 and DeleteValue < X->key[i])
			i--;
		
		if(X->key[i] == DeleteValue)
			DeleteLeaf(X, i);
		else
			cout << "Element [" << DeleteValue << "] Doesn't Exist!!" << endl;
	}
	else
	{
		while(i >= 1 and DeleteValue < X->key[i])
			i--;
			
		if(X->key[i] == DeleteValue)
			DeleteNonLeaf(X, X, i);
		else
			DeleteRecursion(X->children[i+1], DeleteValue);
		
		Repair(X, i);
	}
}

//

void BTree::Delete(const int DeleteValue)
{
	if(Root == NULL)
		cout << "The B-Tree Is Empty!!" << endl;
	else
		DeleteRecursion(Root, DeleteValue);
		
	if(Root->count == 0)
	{
		Node *Temp = Root;
		Root = Root->children[0];
		Temp->children[0] = NULL;
		delete Temp;
	}
}

/*
	> Beautiful Print.
*/

void BTree::PrintRecursion(Node *Queue[], int Depth, int Size)
{
	string space = "    ";
	
	for(int i = 0; i < Size; i++)
	{
		Node *Temp = Queue[i];
		
		for(int i = 0; i < (order-1)*Depth; i++)
		cout << space;
	
		cout << " [";
		for(int i = 0; i < Temp->count-1; i++)
			cout << Temp->key[i] << ", ";
		cout << Temp->key[Temp->count-1];
		
		for(int i = 0; i < order-Temp->count-1; i++)
			cout << space;
		cout << "]";
		
		for(int i = 0; i < (order-1)*Depth; i++)
			cout << space;
	}
	cout << "\n\n";
/*
																								 [01, 92, 81]
						 
			        [92, 24, 10]										[28, 23, 01]										[73, 12, 42]										[73, 12, 42]					

[92, 24, 12] [28, 23, 01] [73, 12, 42] [92, 24, 12] [28, 23, 01] [73, 12, 42] [92, 24, 12] [28, 23, 01] [73, 12, 42] [28, 23, 01] [73, 12, 42] [92, 24, 12] [73, 12, 42] [28, 23, 01] [73, 12, 42] [92, 24, 12]

			   7
[100, 200, 300]

>	only use " " for spacing cause using groups can be hard to implement.
>	first we will find out the max length of number (100, 10, 1) etc. once that is confirmed we can count the " " taken by one node.
>	[] take 2 - " " | ", " takes 2*(order-2) - " " | now the length the numbers gonna take first we get the key size that is count-1, now how many characters per
	number = max length of number + 1 , Total spaces needed is (count-1) * (max length of number +1) - " ".
>	Keep the sum of them all in a variable called Node size,

*/	
	
	if(!Queue[0]->leaf)
	{
		int NewSize = 0;
		Node *NewQueue[100];
		
		for(int x = 0; x < Size; x++)
		{
			Node *Temp = Queue[x];
			
			for(int j = 0; j <= Temp->count; j++)
			{
				NewQueue[NewSize] = Temp->children[j];
				NewSize++;	
			}
		}
		
		PrintRecursion(NewQueue, Depth-1, NewSize);
	}
}

void BTree::Print()
{
	int depth = 0;
	
	Node *Temp = Root;
	
	while(!Temp->leaf)
	{
		Temp = Temp->children[Temp->count];
		depth++;
	}
	int largest = Temp->key[Temp->count-1];
	
	Temp = Root;
	
	Node *Queue[] = {Temp};
	int size = 1;
	
	PrintRecursion(Queue, depth, size, largest);
}






int main()
{
	int order;
	cout << "Order of B-Tree : ";
	cin >> order;
	
	BTree Obj(order);
	
	Obj.Insert(12);
	Obj.Insert(87);
	Obj.Insert(45);
	Obj.Insert(23);
	Obj.Insert(64);
	Obj.Insert(91);
	Obj.Insert(33);
	Obj.Insert(78);
	Obj.Insert(5);
	Obj.Insert(56);
	Obj.Insert(29);
	Obj.Insert(41);
	Obj.Insert(82);
	Obj.Insert(14);
	Obj.Insert(63);
	Obj.Insert(38);
	Obj.Insert(70);
	Obj.Insert(95);
	Obj.Insert(18);
	Obj.Insert(49);
	Obj.Print();
	std::string condition = "y";
	
	while(condition == "y" or condition == "Y" or condition == "yes" or condition == "YES")
	{
		int choice;
	
		cout << "--- Menu ---\n" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Print" << endl;
		cout << "\nEnter Choice : ";
		cin >> choice;
		
		int value;
		
		switch(choice)
		{
			case 1:		// Insert
				cout << "\n---------------------------------------------\n" << endl;
				
				cout << "Enter Value: ";
				cin >> value;
				
				Obj.Insert(value);
				
				break;
				
			case 2:		// Search
				cout << "\n---------------------------------------------\n" << endl;
				
				cout << "Enter Value: ";
				cin >> value;
				
				Obj.Search(value);
				break;
				
			case 3:		// Delete
				cout << "\n---------------------------------------------\n" << endl;
				
				cout << "Enter Value: ";
				cin >> value;
				
				Obj.Delete(value);
								
				break;
				
			case 4:		// Print	
				cout << "\n---------------------------------------------\n" << endl;
				
				Obj.Traverse();	
				cout << endl;		
				break;		
		}
		
		cout << "\n---------------------------------------------\n" << endl;
		
		cout << "Want to Continue? \n> ";
		cin >> condition;
		
		cout << "\n---------------------------------------------\n" << endl;
	}
	
	return 0;
}
