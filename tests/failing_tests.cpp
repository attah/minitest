#include "test.h"

TEST(assert_false)
{
  ASSERT(false);
}

TEST(assert_false_true)
{
  ASSERT_FALSE(true);
}

TEST(wrong_throw)
{
  ASSERT_THROW(throw std::runtime_error("error"), std::out_of_range);
}

TEST(uncaught_throw)
{
  throw std::runtime_error("error");
}
