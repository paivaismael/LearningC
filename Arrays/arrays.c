#include <stdio.h>
#include <stdlib.h>

void setarrays(int size,int array[], int *array2);
void printarrays(int size, int array[], int *array2, const char *string);

int main(void){
    // Declare an array of 10 integers in the usual way
    int size=10;
    int sizechar = 7;
    int array[size];

    // Allocate a block of 10 integers and assign the address
    // of the beginning of the memory block to the pointer array2
    int *array2 = malloc(size * sizeof(int));
    /* WARNING: malloc may fail and return a NULL value for the pointer
                Good programming practice mandates checking for such failures. */
    if (NULL == array){
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "malloc failed\n");
      // Return a non-successful integer
      return(-1);
    }

    // character array (i.e., a string)
    const char *string = "Foobar.";

    // set the arrays
    setarrays(size,array,array2);

    // call the function printarrays
    printarrays(size,array,array2,string);

    // explicitly free the block of memory malloc-ed at array2 for later use
    free(array2);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}

void setarrays(int size, int array[], int *array2){
    // iteration index
    int i;
    for (i=0; i<size; i++){
        // assign the value i to the ith integer element of array
        array[i] = i;
        // set the value inside the memory address at array2 + (i bytes) to i
        *(array2+i) = i;
    }
}

void printarrays(int size, int array[], int *array2, const char *string){
    // iteration index
    int i;
    // increment three bytes BEYOND the allocated memory (buffer overrun)
    for (i=0; i<size+3; i++){
        // print the array values in the usual way
        printf("array[%d] : %d\t", i, array[i]);
        // print the values contained in each memory address starting at array2 
        printf("*(array2 + %d) : %d\t", i, *(array2+i));
        // print each character in the string
        printf("string[%d] : %c\t", i, string[i]);
        // do the same thing, but in pointer notation
        printf("*(string + %d) : %c\n", i, *(string+i));
    }
}
