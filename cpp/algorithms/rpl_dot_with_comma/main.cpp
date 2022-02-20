#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

std::string replace_dot_with_comma( const double &value )
{
  std::string result;
  char buf[40];
  memset(buf, 0, sizeof(buf));
  snprintf(buf, 40, "%lf", value);
  result.append(buf);
  std::replace(result.begin(), result.end(), '.', ',');
  return result;
}

int main()
{
  double d = 38.708;
  std::cout << replace_dot_with_comma(d) << std::endl;
    return 0;
}
