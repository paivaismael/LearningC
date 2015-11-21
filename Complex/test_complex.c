#include<stdio.h>
#include<assert.h>
#include"complex.h"

void test(){
	COMPLEX A,B,*C;
	A.x=1.;
	A.y=2.;
	B.x=2.;
	B.y=3.;
	C=mult2(&A,&B);
	assert(C->x==-4.);
	assert(C->y==7.);
	printf("The function mult2 is working correctly.\n");
	C=square(&A);
	assert(C->x==-3.);
	assert(C->y==4.);
	printf("The function square is working correctly.\n");
	C=add2(&A,&B);
	assert(C->x==3.);
	assert(C->y==5.);
	printf("The function add2 is working correctly.\n");
	C=juliamap(&A,&B);
	assert(C->x==-1.);
	assert(C->y==7.);
	printf("The fuction juliamap is working correctly.\n");
	complex_print(&A);
	printf("If the previous sentence is 'z=1.000000+2.000000i', the function complex_print is working correctly.\n");
}

int main(){
	test();
	return 0;
}
