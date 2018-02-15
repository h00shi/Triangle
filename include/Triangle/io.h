/*****************************************************************************/
/*                                                                           */
/*  (io.h)                                                                   */
/*                                                                           */
/*  Include file for programs that call Triangle.                            */
/*                                                                           */
/*  Accompanies Triangle Version 1.6                                         */
/*  July 28, 2005                                                            */
/*                                                                           */
/*  Copyright 1996, 2005                                                     */
/*  Jonathan Richard Shewchuk                                                */
/*  2360 Woolsey #H                                                          */
/*  Berkeley, California  94705-1927                                         */
/*  jrs@cs.berkeley.edu                                                      */
/*                                                                           */
/*****************************************************************************/
#ifndef TRIANGLE_IO_H
#define TRIANGLE_IO_H

/* #define NO_ACUTE */

#include "Triangle/config.h"

/********* File I/O routines begin here                              *********/
/**                                                                         **/

int file_writenodes (mesh *m, behavior *b, FILE *nodefile);

int file_writeelements (mesh *m, behavior *b, FILE *elefile);

int file_writepoly (mesh *m, behavior *b, FILE *polyfile, REAL *holelist,
                    int holes, REAL *regionlist, int regions);

int file_writeedges (mesh *m, behavior *b, FILE *edgefile);

int file_writeneighbors (mesh *m, behavior *b, FILE *neighborfile);

int file_write_eps (mesh *m, behavior *b, FILE *file);

int file_readnodes (FILE *nodefile, triangleio *io, int *firstnode);

int file_readpoly (FILE *nodefile, triangleio *io, int *firstnode);

int file_readelements (FILE *nodefile, triangleio *io);

int file_readelementsarea (FILE *file, triangleio *io);

/**                                                                         **/
/********* File I/O routines end here                                *********/

#endif /* TRIANGLE_IO_H */
