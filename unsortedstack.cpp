#include <iostream>
using namespace  std ;
const int maxsize = 100;
class unsortedstack {
private :
int top ;
int arr[maxsize];
public :
unsortedstack () {
top = -1 ;
}
void makeempty () {
top = -1 ;
}
bool isempty () {
return (top == -1);
}
bool isfull () {
return (top == maxsize - 1);
}
void push (int x) {
if (isfull ()) {
cout << "Stack is full" << endl ;
} else {
top ++ ;
arr[top] = x ;
}
}
int pop () {
if (isempty ()) {
cout << "Stack is empty" << endl ;
return -1 ;
} else {
int x = arr[top] ;
top -- ;
return x ;
}
}
 
}; 

int main (){}