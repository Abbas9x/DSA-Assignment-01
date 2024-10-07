#include<iostream>
using namespace std;


class Stack{
    
    private:
    
    int top;
    int *stack;
    int maxSize;
    int min;
    
    public:
    
    Stack(int maxSize){
        top = -1;
        stack = new int[maxSize];
        this->maxSize = maxSize;
    }
    
    bool isEmpty(){
        return (top == -1);
    }
    
    bool isFull(){
        return (top == maxSize - 1);
    }
    
    void Push(int item){
        if(isFull()){
            cout << "\nStack Overflow\n";
            return;
        }else{
            
            if(top == -1){
                min = item;
                stack[++top] = item;
            }else if(item < min){
                stack[++top] = 2 * item - min;
                min = item;
            }else if(top == 0){
                stack[++top] = item;
            }else{
                stack[++top] = item;
            }
            
            
        }
    }
    
    void Pop(int &item){
        if(isEmpty()){
            cout << "\nStack Underflow!\n";
            return;
        }else{
            
            int Poppeditem = stack[top--];
            
            if(Poppeditem < min){
                item = min;
                min = 2 * min - Poppeditem;
            }else{
                item = Poppeditem;
            }
        }
    }
    
    int Size(){
        if(isEmpty()){
            cout << "\nStack is Empty\n";
            return 0;
        }else{
            return top + 1;
        }
    }
    
    int getMin(){
        return this->min;
    }
};

void Menu(){
    cout << "\n---------- Main Menu -----------\n";
    cout << "\n1.Push";
    cout << "\n2.Pop";
    cout << "\n3.Size";
    cout << "\n4.Minimum";
    cout << "\n5.Exit";
    cout << "\n\nEnter your Choice: ";
}


int main(){
    
    int maxSize;
    cout << "\nEnter the Max Size of the Stack: ";
    cin >> maxSize;
    Stack stack = Stack(maxSize);
    
    while(true){
        Menu();
        int choice = 0;
        cin >> choice;
        
        if(choice == 5){
            break;
        }else if(choice == 1){
            int n;
            cout << "\nEnter the Number: ";
            cin >> n;
            stack.Push(n);
            cout << "\nSuccessfully Pushed " << n << endl;
        }else if(choice == 2){
            int n;
            stack.Pop(n);
            cout << "\nSuccessfully Popped " << n << endl;
        }else if(choice == 3){
            cout << "\nSize: " << stack.Size();
        }else if(choice == 4){
            cout << "\nSmallest: " << stack.getMin();
        }
        else{
            cout << "\nInvalid Input\n";
            cout << "\nTry Again";
        }
    }

  
    cout << "\nGoodBye!\n";
    cout << endl << endl;
    return 0;
}


