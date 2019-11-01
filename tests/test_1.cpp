//
// Created by DarthBarada on 01.11.2019.
//

#include <gtest/gtest.h>
#include "Stack.hpp"
#include "StackExceptions.hpp"

TEST(Stack,EmptyStack)
    {
        Stack<int> my_stack;

        EXPECT_THROW(my_stack.pop(),PopFromEmptyStack);
        EXPECT_THROW(my_stack.head(),StackIsEmpty);
        EXPECT_THROW(my_stack.tail(),StackIsEmpty);
        EXPECT_EQ(my_stack.size(),0u);
    }

TEST(Stack,EmptyStackPop)
    {
        Stack<double> my_stack;
        for (size_t index = 0;index<10;++index)
        my_stack.push(5.);

        for (size_t index = 0;index<10;++index)
        my_stack.pop();
        EXPECT_THROW(my_stack.pop(),PopFromEmptyStack);
    }

TEST(Stack,push_test_1)
    {
        Stack<int> my_stack;
        for (size_t index = 1;index<=10;++index)
            my_stack.push(index);
        EXPECT_EQ(my_stack.head(),10);
        EXPECT_EQ(my_stack.tail(),1);
    }

TEST(Stack,push_test_2)
    {
        Stack<int> my_stack;

        my_stack.push(std::move(1));
        my_stack.push(std::move(5));
        my_stack.push(std::move(10));

        EXPECT_EQ(my_stack.head(),10);
        EXPECT_EQ(my_stack.tail(),1);
    }

TEST(Stack,size_test)
    {
        Stack<int> my_stack;

        for (size_t index = 0;index<1000;++index)
            {
                my_stack.push(index);
            }

        EXPECT_EQ(my_stack.size(),1000);
    }
