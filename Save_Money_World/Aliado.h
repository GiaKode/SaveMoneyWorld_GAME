#pragma once
#include"Movimiento.h"
#include"Heroe.h"

class Aliado : public Movimiento
{
private:
	int direcciones;
public:
	Aliado(int x, int y, int ancho, int alto) :Movimiento(ancho, alto) {
		//x = rand() % 600 + 200;
		//y = rand() % 500;
		this->x = x;
		this->y = y;
		dx = dy = 30;
		//idY = 2;

	}
	~Aliado() {}

	void movimientos(Graphics^ g) {


		if (x + ancho * 1.0 <= g->VisibleClipBounds.Width) {
			x += dx;
			idY = 2;
		}
		idX++;
		if (idX > 2)idX = 0;

	}



};
