#include "stack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> A(3););
}
TEST(TStack, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> A(-4););
}
TEST(TStack, can_put_and_get_element_into_stack)
{
  TStack<int> A(3);
  A.Put(10);
  EXPECT_EQ(10, A.Get());
}
TEST(TStack, throws_when_get_element_into_empty_stack)
{
  TStack<int> A(3);
  ASSERT_ANY_THROW(A.Get());
}
TEST(TStack, throws_when_put_element_into_full_stack)
{
  TStack<int> A(2);
  A.Put(10);
  A.Put(2);
  ASSERT_ANY_THROW(A.Put(10););
}
TEST(TStack, can_use_method_IsEmpty)
{
  TStack<int> A(2);
  EXPECT_EQ(1, A.IsEmpty());
  A.Put(3);
  EXPECT_NE(1, A.IsEmpty());
}
TEST(TStack, can_use_method_IsFull)
{
  TStack<int> A(2);
  EXPECT_EQ(0, A.IsFull());
  A.Put(3);
  A.Put(4);
  EXPECT_NE(0, A.IsFull());
}




