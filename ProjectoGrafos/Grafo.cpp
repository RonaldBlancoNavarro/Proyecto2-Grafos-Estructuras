#include "Grafo.h"
Grafo::Grafo() {
	vertices = new vector <Vertice>();
	matriz = new vector <vector <Arista>>();
}

void Grafo::setVertices(vector <Vertice>* v) {
	vertices = v;
}
void Grafo::setMatriz(vector <vector <Arista>>* m) {
	matriz = m;
}

vector <Vertice>* Grafo::getVertices() {
	return vertices;
}
vector <vector <Arista>>* Grafo::getMatriz() {
	return matriz;
}
