# {fmt} library with C++ Builder's clang toolchains

## Cloning

Please, clone the repository using the 'recurse-submodule' switch:

```
git clone --recurse-submodules https://github.com/gcardi/Tabellone.git
```

## Notes

The FMT_HEADER_ONLY macro is defined for all platforms/configurations in order to select the header only mode of {fmt}.
It also should works with a compiled versione of the library, but there are some problems with the dynamic RTL versions of Embarcadero's clang based compilers' libraries. See the [RSP-34592](https://quality.embarcadero.com/browse/RSP-34592) problem report.
