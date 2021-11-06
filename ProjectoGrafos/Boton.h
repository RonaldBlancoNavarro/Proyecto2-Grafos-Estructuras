#pragma once
#ifndef BOTON_H
#define BOTON_H
#include <SFML/Graphics.hpp>
//#include "Matriz.h"
#include <iostream>

using namespace sf;// este es para usar el SFML
using namespace std;

enum estados_boton { BTN_INACTIVO = 0, BTN_HOVER, BTN_ACTIVO};

class Boton {


private:
	short unsigned estadoBoton; // unsigned es para no aceptar negativos

	RectangleShape figura;
	Font* font;
	Text texto;

	Color colorInactivo;
	Color colorHover;
	Color colorActivo;
	Color colorSelected;


public:
	Boton();

	Boton(float x, float y, float ancho, float alto, Font* font, string texto, int tamText,
		Color colorInactivo, Color colorHover, Color colorActivo);
	void actualizarBoton(Vector2f posMouse);
	bool procesarBoton(RenderWindow* ventana);
	void setEstadoBoton(short unsigned estadoBoton);
	void setPosicion(Vector2f);
	void setBounds(Vector2f);
};

#endif