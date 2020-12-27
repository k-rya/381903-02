#include "stack.h"
#include <gtest.h>
TEST(CMyStack, full_is_correct)
{
	CMyStack<int> stack(4);
	EXPECT_EQ(stack.IsFull(), false);
	stack.push(0);
	stak.push(1);
	EXPECT_EQ(stack.IsFull(), true);
}

TEST(CMyStack, empty_is_correct)
{
	CMyStack<int> stack(4);
	EXPECT_EQ(stack.IsEmpty(), true);
	stack.push(0);
	EXPECT_EQ(stack.IsEmpty(), false);
}

TEST(CMyStack, create_stack_with_normal_length)
{
	ASSERT_NO_THROW(CMyStack<int> stack(7));
}

TEST(CMyStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(CMyStack<int> stack(-7));
}

TEST(CMyStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(CMyStack <int> stack(MaxSize + 1));
}


TEST(CMyStack, cant_pop_in_empty_stack)
{
	CMyStack<int> stack(3);
	ASSERT_ANY_THROW(stack.pop());
}
TEST(CMyStack, cant_push_in_full_stack)
{
	CMyStack<int> stack(5);
	for (int i = 0; i < 5; i++)
		stack.push(i);
	ASSERT_ANY_THROW(stack.push(6));
}

TEST(CMyStack, can_push_and_pop)
{
	CMyStack<int> stack(4);
	stack.push(10);
	EXPECT_EQ(10, stack.pop());
}

