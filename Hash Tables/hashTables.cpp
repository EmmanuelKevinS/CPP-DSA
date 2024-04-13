#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable{
    private:
        //If you have a prime number of addresses, your key-value pair will be distributed more randomly leading to fewer collisions 
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        //Function that returns an interger in which the key-value pair will be stored in the hash table
        int hash(string key){
            int hash = 0;
            for(int i = 0; i < key.length(); i++){
                int asciiValue = int (key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

        void printTable(){
            for(int i = 0; i < SIZE; i++){
                cout << i << ":" << endl;
                if(dataMap[i]){
                    Node* temp = dataMap[i];
                    while(temp){
                        cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
};

int main(){

    HashTable* myHashTable = new HashTable();
    
    myHashTable->printTable();

    return 0;
}