#pragma once
#include"EnemigoMenor.h"
#include"Heroe.h"
#include"Dinero.h"
#include"Banco.h"
#include"Vida.h"

#include<vector>
#include<iostream>
using namespace std;

class Controladora1
{
private:
	Heroe* heroe;
	Banco* banco;
	Vida* vida;
	EnemigoMenor* enemigo;
	vector<EnemigoMenor*>enemigosMenores;
	vector<Dinero*>dineros;
	vector<Vida*>vidas;
	int ContadorDinero;
	int CantidadDinero;

public:
	Controladora1(Bitmap^ bmpJugador, Bitmap^ bmpEnemigo1, Bitmap^ bmpBanco, Bitmap^ bmpVida) {
		ContadorDinero = 0;
		CantidadDinero = (rand() % 25 + 7 - 1);
		if (CantidadDinero <= 7 || CantidadDinero >= 25)
		{
			CantidadDinero = 18;

		}
		//inicio de JUGADOR:
		heroe = new Heroe(0, 300, bmpJugador->Width / 4, bmpJugador->Height / 3);
		//inicio de ENEMIGOS:
		for (int i = 0; i < 1; i++) {//Izquierda - derecha
			enemigosMenores.push_back(new EnemigoMenor(bmpEnemigo1->Width / 4, bmpEnemigo1->Height / 4, 0));

		}//rand() % 11 + 6
		for (int i = 0; i <1; i++) { //arriba - abajo

			enemigosMenores.push_back(new EnemigoMenor(bmpEnemigo1->Width / 4, bmpEnemigo1->Height / 4, 1));
		}
		//Inicio de Dinero:
		for (int i = 0; i < CantidadDinero; i++) {
			agregarDinero();
		}
		//Inicio imagen Banco:
		banco = new Banco(bmpBanco->Width, bmpBanco->Height);
		//Inicio imagen Vida:
		vidas.push_back(new Vida(100, 50, bmpBanco->Width, bmpBanco->Height));
		vidas.push_back(new Vida(50, 50, bmpBanco->Width, bmpBanco->Height));
		vidas.push_back(new Vida(0, 50, bmpBanco->Width, bmpBanco->Height));


	}
	~Controladora1() {}

	void agregarDinero() {
		Dinero* d = new Dinero();
		dineros.push_back(d);
	}



	//dibujar - mover

	void dibujarTODO(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo1, Bitmap^ bmpBanco, Bitmap^ bmpVida) {
		heroe->dibujar(g, bmpJugador);
		if (ContadorDinero >= CantidadDinero)
		{

			banco->setX(850);
		}
		banco->dibujarBanco(g, bmpBanco);

		for (int i = 0; i < dineros.size(); i++)
		{
			dineros[i]->dibujarDinero(g);
		}

		for (int i = 0; i < enemigosMenores.size(); i++)
		{
			enemigosMenores[i]->dibujar(g, bmpEnemigo1);
		}

		for (int i = 0; i < vidas.size(); i++)
		{
			vidas[i]->dibujar(g, bmpVida);
		}

	}

	void moverTODO(Graphics^ g) {
		for (int i = 0; i < enemigosMenores.size(); i++) {
			enemigosMenores[i]->movimientos(g);
		}


	}

	void colisiones() {

		//Jugador - Enemigos
		for (int i = 0; i < enemigosMenores.size(); i++) {
				if (heroe->getRectangulo().IntersectsWith(enemigosMenores[i]->getRectangulo())) {
					heroe->setX(0);
					heroe->setY(300);
					heroe->BajaVida();
					vidas[0]->setVisible(false);


				}
		}

		//Jugador - Monedas
		for (int i = 0; i < dineros.size(); i++) {
			if (heroe->getRectangulo().IntersectsWith(dineros[i]->getRectangulo())) {
				dineros[i]->setVisible(false);
				ContadorDinero++;
			}
		}

		//Enemigos - Banco

		for (int i = 0; i < enemigosMenores.size(); i++) {
			if (enemigosMenores[i]->getRectangulo().IntersectsWith(banco->getRectanguloBanco())) {
				enemigosMenores[i]->setdX(-9);



			}
		}

		//Eliminacion:

		//Eliminacion de monedas
		for (int i = 0; i < dineros.size(); i++) {
			if (!dineros[i]->getVisible()) {
				dineros.erase(dineros.begin() + i);
			}
		}
		//Eliminacion de vidas
		for (int i = 0; i < vidas.size(); i++) {
			if (!vidas[i]->getVisible()) {
				vidas.erase(vidas.begin() + i);
			}
		}


	}

	Banco* getBanco() { return banco; }
	Heroe* getHeroe() { return heroe; }
	int getContadorDinero() { return ContadorDinero; }

};


