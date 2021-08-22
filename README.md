# fsync tester/checker

**Snippet to check if your kernel has been built with fsync (futex_wait_multiple) patch**

## How To

- Install `make` and `gcc` packages
- Clone this repository and `cd` into the dir
- run `make`
- :money_with_wings:
  - `FSYNC: OK` means the patch is there
  - `FSYNC: FAIL` means no bueno
- after running `make` at least once you can recheck with `./check.sh`

