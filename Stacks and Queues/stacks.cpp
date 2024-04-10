#include <iostream>
using namespace std;

class Node{ 
    public:
        Node* next;
        int value;
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Stack{
    private:
        Node* top;
        int height;

    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        //Push(similar to prepend function in LL)
        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        //Popping a node at the top of the stack
        int pop(){
            if(top == nullptr) return INT_MIN;
            Node* temp = top;
            int poppedValue = temp->value;
            top = top->next;
            delete temp;
            height--;
            return poppedValue;
        }

        void printStack(){
            Node* temp = top;
            while (temp != nullptr){
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main(){

    Stack* myStack = new Stack(10);
    myStack->push(3);
    myStack->push(21);
    myStack->push(2);
    myStack->push(453);
    myStack->push(543);
    myStack->push(9872);
    myStack->push(213);
    cout << "My stack: ";
    myStack->printStack();

    cout << "Popped: " << myStack->pop() << endl;
    cout << "Popped: " << myStack->pop() << endl;
    cout << "Popped: " <<  myStack->pop() << endl;
    cout << "After popping: ";
    myStack->printStack();


    return 0;
}