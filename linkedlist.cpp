#include<iostream>
#include<string>
using namespace std ;
struct node {
    int *info;
    node *next;
};
class unsortedlinkedlist {
 int length ;
 node *listdata;
 node *currentpos;
 public :
  unsortedlinkedlist(){
    length = 0 ;
    listdata = NULL;
  }
unsortedlinkedlist(){   // destructor
    makeempty();
}
void makeempty(){
    node * temp ;
    while ( listdata != NULL ){       
        temp = listdata;
        listdata = listdata ->next;
        delete temp;
    }
    length = 0 ;
}
bool isfull (){
    node*ptr;
    ptr = new node;
    if (ptr == NULL){
        return true ;
    }
    else {
        delete ptr;
        return false ;
    }

}
int lengthis () const {
    return length ;
}
void resetlist (){
    currentpos = NULL;
    
}
void  getnextitem (int item ){
    item = *(currentpos -> info);
    currentpos = currentpos -> next;

}
bool islastitem (){
    if (currentpos == NULL){
        return true ;
    }
    else {
        return false ;
    }
}

void getitem (int item ){
    node *temp;
    temp = listdata;
    while (temp != NULL){
        if (*(temp -> info) == item){
            currentpos = temp;
            return ;
        }
        temp = temp -> next;
    }
    currentpos = NULL;
}
void insertitem (int item ){
    if (isfull()){
        cout << "List is full" << endl;
        return ;
    }
    node *temp;
    temp = new node;
    temp -> info = new int;
    *(temp -> info) = item;
    temp -> next = listdata;
    listdata = temp;
    length++;
}
void deleteitem (int item ){
    node *temp;
    node *prev;
    temp = listdata;
    prev = NULL;
    while (temp != NULL){
        if (*(temp -> info) == item){
            if (prev == NULL){
                listdata = temp -> next;
            }
            else {
                prev -> next = temp -> next;
            }
            delete temp -> info;
            delete temp;
            length--;
            return ;  // exit the function
        }
        prev = temp;
        temp = temp -> next;
    }
}
void retriveitem (int item ){
    node *temp;
    temp = listdata;
    while (temp != NULL){
        if (*(temp -> info) == item){
            cout << *(temp -> info) << endl;
            return ;
        }
        temp = temp -> next;
    }
    cout << "Item not found" << endl;
}
void printlist (){
    node *temp;
    temp = listdata;
    while (temp != NULL){
        cout << *(temp -> info) << " ";
        temp = temp -> next;
    }
    cout << endl;
}
};

int main (){
    unsortedlinkedlist list;
    list.insertitem(1);
    list.insertitem(2);
    list.insertitem(3);
    list.printlist();
    list.deleteitem(2);
    list.printlist();
    list.retriveitem(1);
    list.retriveitem(2);
    return 0;
}
