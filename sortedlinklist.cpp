#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};

template<class ItemType>
class SortedType {
public:
    SortedType(); // Constructor
    ~SortedType(); // Destructor
    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType&, bool&);
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void ResetList();
    bool IsLastItem() const;
    void GetNextItem(ItemType&);

private:
    int length;
    NodeType<ItemType>* listData;
    NodeType<ItemType>* currentPos;
};

// Constructor
template<class ItemType>
SortedType<ItemType>::SortedType() {
    length = 0;
    listData = NULL;
}

// Destructor
template<class ItemType>
SortedType<ItemType>::~SortedType() {
    MakeEmpty();
}

// MakeEmpty: Empties the list
template<class ItemType>
void SortedType<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

// IsFull: Checks if the list is full
template<class ItemType>
bool SortedType<ItemType>::IsFull() const {
    NodeType<ItemType>* ptr;
    ptr = new NodeType<ItemType>;
    if (ptr == NULL)
        return true;
    else {
        delete ptr;
        return false;
    }
}

// LengthIs: Returns the length of the list
template<class ItemType>
int SortedType<ItemType>::LengthIs() const {
    return length;
}

// ResetList: Resets the current position for iteration
template<class ItemType>
void SortedType<ItemType>::ResetList() {
    currentPos = listData;
}

// GetNextItem: Gets the next item in the list during iteration
template<class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item) {
    item = currentPos->info;
    currentPos = currentPos->next;
}

// IsLastItem: Checks if the current item is the last in the list
template<class ItemType>
bool SortedType<ItemType>::IsLastItem() const {
    return (currentPos == NULL);
}

// RetrieveItem: Retrieves an item from the list
template<class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    NodeType<ItemType>* location;
    location = listData;
    found = false;

    while ((location != NULL) && !found) {
        if (location->info < item)
            location = location->next;
        else if (location->info == item) {
            found = true;
            item = location->info;
        } else
            location = NULL; // No reason to keep searching
    }
}

// InsertItem: Inserts an item into the list in sorted order
template<class ItemType>
void SortedType<ItemType>::InsertItem(ItemType newItem) {
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = newItem;
    newNode->next = NULL;

    location = listData;
    predLoc = NULL;
    found = false;

    while (location != NULL && !found) {
        if (location->info < newItem) {
            predLoc = location;
            location = location->next;
        } else
            found = true;
    }

    if (predLoc == NULL) { // Inserting at the beginning
        newNode->next = listData;
        listData = newNode;
    } else { // Inserting between or at the end
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

// DeleteItem: Deletes an item from the list
template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    if (item == listData->info) {
        tempLocation = location;
        listData = listData->next; // delete first node
    } else {
        while (!(item == (location->next)->info))
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

// Main function to demonstrate the SortedType class
int main() {
    SortedType<int> list;

    // Insert items into the list
    list.InsertItem(5);
    list.InsertItem(3);
    list.InsertItem(8);
    list.InsertItem(1);

    // Retrieve an item
    int item = 3;
    bool found;
    list.RetrieveItem(item, found);
    if (found) {
        cout << "Item " << item << " found in the list." << endl;
    } else {
        cout << "Item " << item << " not found in the list." << endl;
    }

    // Delete an item
    list.DeleteItem(5);

    // Display the list
    list.ResetList();
    cout << "List items: ";
    while (!list.IsLastItem()) {
        list.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}