#include "hashlist.h"

#include <gtest.h>

TEST(THashTable, can_create_table)
{
  ASSERT_NO_THROW(THashTable<int> A(10));
}
TEST(THashTable, throw_when_create_table_with_negative)
{
  ASSERT_ANY_THROW(THashTable<int> A(-5));
}
TEST(THashTable, can_copy_table)
{
  THashTable<int> A(10);
  ASSERT_NO_THROW(THashTable<int> B(A));
}
TEST(THashTable, can_put_elem_on_table)
{
  THashTable<int> A(10);
  A.Put("a", 44);
  ASSERT_TRUE(A.Find("a") == 44);
}
TEST(THashTable, can_del_elem_on_table)
{
  THashTable<int> A(10);
  A.Put("a", 44);
  ASSERT_TRUE(A.Find("a") == 44);
  A.Del("a");
  ASSERT_TRUE(A.Find("a") == 0);
}
TEST(THashTable, can_get_size_of_table)
{
  THashTable<int> A(10);
  ASSERT_TRUE(A.GetSize() == 10);
}
TEST(THashTable, can_set_size_of_table)
{
  THashTable<int> A(10);
  ASSERT_TRUE(A.GetSize() == 10);
  A.SetSize(16);
  ASSERT_TRUE(A.GetSize() == 16);
}