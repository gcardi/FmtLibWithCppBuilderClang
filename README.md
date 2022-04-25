# {fmt} library with C++ Builder's clang toolchains

## Cloning

Please, clone the repository using the 'recurse-submodule' switch:

```
git clone --recurse-submodules https://github.com/gcardi/FmtLibWithCppBuilderClang.git
```

## Notes

In the examples, the FMT_HEADER_ONLY macro is defined for all platforms/configurations in order to select the header only mode of {fmt}.
It also should works with a compiled versione of the library, but there are some problems with the dynamic RTL versions of Embarcadero's clang based compilers' libraries. See the [RSP-34592](https://quality.embarcadero.com/browse/RSP-34592) problem report.

The Console examples emit the text in UTF8, while those used in the GUI mainly treat UNICODE.

Please, don't forget to add the ```fmt\include``` directory to search-paths for header files in the project settings for all platforms/configurations.

<a><img src="docs/assets/images/1.png" alt="1" border="0"></a>

Also note that, since {fmt} looks for the _isatty function which does not exist on the C++ Builder, you must put 

```#define _isatty isatty```

before the ```#include <fmt/core.h>``` (or set this macro in the project definitions).

Moreover, regardless you link with static or dynamic libraries, the default library set for the clang's toolchains forget to include two functions that {fmt} library uses, i.e.: __udivti3 and __umodti3. To remedy to this problem simply you have to add (somewhere in your code) the following line:

```#pragma comment(lib, "compiler_rt") // __udivti3, __umodti3```

or explicitly add compiler_rt.a (for bcc64) or compiler_rt.lib (for bcc32c) in the project.

## Screenshots

Demo Examples/Console/Simple

<a><img src="docs/assets/images/3.png" alt="3" border="0"></a>

Demo Examples/Console/Colors

<a><img src="docs/assets/images/4.png" alt="4" border="0"></a>

Demo Examples/GUI/Simple

<a><img src="docs/assets/images/2.png" alt="2" border="0"></a>
