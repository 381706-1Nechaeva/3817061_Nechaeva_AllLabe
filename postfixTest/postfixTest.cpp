#include "postfix.h"

#include <gtest.h>

TEST(TPostfix, throw_when_different_number_of_brackets)
{
  char str[] = "((1+1)";
  TPostfix pol(str);
  ASSERT_ANY_THROW(pol.Postfix());
}
TEST(TPostfix, throw_when_the_wrong_symbol)
{
  char str[] = "1+3+&";
  TPostfix pol(str);
  ASSERT_ANY_THROW(pol.Postfix());
}
TEST(TPostfix, throw_when_operations_more_then_operands)
{
  char str[] = "1++3";
  TPostfix pol(str);
  pol.Postfix();
  ASSERT_ANY_THROW(pol.calculate());
}
TEST(TPostfix, can_add_two_numbers)
{
  char str[] = "1+3";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(4, pol.calculate());
}
TEST(TPostfix, can_multiply_two_numbers)
{
  char* str = new char[255];
  str = "10*3";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(30, pol.calculate());
}
TEST(TPostfix, can_subtract_two_numbers)
{
  char str[] = "100-50";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(50, pol.calculate());
}
TEST(TPostfix, can_divide_two_numbers)
{
  char str[] = "10/5";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(2, pol.calculate());
}
TEST(TPostfix, can_calculate_all_operations)
{
  char str[] = "(1+3)-100*2/50";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(0, pol.calculate());
}
TEST(TPostfix, can_calculate_with_negative_numbers)
{
  char str[] = "100*2-(-100+30)";
  TPostfix pol(str);
  pol.Postfix();
  EXPECT_EQ(270, pol.calculate());
}

