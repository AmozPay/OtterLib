#ifndef TEST_HPP
#define TEST_HPP
#include "OtterCore.hpp"

#include <gtest/gtest.h>

class intTest {
  public:
    intTest(int dt) { _dt = dt; }

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

class SystTest : public ::testing::Test {
  protected:
    void SetUp() override
    {
        s2.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s2.init" << std::endl; }),
                          Otter::Core::SystemManager::Phase::init);

        s3.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s3.init" << std::endl; }),
                          Otter::Core::SystemManager::Phase::init);
        s3.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s3.update" << std::endl; }),
                          Otter::Core::SystemManager::Phase::update);

        s4.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s4.first"; }),
                          Otter::Core::SystemManager::Phase::init);
        s4.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s4.third"; }),
                          Otter::Core::SystemManager::Phase::init);
        s4.registerSystem(([](Otter::Core::Orchestrator& reg) { std::cout << "s4.second"; }),
                          Otter::Core::SystemManager::Phase::update);
    }

    Otter::Core::SystemManager s1;
    Otter::Core::SystemManager s2;
    Otter::Core::SystemManager s3;
    Otter::Core::SystemManager s4;
};

#endif /* TEST_HPP */
