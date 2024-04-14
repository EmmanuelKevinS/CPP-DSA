#include<iostream>
#include<string>
#include<vector>
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
        //To determine the Hash value of a string
        int hash(string key){
            int hash = 0;
            for(int i = 0; i < key.length(); i++){
                int asciiValue = int (key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

        // A function that sets the key value pair to the hash table
        void set(string key, int value){
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if(dataMap[index] == nullptr){
                dataMap[index] = newNode;
            }else{
                Node* temp = dataMap[index];
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        //Get the value of an item in the hash table
        int get(string key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while(temp != nullptr){
                if(temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }

        //Returns all keys
        vector<string> keys(){
            vector<string> allKeys;
            for(int i = 0; i < SIZE; i++){
                Node* temp = dataMap[i];
                while(temp != nullptr){
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
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
                cout << "" << endl;
            }
        }
};

int main(){

    HashTable* myHashTable = new HashTable();
    
    myHashTable->set("Transformers", 100);
    myHashTable->set("Pandas", 21);
    myHashTable->set("Phones", 13);
    myHashTable->set("Magnets", 18);
    myHashTable->set("Burgers", 3);
    myHashTable->set("Cups", 123);
    myHashTable->set("Tables", 19);
    myHashTable->set("Footballs", 90);
    myHashTable->set("Shirts", 10);
    myHashTable->printTable();

    cout << "Testing out 'get' function:" << endl;
    cout << myHashTable->get("Shirts") << endl; 
    cout << myHashTable->get("Magnets") << endl;

    cout << "Testing out 'keys' function:" << endl;
    vector<string> myKeys = myHashTable->keys();
    for(auto& key: myKeys){
        cout << key << " ";
    }




    return 0;
}