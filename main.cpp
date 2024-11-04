#include <iostream> 
#include <cassert>

using namespace std;

struct Node
{
    string data;
    Node* next;
};

class LinkedList
{
    private:
        Node* first;
    public:
        LinkedList()
            :first(nullptr){}
        ~LinkedList(){ //since we have the destructor, we need the big three in the Linked List
            for (Node* i=first; i!=nullptr; i=i->next){
                delete i;
            }
        }
        LinkedList(const LinkedList& other){
            first = other.first;
        }
        LinkedList& 
        bool empty() const {return !first;} //could do first == nullptr
        //R: list not empty
        //Eff: returns a reference to the item at the front of the list
        string& peek() const{
            assert(!empty());
            return first->data;
        }
        //R: nothing
        //Eff:inserts node on the front of the list with data_in
        void push(const string& data_in){
            Node *n = new Node(); 
            n->data = data_in;
            // empty()? n->next = nullptr : n->next = first; 
            n->next = first; //by our implementation, linked list is initialized as nullptr
            first = n;
        }
        //R: list not empty
        //Eff: removes and returns the item at the front of the list
        string pop(){
            string removed_string = first->data;
            Node* temp = first->next;
            delete first;
            first = temp;
            return removed_string;
        }
        //R: list not empty
        //Eff: inserts data t the nth location. (0 = start). 
        //      Ignores if n>= elements in list 
        void insert(const string& data_in, int n){
            //make the n-1 th point to it, and make it point to n+1;
            for (Node* i=first; i!=nullptr; i=i->next){

            }
        }
};