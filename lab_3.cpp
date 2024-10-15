#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct node {
	  char inf[256];  // полезная информация
	  struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;
char ch = '+';
int n = 0;

// Функции добавления элемента, просмотра списка
int spstore(void);
void review(void), del();

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента



struct node* get_struct(void)
{
	  struct node* p = NULL;
	  char s[256];

	  if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	  {
			printf("Ошибка при распределении памяти\n");
			exit(1);
	  }

	  printf("Введите название объекта: \n");   // вводим данные
	  scanf("%s", s);
	  fflush(stdin);
	  if (*s == 0) {
			printf("Запись не была произведена\n");
			return NULL;
	  }
	  strcpy(p->inf, s);

	  p->next = NULL;

	  return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
int spstore(void) {
	  struct node* p = NULL;
	  struct node* struc = head;

	  p = get_struct();
	  if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	  {
			head = p;
			last = p;
	  }
	  else if (head != NULL && p != NULL) {
			last->next = p;
			last = p;
	  }
	  printf("Продолжить ввод? (+ или -)\n");
	  scanf(" %c", &ch);
	  getchar();
	  if (ch == '+') {
			n = 1;
	  }
	  else {
			n = 0;
	  }

	  return n;
}


/* Просмотр содержимого списка. */
void review(void)
{
	  struct node* struc = head;
	  if (head == NULL) {
			printf("Список пуст\n");
	  }
	  while (struc) {
			printf("Имя - %s \n", struc->inf);
			struc = struc->next;
	  }
	  return;
}




/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	  struct node* struc = head;
	  if (head == NULL) {
			printf("Список пуст\n");
	  }
	  while (struc) {
			if (strcmp(name, struc->inf) == 0) {
				  return struc;
			}
			struc = struc->next;
	  }
	  printf("Элемент не найден\n");
	  return NULL;
}

/*Удаление элемента по содержимому*/
void del()
{
	  struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	  struct node* prev = NULL;// указатель на предшествующий удаляемому элемент

	  if (head == NULL) // если голова списка равна NULL, то список пуст
	  {
			printf("Список пуст\n");
			return;
	  }

	  prev = struc->next;
	  head = prev;
	  free(struc);

}


int main(void) {

	  SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);

	  printf("Символ окончания ввода: - \n");
	  spstore();

	  while (n == 1)
			n = spstore();
	  review();
	  del();

	  return 0;
}