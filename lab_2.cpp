const int NUM_SIZES = 7;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	  const int SIZES[NUM_SIZES] = { 100, 200, 400, 1000, 2000, 4000, 10000 };

	  int i = 0, j = 0, r = 0, elem_c = 0;
	  setvbuf(stdin, NULL, _IONBF, 0);
	  setvbuf(stdout, NULL, _IONBF, 0);


	  for (int sID = 0; sID < NUM_SIZES; sID++) {

			int SIZE = SIZES[sID];

			int** a = (int**)malloc(SIZE * sizeof(int*));
			int** b = (int**)malloc(SIZE * sizeof(int*));
			int** c = (int**)malloc(SIZE * sizeof(int*));

			for (i = 0; i < SIZE; i++) {
				  a[i] = (int*)malloc(SIZE * sizeof(int));
				  b[i] = (int*)malloc(SIZE * sizeof(int));
				  c[i] = (int*)malloc(SIZE * sizeof(int));
			}

			clock_t start, end; // объявляем переменные для определения времени выполнения


			srand(time(NULL)); // инициализируем параметры генератора случайных чисел
			for (i = 0; i < SIZE; i++) {
				  for (j = 0; j < SIZE; j++) {
						a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
						b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
				  }
			}

			start = clock();
			for (i = 0; i < SIZE; i++) {
				  for (j = 0; j < SIZE; j++) {
						elem_c = 0;
						for (r = 0; r < SIZE; r++)
							  elem_c = elem_c + a[i][r] * b[r][j];

						c[i][j] = elem_c;
				  }
			}
			end = clock();
			
			printf("%d\t%f\n", SIZE, (double)(end - start) * 1000.0 / CLOCKS_PER_SEC);

			for (i = 0; i < SIZE; i++) {
				  free(a[i]);
				  free(b[i]);
				  free(c[i]);
			}
			free(a);
			free(b);
			free(c);

	  }

	  return 0;
}