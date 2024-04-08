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

        //Inserting a node at the beginning of the Linked List
        void prepend(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        //Deleting the First Node of the Linked List
        void deleteFirst(){
            Node* temp = head;
            if (length == 0){
                return;
            }else if(length == 1){
                head = NULL;
                tail = NULL;
            }else{
                head = head->next;
            }
            delete temp;
            length--;
        }

        //Getting the value of the Node at index of choice
        Node* get(int index){
            if(index < 0 || index >= length){
                return nullptr;
            }
            Node* temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp;
        }

        //Setting a value to an already existing node
        bool set(int index, int value){
            Node* temp = get(index);
            if(temp != nullptr){
                temp->value = value;
                return true;
            }
            return false;
        }

        //Inserting a node into a particular index
        bool insertNode(int index, int value){
            Node* newNode = new Node(value);
            if(index < 0 || index > length){
                return false;
            }
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
            temp->next = newNode;
            length++;
            return true;
        }

        //Deleting a Node at a particular index
        void deleteNode(int index) {
        if (index < 0 || index >= length) return;

        if (index == 0) {
            return deleteFirst();
        }

        if (index == length - 1) {
            return deleteLast();
        }

        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
        }   

        //Reversing the Linked List
        void reverse(){
            if(head == nullptr) return;
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* before = nullptr;
            Node* after = temp->next;
            for(int i = 0; i < length; i++){
                after = temp->next;
                temp->next = before; //breaking the LL at this step
                before = temp;
                temp = after;
            };
            
            
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

    myLinkedList->prepend(2);
    myLinkedList->prepend(5);
    myLinkedList->printList();

    myLinkedList->deleteFirst();
    myLinkedList->printList();

    cout << myLinkedList->get(2)->value << endl;

    myLinkedList->set(1,10);
    myLinkedList->printList();

    myLinkedList->insertNode(2,25);
    cout << "After inserting new Node: ";
    myLinkedList->printList();

    cout << "After deleting Node once: ";
    myLinkedList->deleteNode(3);
    myLinkedList->printList();
    cout << "After deleting Node twice: ";
    myLinkedList->deleteNode(1);
    myLinkedList->printList();

    cout << "Reverse Linked List: ";
    myLinkedList->reverse();
    myLinkedList->printList();

    delete myLinkedList;
    return 0;
}