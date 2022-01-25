# {fmt} library with C++ Builder's clang toolchains

## Cloning

Please, clone the repository using the 'recurse-submodule' switch:

```
git clone --recurse-submodules https://github.com/gcardi/Tabellone.git
```

## Notes

The FMT_HEADER_ONLY macro is defined for all platforms/configurations in order to select the header only mode of {fmt}.
It also should works with a compiled versione of the library, but there are some problems with the dynamic RTL versions of Embarcadero's clang based compilers' libraries. See the [RSP-34592](https://quality.embarcadero.com/browse/RSP-34592) problem report.

Also don't forget to add ```..\fmt\include``` to your project settings for all platforms/configurations.

<a href="https://ibb.co/6PpYkYH"><img src="https://i.ibb.co/G217q7W/1.png" alt="1" border="0"></a>

Also note that, since {fmt} looks for the _isatty function which does not exist on the C++ Builder, you must put 

```#define _isatty isatty```

before the ```#include <fmt/core.h>``` (or set this macro in the project definitions).
