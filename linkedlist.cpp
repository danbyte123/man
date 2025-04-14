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
};

int main (){}
