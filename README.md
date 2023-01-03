# Mixed Precision Iterative Refinement

This repo contains the code associated with the paper: "Mixed Precision Iterative Refinement"

# How to build

This repo uses git submodules. The first step after pulling the repository is to configure the submodules:

```text
> git submodules init && git submodules update
```

After that, the repo is ready to be build:

```text
> mkdir build
> cd build
> cmake ..
> make
```

This will build the libraries, the cli command `src/semver` and the tests in `test/mpir_tests`.
