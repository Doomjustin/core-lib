#ifndef DOOM_CORE_LIB_UTILITY_H
#define DOOM_CORE_LIB_UTILITY_H

#include "TypeTraits.h"


namespace doom {

/**
 * @brief 栈创建单例对象(单例工厂)
 *
 * @tparam T
 * @tparam Args
 * @return T*
 */
template<typename T, typename... Args,
      is_singletonable<T, Args...> = true>
T* static_singleton(Args&&... args)
{
  static T singleton { std::forward<Args>(args)... };

  return &singleton;
}

} // namespace doom

#endif // DOOM_CORE_LIB_UTILITY_H