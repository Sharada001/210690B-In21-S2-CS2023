#include <iostream>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class StackUsingLinkedList {
    private:
        Node* top;
        int size;
        int count = 0;
    public:
        StackUsingLinkedList(int s) {
            top = nullptr;
            size = s;
        }
        void Push(int value) {
            if (count>=size) {
                cout << "Stack Overflow" << endl;
            } else {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = top;
                top = newNode;
                count += 1;
            }
        }
        int Pop() {
            if (top == nullptr) {
                throw runtime_error("Empty Stack");
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            count -= 1;
            return value;
        }
        void Display() {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        bool isEmpty() {
            if (top == nullptr) {
                return true;
            }
            return false;
        }
        int StackTop() {
            if (top == nullptr) {
                throw runtime_error("Empty Stack");
            } else {
                return top->data;
            }
        }
        bool isFull() {
            if (count==size) {
                return true;
            }
            return false;
        }

};


int main() {
    
    StackUsingLinkedList Stack2(15);
    auto start_time2 = chrono::high_resolution_clock::now();
    Stack2.Push(8);
    Stack2.Push(10);
    Stack2.Push(5);
    Stack2.Push(11);
    Stack2.Push(15);
    Stack2.Push(23);
    Stack2.Push(6);
    Stack2.Push(18);
    Stack2.Push(20);
    Stack2.Push(17);
    Stack2.Display();
    Stack2.Pop(); Stack2.Pop(); Stack2.Pop(); Stack2.Pop(); Stack2.Pop();
    Stack2.Display();
    Stack2.Push(4);
    Stack2.Push(30);
    Stack2.Push(3);
    Stack2.Push(1);
    Stack2.Display();
    auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);
    cout << "Execution time of Stack (implemented with LinkedList): " << duration2.count() << " microseconds\n"<< endl;

    return 0;
}
