#include<stdio.h>

typedef struct complex {long double x, y;} COMPLEX;

COMPLEX *mult2(const COMPLEX *a,const COMPLEX *b);
COMPLEX *square(const COMPLEX *a);
COMPLEX *add2(const COMPLEX *a,const COMPLEX *b);
COMPLEX *juliamap(const COMPLEX *a,const COMPLEX *b);
void complex_print(const COMPLEX *a);	
