#include<stdio.h>
#include<cmath.h>

int count(int n)
{
	int c;
	c=0;
	while (n!=0)
	{
		n=n/10;
		c=c+1;
	}
	return c;
}

int digit(int n,int m)
{
	int c,d;
	for (c=1;c<=m;c++)
	{
		d=n%10;
		n=n/10;
	}
	return d;
}

int main()
{
	int n,m,i,p,z;
	printf("Please enter with a sequence of zeros and ones:\n");
	scanf("%d",&n);
	z=0;
	m=count(n);
	for (i=1;i<=m;i++)
	{
		p=digit(n,i);
		z=z+p*pow(2,i-1);
	}
	printf("The sequence of zeros and ones represents the integer %d.\n",z);
	return 0;
}
