#ifndef DOOM_CORE_LIB_TYPE_TRAITS_H
#define DOOM_CORE_LIB_TYPE_TRAITS_H


namespace doom {

template<bool Condtion, typename T>
struct enable_if {};

template<typename T>
struct enable_if<false, T> {
  using type = T;
};

template<bool Condition, typename T>
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


} // namespace doom

#endif // DOOM_CORE_LIB_TYPE_TRAITS_H