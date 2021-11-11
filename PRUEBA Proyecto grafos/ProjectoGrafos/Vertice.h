#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum estados_vertice { BTN_VINACTIVO = 0, BTN_VHOVER, BTN_VACTIVO };

class Vertice
{
private:

	CircleShape figura;
	Font* font;
	Text texto;

	short unsigned estadoVertice; // unsigned es para no aceptar negativos

	Color colorInactivo;
	Color colorHover;
	Color colorActivo;
	Color colorSelected;

	int posIJ;

public:
	Vertice(string , Vector2f , int );

	void setEstadoBoton(short unsigned estadoVertice);
	void actualizarBoton(Vector2f posMouse);
	bool procesarBoton(RenderWindow* ventana);

	void setPosicion(Vector2f);
	Vector2f getPosicion();

	void setTexto(string);
	string getTexto();

	void setPosIJ(int);
	int getPosIJ();

};

