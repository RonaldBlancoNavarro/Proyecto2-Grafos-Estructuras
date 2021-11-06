#include "Vertice.h"

Vertice::Vertice(string letra, Vector2i xy, int posIJ) : letra(letra), xy(xy), posIJ(posIJ) {

}

void Vertice::setLetra(string letra) {
	this->letra = letra;
}

void Vertice::setXY(Vector2i xy) {
	this->xy = xy;
}

void Vertice::setPosIJ(int posIJ) {
	this->posIJ = posIJ;
}

string Vertice::getLetra() {
	return letra;
}

Vector2i Vertice::getXY() {
	return xy;
}

int Vertice::getPosIJ() {
	return posIJ;
}


