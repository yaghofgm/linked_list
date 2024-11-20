#include <cassert>
struct Node
{
    int data;
    Node* next;
};
class LinkedList 
{
    private:
        Node* first;
        int length;
    public:
        LinkedList():first(nullptr),length(0){}
        
};
// gives the size of the list.
// basically a clicker counting the elements until the end
int getListSize(Node *n, int size = 0)
{ // no need for reference as we are not modifying the original node
    // we know that if n is nullptr, we have reached the end of the list
    if (n == nullptr) return size;
    return getListSize(n->next, size + 1); // tail recursive: optimizes memory usage by reusing stack frames
}
// Returns the maximum value in the linked list.
// Precondition: the list is not empty.
int max(Node* n)
{
    assert(n && "Attempted to find max in an empty list");
    if (!n->next) return n->data;
    int m = max(n->next);
    return (m > n->data) ? m : n->data;
}
//let us do binary search on the sorted linked list
//requires list is ordered


//binary search in a linked list is not ideal because the movement is On already
//there is no random access in linked list, but there is on BST
