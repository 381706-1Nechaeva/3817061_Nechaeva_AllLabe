#include "arrlist.h"

#include <gtest.h>

TEST(TArrList, can_create_arrlist)
{
  ASSERT_NO_THROW(TArrList<int> a;);
}
TEST(TArrList, can_copy_arrlist)
{
  TArrList<int> a;
  ASSERT_NO_THROW(TArrList<int> b(a););
}
TEST(TArrList, can_put_and_get_from_the_begin_arrlist)
{
  TArrList<int> a;
  a.PutBegin(3);
  a.PutBegin(2);
  EXPECT_EQ(2, a.GetBegin());
  a.PutEnd(4);
  EXPECT_EQ(4, a.GetEnd());
}
TEST(TArrList, can_put_and_get_from_the_end_arrlist)
{
  TArrList<int> a;
  a.PutBegin(3);
  a.PutBegin(1);
  EXPECT_EQ(3, a.GetEnd());
  a.PutEnd(4);
  EXPECT_EQ(4, a.GetEnd());
}
TEST(TArrList, can_use_empty_check_true)
{
  TArrList<int> a;
  ASSERT_TRUE(a.IsEmpty());
}
TEST(TArrList, throws_when_try_to_get_begin_into_empty_arrlist)
{
  TArrList<int> a;
  ASSERT_ANY_THROW(a.GetBegin());
}
TEST(TArrList, throws_when_try_to_get_end_into_empty_arrlist)
{
  TArrList<int> a;
  ASSERT_ANY_THROW(a.GetEnd());
}
TEST(List, correct_empty_check)
{
  TArrList<int> a;
  a.PutBegin(3);
  ASSERT_FALSE(a.IsEmpty());
}
TEST(TArrList, can_put_and_get_from_any_place)
{
  TArrList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  a.PutTek(4, 1);
  EXPECT_EQ(4, a.GetTek(1));
}
TEST(TArrList, throw_when_put_and_get_from_any_place_into_empty_arrlist)
{
  TArrList<int> a;
  ASSERT_ANY_THROW(a.GetTek(2));
}
TEST(TArrList, throw_when_put_and_get_from_any_place_with_negativ_number)
{
  TArrList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  ASSERT_ANY_THROW(a.PutTek(4, -2));
  ASSERT_ANY_THROW(a.GetTek(-2));
}
TEST(TArrList, throw_when_put_and_get_from_any_place_with_large_number)
{
  TArrList<int> a;
  a.PutBegin(3);
  a.PutEnd(5);
  ASSERT_ANY_THROW(a.PutTek(4, 4));
  ASSERT_ANY_THROW(a.GetTek(4));
}
TEST(TArrList, throw_when_print_empty_arrlist)
{
  TArrList<int> a;
  ASSERT_ANY_THROW(a.PrintArr());
}
TEST(TArrList, throw_when_put_in_begin_into_full_arrlist)
{
  TArrList<int> a(2);
  a.PutBegin(12);
  a.PutBegin(10);
  ASSERT_ANY_THROW(a.PutBegin(2));
}
TEST(TArrList, throw_when_put_in_end_into_full_arrlist)
{
  TArrList<int> a(2);
  a.PutBegin(12);
  a.PutEnd(1);
  ASSERT_ANY_THROW(a.PutEnd(2));
}
TEST(TArrList, throw_when_put_in_any_place_into_full_arrlist)
{
  TArrList<int> a(3);
  a.PutBegin(12);
  a.PutEnd(1);
  a.PutTek(1, 1);
  ASSERT_ANY_THROW(a.PutTek(10,1));
}
TEST(List, correct_full_check)
{
  TArrList<int> a(2);
  a.PutBegin(3);
  a.PutEnd(12);
  ASSERT_TRUE(a.IsFull());
  a.GetBegin();
  ASSERT_FALSE(a.IsFull());
}

