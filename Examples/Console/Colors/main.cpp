#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>
#include <fmt/xchar.h>

#include <conio.h>

#include <string>
#include <vector>
#include <cstdio>

int _tmain( int argc, _TCHAR* argv[] )
{
    printf( u8"π мир\n" );
    fmt::print( "Hello, {} world!\n", "virulent" );
    fmt::print(
        fmt::fg( fmt::color::crimson ) | fmt::emphasis::bold,
        "Hello, {}!\n", "peace"
    );
    std::vector<std::string> v {
        "Relinquo", "vos", "liberos", "ab", "utroque", "homine"
    };
    fmt::print( fg(
        fmt::color::steel_blue) | fmt::emphasis::italic, "A vector: {}\n", v
    );
    fmt::print(
        fg( fmt::color::floral_white ) | bg( fmt::color::slate_gray ) |
        fmt::emphasis::underline, "(Russian) Hello, {}!\n", u8"мир"
    );
    //fmt::print( fg( fmt::color::steel_blue) | fmt::emphasis::italic,
    //            u8"(Chinese) Hello, {}!\n", u8"π 和平" );
    fmt::print( "\nPress any key" );
    getch();
	return 0;
}


