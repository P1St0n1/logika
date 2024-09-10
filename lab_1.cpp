#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <random>
#include <time.h>
#include <Windows.h>
#include <string.h>

struct student {
	  char last_name[20];
	  char name[20], faculty[20];
	  int num_zach;
};

void print_struct(struct student* p_stud) {

	  size_t len;

	  for (int i = 0; i < 3; i++) {
			len = strlen(p_stud[i].last_name);
			if (len > 0 && p_stud[i].last_name[len - 1] == '\n')
				  p_stud[i].last_name[len - 1] = '\0';

			len = strlen(p_stud[i].name);
			if (len > 0 && p_stud[i].name[len - 1] == '\n')
				  p_stud[i].name[len - 1] = '\0';

			len = strlen(p_stud[i].faculty);
			if (len > 0 && p_stud[i].faculty[len - 1] == '\n')
				  p_stud[i].faculty[len - 1] = '\0';

			printf("%-10s", p_stud[i].last_name);
			printf("%-10s", p_stud[i].name);
			printf("%-10s", p_stud[i].faculty);
			printf("%-7d", p_stud[i].num_zach);
			printf("\n");
	  }
};

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
	  int a[10] = { 0 };

	  for (int i = 0; i < 10; i++) {
			a[i] = rand() % 100;
			printf("%d ", a[i]);
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
	  int arr[5][5] = { 0 };

	  for (int i = 0; i < 5; i++) {
			int sum = 0;
			for (int j = 0; j < 5; j++) {
				  arr[i][j] = (i + j) * 2 - 5;
				  sum += arr[i][j];
				  printf("%d\t", arr[i][j]);
			}
			printf("sum = %d\n", sum);
	  }

	  //Задание 5
	  SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);
	  
	  struct student stud[3];

	  for (int i = 0; i < 3; i++) {
			printf("Введите фамилию студента %d\n", i + 1);
			getchar();
			fgets(stud[i].last_name, sizeof stud[i].last_name, stdin);

			printf("Введите имя студента %d\n", i + 1);
			fgets(stud[i].name, sizeof stud[i].name, stdin);

			printf("Введите название факультета студента %d\n", i + 1);
			fgets(stud[i].faculty, sizeof stud[i].faculty, stdin);

			printf("Введите номер зачётной книжки студента %d\n", i + 1);
			scanf("%d", &stud[i].num_zach);
	  }

	  printf("\n\n\n");

	  struct student* ps = stud;

	  print_struct(ps);

	  printf("\nВведите фамилию студента: ");
	  char f[20];
	  scanf("%s", f);

	  for (int i = 0; i < 3; i++) {
			if (strcmp(f, stud[i].last_name) == 0) {
				  printf("%-10s", stud[i].last_name);
				  printf("%-10s", stud[i].name);
				  printf("%-10s", stud[i].faculty);
				  printf("%-7d", stud[i].num_zach);
			}
	  }

	  return 0;
}
