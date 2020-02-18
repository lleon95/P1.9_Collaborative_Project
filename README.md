# P1.9_Collaborative_Project

Master:
![](https://travis-ci.com/KristerJazz/P1.9_Collaborative_Project.svg?branch=master)

Development: ![](https://travis-ci.com/KristerJazz/P1.9_Collaborative_Project.svg?branch=develop)

## Description

This package contains simplified MD code with multi-threading.
parallelization for simulating atoms with a Lennard-Jones potential.

The bundled makefiles are set up to compile the executable once
with OpenMP disabled and once with OpenMP enabled with each build
placing the various object files in separate directories.

The examples directory contains 3 sets of example input decks
and the reference directory the corresponding outputs.

## Collaborators

* **Stefano Campanella**: stefanocampanella
* **Luis Leon**: lleon95
* **Mattia Carello**: mattiacmhpc
* **Jazz Krister**: KristerJazz

## Policies

1. Use merge instead of rebase
2. If merge conflict, report and look for the responsibles!
3. Two approvals in the Pull Request before merge
4. Before leaving your PC, push to remote
5. Do not touch others branch
6. Branch naming convention: `feature/<username>-<feature_name>`

## Compilation instructions

**Compile**

* Without MPI nor OpenMP: `make`
* With MPI but not OpenMP: `make WITH_MPI=1`
* With OpenMP but not MPI: `make WITH_OMP=1`
* With OpenMP and MPI: `make WITH_OMP=1 WITH_MPI=1`
  
**Running checks**

* Without MPI nor OpenMP: `make check`
* With MPI but not OpenMP: `make WITH_MPI=$NUM_PROCS check`
* With OpenMP but not MPI: `make WITH_OMP=$NUM_THREADS check`
* With OpenMP and MPI: `make WITH_OMP=$NUM_THREADS WITH_MPI=$NUM_PROCS check`

**Cleaning**

`make clean`

Type: make
to compile everything and: make clean
to remove all compiled objects

### Requirements

* OpenMPI > 3
* GCC > 8
* pytest Python Module
* make