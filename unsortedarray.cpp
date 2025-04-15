#include<iostream>
using namespace std;
const int max_size = 100;
class unsortedarray{
    int length;
    int arr[max_size];
public:
    unsortedarray(){
        length = 0;
    }
    bool isempty(){
        return (length == 0);
    }
    bool isfull(){
        return (length == max_size);
    }

    void insertelment(int elment){
        if (isfull()){
            cout << " array is full " << endl;
        }
        else
        {
            arr[length] = elment;
            length++;
        }
    }
    void deletelment(int elment){
        if (isempty()){
            cout << " u cant delete from empty " << endl;
        }
        else {
            for(int i = 0; i < length; i++) {
                if(arr[i] == elment) {
                    
                    for(int j = i; j < length-1; j++) {
                        arr[j] = arr[j+1];
                    }
                    length--;
                    return;
                }
            }
            cout << "Element not found" << endl;
        }
    }
    int getlength(){
        return length;
    }
    void makeempty(){
        length = 0;
    }
    void retriveelment(int elment){
        bool found = false;
        for(int i = 0; i < length; i++){
            if(arr[i] == elment){
                cout << " elment found at position " << i << endl;
                found = true;
            }
        }
        if(!found){
            cout << " elment not found " << endl;
        }
    }
    void print (){
        if (isempty()){
            cout << " array is empty " << endl;
        }
        else {
            for (int i = 0; i < length; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){ 
    unsortedarray a; 
    a.insertelment(5);
    a.insertelment(10);
    a.insertelment(15);
    a.insertelment(20);
    a.insertelment(25);
    a.deletelment(25);
    a.retriveelment(25);
   
    cout << " length of array is " << a.getlength() << endl;
    cout << " array is " << (a.isempty() ? "empty" : "not empty") << endl;
    a.print();
    return 0;
}