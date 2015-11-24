#include<stdio.h>

typedef long double VALUE;
typedef struct complex {
  VALUE x;
  VALUE y;
} COMPLEX;

void set(COMPLEX *c, VALUE a, VALUE b);
COMPLEX mult2(COMPLEX *a, COMPLEX *b);
COMPLEX square(COMPLEX *a);
COMPLEX add2(COMPLEX *a,COMPLEX *b);
COMPLEX juliamap(COMPLEX *a, COMPLEX *b);
void complex_print(COMPLEX *a);
COMPLEX get_result(char *name, COMPLEX *a, COMPLEX *b);
void assert_function(char *function, COMPLEX *a, COMPLEX *b, VALUE cx, VALUE cy);
