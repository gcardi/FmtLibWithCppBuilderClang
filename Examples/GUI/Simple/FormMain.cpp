//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>

#include <chrono>

#include <fmt/core.h>
#include <fmt/xchar.h> // optional wchar_t support
#include <fmt/chrono.h>

#include "FormMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma comment(lib, "compiler_rt") // __udivti3, __umodti3
TForm1 *Form1;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actTestExecute(TObject *Sender)
{
    ShowMessage(
        fmt::format(
            _D( "Hello {}\nCurrent time: {:%H:%M:%S}" ),
            TPath::GetFileName( Application->ExeName ),
            std::chrono::system_clock::now()
        ).c_str()
    );
}
//---------------------------------------------------------------------------
