#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
enum estados_submenu { SBMN_INACTIVO = 0, SBMN_SUBMENU };
class Simulacion
{
private:
	RenderWindow* ventana;
	Sprite* sprite;
	CircleShape shape;
public:
	Simulacion();
	void dibujarVentana();
	void mostrarVentana();
	void graficar();
	void procesarEventos();
};

