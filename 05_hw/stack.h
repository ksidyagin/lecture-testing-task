#ifndef STACK_H
#define STACK_H

typedef struct Node{
    int data;
    struct Node *next;
} Node;

class Stack{
    private:
        Node* top;
        void initStack();
        void destroyStack();
        Node* createNode(int data);
    public:
        void push(int data);
        void pop();
        Node *searchByValue(int value);
        Node *searchByIndex(int index);
        Node *getTop();
        void traverseStack();
        bool isEmpty();
        Stack();
        ~Stack();
};

#endif