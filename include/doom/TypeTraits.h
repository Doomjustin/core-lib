#ifndef DOOM_CORE_LIB_TYPE_TRAITS_H
#define DOOM_CORE_LIB_TYPE_TRAITS_H

#include <cstddef>
#include <type_traits>


namespace doom {

template<bool Condtion, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> {
  using type = T;
};

template<bool Condition, typename T = void>
using enable_if_t = typename enable_if<Condition, T>::type;


template<bool Condition, typename T, typename U>
struct conditional {
  using type = T;
};

template<typename T, typename U>
struct conditional<false, T, U> {
  using type = U;
};

template<bool Conditional, typename T, typename U>
using conditional_t = typename Conditional<Condition, T, U>::type;


template<unsigned N, typename... Cases>
struct select;

template<unsigned N, typename T, typename... Cases>
struct select<N, T, Cases...>: select<N - 1, Cases...> {};

template<typename T, typename... Cases>
struct select<0, T, Cases...> {
  using type = T;
};

template<unsigned N, typename... Cases>
using select_t = typename select<N, Cases...>::type;


template<typename T, size_t N>
size_t array_size(T (&)[N])
{
  return N;
}


// 是否能单例化
template<typename T, typename... Args>
using is_singletonable = std::enable_if_t<
      !std::is_copy_assignable_v<T> &&
      !std::is_copy_constructible_v<T> &&
      std::is_constructible_v<T, Args...>, bool>;

} // namespace doom

#endif // DOOM_CORE_LIB_TYPE_TRAITS_H