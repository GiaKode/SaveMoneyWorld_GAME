#pragma once
#include"Movimiento.h"

class Banco : public Movimiento
{
public:
	Banco(int ancho, int alto) :Movimiento(ancho, alto) {
		x = 6000;
		y = 460;
		idX = idY = 0;
		dx = dy = 0;

	}
	~Banco() {}
	void dibujarBanco(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * ancho, idY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.2, alto * 0.2);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);

	}
	Rectangle getRectanguloBanco() {
		return Rectangle(x, y, ancho * 0.2, alto * 0.2);
	}


private:


};