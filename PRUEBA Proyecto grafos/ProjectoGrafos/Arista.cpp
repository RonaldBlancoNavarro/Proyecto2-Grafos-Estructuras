#include "Arista.h"

Arista::Arista() {

}

Arista::Arista(int p, vector<Vector2f> pos) {
	peso = p;
	font = new Font();
	font->loadFromFile("HU The Game.ttf");

	this->texto.setFont(*this->font);
	this->texto.setString(std::to_string(peso));
	this->texto.setFillColor(Color::Black);
	this->texto.setCharacterSize(20);
	this->texto.setPosition(pos[0].x + ((pos[1].x - pos[0].x) / 2), pos[0].y + ((pos[1].y - pos[0].y) / 2));

	this->posXY = pos;
}
void Arista::setPeso(int p) {
    peso = p;
	texto.setString(std::to_string(p));
}

int Arista::getPeso() {
    return peso;
}

void Arista::setPosIJ(Vector2i vec) {
    posIJ = vec;
}

Vector2i Arista::getPosIJ() {
    return posIJ;
}

vector<Vector2f> Arista::getXY() {
	return posXY;
}

void Arista::setTexto(Text t) {
	texto = t;
	string num = t.getString();
	peso = stoi(num);
}

Text Arista::getTexto() {
	return texto;
}