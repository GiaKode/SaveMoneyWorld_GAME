#pragma once
#pragma once
#include"Movimiento.h"
#include"Heroe.h"

class EnemigoMenor : public Movimiento
{
private:
	int direcciones;
public:
	EnemigoMenor(int ancho, int alto, int direcciones) :Movimiento(ancho, alto) {
		this->direcciones = direcciones;
		x = rand() % 600 + 200;
		y = rand() % 500;
		dx = dy = 9;

	}
	~EnemigoMenor() {}

	void movimientos(Graphics^ g) {

		if (direcciones == 1)
		{
			if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x - 100 < 0)
				dx *= -1;
			if (dx > 0) {
				idY = 2;
			}
			else idY = 1;
			x += dx;
		}
		else
		{
			if (y + alto * 1.0 > g->VisibleClipBounds.Height || y < 0)
				dy *= -1;
			if (dy > 0) {
				idY = 0;
			}
			else idY = 3;
			y += dy;
		}
		idX++;
		if (idX > 3)idX = 0;
	}



};

