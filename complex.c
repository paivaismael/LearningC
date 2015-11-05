#include<stdio.h>
#include<assert.h>

struct complex{
	long double x;
	long double y;
}a,b,c,z;

struct complex mult2(struct complex a,struct complex b){
	z.x=a.x*b.x-a.y*b.y;
	z.y=a.x*b.y+a.y*b.x;
	return z;
}

struct complex square(struct complex a){
	z=mult2(a,a);
	return z;
}

struct complex add2(struct complex a,struct complex b){
	z.x=a.x+b.x;
	z.y=a.y+b.y;
	return z;
}

struct complex juliamap(struct complex z,struct complex c){
	z=add2(square(z),c);
	return z;
}

void complex_print(struct complex z){
	printf("z=%Lf+%Lfi\n",z.x,z.y);
}

void test(){
	a.x=1.;
	a.y=2.;
	b.x=2.;
	b.y=3.;
	c=mult2(a,b);
	assert(c.x==-4.);
	assert(c.y==7.);
	printf("The function mult2 is working correctly.\n");
	c=square(a);
	assert(c.x==-3.);
	assert(c.y==4.);
	printf("The function square is working correctly.\n");
	c=add2(a,b);
	assert(c.x==3.);
	assert(c.y==5.);
	printf("The function add2 is working correctly.\n");
	c=juliamap(a,b);
	assert(c.x==-1.);
	assert(c.y==7.);
	printf("The fuction juliamap is working correctly.\n");
	complex_print(a);
	printf("If the previous sentence is 'z=1.000000+2.000000i', the function complex_print is working correctly.\n");
}

int main(){
	test();
	return 0;
}
	
