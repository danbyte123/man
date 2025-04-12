#include <iostream>
using namespace std;
class arraylist{
    int *arr;
    int maxSize;
    int length;
public:
arraylist(int s = 10) {
    if (s < 0) {
        maxSize = 5;
    }                    // things we give and not rel nums 
    else if (s > 0) {
        maxSize = s;
    }
    length = 0;
    arr = new int[maxSize];  // Allocate memory for the array
}
bool isempty(){
    if (length ==0 ){
        return true;
    }
    else {
        return false;
    }
}
bool isfull (){
    if (length == maxSize){
        return true;
    }
    else {
        return false;
    }
}
int getlength(){
    return length;
}
void print ( ){
    if (isempty()){
        cout << "array is empty" << endl;
    }
    else {
        for (size_t i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void insertatpos (int pos , int elment ){
    if (isfull()){
        cout <<"array is full "<< endl;
    }
    else {
        if (pos < 0 || pos > length){
            cout << "invalid position" << endl;
        }
        else {
            for (int i = length; i > pos; i--){
                arr[i] = arr[i-1];
            }
            arr[pos] = elment;
            length++;
        }
    }
}
void insertatend(int elment )
{
    if (isfull()){
        cout << "array is full" << endl;

    }
    else {
        arr[length] = elment;
        length++;
    }
}
int  searchelment ( int elment ){
    for ( int i = 0; i < length; i++){
        if (arr[i] == elment){
            cout << "element found at position " << i << endl;
            return i;
        }
    }
    return -1;
}
void searchinsertnodubplicate( int elment ){
    if (searchelment(elment) == -1){
        insertatend(elment);
    }
    else {
        cout << "element already exists" << endl;
    }
}

void updateaat( int pos , int elment ){
    if (pos < 0 || pos >= length){
        cout << "invalid position" << endl;
    }
    else {
        arr[pos] = elment;
    }
}
int getelment(int pos ){
    if (pos < 0 || pos >= length){
        cout << "invalid position" << endl;
        return -1;
    }
    else {
        return arr[pos];
    }


}
void deleteatpos (int pos ){
    if (isempty()){
        cout << "array is empty" << endl;
    }
    else {
        if (pos < 0 || pos >= length){   // check if pos is valid
            cout << "invalid position" << endl;
        }
        else{
            for (int i = pos; i < length - 1; i++){
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }
}

~arraylist(){
    delete [] arr;
}
void clear (){
    length = 0 ;
}
};
int main (){
arraylist a(100);
a.insertatpos(0, 5);
a.insertatpos(1, 10);
a.insertatpos(2, 15);
a.insertatend(20);
a.searchinsertnodubplicate(25);
a.searchinsertnodubplicate(25);
a.print();




}