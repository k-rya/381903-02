#include "TForm.h"
#include <gtest.h>

TEST(TForm, can_create)
{
    ASSERT_NO_THROW(TForm f);
}
TEST(TForm, convert_vir_to_post)
{
    TForm f("x^2+y^2");

    f.To_Inf();

    EXPECT_EQ(f.getPostf(), "x2 ^y2 ^+");
}

TEST(TForm, best_priority_mull)
{
    TForm f("15-3*4");

    double res = f.Calculate();

    EXPECT_EQ(res, 3.0);
}

TEST(TForm, wrong_brackets)
{
    ASSERT_ANY_THROW(TForm f("(1+(2*3)"));
}

TEST(TForm, calc_is_correct)
{
    TForm f("(6+5)*2-11");

    EXPECT_EQ(f.Calculate(),11.0);
}
