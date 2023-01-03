#include <semver.hpp>
#include <gtest/gtest.h>

class SemverTest : public ::testing::Test {
	protected:

		 virtual void SetUp() {}

		 virtual void TearDown() {}

		 virtual void verify(int index) {
			 EXPECT_EQ(index == 10);
		 }
};

TEST_F(SemverTest, equals_10) {
	verify(10);
}
