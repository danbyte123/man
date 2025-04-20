#include <iostream>
#include <string>
using namespace std;

const int max_size = 100;

class unsortedlist {
    int length;
    int arr[max_size];
    int curpos;

public:
    unsortedlist() {
        length = 0;
        curpos = -1;
    }

    bool isempty() {
        if (length == 0) {
            cout << "list is empty" << endl;
            return true;
        } else {
            cout << "list is not empty" << endl;
            return false;
        }
    }

    bool isfull() {
        bool full = (length == max_size);
        if (full) {
            cout << "list is full" << endl;
        } else {
            cout << "list is not full" << endl;
        }
        return full;
    }

    int getlength() {
        return length;
    }

    void insertitem(int item) {
        if (isfull()) {
            cout << "list is full, cannot insert" << endl;
        } else {
            arr[length] = item;
            length++;
            cout << "item inserted" << endl;
        }
    }

    void deleteItem(int item) {
        if (isempty()) {
            cout << "List is empty, you can't delete." << endl;
            return;
        }

        for (int i = 0; i < length; i++) {
            if (arr[i] == item) {
                arr[i] = arr[length - 1]; // Replace with last element
                length--;                 // Shrink the array
                cout << "Item deleted." << endl;
                return;
            }
        }

        cout << "Item not found." << endl;
    }

    void retriveitem(int item) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == item) {
                cout << "item found at position " << i << endl;
                return;
            }
        }
        cout << "item not found" << endl;
    }

    void makeempty() {
        length = 0;
        cout << "list is empty now" << endl;
    }

    void resetlist() {
        curpos = -1;
        cout << "list is reset" << endl;
    }

    bool islastitem() {
        if (curpos == length - 1) {
            cout << "this is the last item" << endl;
            return true;
        } else {
            cout << "this is not the last item" << endl;
            return false;
        }
    }

    void getnextitem() {
        if (curpos < length - 1) {
            curpos++;
            cout << "next item is " << arr[curpos] << endl;
        } else {
            cout << "no next item" << endl;
        }
    }
    void print (){
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    unsortedlist list;
    list.insertitem(10);
    list.insertitem(20);
    list.insertitem(30);
    list.insertitem(40);
    list.insertitem(50);
    list.deleteItem(30);
    list.retriveitem(20);
     list.print();
    return 0;
}