#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new Stack();
    }

    void TearDown() override {
        delete stack;
    }

    Stack* stack;
};

TEST_F(StackTest, IsEmpty) {
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, GetTopEmpty) {
    Node * result = stack->getTop();
    EXPECT_EQ(result, nullptr);
}

TEST_F(StackTest, Push) {
    stack->push(10);
    Node * result = stack->getTop();
    EXPECT_EQ(result->data,10);
}

TEST_F(StackTest, Pop) {
    stack->push(10);
    stack->pop();
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, PopFromEmptyStack) {
    stack->pop();
    EXPECT_EQ(stack->isEmpty(),true);
}

TEST_F(StackTest, GetTop) {
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->pop();
    stack->pop();
    Node * result = stack->getTop();
    EXPECT_EQ(result->data,10);
}

TEST_F(StackTest, SearchByValueSuccess) {
    stack->push(10);
    stack->push(20);
    stack->push(30);
    Node * result = stack->searchByValue(20);
    EXPECT_EQ(result->data,20);
}

TEST_F(StackTest, SearchByValueFail) {
    stack->push(10);
    stack->push(20);
    stack->push(30);
    Node * result = stack->searchByValue(40);
    EXPECT_EQ(result,nullptr);
}

TEST_F(StackTest, SearchByIndexSuccess) {
    stack->push(10);
    stack->push(20);
    stack->push(30);
    Node * result = stack->searchByIndex(1);
    EXPECT_EQ(result->data,20);
}

TEST_F(StackTest, SearchByIndexFail) {
    stack->push(10);
    stack->push(20);
    Node * result = stack->searchByIndex(2);
    EXPECT_EQ(result,nullptr);
}

TEST_F(StackTest, TraverseStack) {
    testing::internal::CaptureStdout();

    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->traverseStack();

    std::string captured_stdout = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Stack elements: 30 20 10 \n", captured_stdout);
}

TEST_F(StackTest, TraverseStackEmpty) {
    testing::internal::CaptureStdout();

    stack->traverseStack();

    std::string captured_stdout = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Stack is empty\n", captured_stdout);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
