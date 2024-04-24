#pragma once
#include "FormNivel1.h"
#include "FormNivel2.h"

namespace SaveMoneyWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormNiveles
	/// </summary>
	public ref class FormNiveles : public System::Windows::Forms::Form
	{
	public:
		FormNiveles(void)
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
		~FormNiveles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnVolver;
	protected:

	protected:
	private: System::Windows::Forms::Label^ lblProx;
	private: System::Windows::Forms::Label^ lblAvanz;
	private: System::Windows::Forms::PictureBox^ PIBMap3;
	private: System::Windows::Forms::Label^ lblPrinc;
	private: System::Windows::Forms::PictureBox^ PIBMap1;
	private: System::Windows::Forms::PictureBox^ PIBMap2;
	private: System::Windows::Forms::Label^ lblUPC;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormNiveles::typeid));
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->lblProx = (gcnew System::Windows::Forms::Label());
			this->lblAvanz = (gcnew System::Windows::Forms::Label());
			this->PIBMap3 = (gcnew System::Windows::Forms::PictureBox());
			this->lblPrinc = (gcnew System::Windows::Forms::Label());
			this->PIBMap1 = (gcnew System::Windows::Forms::PictureBox());
			this->PIBMap2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblUPC = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::LightPink;
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVolver->Location = System::Drawing::Point(389, 433);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(219, 56);
			this->btnVolver->TabIndex = 2;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormNiveles::btnVolver_Click);
			// 
			// lblProx
			// 
			this->lblProx->AutoSize = true;
			this->lblProx->BackColor = System::Drawing::Color::Transparent;
			this->lblProx->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProx->ForeColor = System::Drawing::Color::Transparent;
			this->lblProx->Location = System::Drawing::Point(689, 341);
			this->lblProx->Name = L"lblProx";
			this->lblProx->Size = System::Drawing::Size(215, 23);
			this->lblProx->TabIndex = 13;
			this->lblProx->Text = L"Coming Soon! - The Cinema";
			// 
			// lblAvanz
			// 
			this->lblAvanz->AutoSize = true;
			this->lblAvanz->BackColor = System::Drawing::Color::Transparent;
			this->lblAvanz->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAvanz->ForeColor = System::Drawing::Color::Transparent;
			this->lblAvanz->Location = System::Drawing::Point(398, 332);
			this->lblAvanz->Name = L"lblAvanz";
			this->lblAvanz->Size = System::Drawing::Size(181, 23);
			this->lblAvanz->TabIndex = 15;
			this->lblAvanz->Text = L"Avanzado - The Jungle";
			// 
			// PIBMap3
			// 
			this->PIBMap3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PIBMap3.Image")));
			this->PIBMap3->Location = System::Drawing::Point(665, 163);
			this->PIBMap3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PIBMap3->Name = L"PIBMap3";
			this->PIBMap3->Size = System::Drawing::Size(277, 158);
			this->PIBMap3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PIBMap3->TabIndex = 12;
			this->PIBMap3->TabStop = false;
			this->PIBMap3->Click += gcnew System::EventHandler(this, &FormNiveles::PIBMap3_Click);
			// 
			// lblPrinc
			// 
			this->lblPrinc->AutoSize = true;
			this->lblPrinc->BackColor = System::Drawing::Color::Transparent;
			this->lblPrinc->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrinc->ForeColor = System::Drawing::Color::Transparent;
			this->lblPrinc->Location = System::Drawing::Point(105, 332);
			this->lblPrinc->Name = L"lblPrinc";
			this->lblPrinc->Size = System::Drawing::Size(180, 23);
			this->lblPrinc->TabIndex = 14;
			this->lblPrinc->Text = L"Principiante - The City";
			// 
			// PIBMap1
			// 
			this->PIBMap1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PIBMap1.Image")));
			this->PIBMap1->Location = System::Drawing::Point(46, 163);
			this->PIBMap1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PIBMap1->Name = L"PIBMap1";
			this->PIBMap1->Size = System::Drawing::Size(277, 158);
			this->PIBMap1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PIBMap1->TabIndex = 10;
			this->PIBMap1->TabStop = false;
			this->PIBMap1->Click += gcnew System::EventHandler(this, &FormNiveles::PIBMap1_Click);
			// 
			// PIBMap2
			// 
			this->PIBMap2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PIBMap2.Image")));
			this->PIBMap2->Location = System::Drawing::Point(358, 163);
			this->PIBMap2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PIBMap2->Name = L"PIBMap2";
			this->PIBMap2->Size = System::Drawing::Size(277, 158);
			this->PIBMap2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PIBMap2->TabIndex = 11;
			this->PIBMap2->TabStop = false;
			this->PIBMap2->Click += gcnew System::EventHandler(this, &FormNiveles::PIBMap2_Click);
			// 
			// lblUPC
			// 
			this->lblUPC->AutoSize = true;
			this->lblUPC->BackColor = System::Drawing::Color::Transparent;
			this->lblUPC->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUPC->ForeColor = System::Drawing::Color::Transparent;
			this->lblUPC->Location = System::Drawing::Point(398, 37);
			this->lblUPC->Name = L"lblUPC";
			this->lblUPC->Size = System::Drawing::Size(210, 72);
			this->lblUPC->TabIndex = 16;
			this->lblUPC->Text = L"Niveles";
			// 
			// FormNiveles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(989, 527);
			this->Controls->Add(this->lblUPC);
			this->Controls->Add(this->lblProx);
			this->Controls->Add(this->lblAvanz);
			this->Controls->Add(this->PIBMap3);
			this->Controls->Add(this->lblPrinc);
			this->Controls->Add(this->PIBMap1);
			this->Controls->Add(this->PIBMap2);
			this->Controls->Add(this->btnVolver);
			this->Name = L"FormNiveles";
			this->Text = L"FormNiveles";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PIBMap2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void PIBMap1_Click(System::Object^ sender, System::EventArgs^ e) {
	JuegoForm^ juegoform = gcnew JuegoForm();
	this->Visible = false;
	juegoform->ShowDialog();
}
private: System::Void PIBMap2_Click(System::Object^ sender, System::EventArgs^ e) {
	JuegoFormN2^ juego2form = gcnew JuegoFormN2();
	this->Visible = false;
	juego2form->ShowDialog();
}
private: System::Void PIBMap3_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
