#include "test.h"
#include <stdio.h>
#include "subprocess.hpp"
#include <sstream>

using namespace std;

TEST(asserts)
{
  ASSERT(true);
  ASSERT_FALSE(false);
  ASSERT_THROW(throw std::runtime_error("error"), std::runtime_error);
}

TEST(failures)
{
  subprocess::popen cmd("./failing_tests", {});
  string line;

  while (std::getline(cmd.stdout(), line))
  {
    ASSERT(line.find("🡆") != std::string::npos);
    std::getline(cmd.stdout(), line);
    ASSERT(line.find("✘") != std::string::npos);
  }

  // Returns non-zero and counts the number of failures
  ASSERT(cmd.wait()==4);
}

TEST(passing)
{
  subprocess::popen cmd("./passing_tests", {});
  string line;

  while (std::getline(cmd.stdout(), line))
  {
    ASSERT(line.find("🡆") != std::string::npos);
    std::getline(cmd.stdout(), line);
    ASSERT(line.find("✔") != std::string::npos);
  }

  ASSERT(cmd.wait()==0);
}

TEST(debug)
{
  subprocess::popen cmd("./debug_tests", {});
  stringstream outs;
  outs << cmd.stdout().rdbuf();
  string out = outs.str();
  ASSERT(out.find("debug1") != std::string::npos);
  ASSERT(out.find("debug2") != std::string::npos);
  ASSERT(out.find("debug2") != std::string::npos);

  ASSERT(cmd.wait()==0);
}
