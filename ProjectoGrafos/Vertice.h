#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Vertice
{
private:
	string letra;
	Vector2i xy;
	int posIJ;

public:
	Vertice(string, Vector2i, int);
	
	void setLetra(string);
	void setXY(Vector2i);
	void setPosIJ(int);
	string getLetra();
	Vector2i getXY();
	int getPosIJ();

};

