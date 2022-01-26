//---------------------------------------------------------------------------

#ifndef fmt_initH
#define fmt_initH

#include <windows.h>
#include <fcntl.h>
#include <io.h>

#include <string>
#include <system_error>

class EnableVirtualTermProcessing {
public:
    EnableVirtualTermProcessing() :
        stdoutHandle_ { ::GetStdHandle( STD_OUTPUT_HANDLE ) }
    {
        DWORD OutMode {};

        if ( stdoutHandle_ == INVALID_HANDLE_VALUE ) {
            //throw std::exception( GetLastErrorString().c_str() );
            fail_ = true;
            return;
        }

        if ( !GetConsoleMode( stdoutHandle_, &OutMode ) ) {
            // throw std::exception( GetLastErrorString().c_str() );
            fail_ = true;
            return;
        }

        outModeInit_ = OutMode;

        OutMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

        if ( !SetConsoleMode( stdoutHandle_, OutMode ) ) {
            //throw std::exception( GetLastErrorString().c_str() );
            fail_ = true;
        }
    }

    ~EnableVirtualTermProcessing() {
        // Reset colors
        wprintf( L"\x1b[0m" );

        // Reset console mode
        ::SetConsoleMode( stdoutHandle_, outModeInit_ );
    }

    EnableVirtualTermProcessing( EnableVirtualTermProcessing const & ) = delete;
    EnableVirtualTermProcessing operator=( EnableVirtualTermProcessing const & ) = delete;

    inline bool Failed() const { return fail_; }

    using StdStrType =
#if defined( _UNICODE )
        std::wstring
#else
        std::string
#endif
    ;

#if 0
    static StdStrType GetErrorString()
    {
        DWORD errorMessageID = ::GetLastError();
        if ( errorMessageID ) {
            return std::system_category().message( errorMessageID );
        }
        else {
            return {};
        }
    }
#else
    static StdStrType GetErrorString()

    {
        auto errorMessageID = ::GetLastError();
        if( !errorMessageID ) {
            return {};
        }

        PTCHAR Buffer = nullptr;

        auto Size =
            ::FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                // https://devblogs.microsoft.com/oldnewthing/20071128-00/?p=24353
                FORMAT_MESSAGE_IGNORE_INSERTS,
                nullptr, errorMessageID,
                MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), (LPSTR)&Buffer,
                0, nullptr
            );

        StdStrType Msg( Buffer, Size );
        ::LocalFree( Buffer );
        return Msg;
    }
#endif
private:
    bool fail_ {};
    HANDLE stdoutHandle_ {};
    DWORD outModeInit_ {};
};

//---------------------------------------------------------------------------
#endif
