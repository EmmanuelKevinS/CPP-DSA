#include<iostream>
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

class Queue{
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }
        
        //Adding a Node to the Queue
        void enqueue(int value){
            Node* newNode = new Node(value);
            if(first == nullptr){   
                first = newNode;
                last = newNode;
            }else{
                //The earlier Node points to the newer Node that joins the queue
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        //Removing the first Node from the queue
        int dequeue(){
            if(first == nullptr) return INT_MIN;
            Node* temp = first;
            int dequeuedValue = temp->value;
            if(length == 1){
                first = nullptr;
                last = nullptr;
            }
            else{
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }

        void printQueue(){
            Node* temp = first;
            while (temp != nullptr){
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main(){

    Queue* myQueue = new Queue(3);
    myQueue->enqueue(41);
    myQueue->enqueue(543);
    myQueue->enqueue(92);
    myQueue->enqueue(45);
    myQueue->enqueue(411);
    myQueue->enqueue(78);
    myQueue->enqueue(32);
    myQueue->enqueue(112);
    myQueue->enqueue(141);
    myQueue->printQueue();

    cout << myQueue->dequeue() << endl;
    cout << myQueue->dequeue() << endl;
    cout << myQueue->dequeue() << endl;
    myQueue->printQueue();

    return 0;
}