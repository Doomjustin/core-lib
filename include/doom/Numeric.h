#ifndef DOOM_CORE_LIB_NUMERIC_H
#define DOOM_CORE_LIB_NUMERIC_H


namespace doom {

template<typename T>
constexpr T factorial(T N)
{
  return N < 2 ? 1 : N * factorial(N - 1);
}


} // namespace doom

#endif // DOOM_CORE_LIB_NUMERIC_H