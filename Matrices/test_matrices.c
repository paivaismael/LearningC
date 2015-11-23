#include <stdio.h>
#include "matrices.h"

void change(MATRIX *p);

int main(void) {

  // Construct a new 3x6 matrix
  MATRIX a = new_matrix(3,6);

  puts("Initial matrix a:");
  print_matrix(&a);

  puts("Modified matrix a:");
  set(&a, 1, 1, 20.0);
  set(&a, 2, 2, 40.0);
  set(&a, 0, 4, 60.0);
  set(&a, 2, 5, 80.0);
  change(&a);
  print_matrix(&a);

  puts("Element a(2,2):");
  print_value(get(&a, 2, 2));
  puts("");
  puts("Element a(0,4):");
  print_value(get(&a, 0, 4));
  puts("");

  // Construct a new 6x5 matrix
  MATRIX b = new_matrix(6,5);
  set(&b, 0, 4, 10.0);
  set(&b, 2, 3, 30.0);
  set(&b, 3, 1, 50.0);
  set(&b, 5, 0, 70.0);
  change(&b);

  puts("Matrix b:");
  print_matrix(&b);
  puts("");

  // Construct a new 4x7 matrix
  MATRIX c = new_matrix(4,7);
  set(&c, 0, 1, 10.0);
  set(&c, 1, 2, 10.0);
  set(&c, 2, 3, 10.0);
  set(&c, 3, 4, 10.0);
  set(&c, 3, 5, 10.0);
  set(&c, 2, 6, 10.0);
  change(&c);

  puts("Matrix c:");
  print_matrix(&c);
  puts("");

  // Test matprod with a product defined case
  puts("The product ab is:");
  MATRIX m = matprod(&a,&b);
  print_matrix(&m);
  puts("");

  // Test matprod with an undefined product case
  puts("The product ac is:");
  MATRIX n = matprod(&a,&c);
  print_matrix(&n);
  puts("");

  // Destruct matrices when done
  delete_matrix(a);
  delete_matrix(b);
  delete_matrix(c);
  delete_matrix(m);
  delete_matrix(n);

  return 0;
}

// Replace zeros for ones
void change(MATRIX *p){
  INDEX i, j;
  for(i=0; i<(p->rows); i++){
    for(j=0; j<(p->cols); j++){
      VALUE val = get(p, i, j);
      if(val==0.0){
        set(p, i, j, 1.0);
      }
    }
  }
}
