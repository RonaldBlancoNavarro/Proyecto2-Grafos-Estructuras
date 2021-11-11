#include "Grafo.h"
Grafo::Grafo() {

}

void Grafo::setVertices(vector <Vertice> v) {
	vertices = v;
}
void Grafo::setVertice(Vertice v) {
	vertices.push_back(v);
}

void Grafo::setAristaPos(int i, Arista v) {
	matriz[i].push_back(v);
}

void Grafo::setMatriz(vector <vector <Arista>> m) {
	matriz = m;
}

void Grafo::setVector(vector<Arista> v) {
	matriz.push_back(v);
}

void Grafo::setPeso(int i, int j, int peso) {
	matriz[i][j].setPeso(peso);
}
vector <Vertice> Grafo::getVertices() {
	return vertices;
}
vector <vector <Arista>> Grafo::getMatriz() {
	return matriz;
}

Vertice  Grafo::getVertice(int n) {
	return vertices[n];
}

void Grafo::mostarMatriz() {

	for (int i = 0; i < matriz.size(); i++)
	{
		for (int j = 0; j < matriz[i].size(); j++)
		{
			cout.width(4);
			cout << matriz[i][j].getPeso();
		}
		cout << endl;
	}
}