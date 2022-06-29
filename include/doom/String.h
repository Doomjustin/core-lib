#ifndef DOOM_CORE_LIB_STRING_H
#define DOOM_CORE_LIB_STRING_H

#include <string>
#include <string_view>


namespace doom {

std::string trim_left(const std::string& str)
{
  size_t pos_end = 0;
  for (; pos_end < str.size(); ++pos_end)
    if (!std::isspace(str[pos_end]))
      break;

  return str.substr(0, pos_end);
}



} // namespace doom

#endif // DOOM_CORE_LIB_STRING_H