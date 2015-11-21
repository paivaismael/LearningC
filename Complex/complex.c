#include<stdio.h>
#include"complex.h"

typedef struct complex{long double x,y;}COMPLEX;

COMPLEX a,b,c,z;

COMPLEX *mult2(const COMPLEX *a,const COMPLEX *b){
	z.x=(a->x)*(b->x)-(a->y)*(b->y);
	z.y=(a->x)*(b->y)+(a->y)*(b->x);
	return &z;
}

COMPLEX *square(const COMPLEX *a){
	return mult2(a,a);
}

COMPLEX *add2(const COMPLEX *a,const COMPLEX *b){
	z.x=(a->x)+(b->x);
	z.y=(a->y)+(b->y);
	return &z;
}

COMPLEX *juliamap(const COMPLEX *a,const COMPLEX *b){
	return add2(square(a),b);
}

void complex_print(const COMPLEX *a){
	printf("z=%Lf+%Lfi\n",a->x,a->y);
}
