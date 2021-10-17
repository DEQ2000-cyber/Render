@echo off




rem Para C
gcc.exe -c main.c
gcc.exe -O3 -o main.exe main.o -L./ -lrender
del *.o


rem Para C++
rem g++.exe -c main.c
rem g++.exe -O3 -o main.exe main.o -L./ -lrender
rem del *.o




pause