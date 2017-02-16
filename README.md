# execbootstrap

A basic program to launch other programs as admin or normally.

This is useful for a game launcher being launched as admin but then using the bootstrapper to launch the games normally.

# Building

Using CMake to generate your build systems files.

Right now only visual studio compiler and windows is supported.

cmake "-GVisual Studio 14 2015"

# Usage

`execbootstrap.exe [program] [runAsAdmin]`

The following will run `programpath/program.exe` as administrator.

`execbootstrap.exe programpath/program.exe 1`

The following will run `programpath/program.exe` as normal.

`execbootstrap.exe programpath/program.exe 0`

If you ommit the true\false boolean it will be run as normal.

:+1: Enjoy.