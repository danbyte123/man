#include <iostream>
using namespace std ;
const int  maxitems = 100 ;
class sortedarray {
	int length ;
    int curr;
    int *arr    
    ;

    public :
sortedarray(){
    length = 0 ;
    curr = -1 ;
    int arr[length ];
}
void makeempty (){
    length = 0 ;
}
bool isfull(){
    if ( length == maxitems ){
        return true;
        cout << "Array is full" << endl ;
    }
    else {
        return false ;
        cout << "Array is not full" << endl ;

    }
}
void isempty(){
    if ( length ==0){
        cout << "Array is empty" << endl ;
    }
    else {
        cout << "Array is not empty" << endl ;
    }
}
};






int main ( ){}