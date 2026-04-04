#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(CheckTask3, test_regular)
{
  ASSERT_EQ(task3("x+2x+1-2=6+x-1"), "x=3");
}

TEST(CheckTask3, test_infinite)
{
  ASSERT_EQ(task3("x=x"), "Infinite");
}

TEST(CheckTask3, test_no)
{
  ASSERT_EQ(task3("10x=1"), "NO");
}

TEST(CheckTask4, test_regular)
{
  ASSERT_EQ(task4({ "12:10", "11:03", "8:30", "13:00", "11:20" }), 17);
}

TEST(CheckTask4, test_2_same)
{
  ASSERT_EQ(task4({ "12:10", "12:10", "11:03", "8:30", "13:00", "11:20" }), 0);
}

TEST(CheckTask5, test_regular)
{
  // Can reach
  ASSERT_TRUE(task5(1, 1));
  ASSERT_TRUE(task5(5, 7));

  // Cant reach
  ASSERT_FALSE(task5(0, 0));
  ASSERT_FALSE(task5(3, 6));
}

TEST(CheckTask6, test_regular)
{
  ASSERT_EQ(task6("5+10-20"), -5);
  ASSERT_EQ(task6("6-1+30"), 35);
}

TEST(CheckTask6, test_unary_minus)
{
  ASSERT_EQ(task6("-5"), -5);
  ASSERT_EQ(task6("-6-1+30"), 23);
}

TEST(CheckTask6, test_unary_plus)
{
  try
  {
    task6("+1");
  }
  catch(std::invalid_argument& e)
  {
    return;
  }
  FAIL();
}

TEST(CheckTask6, test_parenthesis)
{
  ASSERT_EQ(task6("4+10-(-5-(5+10))"), 34);
}

TEST(CheckTask6, test_parenthesis_unary_minus)
{
  ASSERT_EQ(task6("-(-5-(5+10))"), 20);
}

TEST(CheckTask7, test_regular)
{
  ASSERT_EQ(task7(5), 5);
  ASSERT_EQ(task7(1), 2);
  ASSERT_EQ(task7(2), 3);
  ASSERT_EQ(task7(3), 3);
}

TEST(CheckTask8, test_regular)
{
  auto res = task8({
      { 10, 10 },
      { 0,  0  },
      { 5,  3  },
      { 10, 4  },
      { 3,  10 }
  });

  ASSERT_FALSE(res.size() != 3 || res[0].first != 10 || res[0].second != 10 || res[1].first != 0 || res[1].second != 0 || res[2].first != 10 || res[2].second != 4);
}
