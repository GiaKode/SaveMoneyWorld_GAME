#pragma once
#include "FormMenu.h"

namespace SaveMoneyWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormUPC
	/// </summary>
	public ref class FormUPC : public System::Windows::Forms::Form
	{
	public:
		FormUPC(void)
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
		~FormUPC()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Label^ lbl3;

	private: System::Windows::Forms::Label^ lbl2;
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::PictureBox^ pictureBoxUPC;
	private: System::Windows::Forms::Panel^ pnl1;





	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormUPC::typeid));
			this->lbl3 = (gcnew System::Windows::Forms::Label());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxUPC = (gcnew System::Windows::Forms::PictureBox());
			this->pnl1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUPC))->BeginInit();
			this->pnl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbl3
			// 
			this->lbl3->AutoSize = true;
			this->lbl3->BackColor = System::Drawing::Color::Crimson;
			this->lbl3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl3->ForeColor = System::Drawing::Color::White;
			this->lbl3->Location = System::Drawing::Point(266, 17);
			this->lbl3->Name = L"lbl3";
			this->lbl3->Size = System::Drawing::Size(471, 44);
			this->lbl3->TabIndex = 0;
			this->lbl3->Text = L"Presione [ENTER] para continuar";
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->BackColor = System::Drawing::Color::Transparent;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Algerian", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl2->ForeColor = System::Drawing::Color::White;
			this->lbl2->Location = System::Drawing::Point(564, 288);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(276, 34);
			this->lbl2->TabIndex = 6;
			this->lbl2->Text = L"EXÍGETE, INNOVA";
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->BackColor = System::Drawing::Color::Transparent;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Algerian", 88.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl1->ForeColor = System::Drawing::Color::White;
			this->lbl1->Location = System::Drawing::Point(517, 103);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(334, 164);
			this->lbl1->TabIndex = 5;
			this->lbl1->Text = L"UPC";
			// 
			// pictureBoxUPC
			// 
			this->pictureBoxUPC->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxUPC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxUPC.Image")));
			this->pictureBoxUPC->Location = System::Drawing::Point(113, 90);
			this->pictureBoxUPC->Name = L"pictureBoxUPC";
			this->pictureBoxUPC->Size = System::Drawing::Size(325, 275);
			this->pictureBoxUPC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxUPC->TabIndex = 0;
			this->pictureBoxUPC->TabStop = false;
			// 
			// pnl1
			// 
			this->pnl1->BackColor = System::Drawing::Color::Crimson;
			this->pnl1->Controls->Add(this->lbl3);
			this->pnl1->Location = System::Drawing::Point(1, 435);
			this->pnl1->Name = L"pnl1";
			this->pnl1->Size = System::Drawing::Size(987, 61);
			this->pnl1->TabIndex = 10;
			// 
			// FormUPC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(989, 527);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->pictureBoxUPC);
			this->Controls->Add(this->pnl1);
			this->Name = L"FormUPC";
			this->Text = L"Intro UPC";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormUPC::FormUPC_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUPC))->EndInit();
			this->pnl1->ResumeLayout(false);
			this->pnl1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void FormUPC_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		FormMenu^ formMenu = gcnew FormMenu();
		if (e->KeyCode == Keys::Enter) {
			this->Visible = false;
			formMenu->ShowDialog();
			//this->Visible = true;
			Close();
		}
	}
};
}
