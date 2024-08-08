# BA: Ginkgo vs Dune
Comparing the Dune-ISTL and Ginkgo libraries against each other

## Versions
Using DUNE 2.9 and Ginkgo 1.8.0

## Installation
### Dune
To install first adjust parameters within `dune_installer.sh` afterwards install as follows:
```
./dune_installer.sh dependencies/DUNE
cd dependcies/DUNE/
./buildmodules.sh
```
Afterwards you might want to remove the modules `common` and `istl` from the `buildmodules.sh` build process, so that upon future calls only the added project-module gets recompiled.  
Add your Code to `DUNE/dune-evaluation/src`  
Find your binary at `DUNE/release-build/dune-evaluation/src`  


