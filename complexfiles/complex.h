#include<stdio.h>

typedef struct complex{	long double x,y;}COMPLEX;

COMPLEX a,b,c,z,*p;

COMPLEX *mult2(const COMPLEX *a,const COMPLEX *b){
	z.x=(a->x)*(b->x)-(a->y)*(b->y);
	z.y=(a->x)*(b->y)+(a->y)*(b->x);
	p=&z;
	return p;
}

COMPLEX *square(const COMPLEX *a){
	p=mult2(a,a);
	return p;
}

COMPLEX *add2(const COMPLEX *a,const COMPLEX *b){
	z.x=(a->x)+(b->x);
	z.y=(a->y)+(b->y);
	p=&z;
	return p;
}

COMPLEX *juliamap(const COMPLEX *a,const COMPLEX *b){
	p=add2(square(a),b);
	return p;
}

void complex_print(const COMPLEX *a){
	printf("z=%Lf+%Lfi\n",a->x,a->y);
}
