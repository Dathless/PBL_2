#pragma once
#include "Landing.h"
#include "Login.h"
#include "Register.h"
#include "DashBoard.h"
#include "Dashboard_Admin.h"
#include "Setting.h"
#include "Credit.h"
#include "Account.h"
#include "SettingManager.h"
#include <fstream>


namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::Media;
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
	private: Dashboard_Admin^ adminDashBoard;
	private: Setting^ setting;
	private: Credit^ credit;
	private: System::String^ user;
	private: AxWMPLib::AxWindowsMediaPlayer^ BGMusic;
	private: SettingManager^ settings;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GAME_CENTER::typeid));
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->BGMusic = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->BeginInit();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::Transparent;
			this->mainPanel->Controls->Add(this->BGMusic);
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(782, 553);
			this->mainPanel->TabIndex = 0;
			this->mainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GAME_CENTER::mainPanel_Paint);
			// 
			// BGMusic
			// 
			this->BGMusic->Enabled = true;
			this->BGMusic->Location = System::Drawing::Point(636, 29);
			this->BGMusic->Name = L"BGMusic";
			this->BGMusic->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"BGMusic.OcxState")));
			this->BGMusic->Size = System::Drawing::Size(110, 36);
			this->BGMusic->TabIndex = 0;
			this->BGMusic->Visible = false;
			// 
			// GAME_CENTER
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->mainPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GAME_CENTER";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GAME_CENTER";
			this->Load += gcnew System::EventHandler(this, &GAME_CENTER::OnLoad);
			this->mainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OnLoad(System::Object^ sender, System::EventArgs^ e) {
		LoadLanding();//Load Landing page
		this->settings = gcnew SettingManager();//setting manager ( bg Img, music, ... )
		settings->Landing_BgImg(this);
		settings->Landing_Music(this->BGMusic);
		
	}
	private: System::Void mainPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void LoadLanding() {//create landing UC
		this->mainPanel->Controls->Clear();
		this->landing = gcnew Landing();
		this->landing->Dock = System::Windows::Forms::DockStyle::Fill;
		this->landing->enterLogin += gcnew System::EventHandler(this, &GAME_CENTER::showLogin);
		this->landing->enterRegis += gcnew System::EventHandler(this, &GAME_CENTER::showRegis);
		this->landing->enterSetting += gcnew System::EventHandler(this, &GAME_CENTER::showSetting);
		this->landing->enterCredit += gcnew System::EventHandler(this, &GAME_CENTER::showCredit);
		this->landing->quitForm += gcnew System::EventHandler(this, &GAME_CENTER::quitGame);
		this->mainPanel->Controls->Add(landing);
	}
	private: System::Void showLogin(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		//Create login form  
		this->login = gcnew Login(/*this*/);
		this->login->Dock = System::Windows::Forms::DockStyle::Fill;
		this->login->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
		this->login->enterDashBoard += gcnew System::EventHandler(this, &GAME_CENTER::showDashBoard);
		this->login->adminDashBoard += gcnew System::EventHandler(this, &GAME_CENTER::showAdminDashBoard);
		this->mainPanel->Controls->Add(login);
	}
	private: System::Void showRegis(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		// Create register form
		this->regis = gcnew Register();
		this->regis->Dock = System::Windows::Forms::DockStyle::Fill;
		this->regis->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
		this->mainPanel->Controls->Add(regis);
	}
	private: System::Void showSetting(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->setting = gcnew Setting();
		this->setting->Dock = DockStyle::Fill;
		this->setting->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
		this->setting->ApplyEvent += gcnew System::EventHandler(this, &GAME_CENTER::OnLoad);
		this->mainPanel->Controls->Add(setting);
	}
	private: System::Void showCredit(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		// Create Credit form
		this->credit = gcnew Credit();
		this->credit->Dock = System::Windows::Forms::DockStyle::Fill;
		this->credit->goBack += gcnew System::EventHandler(this, &GAME_CENTER::GoToBack);
		this->mainPanel->Controls->Add(credit);
	}
	private: System::Void GoToBack(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(landing);
	}
	private: System::Void BackToLanding(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		this->mainPanel->Controls->Add(landing);
		this->settings->Landing_Music(BGMusic);
	}

	private: System::Void showDashBoard(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		System::String^ usr = this->login->usrname;//add username when login successfully
		this->dashBoard = gcnew DashBoard(usr);
		this->dashBoard->Dock = System::Windows::Forms::DockStyle::Fill;
		this->dashBoard->goBack += gcnew System::EventHandler(this, &GAME_CENTER::BackToLanding);
		this->dashBoard->enterGame2 += gcnew System::EventHandler(this, &GAME_CENTER::pauseMusic);
		this->dashBoard->backDashBoard += gcnew System::EventHandler(this, &GAME_CENTER::continueMusic);
		this->mainPanel->Controls->Add(dashBoard);
		this->settings->Dashboard_Music(this->BGMusic);
	}
	private: System::Void showAdminDashBoard(System::Object^ sender, System::EventArgs^ e) {
		this->mainPanel->Controls->Clear();
		System::String^ usr = this->login->usrname;//add username when login successfully
		this->adminDashBoard = gcnew Dashboard_Admin(usr);
		this->adminDashBoard->Dock = System::Windows::Forms::DockStyle::Fill;
		this->adminDashBoard->goBack += gcnew System::EventHandler(this, &GAME_CENTER::BackToLanding);
		this->mainPanel->Controls->Add(adminDashBoard);
		this->settings->Dashboard_Music(this->BGMusic);
	}
	private: System::Void pauseMusic(Object^ sender, EventArgs^ e) {
		this->settings->PauseAxWMP(BGMusic);

	}
	private: System::Void continueMusic(Object^ sender, EventArgs^ e) {
		this->settings->Dashboard_Music(BGMusic);
	}
	private: System::Void quitGame(System::Object^ sender, System::EventArgs^ e) {
		this->BGMusic->Ctlcontrols->stop();
		this->Close();
	}
	
	};
}
