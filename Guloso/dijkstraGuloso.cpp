#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000
/*TODO: refatorar*/
using namespace std;

class Grafo{

private: 
    int Vertices; //Numero de vertices do grafo
    list< pair<int, int> >* verticesAdjacentes; //Lista de pares, com os vertices adjacentes e o peso da aresta

public:
    Grafo(int Vertices){
        this->Vertices = Vertices; //inicia numero de vertices

        verticesAdjacentes = new list<pair<int,int> >[Vertices]; //lista onde cada posição representa um vertice, e na posicao existe uma lista com os vertices adjacentes
    }

    void addAresta(int origem, int destino, int peso){
        verticesAdjacentes[origem].push_back(make_pair(destino,peso));
    }
    int dijkstra(int origem, int destino){
        int menorDistancia[Vertices];//distancia vertice origem até pos vetor
        
        //caso vertice já tenha sido verificado, não verificar again
        bool visitado[Vertices];

        priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > >fila; //fila de verificacoes das adjascencias

        for (int j = 0; j < Vertices; j++)
        {
           menorDistancia[j] = INFINITO;
           visitado[j] = false;
        }

        menorDistancia[origem] = 0;

        fila.push(make_pair(menorDistancia[origem], origem));
        while (!fila.empty())
        {
            pair<int, int> p = fila.top();
            int vertice = p.second; //vertice
            fila.pop(); //remove fila

            if(visitado[vertice] == false){
                visitado[vertice] == true;

                list<pair<int,int> >::iterator it;

                for (it = verticesAdjacentes[vertice].begin(); it != verticesAdjacentes[vertice].end(); it++ ){
                    int apontado = it->first;
                    int pesoAresta = it->second;

                    //relaxamento olhar livro cormen pag 497
                    /*o processo de relaxar uma aresta, consiste em testar se podemos melhor o caminho mais curto
                    para v encontrado até agora pela passagem atraves de u, nesse caso, 
                    atualizar o vetor de distancia*/
                    if (menorDistancia[apontado] > (menorDistancia[vertice] + pesoAresta)){
                        menorDistancia[apontado] = menorDistancia[vertice] + pesoAresta;
                        fila.push(make_pair(menorDistancia[apontado], apontado));
                    }
                }
                
            }
        }
        
        return menorDistancia[destino];
    }
};

int main(int argc, char const *argv[])
{
    Grafo g(6);
    g.addAresta(1,2,2);
	g.addAresta(1, 3, 3);
	g.addAresta(2,5,2);
	g.addAresta(3,4,-1);
	g.addAresta(4,5,3);
	cout << g.dijkstra(1, 5) << endl;
}
