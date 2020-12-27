#include "postfix.h"
#include <gtest.h>

TEST(CMyPostfix, can_create_postf)
{
	ASSERT_NO_THROW(CMyPostfix p);
}

TEST(CMyPostfix, calc_is_correct)
{
	CMyPostfix p("(7+4)*2");
	p.ToPostf();
	EXPECT_EQ(p.Calc(), 22);

TEST(CMyPostfix, cant_create_postfix_with_unusal_symbols)
{
	ASSERT_ANY_THROW(CMyPostfix p("a+b&c!d"));
}

TEST(CMyPostfix, convert_equal_expression)
{
	CMyPostfix p1("(a+b)");
	p1.ToPostf();
	CMyPostfix p2("a+b");
	p2.ToPostf();
	EXPECT_EQ(p1.getPostf(), p2.getPostf());
}
TEST(CMyPostfix, convert_infix_in_brackets)
{
	TPostfix p("(a+b)*c");
	p.ToPostfix();
	EXPECT_EQ(p.getPostfix(), "ab+c*");
}
TEST(CMyPostfix, cant_create_postf_with_incurrect_names)
{
	ASSERT_ANY_THROW(CMyPostfix p("a+bcd"));
}


TEST(CMyPostfix, convert_infix_to_postf)
{
	CMyPostfix p("a+b/c*d-h+k");
	p.ToPostf();
	EXPECT_EQ(p.getPostf(), "abc/d*+h-k+");
}

TEST(CMyPostfix, throws_inf_with_only_spaces)
{
	ASSERT_ANY_THROW(CMyPostfix p("      "));
}

TEST(CMyPostfix, throws_when_operation_behind)
{
	ASSERT_ANY_THROW(CMyPostfix p("a-b*"));
}

TEST(CMyPostfix, throws_when_operation_ahead)
{
	ASSERT_ANY_THROW(CMyPostfix p("+a-b"));
}

TEST(CMyPostfix, throws_when_too_many_left_brackets)
{
	ASSERT_ANY_THROW(CMyPostfix p("(a+(b*c)"));
}

TEST(CMyPostfix, throws_when_too_many_right_brackets)
{
	ASSERT_ANY_THROW(CMyPostfix p("(a+(b*c))+d))"));
}

