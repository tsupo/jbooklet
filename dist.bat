echo off

REM batch file for distribution of "jbooklet"
REM $Header: /comm/jbooklet/dist.bat 1     09/05/14 3:52 tsupo $

chmod -R +w dist

rm -Rf dist\src

mkdir dist\src
mkdir dist\src\include
mkdir dist\src\lib

copy *.c   dist\src
copy *.cpp dist\src
copy *.h   dist\src

copy Release\jbooklet.exe dist
copy Release\xmlRPC.dll dist

copy ..\xmlRPC\xmlRPC.h dist\src\include
copy ..\xmlRPC\Release\xmlRPC.lib dist\src\lib
