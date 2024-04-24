#pragma once
#include"Movimiento.h"

class Vida : public Movimiento {
private:

public:
	Vida(int x, int y, int ancho, int alto) :Movimiento(ancho, alto) {
		this->x = x;
		this->y = y;
		idX = idY = 0;
		dx = dy = 0;

	}
};