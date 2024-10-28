#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <random>
#include <Windows.h>
#include <conio.h>
#include <malloc.h>
#include <time.h>


int main(void) {

	  SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);

	  //Задание 1.1

	  srand(time(NULL));
	  int n = 10, size = 0, size2 = 0, *deg = NULL;

	  printf("Введите количество вершин: ");
	  scanf_s("%d", &n);
	  printf("Матрица смежности графа G\n");

	  int **G = (int**)malloc(n * sizeof(int*));
	  for (int i = 0; i < n; i++)
			G[i] = (int*)malloc(n * sizeof(int));

	  for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				  G[i][j] = rand() % 2;
				  G[j][i] = G[i][j];
				  if (i == j) 
						G[i][j] = 0;
			}
	  }
	  for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				  printf("%d ", G[i][j]);
			}
			printf("\n");
	  }

	  //Задание 1.2

	  for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				  size2 += G[i][j];
				  if (G[i][j] != 0) 
						size++;
			}
	  }
	  size /= 2;
	  printf("Размер графа G: %d\n", size);

	  //Задание 1.3

	  deg = (int*)malloc(n * sizeof(int));
	  for (int i = 0; i < n; i++)
			deg[i] = 0;

	  for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				  if (G[i][j] != 0)
						deg[i]++;
			}
	  }

	  for (int i = 0; i < n; i++)
			printf("Степень вершины %d = %d\n", i, deg[i]);

	  for (int i = 0; i < n; i++) {
			if (deg[i] == 0) printf("Вершина %d - изолированная\n", i);
			if (deg[i] == 1) printf("Вершина %d - концевая\n", i);
			if (deg[i] == n - 1) printf("Вершина %d - доминирующая\n", i);
	  }


	  //Задание 2.1
	  // Подсчет количества ребер для создания матрицы инцидентности
	  int count_edge = 0;
	  for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				  if (G[i][j] != 0)
						count_edge++;
	  }
	  int **incidenceMatrix = (int**)malloc(n * sizeof(int*));
	  for (int i = 0; i < n; i++) {
			incidenceMatrix[i] = (int*)malloc(count_edge * sizeof(int));
			for (int j = 0; j < count_edge; j++)
				  incidenceMatrix[i][j] = 0;
	  }
	  // Заполнение матрицы инцидентности
	  int edgeIndex = 0;
	  for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				  if (G[i][j] != 0) {
						incidenceMatrix[i][edgeIndex] = 1;
						incidenceMatrix[j][edgeIndex] = 1;
						edgeIndex++;
				  }
	  printf("\nМатрица инцидентности:\n");
	  for (int i = 0; i < n; i++) {
			for (int j = 0; j < count_edge; j++)
				  printf("%d ", incidenceMatrix[i][j]);
			printf("\n");
	  }

	  //Задание 2.2
	  printf("Размер графа = %d\n", count_edge);

	  //Задание 2.3
	  int* deg_inc = (int*)malloc(n * sizeof(int));
	  for (int i = 0; i < n; i++)
			deg_inc[i] = 0;
	  for (int i = 0; i < n; i++) {
			for (int j = 0; j < count_edge; j++) {
				  if (incidenceMatrix[i][j] != 0)
						deg_inc[i]++;
			}
	  }

	  for (int i = 0; i < n; i++)
			printf("Степень вершины %d = %d\n", i, deg_inc[i]);

	  for (int i = 0; i < n; i++) {
			if (deg_inc[i] == 0) printf("Вершина %d - изолированная\n", i);
			if (deg_inc[i] == 1) printf("Вершина %d - концевая\n", i);
			if (deg_inc[i] == n - 1) printf("Вершина %d - доминирующая\n", i);
	  }

	  return 0;
}