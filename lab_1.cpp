﻿#include <stdio.h>
#include <limits.h>
#include <random>
#include <time.h>

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

	  

	  return 0;
}
