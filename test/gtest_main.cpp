#include <gtest/gtest.h>
#include "myabs.hpp"

/**
 * @brief This function calculates the absolute value of an integer.
 *
 * @param num The integer for which the absolute value is to be calculated.
 *
 * @return The absolute value of the input integer.
 *
 * @note This function assumes that the input integer is within the range of a 32-bit signed integer.
 *
 * @code
 * // Example usage:
 * int num = -5;
 * int absNum = myabs(num); // absNum will be 5
 * @endcode
 */
TEST(AbsTest, MinusValue){
	EXPECT_EQ(5, myabs(-5));
}


TEST(AbsTest, PlusValue){
	EXPECT_EQ(5, myabs(5));
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
