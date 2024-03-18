// 1) check cubes
// 2) check lines
// 3) check columns

// matrix of numbers (sudoku): matrix[9][9]
// 1 0 0 0 0 0 0 0 0 
// 0 1 2 3 4 5 6 7 8
// 2 0 0 0 0 0 0 0 0 
// 3 0 0 0 0 0 0 0 0 
// 4 0 0 0 0 0 0 0 0 
// 5 0 0 0 0 0 0 0 0 
// 6 0 0 0 0 0 0 0 0 
// 7 0 0 0 0 0 0 0 0 
// 8 0 0 0 0 0 0 0 0 

// matrix of cubes[3][3]: matrix[3xCube][3xCube]
// C10 C11 C12
// C20 C21 C22
// C30 C31 C32

#include <stdio.h>

int checkLines(int matrix[9][9]) {
  int i, j, verif[10] = {0}; // line, column, verifier
  int k; // elements from verif[]
  int l = 0; // amount of loops (amount of lines checked)

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      int a = matrix[i][j];
      verif[a] += 1;
    }
    for (k = 1; k < 10; k++) {
      if (verif[k] != (1 + l)) {
        return 0;
      }
    }

    l++;
  }
  return 1;
}

int checkColumns(int matrix[9][9]) {
  int i, j, verif[10] = {0}; // line, column, verifier
  int k; // elements from verif;
  int c = 0; // amount of loops (amount of columns checked)

  for (j = 0; j < 9; j++) {
    for (i = 0; i < 9; i++) {
      int a = matrix[i][j];
      verif[a] += 1;
    }

    for (k = 1; k < 10; k++) {
      if (verif[k] != (1 + c)) {
        return 0;
      }
    }

    c++;
  }
  return 1;
}

int checkCubes(int matrix[9][9]) {
  int i, j, verif[10] = {0}; // line, column
  int k; // elements from verify;
  int Ci = 0, Cj = 0; // current cube line and column, in a matrix[3][3] of cubes
  int c; // amount of loops (amount of cubes checked)

  for (c = 0; c < 9; c++) {

    for(i = 0+(Ci * 3); i < 3+(Ci * 3); i++) {
      for(j = 0+(Cj * 3); j < 3+(Cj * 3); j++) {
        int a = matrix[i][j];
        verif[a] += 1;
      }
    }

    for (k = 1; k < 10; k++) {
      if (verif[k] != (1 + c)) {
        return 0;
      }
    }

    if (Ci == 2) { Ci = 0; Cj++; } 
    else { Ci++; };
  }
  return 1;
}

int main() {

  int a, i, j, matrix[9][9];
  int num;

  scanf("%d", &num);

  for (a = 0; a < num; a++) {
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        scanf("%d", &matrix[i][j]);
      };
    };
    printf("Instancia %d\n", a + 1);

    if (checkLines(matrix) == 0) {
      printf("NAO\n\n");
    } else if (checkColumns(matrix) == 0) {
      printf("NAO\n\n");
    } else if (checkCubes(matrix) == 0) {
      printf("NAO\n\n");
    } else { printf("SIM\n\n"); };
  };

  return 0;
}
