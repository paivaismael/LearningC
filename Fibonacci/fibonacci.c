#include<stdio.h>

int main()
{
	long double n,a,b,c; // long double type to avoid the negative numbers that were appearing before
	a=1,b=1;
	printf("Enter the number of terms: ");
	scanf("%Lf",&n);

	printf("The first %d terms of Fibonacci series are:\n",n);
	printf("%Lf\n",a);
	if (n>1)
	  {
	    printf("%Lf\n",b);
	  }

	for (c=3;c<=n;)
	{
		if (n>2)
		{
			b=a+b;
			a=b-a;
			c=c+1;
			printf("%Lf\n",b);
		}
	}

	return 0;
}
