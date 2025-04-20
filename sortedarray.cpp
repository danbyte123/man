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

    void retrieveItem(int arr[], int length, int& element, bool& found) {
        found = false;
        int location = 0;
        
        while (location < length && !found) {
            if (arr[location] == element) {
                found = true; // we found it
            } else if (element < arr[location]) {
                // since the array is sorted, no need to keep looking
                break;
            } else {
                location++;
            }
        }
    }
    
void insertitem (int elment ){
    int location = 0 ;
    bool found = false ;
    if (isfull ()){
        cout << " array is full " << endl ;
    }
    else {
        while ( (location < length ) && !found  ){
            if (arr[location] == elment){
                cout << " element already exists " << endl ;
                return ;
                found = true ;
            }
            else if (arr[location] > elment){
                found = true ;
            
            else {
                location++;
            }
        }

    }
    for ( int index = length ; index > location ; index--){
        arr[index] = arr[index - 1];
    }
    arr[location] = elment ;
    length++;
}
void deleteitem ( int elment ){
    int location = 0;
    bool found = false ;
    while ( elment != arr[location]){
        location++;
    }
    for ( int index = location+1; index < length -1 ; index++){
        arr[index -1 ] = arr[index];
    }
    length--;
}
void resetlist (){
    currpos = -1 ;
}
bool islastitem () const {
    return (currpos == length -1);

}
bool getnextitem (int& element){
    if (currpos == length -1){
        cout << " no more items " << endl ;
        return false ;
    }
    else {
        currpos++;
        element = arr[currpos];
        return true ;
    }
}
};

int main (){}