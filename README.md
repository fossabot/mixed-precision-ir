# Mixed Precision Iterative Refinement

This repo contains the code associated with the paper: "Mixed Precision Iterative Refinement"

# How to build

This repo uses git submodules. The first step after pulling the repository is to configure the submodules:

```text
> git submodule init && git submodule update
```

After that, the repo is ready to be build:

```text
> mkdir build
> cd build
> cmake ..
> make
```

This will build the libraries, the CLI command projects, and the tests in `test/mpir_tests`.

When using VSCode, the repository contains a devcontainer spec in the directory $MPIR_ROOT/.devcontainer. 

![VS code environment](img/vscode-devcontainer.png)

The default container provides a build environment based on GCC11:

```json
{
	"image": "stillwater/universal:gcc11builder"
}
```
There is a set of builders that can be used that contain specific compilers. Other environments are:
```text
gcc9builder
gcc10builder
gcc12builder
clang11builder
clang12builder
clang13builder
clang14builder
```
If you want to change your development container, simply replace the json with the container of your choice.

You can also build natively. The .gitignore of this repo filters out the following directories:
```text
build/
build_msvc/
build_gcc/
build_clang/
```
You can use these build directories to organize your native and specific build containers so that they can run concurrently. For example, you can use the `build/` directory to hold native builds, and `build_gcc/` directory to hold the default build container builds.

# Install command line tools, libraries, and include files

To install the command line tools for ease of use, issue the `install` target:

```bash
> make install
```

This command will populate the $MPIR_ROOT/bin, $MPIR_ROOT/lib, and $MPIR_ROOT/include directories, where $MPIR_ROOT represents the directory path of the mixed-precision-ir repository clone.

If you are on a Linux or MacOS system, you can add the bin directory to your path to pick up the command line tools:

```bash
> export PATH=$PATH:$MPIR_ROOT/bin
```

For Windows, use the environment variable editor to do the same.

# Project structure

The following figure shows the project structure of this repository:

![Project Structure](img/project-structure.png)
