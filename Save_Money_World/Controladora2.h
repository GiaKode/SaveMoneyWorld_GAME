#pragma once
#include"EnemigoMenor.h"
#include"EnemigoMayor.h"
#include"Aliado.h"
#include"Heroe.h"
#include"Dinero.h"
#include"Banco.h"
#include"Vida.h"
#include"File.h"
#include<vector>
#include<iostream>
using namespace std;

class Controladora2
{
private:
	Heroe* heroe;
	Banco* banco;
	Vida* vida;
	Aliado* aliado;
	EnemigoMenor* enemigoMenor;
	EnemigoMayor* enemigoMayor;
	File* file;
	vector<Aliado*>aliados;
	vector<EnemigoMenor*>enemigosMenores;
	//vector<Enemigo2*>enemigos2;
	vector<Dinero*>dineros;
	vector<Vida*>vidas;
	int ContadorDinero;
	int CantidadDinero;
	int cantidadAliados;
	int x, y;

public:
	Controladora2(Bitmap^ bmpJugador, Bitmap^ bmpEnemigo1, Bitmap^ bmpBanco, Bitmap^ bmpVida, Bitmap^ bmpAliado, Bitmap^ bmpEnemigo2) {
		ContadorDinero = 0;
		CantidadDinero = 20 + rand() % (26 - 20);
		cantidadAliados = 6;
		//if (CantidadDinero <= 15 || CantidadDinero>=30)
		//{
		//	CantidadDinero = 20;
		//
		//}

		//inicio de JUGADOR:
		heroe = new Heroe(0, 300, bmpJugador->Width / 4, bmpJugador->Height / 3);
		//inicio de ENEMIGOS:
		for (int i = 0; i < 4 + rand() % 6; i++) {//Izquierda - derecha
			enemigosMenores.push_back(new EnemigoMenor(bmpEnemigo1->Width / 4, bmpEnemigo1->Height / 4, 0));

		}//rand() % 9 + 6
		for (int i = 0; i < 4 + rand() % 6; i++) { //arriba - abajo

			enemigosMenores.push_back(new EnemigoMenor(bmpEnemigo1->Width / 4, bmpEnemigo1->Height / 4, 1));
		}
		//Enemigos 2:
		enemigoMayor = new EnemigoMayor(bmpEnemigo2->Width / 3, bmpEnemigo2->Height / 4, 1);
		//Aliado:



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
		vidas.push_back(new Vida(100, 100, bmpBanco->Width, bmpBanco->Height));
		vidas.push_back(new Vida(50, 100, bmpBanco->Width, bmpBanco->Height));
		vidas.push_back(new Vida(0, 100, bmpBanco->Width, bmpBanco->Height));


	}
	~Controladora2() {}

	void agregarDinero() {
		Dinero* d = new Dinero();
		dineros.push_back(d);
	}

	void agregarAliado(Bitmap^ bmpAliado) {
		aliados.push_back(new Aliado(rand() % 5, rand() % 580, bmpAliado->Width / 3, bmpAliado->Height / 4));

	}

	//dibujar - mover

	void dibujarTODO(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo1, Bitmap^ bmpBanco, Bitmap^ bmpVida, Bitmap^ bmpAliado, Bitmap^ bmpEnemigo2) {
		heroe->dibujar(g, bmpJugador);

		if (ContadorDinero >= CantidadDinero)
		{

			enemigoMayor->setdX(13);
			banco->setX(850);
			eliminacionEnemigos();
		}
		banco->dibujarBanco(g, bmpBanco);

		for (int i = 0; i < dineros.size(); i++)
		{
			dineros[i]->dibujarDinero(g);
		}
		for (int i = 0; i < aliados.size(); i++)
		{
			aliados[i]->dibujar(g, bmpAliado);
		}
		for (int i = 0; i < enemigosMenores.size(); i++)
		{
			enemigosMenores[i]->dibujar(g, bmpEnemigo1);
		}

		for (int i = 0; i < vidas.size(); i++)
		{
			vidas[i]->dibujar(g, bmpVida);
		}
		enemigoMayor->dibujar(g, bmpEnemigo2);
	}

	void moverTODO(Graphics^ g) {
		for (int i = 0; i < enemigosMenores.size(); i++) {
			enemigosMenores[i]->movimientos(g);
		}
		for (int i = 0; i < aliados.size(); i++) {
			aliados[i]->movimientos(g);
		}

		enemigoMayor->movimientos(g, heroe);

	}

	void colisiones(Graphics^ g) {

		//Jugador - Enemigos
		for (int i = 0; i < enemigosMenores.size(); i++) {
			if (heroe->getRectangulo().IntersectsWith(enemigosMenores[i]->getRectangulo())) {
				heroe->setX(0);
				heroe->setY(300);
				heroe->BajaVidaN2();
				vidas[0]->setVisible(false);
				ContadorDinero--;
				CantidadDinero--;

			}
		}

		for (int i = 0; i < aliados.size(); i++) {
			if (aliados[i]->getX() <= 0 || aliados[i]->getXAncho() >= g->VisibleClipBounds.Width ||
				aliados[i]->getY() <= 0 || aliados[i]->getYAlto() >= g->VisibleClipBounds.Height) {
				aliados[i]->setVisible(false);
			}
		}

		//Aliado - Enemigos

		for (int i = 0; i < enemigosMenores.size(); i++) {

			for (int j = 0; j < aliados.size(); j++) {
				if (enemigosMenores[i]->getRectangulo().IntersectsWith(aliados[j]->getRectangulo())) {
					enemigosMenores[i]->setVisible(false);

					//aliados[j]->setVisible(false);
				}


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
				//enemigos1[i]->setdY(-9);



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
		//Eliminacion de aliados
		for (int i = 0; i < aliados.size(); i++) {
			if (!aliados[i]->getVisible()) {
				aliados.erase(aliados.begin() + i);
			}
		}
		//Eliminacion de enemigos
		for (int i = 0; i < enemigosMenores.size(); i++) {
			if (!enemigosMenores[i]->getVisible()) {
				enemigosMenores.erase(enemigosMenores.begin() + i);
			}
		}


	}
	void eliminacionEnemigos() {

		for (int i = 0; i < enemigosMenores.size(); i++) {
			if (!enemigosMenores[i]->getVisible()) {
				enemigosMenores.erase(enemigosMenores.begin() + i);
			}
		}


	}

	EnemigoMayor* getEnemigoMayor() { return enemigoMayor; }
	Aliado* getAliado() { return aliado; }
	Banco* getBanco() { return banco; }
	Heroe* getJugador() { return heroe; }
	int getContadorDinero() { return ContadorDinero; }
	int getCantidadAliados() { return cantidadAliados; }
	int getDisminuirCantidadAliados() { return cantidadAliados--; }
	int getCM() { return dineros.size(); }
};

