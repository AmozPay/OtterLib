#ifndef TEST_HPP
#define TEST_HPP
#include "OtterCore.hpp"

#include <gtest/gtest.h>

class intTest {
  public:
    intTest(int dt) { _dt = dt; }

    ~intTest(){};

    int getDt() const { return _dt; };

    void setDt(int dt) { _dt = dt; };

  private:
    int _dt;
};

class sparse_arrayTest : public ::testing::Test {
  protected:
    void SetUp() override
    {
        f2.insert_at(0, 42);
        f3.insert_at(0, 41);
        f3.insert_at(1, 42);
        f3.insert_at(3, 43);
    };

    Otter::Core::sparse_array<int> f0;
    Otter::Core::sparse_array<int> f1;
    Otter::Core::sparse_array<int> f2;
    Otter::Core::sparse_array<int> f3;
    Otter::Core::sparse_array<intTest> f4;
};

#endif /* TEST_HPP */
