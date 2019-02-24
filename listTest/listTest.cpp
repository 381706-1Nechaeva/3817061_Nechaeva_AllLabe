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
TEST(TList, can_use_empty_check_true)
{
  TList<int> a;
  ASSERT_TRUE(a.IsEmpty());
}
TEST(TList, throws_when_try_to_get_begin_into_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.GetBegin());
}
TEST(TList, throws_when_try_to_get_end_into_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.GetEnd());
}
TEST(TList, correct_empty_check)
{
  TList<int> a;
  a.PutBegin(3);
  ASSERT_FALSE(a.IsEmpty());
}
TEST(TList, can_put_and_get_from_any_place)
{
  TList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  a.PutTek(4, 1);
  EXPECT_EQ(4, a.GetTek(1));
}
TEST(TList, throw_when_put_and_get_from_any_place_into_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.GetTek(2));
}
TEST(TList, throw_when_put_and_get_from_any_place_with_negativ_number)
{
  TList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  ASSERT_ANY_THROW(a.PutTek(4,-2));
  ASSERT_ANY_THROW(a.GetTek(-2));
}
TEST(TList, throw_when_put_and_get_from_any_place_with_large_number)
{
  TList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  ASSERT_ANY_THROW(a.PutTek(4, 4));
  ASSERT_ANY_THROW(a.GetTek(4));
}
TEST(TList, throw_when_print_empty_list)
{
  TList<int> a;
  ASSERT_ANY_THROW(a.Print());
}
TEST(TList, correct_count_method)
{
  TList<int> a;
  a.PutBegin(3);
  a.PutEnd(10);
  a.PutTek(1,1);
  a.GetBegin();
  EXPECT_EQ(2, a.Count());
}



