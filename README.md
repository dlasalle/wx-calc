Wx-Calc
=======

This program is a simple example for using CMake and wxWidgets to create a
portable GUI application.

Components used in this application:
* wxBoxSizer
* wxGridSizer
* wxTextCtrl
* wxButton


How to build on GNU/Linux/Unix
------------------------------

You'll need to install the `wxWidgets` and `cmake` packages for your
distribution, and then run:

```
$ mkdir build
$ cd build
$ cmake ../
$ make
```


How to build on Windows 
-----------------------

You'll need to install `wxWidgets` and `cmake`.

Then create a `build` directory inside of the repository folder and execute the
appropriate generate for your environment:
```
cmake -G 'Visual Studio 15 2017 Win64' ../
```
