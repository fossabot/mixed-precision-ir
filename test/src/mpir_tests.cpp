#include <version.hpp>
#include <gtest/gtest.h>

class VersionTest : public ::testing::Test {
	protected:

		 virtual void SetUp() {}

		 virtual void TearDown() {}

		 virtual void verify(int index) {
			 EXPECT_EQ(index, 10);
		 }
};

TEST_F(VersionTest, equals_10) {
	verify(10);
}
