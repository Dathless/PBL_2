#pragma once
#include "GAME_CENTER.h"
#include "DashBoard.h"
#include "CryptoUtils.h"
#include "fstream"
//#include <openssl/sha.h>  // Cần thư viện OpenSSL
//#include <msclr/marshal_cppstd.h> 
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;

namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::UserControl
	{
	/*private: GAME_CENTER^ game_center;*/
	public:
		event EventHandler^ goBack;
		event EventHandler^ enterDashBoard;
		
		System::String^ usrname;
		Login(/*GAME_CENTER^ parent*/)
		{
			/*game_center = parent;*/
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		/*event System::EventHandler<System::String^>^ enterDashBoard;*/
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
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
	private: System::Windows::Forms::CheckBox^ remCheckbox;
	private: System::Windows::Forms::Label^ errMes;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Button^ exBtn;
	private: System::Windows::Forms::TextBox^ usrInp;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->usrLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->remCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->errMes = (gcnew System::Windows::Forms::Label());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->exBtn = (gcnew System::Windows::Forms::Button());
			this->usrInp = (gcnew System::Windows::Forms::TextBox());
			this->passInp = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(295, 93);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(233, 69);
			this->Title->TabIndex = 7;
			this->Title->Text = L"LOG IN";
			// 
			// usrLabel
			// 
			this->usrLabel->AutoSize = true;
			this->usrLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->usrLabel->ForeColor = System::Drawing::Color::White;
			this->usrLabel->Location = System::Drawing::Point(134, 216);
			this->usrLabel->Name = L"usrLabel";
			this->usrLabel->Size = System::Drawing::Size(139, 31);
			this->usrLabel->TabIndex = 8;
			this->usrLabel->Text = L"Username";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->passLabel->ForeColor = System::Drawing::Color::White;
			this->passLabel->Location = System::Drawing::Point(137, 297);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(134, 31);
			this->passLabel->TabIndex = 2;
			this->passLabel->Text = L"Password";
			// 
			// remCheckbox
			// 
			this->remCheckbox->AutoSize = true;
			this->remCheckbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->remCheckbox->ForeColor = System::Drawing::Color::White;
			this->remCheckbox->Location = System::Drawing::Point(307, 371);
			this->remCheckbox->Name = L"remCheckbox";
			this->remCheckbox->Size = System::Drawing::Size(146, 24);
			this->remCheckbox->TabIndex = 3;
			this->remCheckbox->Text = L"Remember me!";
			this->remCheckbox->UseVisualStyleBackColor = true;
			// 
			// errMes
			// 
			this->errMes->AutoSize = true;
			this->errMes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->errMes->ForeColor = System::Drawing::Color::Red;
			this->errMes->Location = System::Drawing::Point(304, 342);
			this->errMes->Name = L"errMes";
			this->errMes->Size = System::Drawing::Size(0, 20);
			this->errMes->TabIndex = 4;
			// 
			// loginBtn
			// 
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->loginBtn->Location = System::Drawing::Point(505, 434);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(99, 41);
			this->loginBtn->TabIndex = 5;
			this->loginBtn->Text = L"Log In";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &Login::openDashBoard);
			// 
			// exBtn
			// 
			this->exBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->exBtn->Location = System::Drawing::Point(208, 434);
			this->exBtn->Name = L"exBtn";
			this->exBtn->Size = System::Drawing::Size(99, 41);
			this->exBtn->TabIndex = 6;
			this->exBtn->Text = L"Exit";
			this->exBtn->UseVisualStyleBackColor = true;
			this->exBtn->Click += gcnew System::EventHandler(this, &Login::backToLanding);
			// 
			// usrInp
			// 
			this->usrInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->usrInp->Location = System::Drawing::Point(307, 216);
			this->usrInp->Name = L"usrInp";
			this->usrInp->Size = System::Drawing::Size(371, 38);
			this->usrInp->TabIndex = 0;
			this->usrInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Login::PerformLogin);
			// 
			// passInp
			// 
			this->passInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->passInp->Location = System::Drawing::Point(307, 297);
			this->passInp->Name = L"passInp";
			this->passInp->Size = System::Drawing::Size(371, 38);
			this->passInp->TabIndex = 1;
			this->passInp->UseSystemPasswordChar = true;
			this->passInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Login::PerformLogin);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			//this->BackgroundImage = gcnew System::Drawing::Bitmap("asset\\img\\bg1.jpg");
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->passInp);
			this->Controls->Add(this->usrInp);
			this->Controls->Add(this->exBtn);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->errMes);
			this->Controls->Add(this->remCheckbox);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->usrLabel);
			this->Controls->Add(this->Title);
			this->Name = L"Login";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: System::String^ ComputeSHA256(String^ input) {
	    std::string inputStr = msclr::interop::marshal_as<std::string>(input);
	    unsigned char hash[SHA256_DIGEST_LENGTH];
	    SHA256((unsigned char*)inputStr.c_str(), inputStr.length(), hash);
	
	    StringBuilder^ sb = gcnew StringBuilder();
	    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
	        sb->Append(hash[i].ToString("x2"));
	    }
	    return sb->ToString();
	}*/
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
		this->usrInp->Focus();
		if (!this->remCheckbox->Checked) {
			this->usrInp->Text = "";
		}
		this->passInp->Text = "";
	}
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
			goBack(this, e);
	}
	private: System::Void openDashBoard(System::Object^ sender, System::EventArgs^ e) {
		//String^ enteredPassword = ComputeSHA256(this->passInp->Text);
  // 		String^ storedPassword = "03ac674216f3e15c761ee1a5e255f067" // Giá trị SHA-256 của "1234"
		/*if (this->usrInp->Text == "Admin" && enteredPassword == storedPassword this->passInp->Text == "1234") {
        		enterDashBoard(this, e);
    		}
		else {
			this->errMes->Text = "The username or password is invalid!";
		}
		if (!this->remCheckbox->Checked) this->usrInp->Text = "";
		this->passInp->Text = "";*/
		System::String^ usr = this->usrInp->Text;
		System::String^ pwd = this->passInp->Text;
		System::String^ userDir = "UserList\\";
		System::String^ userPath = userDir + usr + ".txt";
		if (File::Exists(userPath)) {
			StreamReader^ reader = gcnew StreamReader(userPath);
			System::String^ line = reader->ReadLine();
			array<System::String^>^ part = line->Split(' ');
			if (part->Length != 2) {
				MessageBox::Show("File Format is invalid!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				System::String^ storedUsr = part[0];
				System::String^ storedPwd = part[1];
				System::String^ decryptPwd = PBLWORDLEGAME::CryptoUtils::Decrypt(storedPwd);
				if (storedUsr == usr && decryptPwd == pwd) {
					usrname = usr;
					enterDashBoard(this, e);
					/*if (enterDashBoard != nullptr) {
						enterDashBoard(this, usr);
					}*/
				}
				else {
					this->errMes->Text = "The username or password is invalid!";
				}
				if (!this->remCheckbox->Checked) this->usrInp->Text = "";
				this->passInp->Text = "";
			}
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void PerformLogin(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			e->SuppressKeyPress = true;
			openDashBoard(sender, e);
		}
	}
};
}
