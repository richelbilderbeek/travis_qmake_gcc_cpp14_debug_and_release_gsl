#include <cassert>
#include <iostream>

#define GSL_UNENFORCED_ON_CONTRACT_VIOLATION

#include <gsl/gsl>

//C++14
auto f() noexcept {
  return "Hello world\n";
}

int main()
{
  try
  {
    #ifdef NDEBUG
    std::clog << "Release mode" << '\n';
    std::clog << "Assert" << '\n';
    assert(1==2);
    std::clog << "expects" << '\n';
    Expects(1==2);
    std::clog << "ensures" << '\n';
    Ensures(1==2);
    #else
    std::clog << "Debug mode" << '\n';
    assert(1+1==2);
    Expects(1+1==2);
    Ensures(1+1==2);

    std::clog << "1" << '\n';
    Expects(1==2);
    std::clog << "2" << '\n';
    Ensures(1==2);
    #endif
    f();
  }
  catch (gsl::fail_fast& e)
  {
    std::cerr << "fast_fail: " << e.what() << '\n';
    return 1;
  }
  catch (std::exception& e)
  {
    std::cerr << "std::exception: " << e.what() << '\n';
    return 1;
  }
  catch (...)
  {
    std::cerr << "Unknown error\n";
    return 1;
  }
  std::clog << "Done" << '\n';
}
