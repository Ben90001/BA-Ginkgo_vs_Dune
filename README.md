# BA: Ginkgo vs Dune
Comparing the Dune-ISTL and Ginkgo libraries against each other

## Versions
Using DUNE 2.9 and Ginkgo 1.8.0

## Installation
### Dune
To install Dune first adjust parameters within `dune_installer.sh` afterwards install as follows:
```
./dependencies/dune_installer.sh DUNE
cd DUNE/
./buildmodules.sh
```
Afterwards you might want to remove the modules `common` and `istl` from the `buildmodules.sh` build process, so that upon future calls only the added project-module gets recompiled.  
Add your Code to `dependencies/DUNE/dune-evaluation/src`  
Find your binary at `dependencies/DUNE/release-build/dune-evaluation/src`  

### Ginkgo
To install Ginkgo simply run:  
```
./dependencies/ginkgo_installer.sh
```
NOTE: This fully builds Ginkgo, compilation takes about 2h.  
The script builds into `dependencies/GINKGO/include`.  