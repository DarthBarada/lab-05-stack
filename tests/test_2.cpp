//
// Created by DarthBarada on 01.11.2019.
//

#include <gtest/gtest.h>
#include <string>

#include "UnicStack.hpp"
#include "StackExceptions.hpp"

TEST(UnicStack,EmptyUnicStack)
{
    UnicStack<int> my_stack;

    EXPECT_THROW(my_stack.pop(),PopFromEmptyStack);
    EXPECT_THROW(my_stack.head(),StackIsEmpty);
    EXPECT_THROW(my_stack.tail(),StackIsEmpty);
    EXPECT_EQ(my_stack.size(),0u);
}

TEST(UnicStack,EmptyUnicStackPop)
{
    UnicStack<double> my_stack;
    for (size_t index = 0;index<10;++index)
        my_stack.push(5.);

    for (size_t index = 0;index<10;++index)
        my_stack.pop();
    EXPECT_THROW(my_stack.pop(),PopFromEmptyStack);
}

TEST(UnicStack,push_test_1)
{
    UnicStack<int> my_stack;
    for (size_t index = 1;index<=10;++index)
        my_stack.push(index);
    EXPECT_EQ(my_stack.head(),10);
    EXPECT_EQ(my_stack.tail(),1);
}

TEST(UnicStack,push_test_2)
{
    UnicStack<int> my_stack;

    my_stack.push(std::move(1));
    my_stack.push(5.);
    my_stack.push_emplace('f');
    my_stack.push_emplace(true);

    EXPECT_EQ(my_stack.head(),true);
    EXPECT_EQ(my_stack.tail(),1);
}

TEST(UnicStack,size_test)
{
    UnicStack<int> my_stack;

    for (size_t index = 0;index<1000;++index)
        {
            my_stack.push(index);
        }

    EXPECT_EQ(my_stack.size(),1000);
}

TEST(UnicStack,pop_test)
{
    UnicStack<int> my_stack;
    char chr = 's';
    my_stack.push(chr);
    EXPECT_EQ(my_stack.pop(),chr);
}