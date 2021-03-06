/*
Input-Output function
Contributor: Krister Jazz Urog

Dependencies:
	struct: mdsys_t
	
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "ljmd.h"

int get_a_line(FILE *fp, char *buf) {
  char tmp[BLEN], *ptr;

  /* read a line and cut of comments and blanks */
  if (fgets(tmp, BLEN, fp)) {
    int i;

    ptr = strchr(tmp, '#');
    if (ptr) *ptr = '\0';
    i = strlen(tmp);
    --i;
    while (isspace(tmp[i])) {
      tmp[i] = '\0';
      --i;
    }
    ptr = tmp;
    while (isspace(*ptr)) {
      ++ptr;
    }
    i = strlen(ptr);
    strcpy(buf, tmp);
    return 0;
  } else {
    perror("problem reading input");
    return -1;
  }
  return 0;
}

void output(mdsys_t *sys, FILE *erg, FILE *traj) {
  int i;

  fprintf(erg, "% 8d % 20.8f % 20.8f % 20.8f % 20.8f\n", sys->nfi, sys->temp,
          sys->ekin, sys->epot, sys->ekin + sys->epot);
  fprintf(traj, "%d\n nfi=%d etot=%20.8f\n", sys->natoms, sys->nfi,
          sys->ekin + sys->epot);
  for (i = 0; i < sys->natoms; ++i) {
    fprintf(traj, "Ar  %20.8f %20.8f %20.8f\n", sys->rx[i], sys->ry[i],
            sys->rz[i]);
  }
}
