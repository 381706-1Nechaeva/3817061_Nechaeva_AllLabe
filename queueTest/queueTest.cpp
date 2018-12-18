#include "queue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> A(3););
}
TEST(TQueue, throws_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> A(-5););
}
TEST(TQueue, can_put_and_get_element_from_queue)
{
  TQueue<int> A(3);
  A.Put(3);
  A.Put(2);
  EXPECT_EQ(3, A.Get());
}
TEST(TQueue, throws_when_try_to_put_element_into_full_queue)
{
  TQueue<int> A(3);
  A.Put(3);
  A.Put(2);
  A.Put(3);
  ASSERT_ANY_THROW( A.Put(5));
}
TEST(TQueue, throws_when_try_to_get_element_from_empty_queue)
{
  TQueue<int> A(3);
  ASSERT_ANY_THROW(A.Get());
}