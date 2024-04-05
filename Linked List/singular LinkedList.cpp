#include<iostream>
using namespace std;
//creating as class for node
class Node{
    public:
        int value;
        Node* next;
        //Constructor
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};
class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        void printList(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
        void getHead(){
            cout << "Head:" << head->value << endl;
        }
        void getTail(){
            cout << "Tail:" << tail->value << endl;
        }
        void getLength(){
            cout << "Length:" << length << endl;
        }
        ~LinkedList(){
            Node* temp = head;
            while(head != NULL){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
};
int main(){
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();
    delete myLinkedList;
    return 0;
}