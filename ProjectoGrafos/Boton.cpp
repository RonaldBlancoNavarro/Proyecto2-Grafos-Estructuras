#include "Boton.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Boton::Boton()
{
	estadoBoton = BTN_INACTIVO;
	font = new Font();
}

Boton::Boton(float x, float y, float ancho, float alto, Font* font, string texto, int tamText, Color colorInactivo, Color colorHover, Color colorActivo)
{	// creacion de boton
	this->estadoBoton = BTN_INACTIVO;

	this->figura.setPosition(Vector2f(x, y));
	this->figura.setSize(Vector2f(ancho, alto));

	this->font = font;
	this->texto.setFont(*this->font);
	this->texto.setString(texto);
	this->texto.setFillColor(Color::Black);
	this->texto.setCharacterSize(tamText);
	this->texto.setPosition(
		this->figura.getPosition().x + (this->figura.getGlobalBounds().width / 2.f) - this->texto.getGlobalBounds().width / 2.f,
		this->figura.getPosition().y + (this->figura.getGlobalBounds().height / 2.f) - this->texto.getGlobalBounds().height / 2.f);


	this->colorInactivo = colorInactivo;
	this->colorHover = colorHover;
	this->colorActivo = colorActivo;
	this->colorSelected = Color::Cyan;
}

void Boton::actualizarBoton(Vector2f posMouse) 
{
	// actualizacion de estado de boton

	//inactivo
	this->estadoBoton = BTN_INACTIVO;

	// hover
	if (this->figura.getGlobalBounds().contains(posMouse))
	{
		this->estadoBoton = BTN_HOVER;

		//activo
		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->estadoBoton = BTN_ACTIVO;
		}
	}

	switch (estadoBoton) // cambio color
	{
	case BTN_INACTIVO:
		this->figura.setFillColor(this->colorInactivo);
		break;
	case BTN_HOVER:
		this->figura.setFillColor(this->colorHover);
		break;
	case BTN_ACTIVO:
		this->figura.setFillColor(this->colorActivo);
		break;
	default:
		this->figura.setFillColor(this->colorInactivo);
		break;
	}
}

bool Boton::procesarBoton(RenderWindow* ventana) // graficar boton en pantalla
{

	ventana->draw(figura);
	ventana->draw(texto);

	if (estadoBoton == BTN_ACTIVO) {
		return true;
	}
	else {
		return false;
	}
}

void Boton::setEstadoBoton(short unsigned estadoBoton)
{
	this->estadoBoton = estadoBoton;
}
void Boton::setBounds(Vector2f b) {
	this->figura.setSize(b);
}

void Boton::setPosicion(Vector2f p) {
	this->figura.setPosition(p);
	this->texto.setPosition(
		this->figura.getPosition().x + (this->figura.getGlobalBounds().width / 2.f) - this->texto.getGlobalBounds().width / 2.f,
		this->figura.getPosition().y + (this->figura.getGlobalBounds().height / 2.f) - this->texto.getGlobalBounds().height / 2.f);
}