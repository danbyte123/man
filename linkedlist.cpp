#include <iostream>
using namespace std;
 template <class T>
struct stnodetype {
    itemtype datavalueinfo;
    stnodetype<T> *next;

};
 template <class itemtype>
 class linkedunsortdeltype {
     
        stnodetype<itemtype> *head;
        stnodetype<itemtype> *tail;
private:
int length;
stnodetype<itemtype> *head;
stnodetype<itemtype> *current;

public :
linkedunsortdeltype() {
     unsortedlinklist();
     void makeempty();
     void resetlist();
        bool isfull();
        int lengthlst ()const ;
        bool islastitem() const;


}
template <class itemtype>
linkedunsortdeltype<itemtype>::linkedunsortdeltype() {
    head = nullptr;
    tail = nullptr;
    length = 0;
    current = nullptr;
};
template <class itemtype>
linkedunsortdeltype<itemtype>::linkedunsortdeltype() {
    makeempty();
    stnodetype<itemtype> *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}
template <class itemtype>
bool linkedunsortdeltype<itemtype>::resetlist() {
     current = head;
        return true;
    }
    template <class itemtype>
bool linkedunsortdeltype<itemtype>::lengthlst() const {
    return length;
}

 };
 
 int main (){

 }
