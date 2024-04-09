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

        //Inserting a node at the start of the DLL
        void prepend(int value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        //Deleting the first node in the DLL
        void deleteFirst() {
            if (head == nullptr) return;
            Node* temp = head;
            if (head->next == nullptr) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        //Get index of node in LL
        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node* temp = head;
            if (index < length/2){          //In the first half we use temp->next
                for(int i = 0; i < index; i++){
                temp = temp->next;
                }
            }else{                          //In the second half we use temp->prev
                temp = tail;
                for(int i = length - 1; i > index; i--){
                    temp = temp->prev;
                }
            }
            return temp;
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

    cout << "After Prepend: ";
    myDLL->prepend(21);
    myDLL->prepend(78);
    myDLL->printList();

    cout << "After Delete First: ";
    myDLL->deleteFirst();
    myDLL->printList();

    cout << "Get(first half of DLL): " << myDLL->get(1)->value << endl;
    cout << "Get(second half of DLL): " << myDLL->get(3)->value << endl;


    return 0;
}