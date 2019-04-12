#include "point.h"

#include <gtest.h>
TEST(TPoint, can_create_point)
{
  ASSERT_NO_THROW(TPoint A);
}
TEST(TPoint, can_get_first_coordinate)
{
  TPoint A(3, 5);
  EXPECT_TRUE(3 == A.GetX());
}
TEST(TPoint, can_get_last_coordinate)
{
  TPoint B(3, 65);
  EXPECT_TRUE(65 == B.GetY());
}
TEST(TPoint, can_set_first_coordinate)
{
  TPoint B(3, 65);
  ASSERT_NO_THROW(B.SetX(32));
  EXPECT_TRUE(32 == B.GetX());
}
TEST(TPoint, can_set_last_coordinate)
{
  TPoint B(3, 65);
  ASSERT_NO_THROW(B.SetY(32));
  EXPECT_TRUE(32 == B.GetY());
}