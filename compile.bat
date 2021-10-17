@echo off




call :borrados


gcc.exe -c -DBUILD_DLL render.c
gcc.exe -shared -o render.dll render.o -Wl,--out-implib,render.a -lgdi32
rem gcc.exe -shared -o render.dll render.o -Wl,--add-stdcall-alias


gcc.exe -c main.c
gcc.exe -o main.exe main.o -L./ -lrender
rem -mwindows


if exist *.o (
	del *.o
	)



pause
exit




:borrados

rem FUNCION DE BORADOS DE ARCHIVOS

if exist *.o (
	del *.o
	)
if exist *.a (
	del *.a
	)
if exist *.dll (
	del *.dll
	)

goto :EOF