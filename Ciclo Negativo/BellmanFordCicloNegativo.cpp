#include <iostream>
#include <list>
#include <queue>

#include <bits/stdc++.h>
#define INFINITO 10000000
using namespace std;

class Grafo{
private:
    int Vertices;
    vector<pair<pair<int,int>, int> > arestas; //lista de arestas, con formato <origen,destino,peso>
    bool cicloNegativo = false;
public:
    Grafo(int Vertices){
        this->Vertices = Vertices;
    }
    void addAresta(int origem, int destino, int peso){
        arestas.push_back({{origem,destino}, peso});
    }
        bool bellmanFord(int origem){
        vector<int> distancia(this->Vertices, INFINITO);
        distancia[origem] = 0;

        vector<pair<pair<int,int>, int> >::iterator it;

        for (int i = 0; i < this->Vertices; i++){
            for (it = arestas.begin(); it != arestas.end(); ++it){
                int origem = it->first.first;
                int destino = it->first.second;
                int peso = it->second;
                //relaxamento arestas
                if (distancia[destino] > distancia[origem] + peso){
                    distancia[destino] = distancia[origem] + peso;
                }
            }
        }
        
        for (it = arestas.begin(); it != arestas.end(); ++it){
            int origem = it->first.first;
            int destino = it->first.second;
            int peso = it->second;
            //relaxamento arestas
            if (distancia[destino] > distancia[origem] + peso){
                this->cicloNegativo = true;
            }
        }
        if(!cicloNegativo){
            for(int i=0;i<Vertices;i++){
                cout << i << " - " << distancia[i] << endl;
            }
        }
        return this->cicloNegativo;
    }
};
int main(int argc, char const *argv[]){
    Grafo g(5);
    g.addAresta(0,1,-7);
    g.addAresta(0,4,-6);
    g.addAresta(1,2,-9);
    g.addAresta(1,3,-3);
    g.addAresta(2,0,-2);
    g.addAresta(2,3,-7);
    g.addAresta(3,4,-2);
    g.addAresta(4,1,-8);
    g.addAresta(4,2,-4);
    g.addAresta(4,3,-5);

    if(g.bellmanFord(2)){
        cout << "Ciclo Negativo";
    } else {
        cout << "Não existe ciclo negativo";
    }
    
    return 0;
}