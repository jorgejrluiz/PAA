// Implementação do algoritmo de Dijkstra
// Teste: http://br.spoj.com/problems/ENGARRAF/

#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // número de vértices
	// ponteiro para um array contendo as listas de adjacências
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; //seta numero de vertices do grafo
		/*
			cria a lista de adjacencias, 
			cada par é composto pelo vertice alcancado e o peso da aresta*
			*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de origem à destino
	void addAresta(int origem, int destino, int custo)
	{
		adj[origem].push_back(make_pair(destino, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int origem, int destino)
	{
		// vetor de distâncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		bool visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de origem para origem é 0
		dist[origem] = 0;

		// insere na fila
		pq.push(make_pair(dist[origem], origem));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[destino];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(6);	
	/*g.addAresta(0, 1, 5);
	g.addAresta(0, 7, 8);
	g.addAresta(0, 4, 9);

	g.addAresta(1, 7, 4);
	g.addAresta(1, 3, -3);
	g.addAresta(1, 2, 12);

	g.addAresta(3, 6, 9);

	g.addAresta(7, 2, 7);
	g.addAresta(7, 5, -1);

	g.addAresta(2, 6, 11);

	g.addAresta(4, 7, 5);
	g.addAresta(4, 5, -3);
	g.addAresta(4, 10, 6);

	g.addAresta(5, 2, 1);
	g.addAresta(5, 6, 13);
	*/
	g.addAresta(1,2,2);
	g.addAresta(1, 3, 3);
	g.addAresta(2,5,2);
	g.addAresta(3,4,-1);
	g.addAresta(4,5,3);
	cout << g.dijkstra(1, 5) << endl;

	return 0;
}