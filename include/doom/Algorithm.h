#ifndef DOOM_CORE_LIB_ALGORITHM_H
#define DOOM_CORE_LIB_ALGORITHM_H

#include <functional>
#include <utility>


namespace doom {
namespace detail {

template<typename T, typename Comparator>
void bubble(T arr[], size_t N, Comparator comparator)
{
  for (size_t i = 0; i < N - 1; ++i)
    if (comparator(arr[i + 1], arr[i]))
      std::swap(arr[i], arr[i + 1]);
}

template<typename T, typename Comparator>
size_t selection(T arr[], size_t N, Comparator comparator)
{
  size_t index = 0;
  for (size_t i = 1; i <= N; ++i)
    if (comparator(arr[index], arr[i]))
      index = i;

  return index;
}

} // namespace detail


template<typename T, typename Comparator = std::less<T>>
void bubble_sort(T arr[], size_t N)
{
  Comparator comparator{};
  for (auto i = N; i > 1; --i)
    detail::bubble(arr, i, comparator);
}

template<typename T, typename Comparator = std::less<T>>
void selection_sort(T arr[], size_t N)
{
  Comparator comparator{};
  size_t index;
  for (auto i = N - 1; i >= 1; --i) {
    index = detail::selection(arr, i, comparator);
    std::swap(arr[index], arr[i]);
  }
}

} // namespace doom

#endif // DOOM_CORE_LIB_ALGORITHM_H