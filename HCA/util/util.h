/*
 * utility header
 * Copyright (C) 2010-2014 Wray Buntine 
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla 
 * Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at
 *      http://mozilla.org/MPL/2.0/.
 *
 * Author: Wray Buntine (wray.buntine@nicta.com.au)
 *
 *   This is a good example of why C++ is better than C  
 */

#ifndef __UTIL_H
#define __UTIL_H

#include <stdint.h>

extern long memallocd;

typedef struct sparse_vec {
  int nnz;
  uint16_t *id;
  double *value;
} sparse_vec;


double digamma(double a) ;
double logadd(double V, double lp) ;
unsigned samplet(float *fact, double facttot, unsigned dim, double U);

uint16_t *u16vec(int n);
uint32_t *u32vec(int n);
double *dvec(int n);
float *fvec(int n);
uint16_t **u16mat(int nr, int nc);
void u16mat_free(uint16_t **mat, int nr, int nc);
uint32_t **u32mat(int nr, int nc);
uint32_t ***u32tri(int ns, int nr, int nc);
sparse_vec *smat(int nr); 
float **fmat(int nr, int nc);
double **dmat(int nr, int nc);
unsigned countntot(char *fname);
void read_didwid(char *wfile, char *dfile, int N, uint32_t *d, uint32_t *w);
void read_dvec(char *dfile, int N, double *d);
void read_fmat(char *dfile, int N, int C, float **f);
void read_u16vec(char *dfile, int N, uint16_t *d);
void write_fvec(char *dfile, int N, float *d);
void write_dvec(char *dfile, int N, double *d);
void write_dmat(char *dfile, int N, int C, double **d);
void write_fmat(char *ffile, int N, int C, float **f);
void write_u16sparse(int nr, int nc, uint16_t **x, char *fname);
void write_u16sparseco(int nr, int nc, uint16_t **x, char *fname,
		       uint16_t cutoff);
void read_u16sparse(int nr, int nc, uint16_t **x, char *fname);
void read_u32sparse(int nr, int nc, uint32_t **x, char *fname);
void write_u32sparse(int nr, int nc, uint32_t **x, char *fname);
void write_u32sparseco(int nr, int nc, uint32_t **x, char *fname,
		       uint32_t cutoff);
void write_u32sparsetri(int ns, int nr, int nc, uint32_t ***x, char *fname,
			uint32_t cutoff);
void read_u32sparsetri(int ns, int nr, int nc, uint32_t ***x, char *fname);
void write_u16vec (int n, uint16_t *x, char *fname);
uint32_t u32max(int n, uint32_t *x);
double dmax(int n, double *x);
double dmin(int n, double *x);
/*
 *  pick up line from file "stem.par" starting with "par" and an "=",
 *  and return stuff after "=" of max length len
 */
char *readpar(char *stem, char *par, int len);
char *readsrcpar(char *stem, char *par, int len);

void vec_atod(double *vec, int N, char *vals);

/*
 *    len is just a hint, it will resize if more needed;
 *    read tokens in range W0:WE-1
 *    place in vector offset by W0
 *    allocate all string memory
 */
char **read_vocab(char *infile, int W0, int WE, int len);
void free_vocab(char **ctmp);


#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#endif
