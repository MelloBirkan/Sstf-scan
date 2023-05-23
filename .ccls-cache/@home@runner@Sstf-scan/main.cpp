#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sstf(vector<int> fila, int cabeca) {
  int distancia= 0;

  while(!fila.empty()) {
    int menor = fila[0];
    vector<int>::iterator trilha_proxima;

    for (auto it = fila.begin(); it != fila.end(); ++it) {
      int diff = abs(cabeca - *it);
      if (diff < menor) {
        menor = diff;
        trilha_proxima = it;
      }
    }
    distancia += menor;
    cabeca = *trilha_proxima; 
    fila.erase(trilha_proxima); 
  }

  return distancia;
}

int scan(vector<int> fila, int cabeca) {
    int distancia = 0;

    sort(fila.begin(), fila.end());
  
    vector<int> esquerda, direita;
    for(int i = 0; i < fila.size(); i++) {
        if(fila[i] < cabeca)
            esquerda.push_back(fila[i]);
        else
            direita.push_back(fila[i]);
    }

    
    for(int i = esquerda.size() - 1; i >= 0; i--) {
        distancia += abs(cabeca - esquerda[i]);
        cabeca = esquerda[i];
    }
  
    for(int i = 0; i < direita.size(); i++) {
        distancia += abs(cabeca - direita[i]);
        cabeca = direita[i];
    }

    return distancia;
}

int main() {
  vector<int> memoria = {98, 183, 37, 122, 14, 124, 65, 67};
  int cabeca = 53;
  
  cout << "Distância total percorrida pela cabeça(SSTF): " << sstf(memoria, cabeca) << endl;
  
  cout << "Distância total percorrida pela cabeça(SCAN): " << scan(memoria, cabeca) << endl;
  return 0;
}
