#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <cstddef>  

class SingleLinkedList {
private:
    class Node {
        // Allows class to access the private members of the `Node` class.
        friend class SingleLinkedList;
        int value;
        Node* next; // Point to the next node in the list
        // Constructor for the Node class.
        // Sets the value and next node pointer.
        Node(int value, Node* next = nullptr) : value(value), next(next) {}
    };

public:
    class iterator {
        // Point to the current node that the iterator is pointing to.
        Node* ptr;

    public:
        // Constructor for the iterator class
        // Sets the current node pointer
        iterator(Node* ptr) : ptr(ptr) {}
        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        // Dereference operator for the iterator class
        // Returns the value of the node that the iterator is pointing to.
        int operator*() {
            return ptr->value;
        }
        // Not-equal-to operator for the iterator class
        // Returns true if the iterator is not pointing to the same node as the other iterator.
        bool operator!=(const iterator& other) {
            return ptr != other.ptr;
        }
    };

    Node* head; // Point to the first node in the list.
    Node* tail; // Point to the last node in the list.
    int num_items;

    SingleLinkedList(); // Default constructor
    ~SingleLinkedList(); // Destructor

    void push_front(int value); // Adds a new node to front
    void push_back(int value); // Adds a new node to back
    void pop_front(); // Removes the first node
    void pop_back(); // Removes the last node
    int front(); // Display the first node
    int back(); // Display the last node
    bool empty(); // Check if the list is empty
    void insert(size_t index, const int& item); // Insert new node to provide index
    bool remove(size_t index); // Remove value from list
    size_t find(const int& item); // Find value from list
    // Returns an iterator that points to the first node in the list.
    iterator begin() { return iterator(head); }
    // Returns an iterator that points to a null pointer
    iterator end() { return iterator(nullptr); }
};

#endif

