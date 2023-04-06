#include <iostream>
#include <chrono>
using namespace std;

class StackUsingArray {
    private:
        int size;
        int top;
        int *arr;
    public:
        StackUsingArray(int s) {
            size = s;
            top = -1;
            arr = new int[size];
        }
        void Push(int value) {
            if (top+1>=size) {
                cout << "Stack Overflow" << endl;
            } else {
                top += 1;
                arr[top] = value;
            }
        }
        int Pop() {
            if (top==-1) {
                throw runtime_error("Empty Stack");
            } else {
                top -= 1;
                return arr[top+1];
            }
        }
        bool isEmpty() {
            if (top==-1) {
                return true;
            }
            return false;
        }
        bool isFull() {
            if (top+1==size) {
                return true;
            }
            return false;
        }
        int StackTop() {
            if (top==-1) {
                throw runtime_error("Empty Stack");
            } else {
                return arr[top];
            }
        }
        void Display() {
            for (int i=top; i>=0; i--) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
};

int main() {

    StackUsingArray Stack1(15);
    auto start_time1 = chrono::high_resolution_clock::now();
    Stack1.Push(8);
    Stack1.Push(10);
    Stack1.Push(5);
    Stack1.Push(11);
    Stack1.Push(15);
    Stack1.Push(23);
    Stack1.Push(6);
    Stack1.Push(18);
    Stack1.Push(20);
    Stack1.Push(17);
    Stack1.Display();
    Stack1.Pop(); Stack1.Pop(); Stack1.Pop(); Stack1.Pop(); Stack1.Pop();
    Stack1.Display();
    Stack1.Push(4);
    Stack1.Push(30);
    Stack1.Push(3);
    Stack1.Push(1);
    Stack1.Display();
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);
    cout << "Execution time of Stack (implemented with Array): " << duration1.count() << " microseconds\n"<< endl;
    
    return 0;
}