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
  std::clog << "Release mode" << '\n';
  std::clog << "assert" << '\n';
  assert(1==2);
  std::clog << "Expects" << '\n';
  Expects(1==2);
  std::clog << "Ensures" << '\n';
  Ensures(1==2);
  #else
  std::clog << "Debug mode" << '\n';
  assert(1+1==2);
  Expects(1+1==2);
  Ensures(1+1==2);
  #endif
  f();
}
