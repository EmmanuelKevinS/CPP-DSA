#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

    Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;
    
    // Corrected constructor declaration
    BST(){
        root = nullptr;
    } 

    // Inserting a new node into the tree
    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) return false;
            if (newNode->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    //To check whether the tree contains the value
    bool contains(int value){
        if(root == nullptr){
            return false;
        }
        Node* temp = root;
        while(temp != nullptr){
            if(value < temp->value){
                 temp = temp->left;
            }else if(value > temp->value){
                 temp = temp->right;
            }else{
                return true;
            }
        }
        return false;
    }
};

void print(bool found, int value) {
    if (found) {
        cout << "The tree contains the value " << value << "." << endl;
    } else {
        cout << "The tree does not contain the value " << value << "." << endl;
    }
}


int main(){

    BST* myBST = new BST();
    
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    //Just checking to see ift his gives me 27
    myBST->insert(27);
    cout << "Testing insert function: " << myBST->root->left->right->value << endl;

    int valueToCheck1 = 18;
    int valueToCheck2 = 19;
    int valueToCheck3 = 27;

    bool containsValue1 = myBST->contains(valueToCheck1);
    bool containsValue2 = myBST->contains(valueToCheck2);
    bool containsValue3 = myBST->contains(valueToCheck3);

    print(containsValue1, valueToCheck1);
    print(containsValue2, valueToCheck2);
    print(containsValue3, valueToCheck3);

    return 0;
}