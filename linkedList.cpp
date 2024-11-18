#include <iostream> 
#include <cassert>

using namespace std;


class LinkedList
{
    private:
        struct Node
        {
            string data;
            Node* next;
        };
        Node* first;
    public:
        LinkedList()
            :first(nullptr){}
        ~LinkedList(){ //since we have the destructor, we need the big three in the Linked List
            clear();
        }
        LinkedList(const LinkedList& other){
            LinkedList();
            copy(other);
        }
        LinkedList& operator=(const LinkedList& rhs){
            if (this == &rhs) return *this;
            clear();
            copy(rhs);
        }
        //clears ALL elements of the linked list 
        void clear(){
            while(!empty()){
                pop(); //much easier 
            }
        }
        //require empty
        //we assign everybody to 
        void copy(const LinkedList& src){
            assert(empty());
            Node* last=nullptr;
            for(Node* p=src.first; p!=nullptr; p=p->next){
                Node* q = new Node;
                q->data = p->data;
                q->next = nullptr;
                if(last==nullptr){
                    first = last = q;
                } else{
                    last->next = q;
                    last = q;
                }
            }
        }
        //this will be LinkedList::Iterator, always like this the iterator type,
        //because the Linked List uses the begin() and end(), which require access to the 
        //Iterator's inner stuff. 
        class Iterator{ //we put it inside here to give it access to the private stuff
        private:
            friend class LinkedList;
            //private constructor, since Node itself is private. 
            //The only one using this is the List
            Iterator(Node* np)
                :node_ptr(np){}
            
            Node* node_ptr;
        public:
            Iterator()
                : node_ptr(nullptr) {}
            
            string& operator*() const{
                assert(node_ptr);
                return node_ptr->data;
            }

            Iterator& operator++(){
                assert(node_ptr);
                node_ptr = node_ptr->next;
                return *this;
            }

            bool operator==(const Iterator& rhs) const{
                return node_ptr == rhs.node_ptr;
            }
        };

        Iterator begin() { return Iterator(first); }
        Iterator end() { return Iterator(); }

        bool empty() const { return !first; } //could do first == nullptr
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
            assert(!empty());
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

