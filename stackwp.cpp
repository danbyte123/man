#include <iostream>
#include <string>
using namespace std;

template <class t>
class stack {
public:
    struct node {  // node structure
        t data;     // data of node
        node* next; // next pointer
    };

    node* top;

    stack() {
        top = NULL;
    }

    void push(t element) {
        node* newitemptr = new node;
        if (newitemptr == NULL) { // check if new item is null
            cout << "Stack overflow" << endl;
            return;
        }
        newitemptr->data = element; // store element in node
        newitemptr->next = top;     // point to top
        top = newitemptr;
    }

    bool isempty() {
        if (top == NULL) // check if top is null
            return true; // if null, return true
        else
            return false; // if not null, return false
        // or just return top == NULL ; ( it would work too )
    }

    void pop(t& stacktop) { // function to pop element from stack
        if (isempty()) { // check if stack is empty
            cout << "Stack empty on top "; // if empty, print message
            return;
        }
        stacktop = top->data; // get top element
        node* temp = top;     // store top in temp
        top = top->next;      // point to next
        delete temp;          // delete temp
    }

    void getop(t& stacktop) { // function to get top element
        if (isempty()) { // check if stack is empty
            cout << "Stack empty on top "; // if empty, print message
            return;
        }
        stacktop = top->data; // get top element
        cout << "Top element is : " << stacktop << endl; // print top element
    }

    void display() {
        node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.display();

    return 0;
}
