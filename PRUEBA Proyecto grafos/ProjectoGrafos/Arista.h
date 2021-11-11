#include <iostream>
#include <SFML/Graphics.hpp>
#include <string> 

using namespace sf;
using namespace std;
class Arista
{
private:
	Font* font;
	Text texto;

	int peso;
	Vector2i posIJ; // mostraba con que letra (vectores) tenia relacion
	vector<Vector2f> posXY;// posiciones para graficado

public:
	Arista();
	Arista(int, vector<Vector2f>);
	void setPeso(int);
	void setPosIJ(Vector2i);
	int getPeso();
	Vector2i getPosIJ();
	vector<Vector2f> getXY();
	void setTexto(Text);
	Text getTexto();

};

