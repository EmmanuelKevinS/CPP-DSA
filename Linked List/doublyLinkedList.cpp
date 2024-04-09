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

        //Setting a value to an already existing node
        bool set(int index, int value){
            Node* temp = get(index);
            if(temp != nullptr){
                temp-> value = value;
                return true;
            }
            return false;
        }

        //Inserting a node at an index of my choice in the DLL
        bool insertNode(int index, int value){
            Node* newNode = new Node(value);
            if(index < 0 || index > length) return false;
            if(index == 0){
                prepend(value);
                return true;
            }
            if(index == length){
                append(value);
                return true;
            }
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
            length++;
            return true;
        }

        //Deleting a node from the DLL
        void deleteNode(int index){
            if(index < 0 || index >= length) return;
            if(index == 0){
                return deleteFirst();
            }
            if(index == length-1){
                return deleteLast();
            }
            Node* temp = get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
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

    cout << "After Prepend: ";
    myDLL->prepend(21);
    myDLL->prepend(78);
    myDLL->printList();

    cout << "After Delete First: ";
    myDLL->deleteFirst();
    myDLL->printList();

    cout << "Get(first half of DLL): " << myDLL->get(1)->value << endl;
    cout << "Get(second half of DLL): " << myDLL->get(3)->value << endl;

    cout << "Set: ";
    myDLL->set(1, 200);
    myDLL->printList();

    cout << "Inserting Node: ";
    myDLL->insertNode(4,780);
    myDLL->insertNode(2,1000);
    myDLL->printList();

    cout << "After deleting Node: ";
    myDLL->deleteNode(3);
    myDLL->deleteNode(0);
    myDLL->deleteNode(4);
    myDLL->printList();


    return 0;
}