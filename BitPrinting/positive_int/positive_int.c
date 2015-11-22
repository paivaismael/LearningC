#include<stdio.h>

long int count(long int n){
	long int c;
	c=0;
	while (n!=0){
		n=n/10;
		c=c+1;
	}
	return c;
}

long int digit(long int n,long int m){
	long int c,d;
	for (c=1;c<=m;c++){
		d=n%10;
		n=n/10;
	}
	return d;
}

long int power(long int k, long int l){
	long int m,n;
	n=1;
	for (m=1;m<=l;m++){
		n=n*k;
	}
	return n;
}

int bigger(long int n, long int m){
	long int p;
	int q;
	q=0;
	for (p=1;p<=m;p++){
		if (q<=digit(n,p)){
			q=digit(n,p);
		}
	}
	return q;
}

int main(){
	long int n,m,i,z;
	int p,q;
	printf("Please enter with a sequence of zeros and ones:\n");
	scanf("%d",&n);
	z=0;
	m=count(n);
	q=bigger(n,m);
	if (q>1){
		printf("The input is not a sequence of zeros and ones.\n");
	}
	else{
		for (i=1;i<=m;i++){
			p=digit(n,i);
			z=z+p*power(2,i-1);
		}
		printf("The sequence of zeros and ones represents the integer %d.\n",z);

	}
	return 0;
}
