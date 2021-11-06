#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Arista
{
private:
	int peso;
	Vector2i posIJ;
public:
	Arista(int);
	void setPeso(int);
	void setPosIJ(Vector2i);
	int getPeso();
	Vector2i getPosIJ();
};

