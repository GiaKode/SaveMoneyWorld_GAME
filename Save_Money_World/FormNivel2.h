#pragma once
#include"Controladora2.h"
#include"File.h"


namespace SaveMoneyWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de JuegoFormN2
	/// </summary>
	public ref class JuegoFormN2 : public System::Windows::Forms::Form
	{
	private:
		Controladora2* controladora2;
		//Buffer:
		Graphics^ g;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;

		//Bitmap:
		Bitmap^ bmpJugador;
		Bitmap^ bmpEnemigo1;
		Bitmap^ bmpMapaNivel2;
		Bitmap^ bmpBanco;
		Bitmap^ bmpVida;
		Bitmap^ bmpAliado;
		Bitmap^ bmpEnemigo2;

		Heroe* heroe;
		File* file;

		int contador;

	private: System::Windows::Forms::Timer^ timerNivel2;
	private: System::Windows::Forms::Timer^ timerTiempo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ LblTiempo;
	private: System::Windows::Forms::Label^ LblAliados;
	private: System::Windows::Forms::Timer^ timerAliado;







	private: System::Windows::Forms::Label^ LblMonedas;

	public:
		JuegoFormN2(void)
		{

			srand(time(NULL));
			InitializeComponent();

			//Buffer:
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Bitmap:
			bmpJugador = gcnew Bitmap("jugador.png");
			bmpEnemigo1 = gcnew Bitmap("enemigo1.png");
			bmpMapaNivel2 = gcnew Bitmap("mapanivel2.png");
			bmpBanco = gcnew Bitmap("banco.png");
			bmpVida = gcnew Bitmap("vida.png");
			bmpAliado = gcnew Bitmap("aliado.png");
			bmpEnemigo2 = gcnew Bitmap("enemigo2.png");

			//Clases:
			controladora2 = new Controladora2(bmpJugador, bmpEnemigo1, bmpBanco, bmpVida, bmpAliado, bmpEnemigo2);
			//jugador = new Jugador(0, 300, bmpJugador->Width / 4, bmpJugador->Height / 3);
			//jugador = new Jugador(file->getX(), file->getY(), bmpJugador->Width / 4, bmpJugador->Height / 3);
			Banco* banco;

			//File
			file = new File();
			file->readData();

			contador = file->getTime();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JuegoFormN2()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->LblMonedas = (gcnew System::Windows::Forms::Label());
			this->timerNivel2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->LblTiempo = (gcnew System::Windows::Forms::Label());
			this->LblAliados = (gcnew System::Windows::Forms::Label());
			this->timerAliado = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// LblMonedas
			// 
			this->LblMonedas->AutoSize = true;
			this->LblMonedas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LblMonedas->Location = System::Drawing::Point(10, 8);
			this->LblMonedas->Name = L"LblMonedas";
			this->LblMonedas->Size = System::Drawing::Size(12, 15);
			this->LblMonedas->TabIndex = 0;
			this->LblMonedas->Text = L".";
			// 
			// timerNivel2
			// 
			this->timerNivel2->Enabled = true;
			this->timerNivel2->Tick += gcnew System::EventHandler(this, &JuegoFormN2::timer1_Tick);
			// 
			// timerTiempo
			// 
			this->timerTiempo->Enabled = true;
			this->timerTiempo->Interval = 1000;
			this->timerTiempo->Tick += gcnew System::EventHandler(this, &JuegoFormN2::timerTiempo_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(88, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tiempo :";
			// 
			// LblTiempo
			// 
			this->LblTiempo->AutoSize = true;
			this->LblTiempo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LblTiempo->Location = System::Drawing::Point(142, 9);
			this->LblTiempo->Name = L"LblTiempo";
			this->LblTiempo->Size = System::Drawing::Size(15, 15);
			this->LblTiempo->TabIndex = 2;
			this->LblTiempo->Text = L"0";
			// 
			// LblAliados
			// 
			this->LblAliados->AutoSize = true;
			this->LblAliados->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LblAliados->Location = System::Drawing::Point(175, 11);
			this->LblAliados->Name = L"LblAliados";
			this->LblAliados->Size = System::Drawing::Size(37, 15);
			this->LblAliados->TabIndex = 3;
			this->LblAliados->Text = L"label2";
			// 
			// timerAliado
			// 
			this->timerAliado->Enabled = true;
			this->timerAliado->Tick += gcnew System::EventHandler(this, &JuegoFormN2::timerAliado_Tick);
			// 
			// JuegoFormN2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 656);
			this->Controls->Add(this->LblAliados);
			this->Controls->Add(this->LblTiempo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LblMonedas);
			this->Location = System::Drawing::Point(2, -1);
			this->Name = L"JuegoFormN2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoForm";
			this->Load += gcnew System::EventHandler(this, &JuegoFormN2::JuegoFormN2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoFormN2::JuegoFormN2_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Borrar - Mover - Dibujar

		buffer->Graphics->Clear(Color::WhiteSmoke);

		controladora2->colisiones(buffer->Graphics);

		controladora2->moverTODO(buffer->Graphics);

		buffer->Graphics->DrawImage(bmpMapaNivel2, 0, 0, this->Width, this->Height); //Crear mapa
		LblTiempo->Text = Convert::ToString(contador);
		controladora2->dibujarTODO(buffer->Graphics, bmpJugador, bmpEnemigo1, bmpBanco, bmpVida, bmpAliado, bmpEnemigo2);
		LblMonedas->Text = "Dinero : " + controladora2->getContadorDinero();
		LblAliados->Text = "Aliados restantes: " + controladora2->getCantidadAliados();

		if (controladora2->getJugador()->getVidaN2() == 0) {
			this->timerNivel2->Enabled = false;
			MessageBox::Show("\t      !!PERDISTE!!\nCantidad de monedas obtenidas: " + controladora2->getContadorDinero(), "GAME OVER");
			Close();
		}
		else if (controladora2->getJugador()->getRectangulo().IntersectsWith(controladora2->getBanco()->getRectanguloBanco())) {
			this->timerNivel2->Enabled = false;
			MessageBox::Show("\t      !!GANASTE!!\nCantidad de monedas obtenidas: " + controladora2->getContadorDinero(), "BRAVO");
			Close();

		}
		else if (controladora2->getJugador()->getRectangulo().IntersectsWith(controladora2->getEnemigoMayor()->getRectangulo())) {
			this->timerNivel2->Enabled = false;
			MessageBox::Show("\t      !!TE ATRAPO!!\nCantidad de monedas obtenidas: " + controladora2->getContadorDinero(), "DEATH");
			Close();





		}

		else if (contador == 0) {
			this->timerNivel2->Enabled = false;
			MessageBox::Show("\t !!SE AGOTO DEL TIEMPO!!\nCantidad de monedas obtenidas: " + controladora2->getContadorDinero(), "GAME OVER");
			Close();
		}
		else
		{
			buffer->Render(g);
		}
	}
	private: System::Void JuegoFormN2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			controladora2->getJugador()->movimientos(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			controladora2->getJugador()->movimientos(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			controladora2->getJugador()->movimientos(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			controladora2->getJugador()->movimientos(buffer->Graphics, 'S'); break;
		}

	}
	private: System::Void JuegoFormN2_Load(System::Object^ sender, System::EventArgs^ e) {

		this->timerAliado->Interval = 15000;
		this->timerAliado->Enabled = true;
	}
	private: System::Void timerTiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
		contador--;
	}

	private: System::Void timerAliado_Tick(System::Object^ sender, System::EventArgs^ e) {

		controladora2->agregarAliado(bmpAliado);
		controladora2->getDisminuirCantidadAliados();
	}
	};
}
