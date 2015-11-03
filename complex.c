#include<stdio.h>
#include<assert.h>

struct complex{
	float x;
	float y;
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
	a=add2(square(z),c);
	return a;
}

void complex_print(struct complex z){
	printf("z = &z.x + &z.y i");
}

void test(){
	a.x=1.;
	a.y=2.;
	b.x=2.;
	b.y=3.;
	c=mult2(a,b);
	assert(c.x==-4.);
	assert(c.y==7.);
	printf("mult2 is working correctly\n");
	c=square(a);
	assert(c.x==-3.);
	assert(c.y==4.);
	printf("square is working correctly\n");
	c=add2(a,b);
	assert(c.x==3.);
	assert(c.y==5.);
	printf("add2 is working correctly\n");
	c=juliamap(a,b);
	assert(c.x==-1.);
	assert(c.y==7.);
	printf("juliamap is working correctly\n");
}

int main(){
	test();
	return 0;
}
	
