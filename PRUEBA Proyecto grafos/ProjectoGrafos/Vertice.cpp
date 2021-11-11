#include "Vertice.h"

//Vertice::Vertice(string letra, Vector2i xy, int posIJ) : texto(texto), xy(xy), posIJ(posIJ) {
//
//}

Vertice::Vertice(string letra, Vector2f xY, int posIj) {
	
	// creacion de boton
	xY.x = xY.x - 10;
	xY.y = xY.y - 10;
	this->estadoVertice = BTN_VINACTIVO;
	this->figura.setPosition(xY);
	this->figura.setRadius(15);

	font = new Font();
	font->loadFromFile("HU The Game.ttf");

	this->texto.setFont(*this->font);
	this->texto.setString(letra);
	this->texto.setFillColor(Color::Black);
	this->texto.setCharacterSize(20);
	this->texto.setPosition(
		this->figura.getPosition().x + (this->figura.getGlobalBounds().width / 2.f) - this->texto.getGlobalBounds().width / 2.f,
		this->figura.getPosition().y + (this->figura.getGlobalBounds().height / 2.f) - this->texto.getGlobalBounds().height / 2.f);


	this->colorInactivo = Color::Blue;
	this->colorHover = Color::Green;
	this->colorActivo = Color::Red;
	this->colorSelected = Color::Cyan;

	this->posIJ = posIj;
 }

void Vertice::setEstadoBoton(short unsigned estadoVertice)
{
	this->estadoVertice = estadoVertice;
}

void Vertice::actualizarBoton(Vector2f posMouse)
{
	// actualizacion de estado de boton

	//inactivo
	this->estadoVertice = BTN_VINACTIVO;

	// hover
	if (this->figura.getGlobalBounds().contains(posMouse))
	{
		this->estadoVertice = BTN_VHOVER;

		//activo
		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->estadoVertice = BTN_VACTIVO;
		}
	}

	switch (estadoVertice) // cambio color
	{
	case BTN_VINACTIVO:
		this->figura.setFillColor(this->colorInactivo);
		break;
	case BTN_VHOVER:
		this->figura.setFillColor(this->colorHover);
		break;
	case BTN_VACTIVO:
		this->figura.setFillColor(this->colorActivo);
		break;
	default:
		this->figura.setFillColor(this->colorInactivo);
		break;
	}
}

bool Vertice::procesarBoton(RenderWindow* ventana) // graficar boton en pantalla
{

	ventana->draw(figura);
	ventana->draw(texto);

	if (estadoVertice == BTN_VACTIVO) {
		return true;
	}
	else {
		return false;
	}
}

void Vertice::setPosicion(Vector2f p) {
	this->figura.setPosition(p);
	this->texto.setPosition(
		this->figura.getPosition().x + (this->figura.getGlobalBounds().width / 2.f) - this->texto.getGlobalBounds().width / 2.f,
		this->figura.getPosition().y + (this->figura.getGlobalBounds().height / 2.f) - this->texto.getGlobalBounds().height / 2.f);
}

Vector2f Vertice ::getPosicion() {
	return figura.getPosition();
}

void Vertice::setTexto(string s) {
	texto.setString(s);
}
string Vertice::getTexto() {
	return texto.getString();
}

void Vertice::setPosIJ(int posIJ) {
	this->posIJ = posIJ;
}

int Vertice::getPosIJ() {
	return posIJ;
}


