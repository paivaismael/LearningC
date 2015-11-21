#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare a multidimensional array of 10x10 integers in the usual way
    int array[10][10];

    // Allocate a block of 10x10 integers and assign the address
    // of the beginning of the memory block to the pointer array2
    // Note : calloc initializes memory as zeros, while malloc does not
    int *array2 = (int *) calloc(10 * 10, sizeof(int));

    // Allocate arrays of structs in a similar way
    typedef struct vec2 { int i; int j; } VEC2;
    VEC2 vecarray[10][10];
    VEC2 *vecarray2 = (VEC2 *) calloc(10 * 10, sizeof(VEC2));
    VEC2 v;

    // iteration indices
    int i, j;
    
    /* WARNING: calloc may fail and return a NULL value for the pointer
                Good programming practice mandates checking for such failures. */
    if (NULL == array2 || NULL == vecarray2) {
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "calloc failed\n");
      // Return a non-successful integer
      return(-1);
    }

    for (i=0; i<10; i++)
    {
	for (j=0; j<10; j++)
	{
            // set the [i][j] integer element of array
            array[j][i] = j * 10 + i;
            // set the value at the memory address at array2 + (i*10 + j) bytes 
            *(array2+i*10+j) = j * 10 + i;
	    // set the [i][j] struct element of vecarray 
	    vecarray[j][i] = (VEC2) {j, i};
	    *(vecarray2+j*10+i) = (VEC2) {j, i};
	}
    }

    // print array in usual array notation
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
	{
	    printf("array[%d][%d] : %02d\t", i, j, array[j][i]);
	}
        puts("");
    }

    // print array2 by just iterating through all the allocated memory
    for (i=0; i<10*10; i++)
    {
        printf("*(array2 + %02d) : %02d\t", i, *(array2+i));
    }
    puts("");
    
    // print vecarray in usual array notation
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
	{
            v = vecarray[j][i];
	    printf("vecarray[%d][%d] : {%d, %d}\t", i, j, v.i, v.j);
	}
        puts("");
    }

    // print vecarray by just iterating through all the allocated memory
    for (i=0; i<10*10; i++)
    {
	v = *(vecarray2+i);
        printf("*(array2 + %02d) : {%d, %d}\t", i, v.i, v.j);
    }
    puts("");

    // explicitly free the block of memory that were calloc-ed 
    free(array2);
    free(vecarray2);

    return 0;
}
