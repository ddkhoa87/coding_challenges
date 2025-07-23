### Compile source file:

+ Linux:
`g++ main.cpp -std=c++20 -o out`

+ Windows:
`cl /EHsc /std:c++20 .\main.cpp /Fe:out.exe`

### Compile test file:

+ On Linux:
`g++ test.cpp -std=c++20 -o test -I/usr/include/gtest -L/usr/lib -lgtest -lgtest_main`

+ On Windows:

Use *x64 Native Tools Command Line Prompt for VS*:
+ `set VCPKG_ROOT=C:\vcpkg\installed\x64-windows`
+ `copy %VCPKG_ROOT%\bin\gtest.dll .`
+ `cl /EHsc /std:c++20 .\test.cpp %VCPKG_ROOT%\src\gtest_main.cc /Fe:test.exe /I"%VCPKG_ROOT%\include" /link /LIBPATH:"%VCPKG_ROOT%\lib" gtest.lib`


### Clean up

On Linux:
+ `rm *.o`

Windows:
+ `del *.exe *.obj`
+ `del *.dll *.exe *.obj`