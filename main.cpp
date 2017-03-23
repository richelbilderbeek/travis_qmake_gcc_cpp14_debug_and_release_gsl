//#define OPTION_1
//#define OPTION_2
#define OPTION_3

#ifdef OPTION_1

//#define GSL_UNENFORCED_ON_CONTRACT_VIOLATION
#include <gsl/gsl_assert>


int main()
{
  Expects(1 + 1 == 3);
}

#endif // OPTION_1

#ifdef OPTION_2

#include <cassert>
#include <iostream>

//#define GSL_UNENFORCED_ON_CONTRACT_VIOLATION

#include <gsl/gsl_assert>

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
    Expects(1 + 1 == 3);
    //Expects(1 == 2);
    std::clog << "ensures" << '\n';
    Ensures(1 + 1 == 2);
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
#endif // OPTION_2


#ifdef OPTION_3

#include <iostream>
#include <gsl/gsl_assert>

int main()
{
  try
  {
    Expects(1 + 1 == 3);
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
}

#endif // OPTION_3
