#pragma once
#include "FormNiveles.h"
#include "FormInstrucciones.h"
#include "FormCreditos.h"

namespace SaveMoneyWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Menu
	/// </summary>
	public ref class FormMenu : public System::Windows::Forms::Form
	{
	public:
		FormMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::Button^ btnIniciarJuego;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;
	private: System::Windows::Forms::Button^ btnSalir;





	protected:










	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::Panel^ pnl1;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenu::typeid));
			this->btnIniciarJuego = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->pnl1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->pnl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnIniciarJuego
			// 
			this->btnIniciarJuego->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->btnIniciarJuego->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciarJuego->Location = System::Drawing::Point(36, 459);
			this->btnIniciarJuego->Name = L"btnIniciarJuego";
			this->btnIniciarJuego->Size = System::Drawing::Size(219, 56);
			this->btnIniciarJuego->TabIndex = 1;
			this->btnIniciarJuego->Text = L"Iniciar juego";
			this->btnIniciarJuego->UseVisualStyleBackColor = false;
			this->btnIniciarJuego->Click += gcnew System::EventHandler(this, &FormMenu::btnIniciarJuego_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Yellow;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(276, 459);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(219, 56);
			this->btnInstrucciones->TabIndex = 4;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FormMenu::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Cyan;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(518, 459);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(219, 56);
			this->btnCreditos->TabIndex = 5;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FormMenu::btnCreditos_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Tomato;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(758, 459);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(219, 56);
			this->btnSalir->TabIndex = 6;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormMenu::btnSalir_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-5, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(999, 529);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->BackColor = System::Drawing::Color::MediumAquamarine;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Algerian", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl1->ForeColor = System::Drawing::Color::Black;
			this->lbl1->Location = System::Drawing::Point(300, 8);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(483, 53);
			this->lbl1->TabIndex = 7;
			this->lbl1->Text = L"SAVE MONEY WORLD\r\n";
			// 
			// pnl1
			// 
			this->pnl1->BackColor = System::Drawing::Color::MediumAquamarine;
			this->pnl1->Controls->Add(this->lbl1);
			this->pnl1->Location = System::Drawing::Point(1, 12);
			this->pnl1->Name = L"pnl1";
			this->pnl1->Size = System::Drawing::Size(987, 61);
			this->pnl1->TabIndex = 9;
			// 
			// FormMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(989, 527);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnIniciarJuego);
			this->Controls->Add(this->pnl1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FormMenu";
			this->Text = L"Menú Principal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->pnl1->ResumeLayout(false);
			this->pnl1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void btnIniciarJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		FormNiveles^ formNiveles = gcnew FormNiveles();
		/*this->Visible = false;*/
		formNiveles->ShowDialog();
	}
	
	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		FormInstrucciones^ formInstrucciones = gcnew FormInstrucciones();
		formInstrucciones->ShowDialog();
	}

	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		FormCreditos^ formCreditos = gcnew FormCreditos();
		formCreditos->ShowDialog();
	}
	
	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}

};
}
