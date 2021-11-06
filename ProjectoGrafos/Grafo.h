#include <iostream>
#include <vector>
#include "Arista.h"
#include "Vertice.h"

class Grafo{

private:
	vector <Vertice> *vertices;
	vector <vector <Arista>> *matriz;

public:
	Grafo();

	void setVertices(vector <Vertice> *v);
	void setMatriz(vector <vector <Arista>> *m);

	vector <Vertice>* getVertices();
	vector <vector <Arista>>* getMatriz();

};

