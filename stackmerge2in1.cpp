#include<iostream>
using namespace std;
struct Stack {
    int* arr;
    int top;
    int size;

    void init(int n) {
        size=n;
        arr = new int[n];
        top = -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (!isFull()) arr[++top] = x;
        else cout << "Overflow!\n";
    }

    int pop() {
        if (!isEmpty()) return arr[top--];
        else {
            cout << "Underflow!\n";
            return -1;
        }
    }

    void destroy() {
        delete[] arr;
    }
};
// Merge two stacks into third alternately
void mergeAlternately(Stack& s1, Stack& s2, Stack& s3) {
    while (!s1.isEmpty() || !s2.isEmpty()) {
        if (!s1.isEmpty()) s3.push(s1.pop());
        if (!s2.isEmpty()) s3.push(s2.pop());
    }
}

int main() 
{
    Stack s1, s2, s3;
    s1.init(5); s2.init(5); s3.init(10);

    //  Push 5 elements into each stack
    for (int i = 1; i <= 5; i++) {
        s1.push(i);       // s1: 1 to 5
        s2.push(i + 5); // s2: 6 to 10
    }

    mergeAlternately(s1, s2, s3);

    // Print merged stack
    cout << "Merged Stack (top to bottom):\n";
    while (!s3.isEmpty()) {
        cout << s3.pop() << " ";
    }
    cout << endl;

    return 0;
}


