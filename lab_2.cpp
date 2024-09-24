////Задание 1
//const int NUM_SIZES = 7;
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <malloc.h>
//#include <conio.h>
//
//int main(void) {
//
//	  const int SIZES[NUM_SIZES] = { 100, 200, 400, 1000, 2000, 4000, 10000 };
//
//	  int i = 0, j = 0, r = 0, elem_c = 0;
//	  setvbuf(stdin, NULL, _IONBF, 0);
//	  setvbuf(stdout, NULL, _IONBF, 0);
//
//
//	  for (int sID = 0; sID < NUM_SIZES; sID++) {
//
//			int SIZE = SIZES[sID];
//
//			int** a = (int**)malloc(SIZE * sizeof(int*));
//			int** b = (int**)malloc(SIZE * sizeof(int*));
//			int** c = (int**)malloc(SIZE * sizeof(int*));
//
//			for (i = 0; i < SIZE; i++) {
//				  a[i] = (int*)malloc(SIZE * sizeof(int));
//				  b[i] = (int*)malloc(SIZE * sizeof(int));
//				  c[i] = (int*)malloc(SIZE * sizeof(int));
//			}
//
//			clock_t start, end; // объявляем переменные для определения времени выполнения
//
//
//			srand(time(NULL)); // инициализируем параметры генератора случайных чисел
//			for (i = 0; i < SIZE; i++) {
//				  for (j = 0; j < SIZE; j++) {
//						a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
//						b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
//				  }
//			}
//
//			start = clock();
//			for (i = 0; i < SIZE; i++) {
//				  for (j = 0; j < SIZE; j++) {
//						elem_c = 0;
//						for (r = 0; r < SIZE; r++)
//							  elem_c = elem_c + a[i][r] * b[r][j];
//
//						c[i][j] = elem_c;
//				  }
//			}
//			end = clock();
//			
//			printf("%d\t%f\n", SIZE, (double)(end - start) * 1000.0 / CLOCKS_PER_SEC);
//
//			for (i = 0; i < SIZE; i++) {
//				  free(a[i]);
//				  free(b[i]);
//				  free(c[i]);
//			}
//			free(a);
//			free(b);
//			free(c);
//
//	  }
//
//	  return 0;
//}


////Задание 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>
#include <random>
#include <time.h>
#include <stdlib.h>

void ShellSort(int n, int arr[]) {

	  int tmp = 0, j = 0, i = 0, step = 0;
	  for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++) {
				  tmp = arr[i];
				  for (j = i; j >= step; j -= step) {
						if (tmp < arr[j - step])
							  arr[j] = arr[j - step];
						else
							  break;
				  }
				  arr[j] = tmp;
			}

}

void qs(int* items, int left, int right) /*вызов функции: qs(items, 0, count-1);*/
{
	  int i = 0, j = 0, x = 0, y = 0;

	  i = left; j = right;

	  /* выбор компаранда */
	  x = items[(left + right) / 2];

	  do {
			while ((items[i] < x) && (i < right)) i++;
			while ((x < items[j]) && (j > left)) j--;

			if (i <= j) {
				  y = items[i];
				  items[i] = items[j];
				  items[j] = y;
				  i++; j--;
			}
	  } while (i <= j);

	  if (left < j)
			qs(items, left, j);
	  if (i < right)
			qs(items, i, right);
}

int compare(const void* x1, const void* x2)   /*функция сравнения элементов массива*/
{
	  return (*(int*)x1 - *(int*)x2);              /*если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2*/
}


int main(void) {

	  SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);

	  srand(time(NULL));

	  clock_t start, end;

	  int size = 0;
	  printf("Введите размер массива: ");
	  scanf_s("%d", &size);
	  /*Метод Шелла*/
	  int* a = (int*)malloc(size * sizeof(int));
	  //printf("Исходный массив:\n");
	  for (int i = 0; i < size; i++) {
			if (i < size / 2)
				  a[i] = i;
			else
				  a[i] = size - (size / 2 - i);
			//printf("%d   ", a[i]);
	  }
	  printf("\n\n");

	  start = clock();
	  ShellSort(size, a);
	  end = clock();

	  //printf("Отсортированный массив методом Шелла:\n");
	  //for (int i = 0; i < size; i++)
			//printf("%d   ", a[i]);
	  printf("\nВремя выполнения сортировки в мс: %f\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

	  free(a);

	  printf("\n\n");
	  /*Метод qs*/
	  int* b = (int*)malloc(size * sizeof(int));
	  //printf("Исходный массив:\n");
	  for (int i = 0; i < size; i++) {
			if (i < size / 2)
				  b[i] = i;
			else
				  b[i] = size - (size / 2 - i);
			//printf("%d   ", a[i]);
	  }
	  printf("\n\n");

	  start = clock();
	  qs(b, 0, size - 1);
	  end = clock();

	  //printf("Отсортированный массив методом qs:\n");
	  //for (int i = 0; i < size; i++)
			//printf("%d   ", b[i]);
	  printf("\nВремя выполнения сортировки в мс: %f\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

	  free(b);

	  /*Метод qsort*/
	  int* c = (int*)malloc(size * sizeof(int));
	  //printf("Исходный массив:\n");
	  for (int i = 0; i < size; i++) {
			if (i < size / 2)
				  c[i] = i;
			else
				  c[i] = size - (size / 2 - i);
			//printf("%d   ", c[i]);
	  }
	  printf("\n\n");

	  start = clock();
	  qsort(c, size, sizeof(int), compare);
	  end = clock();

	  //printf("Отсортированный массив методом qsort:\n");
	  //for (int i = 0; i < size; i++)
			//printf("%d   ", c[i]);
	  printf("\nВремя выполнения сортировки в мс: %f\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

	  free(c);

	  return 0;	  
}