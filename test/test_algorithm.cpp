#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>

#include <vector>
#include <algorithm>
#include <numeric>

#include "doom/Algorithm.h"

template<typename T>
struct SortTestFixture {

  using Sorter = std::function<void(T arr[], size_t N)>;

  SortTestFixture()
    : test_vec_(1000)
  {
    // 生成逆序数组
    std::iota(test_vec_.begin(), test_vec_.end(), 0);
    std::reverse(test_vec_.begin(), test_vec_.end());
  }

  bool test_sort(Sorter sorter)
  {
    sorter(test_vec_.data(), test_vec_.size());

    return std::is_sorted(test_vec_.begin(), test_vec_.end());
  }

  bool test_stl_sort()
  {
    std::sort(test_vec_.begin(), test_vec_.end());

    return std::is_sorted(test_vec_.begin(), test_vec_.end());
  }

  std::vector<T> test_vec_;
};


TEMPLATE_TEST_CASE_METHOD(SortTestFixture,
                          "bubble sort",
                          "[template][bubble sort]",
                          char, int, float, double) {

  REQUIRE( SortTestFixture<TestType>{}.test_sort(doom::bubble_sort<TestType>) );
}

TEMPLATE_TEST_CASE_METHOD(SortTestFixture,
                          "selection sort",
                          "[template][selection sort]",
                          char, int, float, double) {

  REQUIRE( SortTestFixture<TestType>{}.test_sort(doom::selection_sort<TestType>) );
}