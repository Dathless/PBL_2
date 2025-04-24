#pragma once

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddAccount
	/// </summary>
	public ref class AddAccount : public System::Windows::Forms::Form
	{
	private: String^ role;
	private: String^ usr;
	private: String^ pwd;
	public:
		AddAccount(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddAccount()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Header;
	protected:
	private: System::Windows::Forms::Panel^ Footer;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ CancelBtn;
	private: System::Windows::Forms::Button^ OKBtn;
	private: System::Windows::Forms::Label^ TypeAcc;
	private: System::Windows::Forms::Label^ usrLabel;
	private: System::Windows::Forms::Label^ passLabel;
	private: System::Windows::Forms::Label^ rePassLabel;
	private: System::Windows::Forms::ComboBox^ typeInp;
	private: System::Windows::Forms::TextBox^ usrInp;
	private: System::Windows::Forms::MaskedTextBox^ passInp;
	private: System::Windows::Forms::MaskedTextBox^ rePassInp;
	private: System::Windows::Forms::CheckBox^ toggleP;
	private: System::Windows::Forms::CheckBox^ toggleRP;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Header = (gcnew System::Windows::Forms::Panel());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->Footer = (gcnew System::Windows::Forms::Panel());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->OKBtn = (gcnew System::Windows::Forms::Button());
			this->TypeAcc = (gcnew System::Windows::Forms::Label());
			this->usrLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->rePassLabel = (gcnew System::Windows::Forms::Label());
			this->typeInp = (gcnew System::Windows::Forms::ComboBox());
			this->usrInp = (gcnew System::Windows::Forms::TextBox());
			this->passInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->rePassInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->toggleP = (gcnew System::Windows::Forms::CheckBox());
			this->toggleRP = (gcnew System::Windows::Forms::CheckBox());
			this->Header->SuspendLayout();
			this->Footer->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->Header->Controls->Add(this->Title);
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(595, 66);
			this->Header->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(161, 19);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(264, 31);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Create New Account";
			// 
			// Footer
			// 
			this->Footer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->Footer->Controls->Add(this->CancelBtn);
			this->Footer->Controls->Add(this->OKBtn);
			this->Footer->Location = System::Drawing::Point(0, 251);
			this->Footer->Name = L"Footer";
			this->Footer->Size = System::Drawing::Size(595, 70);
			this->Footer->TabIndex = 1;
			// 
			// CancelBtn
			// 
			this->CancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CancelBtn->Location = System::Drawing::Point(136, 14);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(100, 35);
			this->CancelBtn->TabIndex = 1;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			this->CancelBtn->Click += gcnew System::EventHandler(this, &AddAccount::Exit);
			// 
			// OKBtn
			// 
			this->OKBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OKBtn->Location = System::Drawing::Point(358, 14);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(100, 35);
			this->OKBtn->TabIndex = 0;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &AddAccount::Perform);
			// 
			// TypeAcc
			// 
			this->TypeAcc->AutoSize = true;
			this->TypeAcc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TypeAcc->ForeColor = System::Drawing::Color::White;
			this->TypeAcc->Location = System::Drawing::Point(79, 86);
			this->TypeAcc->Name = L"TypeAcc";
			this->TypeAcc->Size = System::Drawing::Size(148, 24);
			this->TypeAcc->TabIndex = 2;
			this->TypeAcc->Text = L"Type of Account";
			// 
			// usrLabel
			// 
			this->usrLabel->AutoSize = true;
			this->usrLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usrLabel->ForeColor = System::Drawing::Color::White;
			this->usrLabel->Location = System::Drawing::Point(79, 125);
			this->usrLabel->Name = L"usrLabel";
			this->usrLabel->Size = System::Drawing::Size(97, 24);
			this->usrLabel->TabIndex = 2;
			this->usrLabel->Text = L"Username";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLabel->ForeColor = System::Drawing::Color::White;
			this->passLabel->Location = System::Drawing::Point(79, 164);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(92, 24);
			this->passLabel->TabIndex = 3;
			this->passLabel->Text = L"Password";
			// 
			// rePassLabel
			// 
			this->rePassLabel->AutoSize = true;
			this->rePassLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rePassLabel->ForeColor = System::Drawing::Color::White;
			this->rePassLabel->Location = System::Drawing::Point(79, 203);
			this->rePassLabel->Name = L"rePassLabel";
			this->rePassLabel->Size = System::Drawing::Size(172, 24);
			this->rePassLabel->TabIndex = 4;
			this->rePassLabel->Text = L"Re-Enter Password";
			// 
			// typeInp
			// 
			this->typeInp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->typeInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->typeInp->FormattingEnabled = true;
			this->typeInp->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"user", L"admin" });
			this->typeInp->Location = System::Drawing::Point(284, 83);
			this->typeInp->Name = L"typeInp";
			this->typeInp->Size = System::Drawing::Size(236, 30);
			this->typeInp->TabIndex = 5;
			// 
			// usrInp
			// 
			this->usrInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usrInp->Location = System::Drawing::Point(284, 122);
			this->usrInp->Name = L"usrInp";
			this->usrInp->Size = System::Drawing::Size(236, 28);
			this->usrInp->TabIndex = 6;
			// 
			// passInp
			// 
			this->passInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passInp->Location = System::Drawing::Point(284, 161);
			this->passInp->Name = L"passInp";
			this->passInp->Size = System::Drawing::Size(236, 28);
			this->passInp->TabIndex = 7;
			this->passInp->UseSystemPasswordChar = true;
			// 
			// rePassInp
			// 
			this->rePassInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rePassInp->Location = System::Drawing::Point(284, 200);
			this->rePassInp->Name = L"rePassInp";
			this->rePassInp->Size = System::Drawing::Size(236, 28);
			this->rePassInp->TabIndex = 8;
			this->rePassInp->UseSystemPasswordChar = true;
			// 
			// toggleP
			// 
			this->toggleP->AutoSize = true;
			this->toggleP->Location = System::Drawing::Point(529, 164);
			this->toggleP->Name = L"toggleP";
			this->toggleP->Size = System::Drawing::Size(18, 17);
			this->toggleP->TabIndex = 9;
			this->toggleP->UseVisualStyleBackColor = true;
			this->toggleP->CheckedChanged += gcnew System::EventHandler(this, &AddAccount::CheckP);
			// 
			// toggleRP
			// 
			this->toggleRP->AutoSize = true;
			this->toggleRP->Location = System::Drawing::Point(529, 203);
			this->toggleRP->Name = L"toggleRP";
			this->toggleRP->Size = System::Drawing::Size(18, 17);
			this->toggleRP->TabIndex = 10;
			this->toggleRP->UseVisualStyleBackColor = true;
			this->toggleRP->CheckedChanged += gcnew System::EventHandler(this, &AddAccount::CheckRP);
			// 
			// AddAccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(103)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->ClientSize = System::Drawing::Size(594, 321);
			this->Controls->Add(this->toggleRP);
			this->Controls->Add(this->toggleP);
			this->Controls->Add(this->rePassInp);
			this->Controls->Add(this->passInp);
			this->Controls->Add(this->usrInp);
			this->Controls->Add(this->typeInp);
			this->Controls->Add(this->rePassLabel);
			this->Controls->Add(this->TypeAcc);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->usrLabel);
			this->Controls->Add(this->Footer);
			this->Controls->Add(this->Header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddAccount";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"AddAccount";
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->Footer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: Void Perform(Object^ sender, EventArgs^ e) {
			if (this->passInp->Text != this->rePassInp->Text) {
				MessageBox::Show("2 password is not the same!");
			}
			else {
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->role = this->typeInp->Text;
				this->usr = this->usrInp->Text;
				this->pwd = this->passInp->Text;
			}
			this->Close();
		}
		private: Void Exit(Object^ sender, EventArgs^ e) {
			this->Close();
		}
		private: Void pressEnter(Object^ sender, KeyEventArgs^ e) {
			if (e->KeyCode != System::Windows::Forms::Keys::Enter) return;
			if (this->typeInp->Text == "" || this->usrInp->Text == "" || this->passInp->Text == "" || this->rePassInp->Text == "") {
				MessageBox::Show("Please fill all fields!");
				return;
			}
			Perform(sender, e);
		}
		private: Void CheckP(Object^ sender, EventArgs^ e){
			togglePass(this->toggleP, this->passInp);
		}
		private: Void CheckRP(Object^ sender, EventArgs^ e) {
			togglePass(this->toggleRP, this->rePassInp);
		}
		private: Void togglePass(CheckBox^ c, MaskedTextBox^ m) {
			if (c->Checked) {
				m->UseSystemPasswordChar = false;
			}
			else {
				m->UseSystemPasswordChar = true;
			}
		}
		public:
			String^ getRole() { return this->role; }
			String^ getUname() { return this->usr; }
			String^ getPass() { return this->pwd; }
	};
}
