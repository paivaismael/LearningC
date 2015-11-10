#include<stdio.h>
#include<assert.h>

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

void test(){
	COMPLEX A,B,C;
	A.x=1.;
	A.y=2.;
	B.x=2.;
	B.y=3.;
	C=*mult2(&A,&B);
	assert(C.x==-4.);
	assert(C.y==7.);
	printf("The function mult2 is working correctly.\n");
	C=*square(&A);
	assert(C.x==-3.);
	assert(C.y==4.);
	printf("The function square is working correctly.\n");
	C=*add2(&A,&B);
	assert(C.x==3.);
	assert(C.y==5.);
	printf("The function add2 is working correctly.\n");
	C=*juliamap(&A,&B);
	assert(C.x==-1.);
	assert(C.y==7.);
	printf("The fuction juliamap is working correctly.\n");
	complex_print(&A);
	printf("If the previous sentence is 'z=1.000000+2.000000i', the function complex_print is working correctly.\n");
}

int main(){
	test();
	return 0;
}
