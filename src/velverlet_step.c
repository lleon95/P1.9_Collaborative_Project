/*
  P1.9_seed
  Function: Velverlet Time Integration Steps Functions
  Contributor: Luis Leon

  Dependencies:
  - Struct: mdsys_t
  - Consts: mvsq2e (m*v^2 in kcal/mol)
*/

#include "ljmd.h"

inline void propagate_position(mdsys_t *sys, int i) {
  sys->rx[i] += sys->dt * sys->vx[i];
  sys->ry[i] += sys->dt * sys->vy[i];
  sys->rz[i] += sys->dt * sys->vz[i];
}

inline void propagate_velocity(mdsys_t *sys, int i) {
  sys->vx[i] += 0.5 * sys->dt / mvsq2e * sys->fx[i] / sys->mass;
  sys->vy[i] += 0.5 * sys->dt / mvsq2e * sys->fy[i] / sys->mass;
  sys->vz[i] += 0.5 * sys->dt / mvsq2e * sys->fz[i] / sys->mass;
}

void initial_propagation(mdsys_t *sys) {
  int i;
  for (i = 0; i < sys->natoms; ++i) {
    propagate_velocity(sys, i);
    propagate_position(sys, i);
  }
}

void final_propagation(mdsys_t *sys) {
  int i;
  for (i = 0; i < sys->natoms; ++i) {
    propagate_velocity(sys, i);
  }
}