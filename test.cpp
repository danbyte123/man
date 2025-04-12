#include <iostream>
#include <string>
using namespace std ;
class arraylist {
private:
    int maxsize;
    int length;
    int *arr;
public:
    arraylist(int s = 20) {
		if (s < 0) {
            cout <<" the size must be positive " << endl ;
            exit(1);
        
			
		}
        else {
            maxsize= s; 
        }
	}
    arraylist (){
        length = 0;
        maxsize = 20;
        arr = new int[maxsize];  // Allocate memory for the array
    }
    bool isempty(){
        if (length ==0 ){
            return true;
        }
        else {
            return false;
        }
    }
    int isfull(){
        if (length == maxsize ){
            return true ;

        }
        else {
            return false ;
        }
    }         
    int getlength (){
        return length ;

    }
    int getmaxsize()
{
    return maxsize;
}
void insertatpos (int pos , int emlent ){
    if (isfull ())
    {
         cout << " array is full " << endl ;
    }
    else {
        if (pos <0 || pos > length ){
            cout << " invalid position " << endl ;
        }
        else {
             for  (int i = length ; i >pos ; i-- ){
                arr [i] = arr [i-1];
             }
    }
    
}
}
void insertatend ( int elment) {
    if (isfull()){
        cout << " array is full " << endl ;
    }
    else {
        arr[length] = elment ;
        length++;
    }
}

int  searchelment ( int elment ){
    for ( int i =0 ; i < length ; i++){
        if ( arr [i]== elment ){
            cout << " element found at position " << i << endl ;
            return i ;
        }
    }
    return -1;
}
 int searforelmentnoduplicate(int elment ){
    if (searchelment(elment) == -1){
        insertatend(elment);
        cout << " element not found " << endl ;
        }
    }
    
};
int main (){

}