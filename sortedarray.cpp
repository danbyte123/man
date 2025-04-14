#include <iostream>
#include <string>
using namespace std;
const int max_size = 100 ;
class sortedarray {
int length ;
int arr[max_size ];
int currpos;
public :
sortedarray(){
    length = 0 ;
    currpos = -1 ;
}
bool isempty (){
    if ( length ==0 ){
        return true ;
    }
    else {
        return false ;
    }
}
bool isfull(){
    if ( length == max_size ){
        cout << " array is full " << endl ;

    }
    else {
        cout << " array is not full " << endl ;
    }
     
}
int getlength (){
    return length;
}

int makeempty (){
    length = 0 ;}


};







int main (){}