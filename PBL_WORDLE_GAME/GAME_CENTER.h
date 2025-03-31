#pragma once
#include "Landing.h"
#include "Login.h"
#include "Register.h"
#include "DashBoard.h"
#include "Credit.h"
#include "Account.h"
#include <fstream>

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GAME_CENTER
	/// </summary>
	public ref class GAME_CENTER : public System::Windows::Forms::Form
	{
	private: Landing^ landing;
	private: Login^ login;
	private: Register^ regis;
	private: DashBoard^ dashBoard;
	private: Credit^ credit;

	public:
		GAME_CENTER(void)
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
		~GAME_CENTER()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ mainPanel;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(782, 553);
			this->mainPanel->TabIndex = 0;
			this->mainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GAME_CENTER::mainPanel_Paint);
			// 
			// GAME_CENTER
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->mainPanel);
			this->BackgroundImage = gcnew System::Drawing::Bitmap("asset\\img\\bg1.jpg");
			this->Icon = gcnew System::Drawing::Icon("asset\\logo\\logo.ico");
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Name = L"GAME_CENTER";
			this->Text = L"GAME_CENTER";
			this->Load += gcnew System::EventHandler(this, &GAME_CENTER::GAME_CENTER_Load);
			this->ResumeLayout(false);
			//
			//Create Landing Page
			//
			this->landing = gcnew Landing();
			this->landing->Dock = System::Windows::Forms::DockStyle::Fill;
			this->landing->enterLogin += gcnew System::EventHandler(this, &GAME_CENTER::showLogin);
			this->landing->enterRegis += gcnew System::EventHandler(this, &GAME_CENTER::showRegis);
			this->landing->enterCredit += gcnew System::EventHandler(this, &GAME_CENTER::showCredit);
			this->landing->quitForm += gcnew System::EventHandler(this, &GAME_CENTER::quitGame);
			//
			//Create login form 
			// 
			this->login = gcnew Login();
			this->login->Dock = System::Windows::Forms::DockStyle::Fill;
			this->login->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
			this->login->enterDashBoard += gcnew System::EventHandler(this, &GAME_CENTER::showDashBoard);
			//
			// Create register form
			// 
			this->regis = gcnew Register();
			this->regis->Dock = System::Windows::Forms::DockStyle::Fill;
			this->regis->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
			//
			// Create dashboard
			// 
			this->dashBoard = gcnew DashBoard();
			this->dashBoard->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dashBoard->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
			//
			// Create Credit form
			// 
			this->credit = gcnew Credit();
			this->credit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->credit->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
			//
			//Load landing page
			//
			this->mainPanel->Controls->Add(landing);

		}
#pragma endregion
	private: System::Void GAME_CENTER_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void mainPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void showLogin(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(login);
	}
	private: System::Void showRegis(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(regis);
	}
	private: System::Void showCredit(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(credit);
	}
	private: System::Void GoToBack(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(landing);
	}
	private: System::Void showDashBoard(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->dashBoard->userLogged = gcnew Account("Admin","");
		this->mainPanel->Controls->Add(dashBoard);
	}
	private: System::Void quitGame(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
