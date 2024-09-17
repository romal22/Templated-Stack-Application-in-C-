#include<iostream>
#include <stdlib.h>
#define max_size 5
using namespace std;

template <class Type>
class Stack
{
private:
    Type stk[max_size];
    int TOP;
public:
    Stack():TOP(-1){}
    
    void push(Type element){
        if(TOP >= max_size - 1){
            cout << "\033[31mSTACK OVERFLOW\033[0m" << endl; // Red
        }else{
            stk[++TOP] = element;
            cout << "\033[32mELEMENT PUSHED\033[0m" << endl; // Green
        }
    }
    void pop(){
        if(TOP < 0){
            cout << "\033[31mSTACK UNDERFLOW\033[0m" << endl; // Red
        }else{
            --TOP;
            cout << "\033[32mELEMENT POPPED\033[0m" << endl; // Green
        }        
    }
    void display_stack(){
        if(TOP < 0){
            cout << "\033[33mSTACK IS EMPTY\033[0m" << endl; // Yellow
        }else{
            cout << "\033[34mSTACK ELEMENT\033[0m" << endl; // Blue
            for(int i = 0; i <= TOP; i++)
                cout << stk[i] << " ";
            cout << endl;
        }
    }
};

template <class Type>
void stack_application(Stack<Type>& stack){
    int choice;
    do{
        cout << "\n\033[36m1. Push\033[0m\n\033[36m2. Pop\033[0m\n\033[36m3. Display Stack\033[0m\n\033[36m4. Main Menu\033[0m" << endl;
        cout << "Select an option: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                Type element;
                cout << "Enter element to push: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display_stack();
                break;
            case 4:
                cout << "\033[32mReturning to main menu...\033[0m" << endl; // Green
                break;
            default:
                cout << "\033[31mInvalid option. Please select again.\033[0m" << endl; // Red
        }
    } while(choice != 4);
}

int main(){
    int main_choice, prev_choice = 0;
    int attempts = 0;
    
    Stack<int> intStack;
    Stack<char> charStack;
    Stack<double> doubleStack;
    Stack<float> floatStack;
    Stack<string> stringStack;
    
    do{
        cout << "\n\033[35mMain Menu:\033[0m\n\033[35m1. Int\033[0m\n\033[35m2. Char\033[0m\n\033[35m3. Float\033[0m\n\033[35m4. Double\033[0m\n\033[35m5. Exit\033[0m" << endl; // Magenta
        cout << "Select an option: ";
        cin >> main_choice;
        if(prev_choice == main_choice)
        {
            int temp;
            cout << "\n\033[32m1. Continue old stack\033[0m\n\033[32m2. New stack\033[0m" << endl; // Green
            cin >> temp;
            if(temp == 1)
            {
                switch(prev_choice)
                {
                    case 1:
                        cout << "Old int stack continues...\n";
                        stack_application(intStack);
                        break;
                    case 2:
                        cout << "Old char stack continues...\n";
                        stack_application(charStack);
                        break;
                    case 3:
                        cout << "Old float stack continues...\n";
                        stack_application(floatStack);
                        break;
                    case 4:
                        cout << "Old double stack continues...\n";
                        stack_application(doubleStack);
                        break;
                }
            }
        }
        prev_choice = main_choice;
        switch(main_choice){
            case 1:
                cout << "Int stack application ready to use\n";
                stack_application(intStack);
                break;
            case 2:
                cout << "Char stack application ready to use\n";
                stack_application(charStack);
                break;
            case 3:
                cout << "Float stack application ready to use\n";
                stack_application(floatStack);
                break;
            case 4:
                cout << "Double stack application ready to use\n";
                stack_application(doubleStack);
                break;
            case 5:
                cout << "\033[31mExiting the program.\033[0m" << endl; // Red
                return 0;
            default:
                attempts++;
                if(attempts >= 3){
                    cout << "\033[31mToo many invalid attempts.\033[0m" << endl; // Red
                    return 0;
                } else if(attempts == 2){
                    cout << "\033[33mLast chance, please be careful!\033[0m" << endl; // Yellow
                } else {
                    cout << "\033[31mInvalid option. Please select carefully.\033[0m" << endl; // Red
                }
                break;
        }
    } while(1);
    return 0;
}
