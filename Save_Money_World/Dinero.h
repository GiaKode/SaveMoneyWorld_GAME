#pragma once
#include"Movimiento.h"

class Dinero : public Movimiento
{
private:

public:
	Dinero() :Movimiento(ancho, alto) {
		x = 130 + rand() % 700;
		y = 40 + rand() % 600;
		dx = dy = 0;
		ancho = alto = 20;
	}
	~Dinero() {}

	void dibujarDinero(Graphics^ g) {
		SolidBrush^ b = gcnew SolidBrush(Color::Yellow);
		Pen^ p = gcnew Pen(Color::Black, 5);
		g->DrawEllipse(p, x, y, ancho, alto);
		g->FillEllipse(b, x, y, ancho, alto);
	}



};

