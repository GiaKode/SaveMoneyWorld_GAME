#pragma once
#include <iostream>
using namespace System;
using namespace System::Drawing;


class Movimiento
{
protected:
	int x, y;
	int ancho, alto;
	int dx, dy;
	int idX, idY;
	bool visible;

public:
	Movimiento(int ancho, int alto) {

		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		idX = idY = 0;
		visible = true;

	}
	~Movimiento() {};

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * ancho, idY * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
		//Pen^ p = gcnew Pen(Color::Red, 5);
		//g->DrawRectangle(p, x, y, ancho * 1.0, alto * 1.0);
	}

	virtual void movimientos() {}

	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}

	int getX() { return x; }
	int getY() { return y; }
	int getdx() { return dx; }
	int getdy() { return dy; }
	bool getVisible() { return visible; }
	int getAncho() { return ancho; }
	void setdX(int v) { this->dx = v; }
	void setdY(int v) { this->dy = v; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setVisible(bool v) { visible = v; }
	int getXAncho() { return x + ancho * 1.0; }
	int getYAlto() { return y + alto * 1.0; }
	int getidX() { return idX; }
};


