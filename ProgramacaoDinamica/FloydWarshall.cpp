#include<stdio.h> 
#include <iostream>
#define INF 99999
#define vertices 4

using namespace std;

int floydWarshall (int grafo[][vertices], int origem, int destino){
    int distancia[vertices][vertices], linha,coluna,k;
    
    for (linha = 0; linha < vertices; linha++){
        for (coluna = 0; coluna < vertices; coluna++){
            distancia[linha][coluna] = grafo[linha][coluna];
        }
    }

    for (k = 0; k < vertices; k++){
        for (linha = 0; linha < vertices; linha++){
            for (coluna = 0; coluna < vertices; coluna++)
            {   
                int custo = distancia[linha][k] + distancia[k][coluna];
                if(custo < distancia[linha][coluna]){
                    distancia[linha][coluna] = custo;
                }
            }
        }        
    }
    return distancia[origem][destino];
}

int main(int argc, char const *argv[]){
    
int grafo[vertices][vertices] = { {0,   5,  INF, 7}, 
                                {INF, 0,   3, INF}, 
                                {INF, INF, 0,   1}, 
                                {INF, INF, INF, 0} 
                                };
    cout << floydWarshall(grafo, 0,3) ;
}