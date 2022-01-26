#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdexcept>

#if defined(__BORLANDC__) && defined(__clang__) && defined(_WIN64)
# pragma comment(lib, "compiler_rt") // __udivti3, __umodti3
#endif

//#pragma comment( lib, "fmt" )

//#define _isatty isatty

#include <fmt/core.h>

#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
    fmt::print("Hello, {} World! (using FMT_HEADER_ONLY)\n", "cruel");
    getch();
	return 0;
}

