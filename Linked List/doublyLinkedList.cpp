#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int value){
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        //Adding a node to the end of the DLL
        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
                length++;
            }else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        //Deleting the last node of the DLL
        void deleteLast(){
            if(head == nullptr) return;
            Node* temp = tail;
            if(head->next == nullptr){
                head = nullptr;
                tail = nullptr;
            }else{
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        //Output
        void printList(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->value<<" -> " << "";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        ~DoublyLinkedList(){
            Node* temp = head;
            while(head != NULL){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
};

int main(){
    
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->append(4);
    myDLL->append(2);
    myDLL->append(56);
    myDLL->append(78);
    cout << "Full DLL: ";
    myDLL->printList();
    cout << "After Delete Last: ";
    myDLL->deleteLast();
    myDLL->printList();

    return 0;
}