#include "list.h"

#include <gtest.h>

TEST(TList, can_create_list)
{
  ASSERT_NO_THROW(TList<int> a;);
}
TEST(TList, can_copy_list)
{
  TList<int> a;
  ASSERT_NO_THROW(TList<int> b(a););
}
TEST(TList, can_put_and_get_from_the_begin_list)
{
  TList<int> a;
  a.PutBegin(3);
  EXPECT_EQ(3, a.GetBegin());
  a.PutBegin(2);
  EXPECT_EQ(2, a.GetBegin());
}
TEST(TList, can_put_and_get_from_the_end_list)
{
  TList<int> a;
  a.PutBegin(3);
  a.PutBegin(1);
  EXPECT_EQ(3, a.GetEnd());
  a.PutEnd(4);
  EXPECT_EQ(4, a.GetEnd());
}
TEST(List, can_use_empty_check_true)
{
  TList<int> a;
  ASSERT_TRUE(a.IsEmpty());
}
TEST(List, throws_when_try_to_get_begin_into_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.GetBegin());
}
TEST(List, throws_when_try_to_get_end_into_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.GetEnd());
}
TEST(List, correct_empty_check)
{
  TList<int> a;
  a.PutBegin(3);
  ASSERT_FALSE(a.IsEmpty());
}
