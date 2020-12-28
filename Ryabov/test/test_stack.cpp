#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create)
{
    ASSERT_NO_THROW(TStack<int> stack(5));
}


TEST(TStack, cant_create_too_large_stack)
{
    ASSERT_ANY_THROW(TStack<int> stack(Max + 1));
}

TEST(TStack, can_pop)
{
    TStack<int> stack(4);
    stack.push(10);
    EXPECT_EQ(10, stack.pop());
}


TEST(TStack, can_push_element)
{
    TStack<int> stack(3);

    ASSERT_NO_THROW(stack.push(3));
}


TEST(TStack, isfull_returns_true)
{
    TStack<int> stack(10);

    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }

    EXPECT_EQ(true, stack.full());
}
