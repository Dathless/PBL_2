#pragma once
#include "SettingManager.h"
#include "BrowsePopup.h"
#include <fstream>
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Setting
	/// </summary>
	public ref class Setting : public System::Windows::Forms::UserControl
	{
	public: EventHandler^ goBack;
	public: EventHandler^ ApplyEvent;
	private: SettingManager^ settings;
	private: String^ fileSetting;
	private: int volValue;
	private: array<String^>^ currSettings;
	public:
		Setting(void)
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
		~Setting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::Label^ BgImg;
	private: System::Windows::Forms::Label^ landingMusic;
	private: System::Windows::Forms::Label^ dashboardMusic;
	private: System::Windows::Forms::Label^ game1Music;
	private: System::Windows::Forms::Label^ game2Music;
	private: System::Windows::Forms::Label^ game3Music;
	private: System::Windows::Forms::Label^ setVolume;
	private: System::Windows::Forms::Button^ applyBtn;
	private: System::Windows::Forms::Button^ cancelBtn;
	private: System::Windows::Forms::Button^ bgImgBrowse;
	private: System::Windows::Forms::Button^ landingBrowse;
	private: System::Windows::Forms::Button^ dashboardBrowse;
	private: System::Windows::Forms::Button^ game1Browse;
	private: System::Windows::Forms::Button^ game2Browse;
	private: System::Windows::Forms::Button^ game3Browse;
	private: System::Windows::Forms::Label^ currBgImg;
	private: System::Windows::Forms::Label^ currLanding;
	private: System::Windows::Forms::Label^ currGame1;
	private: System::Windows::Forms::Label^ currDashboard;
	private: System::Windows::Forms::Label^ currGame3;
	private: System::Windows::Forms::Label^ currGame2;
	private: System::Windows::Forms::TextBox^ currVol;
	private: System::Windows::Forms::Button^ IncVol;
	private: System::Windows::Forms::Button^ DecVol;
	private: System::Windows::Forms::Button^ sDecVol;

	private: System::Windows::Forms::Button^ sIncVol;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Setting::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BgImg = (gcnew System::Windows::Forms::Label());
			this->landingMusic = (gcnew System::Windows::Forms::Label());
			this->dashboardMusic = (gcnew System::Windows::Forms::Label());
			this->game1Music = (gcnew System::Windows::Forms::Label());
			this->game2Music = (gcnew System::Windows::Forms::Label());
			this->game3Music = (gcnew System::Windows::Forms::Label());
			this->setVolume = (gcnew System::Windows::Forms::Label());
			this->applyBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->bgImgBrowse = (gcnew System::Windows::Forms::Button());
			this->landingBrowse = (gcnew System::Windows::Forms::Button());
			this->dashboardBrowse = (gcnew System::Windows::Forms::Button());
			this->game1Browse = (gcnew System::Windows::Forms::Button());
			this->game2Browse = (gcnew System::Windows::Forms::Button());
			this->game3Browse = (gcnew System::Windows::Forms::Button());
			this->currBgImg = (gcnew System::Windows::Forms::Label());
			this->currLanding = (gcnew System::Windows::Forms::Label());
			this->currGame1 = (gcnew System::Windows::Forms::Label());
			this->currDashboard = (gcnew System::Windows::Forms::Label());
			this->currGame3 = (gcnew System::Windows::Forms::Label());
			this->currGame2 = (gcnew System::Windows::Forms::Label());
			this->currVol = (gcnew System::Windows::Forms::TextBox());
			this->IncVol = (gcnew System::Windows::Forms::Button());
			this->DecVol = (gcnew System::Windows::Forms::Button());
			this->sDecVol = (gcnew System::Windows::Forms::Button());
			this->sIncVol = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(250, 8);
			this->Title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(144, 46);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Setting";
			// 
			// BgImg
			// 
			this->BgImg->AutoSize = true;
			this->BgImg->BackColor = System::Drawing::Color::Transparent;
			this->BgImg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BgImg->ForeColor = System::Drawing::Color::White;
			this->BgImg->Location = System::Drawing::Point(45, 61);
			this->BgImg->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BgImg->Name = L"BgImg";
			this->BgImg->Size = System::Drawing::Size(250, 25);
			this->BgImg->TabIndex = 1;
			this->BgImg->Text = L"Choose Background Image";
			// 
			// landingMusic
			// 
			this->landingMusic->AutoSize = true;
			this->landingMusic->BackColor = System::Drawing::Color::Transparent;
			this->landingMusic->ForeColor = System::Drawing::Color::White;
			this->landingMusic->Location = System::Drawing::Point(45, 105);
			this->landingMusic->Name = L"landingMusic";
			this->landingMusic->Size = System::Drawing::Size(213, 25);
			this->landingMusic->TabIndex = 2;
			this->landingMusic->Text = L"Choose Landing Music";
			// 
			// dashboardMusic
			// 
			this->dashboardMusic->AutoSize = true;
			this->dashboardMusic->BackColor = System::Drawing::Color::Transparent;
			this->dashboardMusic->ForeColor = System::Drawing::Color::White;
			this->dashboardMusic->Location = System::Drawing::Point(45, 151);
			this->dashboardMusic->Name = L"dashboardMusic";
			this->dashboardMusic->Size = System::Drawing::Size(241, 25);
			this->dashboardMusic->TabIndex = 3;
			this->dashboardMusic->Text = L"Choose DashBoard Music";
			// 
			// game1Music
			// 
			this->game1Music->AutoSize = true;
			this->game1Music->BackColor = System::Drawing::Color::Transparent;
			this->game1Music->ForeColor = System::Drawing::Color::White;
			this->game1Music->Location = System::Drawing::Point(45, 194);
			this->game1Music->Name = L"game1Music";
			this->game1Music->Size = System::Drawing::Size(212, 25);
			this->game1Music->TabIndex = 4;
			this->game1Music->Text = L"Choose Game 1 Music";
			// 
			// game2Music
			// 
			this->game2Music->AutoSize = true;
			this->game2Music->BackColor = System::Drawing::Color::Transparent;
			this->game2Music->ForeColor = System::Drawing::Color::White;
			this->game2Music->Location = System::Drawing::Point(45, 237);
			this->game2Music->Name = L"game2Music";
			this->game2Music->Size = System::Drawing::Size(212, 25);
			this->game2Music->TabIndex = 5;
			this->game2Music->Text = L"Choose Game 2 Music";
			// 
			// game3Music
			// 
			this->game3Music->AutoSize = true;
			this->game3Music->BackColor = System::Drawing::Color::Transparent;
			this->game3Music->ForeColor = System::Drawing::Color::White;
			this->game3Music->Location = System::Drawing::Point(45, 283);
			this->game3Music->Name = L"game3Music";
			this->game3Music->Size = System::Drawing::Size(212, 25);
			this->game3Music->TabIndex = 6;
			this->game3Music->Text = L"Choose Game 3 Music";
			// 
			// setVolume
			// 
			this->setVolume->AutoSize = true;
			this->setVolume->BackColor = System::Drawing::Color::Transparent;
			this->setVolume->ForeColor = System::Drawing::Color::White;
			this->setVolume->Location = System::Drawing::Point(45, 320);
			this->setVolume->Name = L"setVolume";
			this->setVolume->Size = System::Drawing::Size(146, 25);
			this->setVolume->TabIndex = 7;
			this->setVolume->Text = L"Set the Volume";
			// 
			// applyBtn
			// 
			this->applyBtn->Location = System::Drawing::Point(400, 369);
			this->applyBtn->Name = L"applyBtn";
			this->applyBtn->Size = System::Drawing::Size(93, 36);
			this->applyBtn->TabIndex = 8;
			this->applyBtn->Text = L"Apply";
			this->applyBtn->UseVisualStyleBackColor = true;
			this->applyBtn->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Setting::saveSetting);
			// 
			// cancelBtn
			// 
			this->cancelBtn->Location = System::Drawing::Point(124, 369);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(93, 36);
			this->cancelBtn->TabIndex = 9;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &Setting::BackToLanding);
			// 
			// bgImgBrowse
			// 
			this->bgImgBrowse->Location = System::Drawing::Point(475, 61);
			this->bgImgBrowse->Name = L"bgImgBrowse";
			this->bgImgBrowse->Size = System::Drawing::Size(90, 32);
			this->bgImgBrowse->TabIndex = 10;
			this->bgImgBrowse->Text = L"Browse";
			this->bgImgBrowse->UseVisualStyleBackColor = true;
			this->bgImgBrowse->Click += gcnew System::EventHandler(this, &Setting::chooseImage);
			// 
			// landingBrowse
			// 
			this->landingBrowse->Location = System::Drawing::Point(475, 105);
			this->landingBrowse->Name = L"landingBrowse";
			this->landingBrowse->Size = System::Drawing::Size(90, 32);
			this->landingBrowse->TabIndex = 11;
			this->landingBrowse->Text = L"Browse";
			this->landingBrowse->UseVisualStyleBackColor = true;
			this->landingBrowse->Click += gcnew System::EventHandler(this, &Setting::chooseLanding);
			// 
			// dashboardBrowse
			// 
			this->dashboardBrowse->Location = System::Drawing::Point(475, 151);
			this->dashboardBrowse->Name = L"dashboardBrowse";
			this->dashboardBrowse->Size = System::Drawing::Size(90, 32);
			this->dashboardBrowse->TabIndex = 12;
			this->dashboardBrowse->Text = L"Browse";
			this->dashboardBrowse->UseVisualStyleBackColor = true;
			this->dashboardBrowse->Click += gcnew System::EventHandler(this, &Setting::chooseDashboard);
			// 
			// game1Browse
			// 
			this->game1Browse->Location = System::Drawing::Point(475, 194);
			this->game1Browse->Name = L"game1Browse";
			this->game1Browse->Size = System::Drawing::Size(90, 32);
			this->game1Browse->TabIndex = 13;
			this->game1Browse->Text = L"Browse";
			this->game1Browse->UseVisualStyleBackColor = true;
			this->game1Browse->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Setting::chooseGame1);
			// 
			// game2Browse
			// 
			this->game2Browse->Location = System::Drawing::Point(475, 233);
			this->game2Browse->Name = L"game2Browse";
			this->game2Browse->Size = System::Drawing::Size(90, 32);
			this->game2Browse->TabIndex = 14;
			this->game2Browse->Text = L"Browse";
			this->game2Browse->UseVisualStyleBackColor = true;
			this->game2Browse->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Setting::chooseGame2);
			// 
			// game3Browse
			// 
			this->game3Browse->Location = System::Drawing::Point(475, 283);
			this->game3Browse->Name = L"game3Browse";
			this->game3Browse->Size = System::Drawing::Size(90, 32);
			this->game3Browse->TabIndex = 15;
			this->game3Browse->Text = L"Browse";
			this->game3Browse->UseVisualStyleBackColor = true;
			this->game3Browse->Click += gcnew System::EventHandler(this, &PBLWORDLEGAME::Setting::chooseGame3);
			// 
			// currBgImg
			// 
			this->currBgImg->AutoSize = true;
			this->currBgImg->BackColor = System::Drawing::Color::Transparent;
			this->currBgImg->ForeColor = System::Drawing::Color::White;
			this->currBgImg->Location = System::Drawing::Point(349, 65);
			this->currBgImg->Name = L"currBgImg";
			this->currBgImg->Size = System::Drawing::Size(43, 25);
			this->currBgImg->TabIndex = 16;
			this->currBgImg->Text = L"File";
			// 
			// currLanding
			// 
			this->currLanding->AutoSize = true;
			this->currLanding->BackColor = System::Drawing::Color::Transparent;
			this->currLanding->ForeColor = System::Drawing::Color::White;
			this->currLanding->Location = System::Drawing::Point(349, 105);
			this->currLanding->Name = L"currLanding";
			this->currLanding->Size = System::Drawing::Size(43, 25);
			this->currLanding->TabIndex = 17;
			this->currLanding->Text = L"File";
			// 
			// currGame1
			// 
			this->currGame1->AutoSize = true;
			this->currGame1->BackColor = System::Drawing::Color::Transparent;
			this->currGame1->ForeColor = System::Drawing::Color::White;
			this->currGame1->Location = System::Drawing::Point(351, 194);
			this->currGame1->Name = L"currGame1";
			this->currGame1->Size = System::Drawing::Size(43, 25);
			this->currGame1->TabIndex = 19;
			this->currGame1->Text = L"File";
			// 
			// currDashboard
			// 
			this->currDashboard->AutoSize = true;
			this->currDashboard->BackColor = System::Drawing::Color::Transparent;
			this->currDashboard->ForeColor = System::Drawing::Color::White;
			this->currDashboard->Location = System::Drawing::Point(349, 151);
			this->currDashboard->Name = L"currDashboard";
			this->currDashboard->Size = System::Drawing::Size(43, 25);
			this->currDashboard->TabIndex = 18;
			this->currDashboard->Text = L"File";
			// 
			// currGame3
			// 
			this->currGame3->AutoSize = true;
			this->currGame3->BackColor = System::Drawing::Color::Transparent;
			this->currGame3->ForeColor = System::Drawing::Color::White;
			this->currGame3->Location = System::Drawing::Point(351, 283);
			this->currGame3->Name = L"currGame3";
			this->currGame3->Size = System::Drawing::Size(43, 25);
			this->currGame3->TabIndex = 21;
			this->currGame3->Text = L"File";
			// 
			// currGame2
			// 
			this->currGame2->AutoSize = true;
			this->currGame2->BackColor = System::Drawing::Color::Transparent;
			this->currGame2->ForeColor = System::Drawing::Color::White;
			this->currGame2->Location = System::Drawing::Point(351, 233);
			this->currGame2->Name = L"currGame2";
			this->currGame2->Size = System::Drawing::Size(43, 25);
			this->currGame2->TabIndex = 20;
			this->currGame2->Text = L"File";
			// 
			// currVol
			// 
			this->currVol->Location = System::Drawing::Point(347, 320);
			this->currVol->Name = L"currVol";
			this->currVol->ReadOnly = true;
			this->currVol->Size = System::Drawing::Size(100, 30);
			this->currVol->TabIndex = 22;
			this->currVol->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// IncVol
			// 
			this->IncVol->Location = System::Drawing::Point(453, 320);
			this->IncVol->Name = L"IncVol";
			this->IncVol->Size = System::Drawing::Size(40, 30);
			this->IncVol->TabIndex = 23;
			this->IncVol->Text = L"+";
			this->IncVol->UseVisualStyleBackColor = true;
			this->IncVol->Click += gcnew System::EventHandler(this, &Setting::VolInc);
			// 
			// DecVol
			// 
			this->DecVol->Location = System::Drawing::Point(301, 320);
			this->DecVol->Name = L"DecVol";
			this->DecVol->Size = System::Drawing::Size(40, 30);
			this->DecVol->TabIndex = 24;
			this->DecVol->Text = L"-";
			this->DecVol->UseVisualStyleBackColor = true;
			this->DecVol->Click += gcnew System::EventHandler(this, &Setting::VolDec);
			// 
			// sDecVol
			// 
			this->sDecVol->Location = System::Drawing::Point(255, 320);
			this->sDecVol->Name = L"sDecVol";
			this->sDecVol->Size = System::Drawing::Size(40, 30);
			this->sDecVol->TabIndex = 25;
			this->sDecVol->Text = L"--";
			this->sDecVol->UseVisualStyleBackColor = true;
			this->sDecVol->Click += gcnew System::EventHandler(this, &Setting::VolSDec);
			// 
			// sIncVol
			// 
			this->sIncVol->Location = System::Drawing::Point(500, 320);
			this->sIncVol->Name = L"sIncVol";
			this->sIncVol->Size = System::Drawing::Size(46, 30);
			this->sIncVol->TabIndex = 26;
			this->sIncVol->Text = L"++";
			this->sIncVol->UseVisualStyleBackColor = true;
			this->sIncVol->Click += gcnew System::EventHandler(this, &Setting::VolSInc);
			// 
			// Setting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->sIncVol);
			this->Controls->Add(this->sDecVol);
			this->Controls->Add(this->DecVol);
			this->Controls->Add(this->IncVol);
			this->Controls->Add(this->currVol);
			this->Controls->Add(this->currGame3);
			this->Controls->Add(this->currGame2);
			this->Controls->Add(this->currGame1);
			this->Controls->Add(this->currDashboard);
			this->Controls->Add(this->currLanding);
			this->Controls->Add(this->currBgImg);
			this->Controls->Add(this->game3Browse);
			this->Controls->Add(this->game2Browse);
			this->Controls->Add(this->game1Browse);
			this->Controls->Add(this->dashboardBrowse);
			this->Controls->Add(this->landingBrowse);
			this->Controls->Add(this->bgImgBrowse);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->applyBtn);
			this->Controls->Add(this->setVolume);
			this->Controls->Add(this->game3Music);
			this->Controls->Add(this->game2Music);
			this->Controls->Add(this->game1Music);
			this->Controls->Add(this->dashboardMusic);
			this->Controls->Add(this->landingMusic);
			this->Controls->Add(this->BgImg);
			this->Controls->Add(this->Title);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"Setting";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &Setting::OnLoad);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OnLoad(System::Object^ sender, System::EventArgs^ e) {
		this->settings = gcnew SettingManager();
		this->fileSetting = settings->getFile();
		LoadContent();
		this->volValue = Convert::ToInt32(this->currVol->Text);
	}
	private: System::Void LoadContent() {
		this->currSettings = browseManager::getSetting();
		array<String^>^ fileName = gcnew array<String^>(currSettings->Length);
		for (int i=0; i<currSettings->Length; i++) {
			fileName[i] = Path::GetFileName(currSettings[i]);
		}
		this->currBgImg->Text = fileName[0];
		this->currLanding->Text = fileName[1];
		this->currDashboard->Text = fileName[2];
		this->currGame1->Text = fileName[3];
		this->currGame2->Text = fileName[4];
		this->currGame3->Text = fileName[5];
		this->currVol->Text = fileName[6];
	}
	private: System::Void chooseImage(Object^ sender, EventArgs^ e) {
		this->currBgImg->Text = browseManager::getImage();
		this->currSettings[0] = browseManager::convertImgPath(this->currBgImg->Text);
	}
	private: System::Void chooseLanding(Object^ sender, EventArgs^ e){
		this->currLanding->Text = browseManager::getMusic();
		this->currSettings[1] = browseManager::convertMusicPath(this->currLanding->Text);
	}
	private: System::Void chooseDashboard(Object^ sender, EventArgs^ e) {
		this->currDashboard->Text = browseManager::getMusic();
		this->currSettings[2] = browseManager::convertMusicPath(this->currDashboard->Text);
	}
	private: System::Void chooseGame1(Object^ sender, EventArgs^ e) {
		this->currGame1->Text = browseManager::getMusic();
		this->currSettings[3] = browseManager::convertMusicPath(this->currGame1->Text);
	}
	private: System::Void chooseGame2(Object^ sender, EventArgs^ e) {
		this->currGame2->Text = browseManager::getMusic();
		this->currSettings[4] = browseManager::convertMusicPath(this->currGame2->Text);
	}
	private: System::Void chooseGame3(Object^ sender, EventArgs^ e) {
		this->currGame3->Text = browseManager::getMusic();
		this->currSettings[5] = browseManager::convertMusicPath(this->currGame3->Text);
	}
	private: System::Void VolInc(Object^ sender,EventArgs^ e){
		if (this->volValue + 1 <= 100) UpdateVol(++volValue);
	}
	private: System::Void VolDec(Object^ sender, EventArgs^ e) {
		if (this->volValue - 1 >= 0) UpdateVol(--volValue);
	}
	private: System::Void VolSInc(Object^ sender, EventArgs^ e) {
		if (this->volValue + 5 <= 100) {
			volValue += 5;
			UpdateVol(volValue);
		}
		else {
			volValue = 100;
			UpdateVol(volValue);
		}
	}
	private: System::Void VolSDec(Object^ sender, EventArgs^ e) {
		if (this->volValue - 5 >= 0) {
			volValue -= 5;
			UpdateVol(volValue);
		}
		else {
			volValue = 0;
			UpdateVol(volValue);
		}
	}
	private: System::Void UpdateVol(int volValue) {
		this->currVol->Text = volValue.ToString();
	}
	private: System::Void saveSetting(Object^ sender, EventArgs^ e) {
		browseManager::saveSetting(this->currSettings);
		this->ApplyEvent(this, e);
	}
	private: System::Void BackToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
};
}
