#include "Arista.h"

Arista::Arista(int peso): peso(peso) {

}

void Arista::setPeso(int p) {
    peso = p;
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