#include "sorttable.h"

#include <gtest.h>

TEST(TSortTable, can_create_table)
{
  ASSERT_NO_THROW(TSortTable<int> A);
}
TEST(TSortTable, throw_when_create_table_with_negative_size)
{
  ASSERT_ANY_THROW(TSortTable<int> A(-5));
}
TEST(TSortTable, can_copy_table)
{
  TSortTable<int> B(5);
  ASSERT_NO_THROW(TSortTable<int> A(B));
}
TEST(TSortTable, can_put_and_get__element_on_table)
{
  TSortTable<int> B(5);
  ASSERT_NO_THROW(B.Put("a",4));
  EXPECT_EQ(1, B.GetCount());
  EXPECT_EQ(4, B["a"]);
}
TEST(TSortTable, throw_when_delete_element_on_empty_table)
{
  TSortTable<int> B(5);
  ASSERT_ANY_THROW(B.Del("a"));
}
TEST(TSortTable, can_delete_element_on_table)
{
  TSortTable<int> B(5);
  B.Put("a", 4);
  EXPECT_EQ(1, B.GetCount());
  ASSERT_NO_THROW(B.Del("a"));
  EXPECT_EQ(0, B.GetCount());
}
TEST(TSortTable, can_change_size_of_full_table)
{
  TSortTable<int> B(1);
  B.Put("a", 4);
  EXPECT_EQ(1, B.GetSize());
  B.Put("d", 56);
  EXPECT_EQ(2, B.GetSize());
}





