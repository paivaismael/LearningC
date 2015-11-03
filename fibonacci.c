#include<stdio.h>

int main()
{
	int n, a=1,b=1,c;
	printf("Enter the number of terms\n");
	scanf("%d\n",&n);

	printf("The first %d terms of Fibonacci series are:\n",n);
	printf("%d\n",a);
	if (n>1)
	  {
	    printf("%d\n",b);
	  }

	for (c=3;c<=n;)
	{
		if (n>2)
		{
			b=a+b;
			a=b-a;
			c=c+1;
			printf("%d\n",b);
		}
	}

	return 0;
}
