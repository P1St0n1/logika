#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <random>
#include <time.h>
#include <Windows.h>
#include <string.h>

typedef struct student {
	  char last_name[20];
	  char name[20], faculty[20];
	  int num_zach;
	  struct student* next;
} stud;

void print_struct(stud* head);

int main(void) {

	  srand(time(0));
	  //Задание 1
	  int x[10] = { 0 };
	  int min = INT_MAX, max = INT_MIN;

	  for (int i = 0; i < 10; i++) {
			x[i] = i * 3 - 10;
			printf("%d ", x[i]);
	  }
	  for (int i = 0; i < 10; i++) {
			if (x[i] >= max)
				  max = x[i];
			if (x[i] <= min)
				  min = x[i];
	  }
	  printf("\nmax = %d min = %d", max, min);
	  printf("\nresult = %d\n", max - min);

	  //Задание 2
	  int arr[10] = { 0 };

	  for (int i = 0; i < 10; i++) {
			arr[i] = rand() % 100;
			printf("%d ", arr[i]);
	  }

	  printf("\nn = ");

	  //Задание 3
	  int* mas;
	  int n = 0;
	  scanf_s("%d", &n);

	  mas = (int*)malloc(n * sizeof(int));

	  for (int i = 0; i < n; i++) {
			printf("%d ", i * 3 - 10);
	  }
	  free(mas);

	  printf("\n\n\n");

	  //Задание 4
	  SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);

	  int b = 0, sum = 0;

	  printf("Введите количество строк/столбцов квадратного массива: ");
	  scanf("%d", &b);

	  int** a = (int**)malloc(b * sizeof(int*));

	  for (int i = 0; i < b; i++) {
			a[i] = (int*)malloc(b * sizeof(int));
			for (int j = 0; j < b; j++) {
				  printf("a[%d][%d] = ", i, j);
				  scanf("%d", &a[i][j]);
			}
	  }

	  for (int i = 0; i < b; i++) {
			int sum = 0;
			for (int j = 0; j < b; j++) {
				  printf("%d\t", a[i][j]);
				  sum += a[i][j];
			}
			printf("sum = %d\n", sum);
	  }

	  int count = 0;

	  for (int i = 0; i < b; i++) {
			for (int j = 0; j < i + 1; j++) {
				  if (a[i][j] == 0) {
							  count += 1;
				  }
			}
	  }
	  printf("Количество 0-элементов на главной диагонали и ниже: %d\n", count);
	  for (int i = 0; i < b; i++)
			free(a[i]);
	  free(a);


	  //Задание 5

	  char sim = 0;
	  scanf("%c", &sim);

	  stud* head = NULL;
	  stud* tail = NULL;

	  while (sim != '+') {
			stud* newData = (stud*)malloc(sizeof(stud));

			printf("Введите фамилию студента\n");
			scanf("%s", &newData->last_name);

			printf("Введите имя студента\n");
			scanf("%s", &newData->name);

			printf("Введите название факультета студента\n");
			scanf("%s", &newData->faculty);

			printf("Введите номер зачётной книжки студента\n");
			scanf("%d", &newData->num_zach);

			newData->next = NULL;

			if (head == NULL) {
				  head = newData;
				  tail = newData;
			}
			else {
				  tail->next = newData;
				  tail = newData;
			}

			printf("\n\nЧтобы закончить введите '+', иначе введите любой другой символ\n");
			getchar();
			scanf("%c", &sim);
			printf("\n\n");
	  }


	  print_struct(head);

	  printf("\nВведите фамилию студента: ");
	  char f[20];
	  scanf("%s", &f);

	  stud* ptr = head;

	  while (ptr != NULL) {
			stud* tmp = ptr;
			if (strcmp(f, tmp->last_name) == 0) {
				  printf("%-10s %-10s %-10s %-7d\n", tmp->last_name, tmp->name, tmp->faculty, tmp->num_zach);
			}
			ptr = ptr->next;
	  }

	  stud* pt = head;
	  while (pt != NULL) {
			stud* tmp = pt;
			pt = pt->next;
			free(tmp);
	  }

	  return 0;
}



void print_struct(stud* head) {
			printf("\n");

			stud* ptr = head;
			while (ptr != NULL) {
				  printf("%-10s %-10s %-10s %-7d\n", ptr->last_name, ptr->name, ptr->faculty, ptr->num_zach);

				  ptr = ptr->next;
			}

			printf("\n");
}
