# fsynctest

**Snippet to check if your kernel has been built with fsync (futex_wait_multiple) patch**

## How To

- Install `make` and `gcc` packages
- Clone this repository and `cd` into it
- running `make` to build the binary, `fsynctest`
  - runing `make check` will build the binary if it's not yet built and run it
- after running make/building at least once you can run `./fsynctest` directly
