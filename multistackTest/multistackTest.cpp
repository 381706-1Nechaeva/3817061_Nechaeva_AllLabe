#include "multistack.h"

#include <gtest.h>

TEST(TMStack, can_create_multistack_with_positive_size)
{
  ASSERT_NO_THROW(TMStack<int> A(3,4););
}
TEST(TMStack, throws_when_create_multistack_with_negative_size)
{
  ASSERT_ANY_THROW(TMStack<int> A(-4,4););
}
TEST(TMStack, throws_when_create_multistack_with_negative_count)
{
  ASSERT_ANY_THROW(TMStack<int> A(3, -4););
}
TEST(TMStack, can_copy_multistack)
{
  TMStack<int> A(6,5);
  ASSERT_NO_THROW(TMStack<int> B(A));
}
TEST(TMStack, can_put_and_get_from_multistack)
{
  TMStack<int> A(6, 5);
  A.Put(1, 5);
  EXPECT_EQ(5, A.Get(1));
}
TEST(TMStack, throws_when_try_to_get_elem_into_empty_multistack)
{
  TMStack<int> A(6, 5);
  ASSERT_ANY_THROW(A.Get(1));
}
TEST(TMStack, repuck_method_correct_changes_size_full_stack)
{
  TMStack<int> A(6, 3);
  EXPECT_EQ(2, A.GetSizeSt(0));
  A.Put(0, 2);
  A.Put(0, 4);
  A.Put(0, 7);
  EXPECT_EQ(3, A.GetSizeSt(0));
}
TEST(TMStack, correct_isfull_method)
{
  TMStack<int> A(6, 3);
  A.Put(0, 2);
  A.Put(0, 4);
  ASSERT_TRUE(A.IsFull(0));
}
TEST(TMStack, correct_isempty_method)
{
  TMStack<int> A(6, 3);
  ASSERT_TRUE(A.IsEmpty(0));
}
TEST(TMStack, can_get_elem_into_multictack)
{
  TMStack<int> A(4, 2);
  A.Put(1, 3);
  ASSERT_FALSE(A.IsEmpty(1));
  A.Get(1);
  ASSERT_TRUE(A.IsEmpty(1));
}

