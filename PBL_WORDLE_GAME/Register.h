#pragma once
#include "Account.h"
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::UserControl
	{
	public:
		event EventHandler^ goBack;
		Register(void)
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
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::Label^ usrLabel;
	private: System::Windows::Forms::Label^ passLabel;
	private: System::Windows::Forms::Label^ rePassLabel;
	private: System::Windows::Forms::TextBox^ usrInp;
	private: System::Windows::Forms::MaskedTextBox^ passInp;
	private: System::Windows::Forms::MaskedTextBox^ rePassInp;
	private: System::Windows::Forms::Label^ errMes;
	private: System::Windows::Forms::Button^ regisBtn;
	private: System::Windows::Forms::Button^ backBtn;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->usrLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->rePassLabel = (gcnew System::Windows::Forms::Label());
			this->usrInp = (gcnew System::Windows::Forms::TextBox());
			this->passInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->rePassInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->errMes = (gcnew System::Windows::Forms::Label());
			this->regisBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(229, 63);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(337, 69);
			this->Title->TabIndex = 0;
			this->Title->Text = L"REGISTER";
			// 
			// usrLabel
			// 
			this->usrLabel->AutoSize = true;
			this->usrLabel->BackColor = System::Drawing::Color::Transparent;
			this->usrLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->usrLabel->ForeColor = System::Drawing::Color::White;
			this->usrLabel->Location = System::Drawing::Point(73, 197);
			this->usrLabel->Name = L"usrLabel";
			this->usrLabel->Size = System::Drawing::Size(139, 31);
			this->usrLabel->TabIndex = 1;
			this->usrLabel->Text = L"Username";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->BackColor = System::Drawing::Color::Transparent;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->passLabel->ForeColor = System::Drawing::Color::White;
			this->passLabel->Location = System::Drawing::Point(76, 249);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(134, 31);
			this->passLabel->TabIndex = 2;
			this->passLabel->Text = L"Password";
			// 
			// rePassLabel
			// 
			this->rePassLabel->AutoSize = true;
			this->rePassLabel->BackColor = System::Drawing::Color::Transparent;
			this->rePassLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->rePassLabel->ForeColor = System::Drawing::Color::White;
			this->rePassLabel->Location = System::Drawing::Point(73, 306);
			this->rePassLabel->Name = L"rePassLabel";
			this->rePassLabel->Size = System::Drawing::Size(250, 31);
			this->rePassLabel->TabIndex = 3;
			this->rePassLabel->Text = L"Re-Enter Password";
			// 
			// usrInp
			// 
			this->usrInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->usrInp->Location = System::Drawing::Point(346, 190);
			this->usrInp->Name = L"usrInp";
			this->usrInp->Size = System::Drawing::Size(357, 38);
			this->usrInp->TabIndex = 4;
			// 
			// passInp
			// 
			this->passInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->passInp->Location = System::Drawing::Point(346, 242);
			this->passInp->Name = L"passInp";
			this->passInp->Size = System::Drawing::Size(357, 38);
			this->passInp->TabIndex = 5;
			this->passInp->UseSystemPasswordChar = true;
			// 
			// rePassInp
			// 
			this->rePassInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->rePassInp->Location = System::Drawing::Point(346, 299);
			this->rePassInp->Name = L"rePassInp";
			this->rePassInp->Size = System::Drawing::Size(357, 38);
			this->rePassInp->TabIndex = 6;
			this->rePassInp->UseSystemPasswordChar = true;
			// 
			// errMes
			// 
			this->errMes->AutoSize = true;
			this->errMes->BackColor = System::Drawing::Color::Transparent;
			this->errMes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->errMes->ForeColor = System::Drawing::Color::Red;
			this->errMes->Location = System::Drawing::Point(343, 387);
			this->errMes->Name = L"errMes";
			this->errMes->Size = System::Drawing::Size(0, 24);
			this->errMes->TabIndex = 7;
			// 
			// regisBtn
			// 
			this->regisBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->regisBtn->Location = System::Drawing::Point(499, 433);
			this->regisBtn->Name = L"regisBtn";
			this->regisBtn->Size = System::Drawing::Size(118, 41);
			this->regisBtn->TabIndex = 8;
			this->regisBtn->Text = L"Register";
			this->regisBtn->UseVisualStyleBackColor = true;
			this->regisBtn->Click += gcnew System::EventHandler(this, &Register::registerAccount);
			// 
			// backBtn
			// 
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->backBtn->Location = System::Drawing::Point(185, 433);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(118, 41);
			this->backBtn->TabIndex = 9;
			this->backBtn->Text = L"Back";
			this->backBtn->UseVisualStyleBackColor = true;
			this->backBtn->Click += gcnew System::EventHandler(this, &Register::backToLanding);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = gcnew System::Drawing::Bitmap("asset\\img\\bg1.jpg");
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->regisBtn);
			this->Controls->Add(this->errMes);
			this->Controls->Add(this->rePassInp);
			this->Controls->Add(this->passInp);
			this->Controls->Add(this->usrInp);
			this->Controls->Add(this->rePassLabel);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->usrLabel);
			this->Controls->Add(this->Title);
			this->Name = L"Register";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &Register::Register_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Register_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
	private: System::Void registerAccount(System::Object^ sender, System::EventArgs^ e) {
		errMes->Text = ""; // Xóa lỗi cũ khi nhập lại
		if (usrInp->Text == "" || passInp->Text == "" || rePassInp->Text == "") {
			errMes->Text = "Please fill in all fields";
		}
		else if (passInp->Text->Length < 6) {
			errMes->Text = "Password must be at least 6 characters long";
		}
		else if (passInp->Text != rePassInp->Text) {
			errMes->Text = "Password does not match";
			rePassInp->clear();
		}	
		else {
			createAccount(usrInp->Text, passInp->Text);
		}
	}
	private: System::Void createAccount(String^ usr, String^ pwd) {
		Account^ newAcc = gcnew Account(usr, pwd);
		String^ folderPath = "UserList\\";
		String^ filePath = folderPath + usr + ".txt";

		if (File::Exists(filePath)) {
			this->errMes->Text = "Username already exists! Choose another.";
			this->errMes->ForeColor = System::Drawing::Color::White;
			return;
		}

		if (!Directory::Exists(folderPath)) {
				Directory::CreateDirectory(folderPath);
			}

		// Save User Data to .txt File
		try {
			StreamWriter^ file = gcnew StreamWriter(filePath);
			file->WriteLine(newAcc->ToTXTObject());
			file->Close();
			this->errMes->Text = "Account created successfully";
			this->errMes->ForeColor = System::Drawing::Color::Green;
		}
		catch (Exception^ ex) {
			this->errMes->Text = "Error saving file! Error:" + ex->Message;
			this->errMes->ForeColor = System::Drawing::Color::Red;
		}
	}
	};
}

