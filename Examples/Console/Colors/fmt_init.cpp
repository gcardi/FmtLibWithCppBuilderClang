//---------------------------------------------------------------------------

#pragma hdrstop

#include "fmt_init.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__attribute__((constructor))
void winsane_init_()
{
    static EnableVirtualTermProcessing vtp;
    if ( vtp.Failed() ) {
#if defined( _UNICODE )
        wprintf
#else
        printf
#endif
        (
            _T( "Error initializind VTP: %s\n" ),
            vtp.GetErrorString().c_str()
        );
    }
}
