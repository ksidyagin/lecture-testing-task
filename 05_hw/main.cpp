#include <iostream>
#include "stack.h"

int main() {
    Stack *stack = new Stack();
    if(stack->isEmpty()){
        std::cout << "Stack initialized" << std::endl;
    }

    stack->pop();
    std::cout << "After popping from an empty stack:" << std::endl;
    if(stack->isEmpty()){
        std::cout << "Stack is empty" << std::endl;
    }

    stack->push(10);
    stack->push(20);
    stack->push(30);
    std::cout << "After pushing elements:" << std::endl;
    stack->traverseStack();

    stack->pop();
    std::cout << "After popping element:" << std::endl;
    stack->traverseStack();

    Node* searchResult = stack->searchByValue(10);
    if (searchResult != nullptr) {
        std::cout << "Element with value 10 found." << std::endl;
    } else {
        std::cout << "Element with value 10 not found." << std::endl;
    }

    Node* searchResult2 = stack->searchByValue(40);
    if (searchResult2 != nullptr) {
        std::cout << "Element with value 40 found." << std::endl;
    } else {
        std::cout << "Element with value 40 not found." << std::endl;
    }

    Node* topElement = stack->getTop();
    if (topElement != nullptr) {
        std::cout << "Top element: " << topElement->data << std::endl;
    }

    Node* searchIndex = stack->searchByIndex(1);
    if (searchIndex != nullptr) {
        std::cout << "Element with index 1 found. The value of element is: " << searchIndex->data << std::endl;
    } else {
        printf("Element with index 1 not found.\n");
    }

    Node* searchIndex2 = stack->searchByIndex(-1);
    if (searchIndex2 != nullptr) {
        std::cout << "Element with index -1 found. The value of element is: " << searchIndex2->data << std::endl;
    } else {
        printf("Element with index -1 not found.\n");
    }

    delete stack;
    return 0;
}


