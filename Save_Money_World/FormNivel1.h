#pragma once
#include"Controladora1.h"

namespace SaveMoneyWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de JuegoForm
	/// </summary>
	public ref class JuegoForm : public System::Windows::Forms::Form
	{
	private:
		Controladora1* controladora1;
		//Buffer:
		Graphics^ g;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;

		//Bitmap:
		Bitmap^ bmpJugador;
		Bitmap^ bmpEnemigo1;
		Bitmap^ bmpMapaNivel1;
		Bitmap^ bmpBanco;
		Bitmap^ bmpVida;



	private: System::Windows::Forms::Label^ LblMonedas;




	public:
		JuegoForm(void)
		{
			srand(time(NULL));
			InitializeComponent();

			//File

			//Buffer:
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap:
			bmpJugador = gcnew Bitmap("jugador.png");
			bmpEnemigo1 = gcnew Bitmap("enemigo1.png");
			bmpMapaNivel1 = gcnew Bitmap("mapanivel1.png");
			bmpBanco = gcnew Bitmap("banco.png");
			bmpVida = gcnew Bitmap("vida.png");

			//Clases:
			controladora1 = new Controladora1(bmpJugador, bmpEnemigo1, bmpBanco, bmpVida);
			Heroe* heroe;
			Banco* banco;


		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JuegoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timerNivel1;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LblMonedas = (gcnew System::Windows::Forms::Label());
			this->timerNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->LblMonedas);
			this->panel1->Location = System::Drawing::Point(2, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1009, 660);
			this->panel1->TabIndex = 0;
			// 
			// LblMonedas
			// 
			this->LblMonedas->AutoSize = true;
			this->LblMonedas->Location = System::Drawing::Point(10, 8);
			this->LblMonedas->Name = L"LblMonedas";
			this->LblMonedas->Size = System::Drawing::Size(10, 13);
			this->LblMonedas->TabIndex = 0;
			this->LblMonedas->Text = L".";
			// 
			// timerNivel1
			// 
			this->timerNivel1->Enabled = true;
			this->timerNivel1->Tick += gcnew System::EventHandler(this, &JuegoForm::timer1_Tick);
			// 
			// JuegoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 656);
			this->Controls->Add(this->panel1);
			this->Name = L"JuegoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoForm::JuegoForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Borrar - Mover - Dibujar

		buffer->Graphics->Clear(Color::WhiteSmoke);

		controladora1->colisiones();

		controladora1->moverTODO(buffer->Graphics);

		buffer->Graphics->DrawImage(bmpMapaNivel1, 0, 0, panel1->Width, panel1->Height); //Crear mapa
		controladora1->dibujarTODO(buffer->Graphics, bmpJugador, bmpEnemigo1, bmpBanco, bmpVida);
		LblMonedas->Text = "Dinero : " + controladora1->getContadorDinero();
		if (controladora1->getHeroe()->getVida() == 0) {
			this->timerNivel1->Enabled = false;
			MessageBox::Show("\t      !!PERDISTE!!\nCantidad de monedas obtenidas: " + controladora1->getContadorDinero(), "GAME OVER");
			Close();
		}
		else if (controladora1->getHeroe()->getRectangulo().IntersectsWith(controladora1->getBanco()->getRectanguloBanco())) {
			this->timerNivel1->Enabled = false;
			MessageBox::Show("\t      !!GANASTE!!\nCantidad de monedas obtenidas: " + controladora1->getContadorDinero(), "BRAVO");
			Close();
		}
		else
		{
			buffer->Render(g);
		}

	}
	private: System::Void JuegoForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controladora1->getHeroe()->movimientos(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controladora1->getHeroe()->movimientos(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controladora1->getHeroe()->movimientos(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controladora1->getHeroe()->movimientos(buffer->Graphics, 'S'); break;
		}
	}
	};
}

