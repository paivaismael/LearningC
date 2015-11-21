#include<stdio.h>
#include <stdlib.h>

typedef struct matrix{unsigned int rows;unsigned int cols;long double *mat;}MATRIX;

MATRIX new(unsigned int rows; unsigned int cols){
	MATRIX A;
	A.rows=rows;
	A.cols=cols;
	A.mat = (long double *) calloc(a.rows * b.cols, sizeof(long double));
	if (NULL == prod) {
      		fprintf(stderr, "calloc failed\n");
      		return(-1);
    	}
	return A;
}

void set(MATRIX *M,int i, int j, long double val){
	*(M->mat+M->rows*i+j)=val;
}

long double get(MATRIX *M, int i, int j){
	return *(M->mat+M->rows*i+j);
}

MATRIX matprod(MATRIX a,MATRIX b){
	MATRIX M;
	long double val;
	int i,j,k;
	if(a.cols!=b.rows){
		printf("The product between the matrixes is undefined.");
		return NULL;
	}
	else{
		M=new(a.rows,b.cols);
		for(i=1;i<=M.rows;i++){
			for(j=1;j<=M.cols;j++){
				val=0;
				for(k=1;k<=a.cols;k++){
					val=val+get(&a,i,k)*get(&b,k,j);
				}
				set(&M,i,j,val);
			}
		}
	return M;
	}
}

int main(){
	MATRIX A,B;
	int i,j,val;
	A.rows=5;
	A.cols=7;
	B.rows=7;
	B.cols=4;
	for(i=1;i<=A.rows;i++){
		for(j=1;j<=A.cols;j++){
			val=i+2*j;
			set(&A,i,j,val);
		}
	}
	for(i=1;i<=B.rows;i++){
		for(j=1;j<=B.cols;j++){
			val=2*i+3*j;
			set(&B,i,j,val);
		}
	}
	matprod(A,B);
	return 0;
}
