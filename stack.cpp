 #include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
class stack { //class 
    int top; //top of the stack
    int arr[MAX_SIZE]; //array to store stack elements
    public :  
    stack (){   //constructor
        top = -1;  //initialize top to -1
    }
    void push (int elment ){        //function to push elment to stack 
     top ++;  
    arr [top] = elment ;  // store element in stack
    if (top> MAX_SIZE-1){ //check if stack is full
        cout << "Stack overflow" << endl; //if full, print message
        return;
    }
    else {
         
        arr [top ] = elment ;
    }
    }  
    bool isempty(){
        if (top <-1)
        return true;
        else 
        return  false;
        // or just return top <0 ; ( it would work too )
    }
    void pop (){     //function to pop element from stack
        if (isempty ()){    //check if stack is empty
            cout <<"Stack empty o top ";   //if empty, print message

        }
        else {                // if not empty
            top --;  //decrement top
        }
    }
    void getop(int & stacktop){
        if (isempty ()){    //check if stack is empty
            cout <<"Stack empty o top ";   //if empty, print message
        }
        else {                // if not empty
            stacktop = arr [top];  //get top element
            cout << "Top element is : " << stacktop << endl; //print top element
        }


    }
    void print (){
        for (int i = top ; i >=0; i--){ //loop to print stack elements
            cout << arr [i] << " "; //print element
        }
        cout << endl; //print new line
    }
    };
    

int main (){
    stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    
 int y =0;
 s.getop(y);
 s.pop();
 s.print();
}