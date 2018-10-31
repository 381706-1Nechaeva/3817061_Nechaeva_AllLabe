#include "vector.h"

#include <gtest.h>

TEST(TVector, can_create_bitfield_with_positive_length)
{
    int d[3] = { 3, 2, 1 };
	ASSERT_NO_THROW( TVector<int> D(d, 3););
}

