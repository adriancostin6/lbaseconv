# lbaseconv - library for number base conversion

Dummy library that converts between different number bases. Main purpose was to better my workflow, and experiment with unit-test using google-test and the github CI/CD workflow.

## Getting started

### Cloning the repository

To get a local copy of the library source code use the following command

```
git clone https://github.com/adriancostin6/lbaseconv.git
```

### Building the library

In order to build the library, you have to execute the following commands:

```
cd lbaseconv
mkdir build
cmake ..
make
```

### Testing the library

For executing the googletest suite, run the following commands, after building
the library.

Firstly, make sure you are inside the build directory using: `cd lbaseconv/build`

Second, run the tests using either the `ctest` or `make test` command.

### Using the library

In order to use the library, make sure to provide the path to the include files
under `lbaseconv/include` and link against the library file found in the build
directory.

An example CMake configuration is provided under [lbaseconv/cmake/LibraryTest.cmake.in](cmake/LibraryTest.cmake.in).
