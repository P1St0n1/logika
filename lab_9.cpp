#include <iostream>
#include <Windows.h>
#include <queue>
#include <climits>
#include <iomanip>

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
                  cout << setw(3) << G[i][j];
            cout << endl;
      }
}

void bfsd(int** G, int size, int s, int* dist) {
      Q.push(s);
      dist[s] = 0;

      while (!Q.empty()) {
            s = Q.front();
            Q.pop();
            for (int i = 0; i < size; i++) {
                  if (G[s][i] == 1 && dist[s] + 1 < dist[i]) {
                        Q.push(i);
                        dist[i] = dist[s] + 1;
                  }
            }
      }
}

int main(void) {

      SetConsoleCP(1251);
      SetConsoleOutputCP(1251);
      srand(time(NULL));

      int nG1 = 0, s = 0;
      cout << "Введите количество вершин G1: ";
      cin >> nG1;

      cout << "Введите стартовую вешину: ";
      cin >> s;

      int** G1 = createG(nG1);
      cout << "Граф G1" << endl;
      printG(G1, nG1);

      int* dist = (int*)malloc(nG1 * sizeof(int));
      for (int i = 0; i < nG1; i++)
            dist[i] = INT_MAX;

      bfsd(G1, nG1, s, dist);
      for (int i = 0; i < nG1; i++) {
            cout << "Расстояние от " << s << " вершины до " << i << " вершины = " << dist[i] << endl;
      }
    
      return 0;
}
