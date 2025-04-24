#pragma once
namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Delete_Acc
	/// </summary>
	public ref class Delete_Acc : public System::Windows::Forms::Form
	{
	private: String^ pass;
	public:
		Delete_Acc(String^ pwd)
		{
			InitializeComponent();
			this->pass = pwd;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Delete_Acc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Header;
	protected:

	protected:
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Panel^ Footer;

	private: System::Windows::Forms::Button^ OKBtn;
	private: System::Windows::Forms::Button^ CancelBtn;
	private: System::Windows::Forms::Label^ ConfirmMess;
	private: System::Windows::Forms::Label^ confirmLabel;
	private: System::Windows::Forms::Label^ passLabel;
	private: System::Windows::Forms::TextBox^ confirmInp;
	private: System::Windows::Forms::MaskedTextBox^ passInp;


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
			this->ConfirmMess = (gcnew System::Windows::Forms::Label());
			this->confirmLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->confirmInp = (gcnew System::Windows::Forms::TextBox());
			this->passInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->Header->SuspendLayout();
			this->Footer->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->Header->Controls->Add(this->Title);
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(496, 58);
			this->Header->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(151, 12);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(175, 29);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Delete Account";
			// 
			// Footer
			// 
			this->Footer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(169)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->Footer->Controls->Add(this->OKBtn);
			this->Footer->Controls->Add(this->CancelBtn);
			this->Footer->Location = System::Drawing::Point(0, 222);
			this->Footer->Name = L"Footer";
			this->Footer->Size = System::Drawing::Size(496, 69);
			this->Footer->TabIndex = 1;
			// 
			// CancelBtn
			// 
			this->CancelBtn->Location = System::Drawing::Point(70, 18);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(118, 38);
			this->CancelBtn->TabIndex = 0;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			this->CancelBtn->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Delete_Acc::Quit);
			// 
			// OKBtn
			// 
			this->OKBtn->Location = System::Drawing::Point(286, 18);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(118, 38);
			this->OKBtn->TabIndex = 1;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Delete_Acc::Confirm);
			// 
			// ConfirmMess
			// 
			this->ConfirmMess->AutoSize = true;
			this->ConfirmMess->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConfirmMess->ForeColor = System::Drawing::Color::Red;
			this->ConfirmMess->Location = System::Drawing::Point(112, 71);
			this->ConfirmMess->Name = L"ConfirmMess";
			this->ConfirmMess->Size = System::Drawing::Size(247, 25);
			this->ConfirmMess->TabIndex = 2;
			this->ConfirmMess->Text = L"I want to delete my account";
			// 
			// confirmLabel
			// 
			this->confirmLabel->AutoSize = true;
			this->confirmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmLabel->Location = System::Drawing::Point(26, 117);
			this->confirmLabel->Name = L"confirmLabel";
			this->confirmLabel->Size = System::Drawing::Size(130, 20);
			this->confirmLabel->TabIndex = 3;
			this->confirmLabel->Text = L"Enter above text";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLabel->Location = System::Drawing::Point(26, 161);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(154, 20);
			this->passLabel->TabIndex = 4;
			this->passLabel->Text = L"Enter your pasword";
			// 
			// confirmInp
			// 
			this->confirmInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirmInp->Location = System::Drawing::Point(206, 117);
			this->confirmInp->Name = L"confirmInp";
			this->confirmInp->Size = System::Drawing::Size(245, 30);
			this->confirmInp->TabIndex = 5;
			this->confirmInp->Focus();
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PBLWORDLEGAME::Delete_Acc::PerForm);
			// 
			// passInp
			// 
			this->passInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passInp->Location = System::Drawing::Point(206, 158);
			this->passInp->Name = L"passInp";
			this->passInp->Size = System::Drawing::Size(245, 30);
			this->passInp->TabIndex = 6;
			this->passInp->UseSystemPasswordChar = true;
			this->passInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PBLWORDLEGAME::Delete_Acc::PerForm);
			// 
			// Delete_Acc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(494, 290);
			this->Controls->Add(this->passInp);
			this->Controls->Add(this->confirmInp);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->confirmLabel);
			this->Controls->Add(this->ConfirmMess);
			this->Controls->Add(this->Footer);
			this->Controls->Add(this->Header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Delete_Acc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Delete_Acc";
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->Footer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void Quit(Object^ sender, EventArgs^ e) {
		this->Close();
	}
	private: Void Confirm(Object^ sender, EventArgs^ e) {
		if (this->confirmInp->Text == this->ConfirmMess->Text && this->passInp->Text == this->pass) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}
	private: Void PerForm(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode != System::Windows::Forms::Keys::Enter) return;
		if (this->confirmInp->Text == "" || this->passInp->Text == "") {
			MessageBox::Show("Please fill all fields!");
		}
		else {
			Confirm(sender, e);
		}
	}
	};
}
