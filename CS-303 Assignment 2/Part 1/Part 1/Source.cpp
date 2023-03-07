#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main() {
    SingleLinkedList list;

    // add some items to the list
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.push_front(20);

    // print the list after push to front
    cout << "List after push front: ";
    for (SingleLinkedList::iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //------------------------------------

    list.push_back(25);
    list.push_back(30);
    list.push_back(35);
    list.push_back(40);

    // print the list after push to back
    cout << "List after push back: ";
    for (SingleLinkedList::iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //-------------------------------------

    // Remove items from the list
    list.pop_front();
    list.pop_front();
    // print the list after pop front value
    cout << "List after pop front: ";
    for (SingleLinkedList::iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //-------------------------------------

    list.pop_back();
    list.pop_back();
    // print the list after pop back
    cout << "List after pop back: ";
    for (SingleLinkedList::iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //-------------------------------------

    bool empty = list.empty();
    // get the front and back items in the list
    int front = list.front();
    int back = list.back();

    // check if the list is empty
    cout << "Is the list Empty: ";
    if (empty)
        cout << "Yes" << endl;
    else if (!empty)
        cout << "No" << endl;

    if (empty) // If list is empty
        cout << "Front value: The list is empty!" << endl;
    else if (!empty) // If list not empty
        cout << "Front value: " << front << endl;

    if (empty)
        cout << "Back value: The list is empty!" << endl;
    else if (!empty)
        cout << "Back value: " << back << endl;

    cout << endl;

    //-------------------------------------
    // Insert value in the given index
    list.insert(1, 33);
    list.insert(3, 99);

    cout << "List after insert: ";
    for (SingleLinkedList::iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //-------------------------------------
    // Remove the item at index 2 (value 5)
    bool removed = list.remove(2);
    if (removed) {
        cout << "Item at index 2 removed successfully.\n";
    }
    else {
        cout << "Could not remove item at index 2.\n";
    }

    // Print the items in the list after remove
    cout << "List after remove: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    //-------------------------------------
    // Find what index a value located
    cout << "List contains 30 at index " << list.find(30) << std::endl;

    return 0;
}

