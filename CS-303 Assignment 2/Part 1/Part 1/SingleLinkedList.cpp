#include "SingleLinkedList.h"

// Constructor initializes the head and tail pointers to null.
// Sets the number of items in the list to 0.
SingleLinkedList::SingleLinkedList() {
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}


// Destructor iterates through each node in the list starting at the head.
// Deletes the current node.
// Sets the current pointer to the next node.
SingleLinkedList::~SingleLinkedList() {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

// set the next pointer to the current head
// If the list is empty, set both the head and tail pointers to the new node
void SingleLinkedList::push_front(int value) {
    Node* new_node = new Node(value, head);
    head = new_node;

    if (tail == nullptr) {
        tail = new_node;
    }
    num_items++;
}

// Set the next pointer to nullptr
// If the list is empty, set both the head and tail pointers to the new node
// Otherwise, add the new node to the end of the list and update the tail pointer
void SingleLinkedList::push_back(int value) {
    Node* new_node = new Node(value, nullptr);
    if (tail == nullptr) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Removes the first element of the list
// Deallocates the memory used by the node
// Updates pointers, and decrements the num_items counter.
void SingleLinkedList::pop_front() {
    if (head == nullptr) {
        return;
    }

    Node* old_head = head;
    head = head->next;
    delete old_head;

    if (head == nullptr) {
        tail = nullptr;
    }

    num_items--;
}

//  Removes the last element of the list
// Deallocates the memory used by the node
// Updates pointers, and decrements the num_items counter
void SingleLinkedList::pop_back() {
    if (tail == nullptr) {
        return;
    }

    if (head == tail) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;

        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    num_items--;
}

// Returns the value stored in the head node
int SingleLinkedList::front() {
    if (head == nullptr) {
        return -1;
    }

    return head->value;
}

// Returns the value stored in the tail node
int SingleLinkedList::back() {
    if (tail == nullptr) {
        return -1;
    }

    return tail->value;
}

// Returns a boolean value indicating whether the list is empty or not
bool SingleLinkedList::empty() {
    return num_items == 0;
}

void SingleLinkedList::insert(size_t index, const int& value) {
    if (index == 0) {
        push_front(value);
    }
    else {
        Node* current = head;
        size_t current_index = 0;

        // Traverse the list to the node just before the insertion point
        while (current_index < index - 1 && current != nullptr) {
            current = current->next;
            current_index++;
        }

        if (current != nullptr) {
            // Create a new node and insert it after the current node
            Node* new_node = new Node(value, current->next);
            current->next = new_node;

            // Update tail pointer if necessary
            if (new_node->next == nullptr) {
                tail = new_node;
            }

            num_items++;
        }
        else {
            // Index is out of range, so insert at the end of the list
            push_back(value);
        }
    }
}

bool SingleLinkedList::remove(size_t index) {
    if (index >= num_items) {
        // Index is beyond the end of the list
        return false;
    }

    if (index == 0) {
        // Remove the first node
        pop_front();
    }
    else if (index == num_items - 1) {
        // Remove the last node
        pop_back();
    }
    else {
        // Remove a node in the middle of the list
        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* node_to_remove = current->next;
        current->next = node_to_remove->next;
        delete node_to_remove;
        num_items--;
    }

    return true;
}

size_t SingleLinkedList::find(const int& item) {
    Node* current = head;
    size_t index = 0;

    while (current != nullptr) {
        if (current->value == item) {
            return index;
        }
        current = current->next;
        index++;
    }

    // Item not found, return the size of the list
    return num_items;
}
