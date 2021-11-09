#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grafo.h"
#include "Boton.h"
#include <vector>
using namespace sf;
using namespace std;
enum estados_submenu { SBMN_INACTIVO = 0, MENU_PRINCIPAL, SBMN_SUBMENU, SBMN_SIMULACION };
class Simulacion
{
private:

	Grafo *grafo;
	RenderWindow* ventana;
	Texture* imagen;
	Sprite* sprite;

	Font* font;
	Text titulo;
	float centro;

	RectangleShape rectangle;
	CircleShape* vertice;
	vector<CircleShape> lts;
	vector<vector<Vector2f>> lineas;
	vector<Vector2f> pos;
	
	Text* pesoArista;
	bool permisoDigitar;
	vector<Text> pesosAristas;

	short unsigned estadoSubmenu; // unsigned es para no aceptar negativos

	Boton* btnNuevaSimulacion;
	Boton* btnSalir;

	//CircleShape shape;
public:
	Simulacion();
	void dibujarVentana();
	void mostrarVentana();
	void graficar();
	void procesarEventos();
	void graficarLineasAndPuntos();
	void agregarLinea();
	void agregarVertice(Vector2f);
	void modificarPesoArista(Event event);
};

