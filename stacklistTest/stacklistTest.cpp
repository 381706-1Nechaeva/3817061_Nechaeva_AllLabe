#include "stacklist.h"

#include <gtest.h>

TEST(TStackList, can_create_Stacklist)
{
  ASSERT_NO_THROW(TStackList<int> a;);
}
TEST(TStackList, can_copy_list)
{
  TStackList<int> a;
  ASSERT_NO_THROW(TStackList<int> b(a););
}
TEST(TStackList, can_put_and_get_from_the_Stacklist)
{
  TStackList<int> a;
  a.Put(3);
  EXPECT_EQ(3, a.Get());
  a.Put(2);
  EXPECT_EQ(2, a.Get());
}
TEST(TStackList, can_use_empty_check_true)
{
  TStackList<int> a;
  ASSERT_TRUE(a.IsEmpty());
}
TEST(TStackArrList, throws_when_try_to_get_into_empty_Stacklist)
{
  TStackList<int> a;
  ASSERT_ANY_THROW(a.Get());
}
TEST(TStackList, correct_empty_check)
{
  TStackList<int> a;
  a.Put(3);
  ASSERT_FALSE(a.IsEmpty());
}
TEST(TStackList, can_get_size_of_stacklist)
{
  TStackList<int> a;
  a.Put(12);
  a.Put(13);
  a.PutTek(1, 1);
  a.Get();
  EXPECT_EQ(2, a.GetSize());
}



