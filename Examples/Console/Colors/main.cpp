#pragma hdrstop
#pragma argsused

#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#pragma comment(lib, "compiler_rt") // __udivti3, __umodti3

#include <string_view>
//#define FMT_USE_STRING_VIEW

#include <fmt/core.h>
//#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>
#include <fmt/xchar.h>

#include <conio.h>

#include <string>
#include <vector>
#include <cstdio>

class EnableVirtualTermProcessing {
public:
    EnableVirtualTermProcessing() { setupConsole(); }
    ~EnableVirtualTermProcessing() { restoreConsole(); }
    EnableVirtualTermProcessing( EnableVirtualTermProcessing const & ) = delete;
    EnableVirtualTermProcessing operator=( EnableVirtualTermProcessing const & ) = delete;
private:
#ifdef _WIN32
    HANDLE stdoutHandle {};
    DWORD outModeInit {};

    void setupConsole(void) {
        DWORD outMode = 0;
        stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        if(stdoutHandle == INVALID_HANDLE_VALUE) {
            exit(GetLastError());
        }

        if(!GetConsoleMode(stdoutHandle, &outMode)) {
            exit(GetLastError());
        }

        outModeInit = outMode;

        // Enable ANSI escape codes
        outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        if(!SetConsoleMode(stdoutHandle, outMode)) {
            exit(GetLastError());
        }
    }

    void restoreConsole(void) {
        // Reset colors
        wprintf(L"\x1b[0m");

        // Reset console mode
        if(!SetConsoleMode(stdoutHandle, outModeInit)) {
            exit(GetLastError());
        }
    }
    #else
    void setupConsole(void) {}

    void restoreConsole(void) {
        // Reset colors
        wprintf(L"\x1b[0m");
    }
    #endif
};

int _tmain(int argc, _TCHAR* argv[])
{
    EnableVirtualTermProcessing Vtp{};

    fmt::print( _T( "Hello, {} World!\n" ), _T( "virulent" ) );
    fmt::print( fmt::fg( fmt::color::crimson ) | fmt::emphasis::bold,
               _T( "Hello, {}!\n" ), _T( "u" ));
#if 0
    //auto out = fmt::output_file("guide.txt");
    //fmt::print("{}\n",v);
    fmt::print( fg( fmt::color::floral_white ) | bg( fmt::color::slate_gray ) |
                fmt::emphasis::underline, _T( "Hello, {}!\n" ), _T( "???" ) );
    fmt::print( fg( fmt::color::steel_blue) | fmt::emphasis::italic,
                _T( "Hello, {}!\n" ), _T( "??" ) );
    fmt::print( _T( "\nPress any key" ) );
#endif
    getch();
	return 0;
}


