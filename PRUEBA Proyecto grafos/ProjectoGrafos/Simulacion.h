#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grafo.h"
#include "Boton.h"
#include <vector>
#define INI 65
#define FIN 90
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
	Vector2i auxIJ;

	Vertice* vertice; // hay que meter este circulo dentro de la clase vertice y aqui manejas vertices con sus funcionalidades
	//vector<CircleShape> lts; // vertices
	//vector<vector<Vector2f>> lineas; // Guardado de todas las lineas
	vector<Vector2f> pos; // guarda las 2 coordenadas de las que se acomoda la linea en [0] - [1]
	
	Text* pesoArista;
	bool permisoDigitar;
	//vector<Text> pesosAristas;

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

