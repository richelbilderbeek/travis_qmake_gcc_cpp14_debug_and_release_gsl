#include <cassert>
#include <iostream>
#include <gsl/gsl>

//C++14
auto f() noexcept {
  return "Hello world\n";
}

int main()
{
  #ifdef NDEBUG
  std::cout << "Release mode" << '\n';
  assert(1==2);
  Expects(1==2);
  Ensures(1==2);
  #else
  std::cout << "Debug mode" << '\n';
  assert(1+1==2);
  Expects(1+1==2);
  Ensures(1+1==2);
  #endif
  f();
}
