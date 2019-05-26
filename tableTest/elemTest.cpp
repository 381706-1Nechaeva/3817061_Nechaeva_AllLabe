#include "elem.h"

#include <gtest.h>

TEST(TElem, can_create_the_element)
{
  ASSERT_NO_THROW(TElem<int> A);
}
TEST(TElem, can_copy_element)
{
  TElem<int> B("d", 3);
  ASSERT_NO_THROW(TElem<int> A(B));
}
TEST(TElem, can_assign_element)
{
  TElem<int> B("d", 3), A;
  ASSERT_NO_THROW(A=B);
  EXPECT_EQ(3, A.GetData());
}
TEST(TElem, throw_when_assign_the_same_elements)
{
  TElem<int> B("d", 3), A(B);
  ASSERT_ANY_THROW(A = B);
}
TEST(TElem, can_compare_two_elements)
{
  TElem<int> B("d", 3), A(B);
  EXPECT_TRUE(A == B);
  A.SetKey("a");
  EXPECT_FALSE(A == B);
  EXPECT_TRUE(A != B);
}
TEST(TElem, can_set_and_get_key)
{
  TElem<int> B("d", 3);
  EXPECT_EQ("d", B.GetKey());
  ASSERT_NO_THROW(B.SetKey("a"));
  EXPECT_EQ("a", B.GetKey());
}
TEST(TElem, can_set_and_get_data)
{
  TElem<int> B("d", 3);
  EXPECT_EQ(3, B.GetData());
  ASSERT_NO_THROW(B.SetData(5));
  EXPECT_EQ(5, B.GetData());
}

