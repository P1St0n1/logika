//#include <stdio.h>
//#include <cstdlib>
//#include <malloc.h>
//#include <conio.h>
//#include <random>
//#include <time.h>
#include <iostream>
#include <Windows.h>
#include <queue>

using namespace std;

queue <int> Q;

int** createG(int size) {
      int** G = NULL;
      G = (int**)malloc(size * sizeof(int*));
      for (int i = 0; i < size; i++)
            G[i] = (int*)malloc(size * sizeof(int));
      for (int i = 0; i < size; i++)
            for (int j = i; j < size; j++) {
                  G[i][j] = rand() % 2;
                  if (i == j)
                        G[i][j] = 0;
                  G[j][i] = G[i][j];
            }
      return G;
}

void printG(int** G, int size) {
      for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                  cout << G[i][j] << " ";
            cout << endl;
      }
}

void bfs(int** G, int size, int s, int *vis) {
      Q.push(s);
      vis[s] = 1;
      cout << s << " ";

      while (!Q.empty()) {
            s = Q.front();
            Q.pop();
            for (int i = 0; i < size; i++) {
                  if (G[s][i] == 1 && vis[i] == 0) {
                        Q.push(i);
                        vis[i] = vis[s] + 1;
                        cout << i << " ";
                  }
            }
      }
}

int main(void) {
      SetConsoleCP(1251);
      SetConsoleOutputCP(1251);
      srand(time(NULL));

      int nG1 = 0;
      cout << "Введите количество вершин G1: ";
      cin >> nG1;

      int** G1 = createG(nG1);
      cout << "Граф G1" << endl;
      printG(G1, nG1);
    
      int* vis = (int*)malloc(nG1 * sizeof(int));
      for (int i = 0; i < nG1; i++)
            vis[i] = 0;

      cout << endl << "Обход в ширину:" << endl;
      bfs(G1, nG1, 0, vis);


      return 0;
}
