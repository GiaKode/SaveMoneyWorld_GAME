#pragma once
#include"Movimiento.h"

class Heroe : public Movimiento
{
private:
	int vida;
	int vidaN2;

public:
	Heroe(int x, int y, int ancho, int alto) :Movimiento(ancho, alto) {
		vida = 3;
		vidaN2 = 6;
		//x = 0;
		//y = 300;
		this->x = x;
		this->y = y;
		dx = dy = 10;
	}

	~Heroe() {}

	void movimientos(Graphics^ g, char i) {

		switch (i)
		{
		case 'A':
			if (x > 0) {
				x -= dx;
				idX = 3;
			}
			break;

		case 'D':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idX = 2;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idX = 1;
			}
			break;

		case 'S':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idX = 0;
			}
			break;
		}

		idY++;
		if (idY >= 2)idY = 0;
	}

	int getVida() { return vida; }
	int getVidaN2() { return vidaN2; }


	void BajaVida() { vida--; }
	void BajaVidaN2() { vidaN2--; }



};


