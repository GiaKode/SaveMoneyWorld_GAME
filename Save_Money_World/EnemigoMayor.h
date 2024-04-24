#pragma once
#pragma once
#include"Movimiento.h"


class EnemigoMayor : public Movimiento
{
private:
	int direcciones;
public:
	EnemigoMayor(int ancho, int alto, int direcciones) :Movimiento(ancho, alto) {
		this->direcciones = direcciones;
		x = 800;
		y = 5;
		dx = dy = 3;

	}
	~EnemigoMayor() {}

	void movimientos(Graphics^ g, Heroe* jugador) {
		if (direcciones == 1) {

			if (x == jugador->getX()) {
				x += 0;
			}
			else if (x > jugador->getX()) {
				x -= dx;
				idY = 1;
			}
			else if (x < jugador->getX()) {
				x += dx;
				idY = 2;
			}
			if (y == jugador->getY()) {
				y += 0;
			}
			else if (y > jugador->getY()) {
				y -= dy;
				idY = 3;
			}
			else if (y < jugador->getY()) {
				y += dy;
				idY = 0;
			}
		}
		idX++;
		if (idX > 2)idX = 0;
	}



};


