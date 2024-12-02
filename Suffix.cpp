#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    vector<char> chars;
    vector<Node*> children;

    Node* getchild(char c) {
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == c) return children[i];
        }
        return nullptr;
    }

    void addchild(char c, Node* node) {
        chars.push_back(c);
        children.push_back(node);
    }
};

class Trie {
public:
    Node* root;

    Trie(string text) {
        root = new Node();
        buildtree(text);
    }

    ~Trie() {
        delnode(root);
    }

    void print() {
        print(root);
    }

private:
    void buildtree(string text) {
        int n = text.size();
        for (int i = 0; i < n; i++) {  // Start at all indices (including 0)
            Node* node = root;
            int j = i;

            // Traverse existing tree as far as possible
            while (j < n) {
                Node* child = node->getchild(text[j]);
                if (child == nullptr) break;  // No match, stop traversing
                node = child;
                j++;
            }

            // Add remaining characters as new nodes
            for (int k = j; k < n; k++) {
                Node* newnode = new Node();
                node->addchild(text[k], newnode);
                node = newnode;
            }
        }
    }

    void delnode(Node* x) {
        for (int i = 0; i < x->children.size(); i++) {
            delnode(x->children[i]);
        }
        delete x;
    }

    void print(Node* node, string temp = "") {
        if (node->chars.empty()) {  // Leaf node
            if (!temp.empty()) cout << temp << endl;
        }
        for (int i = 0; i < node->chars.size(); i++) {
            print(node->children[i], temp + node->chars[i]);
        }
    }
};

int main() {
    string text = "caracas";
    Trie obj(text);
    cout << "The Suffix Tree is: " << endl;
    obj.print();
    return 0;
}
