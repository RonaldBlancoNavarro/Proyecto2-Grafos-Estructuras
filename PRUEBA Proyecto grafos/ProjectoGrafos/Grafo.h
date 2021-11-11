#include <iostream>
#include <vector>
#include "Arista.h"
#include "Vertice.h"

class Grafo{

private:
	vector <Vertice> vertices;
	vector <vector <Arista>> matriz;

public:
	Grafo();

	void setVertices(vector <Vertice> v);
	void setMatriz(vector <vector <Arista>> m);
	void setVertice(Vertice);
	void setAristaPos(int, Arista);
	void setVector(vector<Arista>);
	void setPeso(int, int, int);
	vector <Vertice> getVertices();
	Vertice getVertice(int);
	vector <vector <Arista>> getMatriz();

	void mostarMatriz();

};

