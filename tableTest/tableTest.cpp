#include "table.h"

#include <gtest.h>

TEST(TTable, can_create_table)
{
  ASSERT_NO_THROW(TTable<int> A);
}
TEST(TTable, throw_when_negative_size)
{
  ASSERT_ANY_THROW(TTable<int> A(-5));
}
TEST(TTable, can_copy_table)
{
  TTable<int> A(3);
  ASSERT_NO_THROW(TTable<int> B(A));
}
TEST(TTable, can_get_size_of_table)
{
  TTable<int> A(3);
  EXPECT_EQ(3, A.GetSize());
}
TEST(TTable, can_get_count_of_table)
{
  TTable<int> A(3);
  A.Put("b", 4);
  EXPECT_EQ(1, A.GetCount());
}
TEST(TTable, can_set_size_of_table)
{
  TTable<int> A(3);
  A.Put("b", 4);
  EXPECT_EQ(3, A.GetSize());
  ASSERT_NO_THROW(A.SetSize(5));
  EXPECT_EQ(1, A.GetCount());
  EXPECT_EQ(5, A.GetSize());
}
TEST(TTable, can_put_and_get_data_on_table)
{
  TTable<int> A(3);
  ASSERT_NO_THROW(A.Put("b", 4));
  EXPECT_EQ(4, A["b"]);
}
TEST(TTable, can_delete_element_on_table)
{
  TTable<int> A(3);
  A.Put("b", 4);
  ASSERT_NO_THROW(A.Del("b"));
}
TEST(TTable, throw_when_put_element_on_full_table)
{
  TTable<int> A(1);
  A.Put("b", 4);
  ASSERT_ANY_THROW(A.Put("d",3));
}
TEST(TTable, throw_when_delete_element_on_empty_table)
{
  TTable<int> A(1);
  ASSERT_ANY_THROW(A.Del("d"));
}