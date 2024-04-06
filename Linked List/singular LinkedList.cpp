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

        //Inserting a new Node to the end of the Linked List
        void append(int value){
            Node* newNode =  new Node(value);
            
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        //Deleting the last Node from the Linked List
        void deleteLast() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while(temp->next) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;            
        }

        void printList(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->value << " ->" << " ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
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
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(9);
    myLinkedList->printList();

    myLinkedList->deleteLast();
    myLinkedList->printList();

    delete myLinkedList;
    return 0;
}