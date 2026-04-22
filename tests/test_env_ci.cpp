#include <gtest/gtest.h>
#include <limits>
#include <multiply/multiply.h>

using namespace test_env_ci;

TEST(test_env_ci, positive_numbers) {
  EXPECT_EQ(6, multiply(2, 3));
  EXPECT_EQ(25, multiply(5, 5));
}

TEST(test_env_ci, negative_numbers) {
  EXPECT_EQ(-6, multiply(-2, 3));
  EXPECT_EQ(-6, multiply(2, -3));
  EXPECT_EQ(6, multiply(-2, -3));
}

TEST(test_env_ci, with_zero) {
  EXPECT_EQ(0, multiply(0, 100));
  EXPECT_EQ(0, multiply(-50, 0));
  EXPECT_EQ(0, multiply(0, 0));
}

TEST(test_env_ci, with_one) {
  EXPECT_EQ(42, multiply(42, 1));
  EXPECT_EQ(42, multiply(1, 42));
}

TEST(test_env_ci, large_numbers) {
  EXPECT_EQ(1000000, multiply(1000, 1000));
  EXPECT_EQ(838102050, multiply(12345, 67890));
}

TEST(test_env_ci, boundary_values) {
  const int max_int = std::numeric_limits<int>::max();
  const int min_int = std::numeric_limits<int>::min();

  EXPECT_EQ(max_int, multiply(max_int, 1));
  EXPECT_EQ(min_int, multiply(min_int, 1));

  EXPECT_EQ(-max_int, multiply(max_int, -1));
  // Осторожно: min_int * -1 может вызвать переполнение
  // EXPECT_EQ(-min_int, multiply(min_int, -1));
}

TEST(test_env_ci, mixed_sign_large_numbers) {
  EXPECT_EQ(-1000000, multiply(-1000, 1000));
  EXPECT_EQ(1500000, multiply(-1500, -1000));
}
