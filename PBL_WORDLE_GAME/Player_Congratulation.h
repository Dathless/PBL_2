#pragma once
#include "User.h"
#include "SettingManager.h"
namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Player_Congratulation
	/// </summary>
	public ref class Player_Congratulation : public System::Windows::Forms::Form
	{
	private: User^ usr;
	private: String^ GameScore;
	private: SettingManager^ settings;
	private: AxWMPLib::AxWindowsMediaPlayer^ BGMusic;

	private: int Ranking;
	public:
		Player_Congratulation(User^ user, String^ score,int ranking)
		{
			InitializeComponent();
			this->usr = user;
			this->GameScore = score;
			this->Ranking = ranking;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Player_Congratulation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::Label^ usrName;
	private: System::Windows::Forms::Label^ score;
	private: System::Windows::Forms::Label^ highestScore;
	private: System::Windows::Forms::Label^ Rank;
	private: System::Windows::Forms::Button^ OKBtn;
	private: System::Windows::Forms::TextBox^ usrTxt;
	private: System::Windows::Forms::TextBox^ scoreTxt;
	private: System::Windows::Forms::TextBox^ hScoreTxt;
	private: System::Windows::Forms::TextBox^ rankTxt;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Player_Congratulation::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->usrName = (gcnew System::Windows::Forms::Label());
			this->score = (gcnew System::Windows::Forms::Label());
			this->highestScore = (gcnew System::Windows::Forms::Label());
			this->Rank = (gcnew System::Windows::Forms::Label());
			this->OKBtn = (gcnew System::Windows::Forms::Button());
			this->usrTxt = (gcnew System::Windows::Forms::TextBox());
			this->scoreTxt = (gcnew System::Windows::Forms::TextBox());
			this->hScoreTxt = (gcnew System::Windows::Forms::TextBox());
			this->rankTxt = (gcnew System::Windows::Forms::TextBox());
			this->BGMusic = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(148, 26);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(294, 36);
			this->Title->TabIndex = 0;
			this->Title->Text = L"CONGRATULATION";
			// 
			// usrName
			// 
			this->usrName->AutoSize = true;
			this->usrName->BackColor = System::Drawing::Color::Transparent;
			this->usrName->Location = System::Drawing::Point(165, 107);
			this->usrName->Name = L"usrName";
			this->usrName->Size = System::Drawing::Size(73, 25);
			this->usrName->TabIndex = 1;
			this->usrName->Text = L"Player:";
			this->usrName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// score
			// 
			this->score->AutoSize = true;
			this->score->BackColor = System::Drawing::Color::Transparent;
			this->score->Location = System::Drawing::Point(165, 152);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(70, 25);
			this->score->TabIndex = 2;
			this->score->Text = L"Score:";
			this->score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// highestScore
			// 
			this->highestScore->AutoSize = true;
			this->highestScore->BackColor = System::Drawing::Color::Transparent;
			this->highestScore->Location = System::Drawing::Point(165, 195);
			this->highestScore->Name = L"highestScore";
			this->highestScore->Size = System::Drawing::Size(141, 25);
			this->highestScore->TabIndex = 3;
			this->highestScore->Text = L"Highest Score:";
			// 
			// Rank
			// 
			this->Rank->AutoSize = true;
			this->Rank->BackColor = System::Drawing::Color::Transparent;
			this->Rank->Location = System::Drawing::Point(165, 241);
			this->Rank->Name = L"Rank";
			this->Rank->Size = System::Drawing::Size(63, 25);
			this->Rank->TabIndex = 4;
			this->Rank->Text = L"Rank:";
			// 
			// OKBtn
			// 
			this->OKBtn->ForeColor = System::Drawing::Color::Black;
			this->OKBtn->Location = System::Drawing::Point(266, 285);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(79, 36);
			this->OKBtn->TabIndex = 5;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &Player_Congratulation::Exit);
			// 
			// usrTxt
			// 
			this->usrTxt->Location = System::Drawing::Point(321, 109);
			this->usrTxt->Name = L"usrTxt";
			this->usrTxt->Size = System::Drawing::Size(121, 30);
			this->usrTxt->TabIndex = 6;
			this->usrTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// scoreTxt
			// 
			this->scoreTxt->Location = System::Drawing::Point(321, 152);
			this->scoreTxt->Name = L"scoreTxt";
			this->scoreTxt->Size = System::Drawing::Size(121, 30);
			this->scoreTxt->TabIndex = 7;
			this->scoreTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// hScoreTxt
			// 
			this->hScoreTxt->Location = System::Drawing::Point(321, 192);
			this->hScoreTxt->Name = L"hScoreTxt";
			this->hScoreTxt->Size = System::Drawing::Size(121, 30);
			this->hScoreTxt->TabIndex = 8;
			this->hScoreTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// rankTxt
			// 
			this->rankTxt->Location = System::Drawing::Point(321, 238);
			this->rankTxt->Name = L"rankTxt";
			this->rankTxt->Size = System::Drawing::Size(121, 30);
			this->rankTxt->TabIndex = 9;
			this->rankTxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// BGMusic
			// 
			this->BGMusic->Enabled = true;
			this->BGMusic->Location = System::Drawing::Point(0, 0);
			this->BGMusic->Name = L"BGMusic";
			this->BGMusic->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"BGMusic.OcxState")));
			this->BGMusic->Size = System::Drawing::Size(75, 23);
			this->BGMusic->TabIndex = 0;
			this->BGMusic->Visible = false;
			// 
			// Player_Congratulation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(620, 330);
			this->Controls->Add(this->BGMusic);
			this->Controls->Add(this->rankTxt);
			this->Controls->Add(this->hScoreTxt);
			this->Controls->Add(this->scoreTxt);
			this->Controls->Add(this->usrTxt);
			this->Controls->Add(this->OKBtn);
			this->Controls->Add(this->Rank);
			this->Controls->Add(this->highestScore);
			this->Controls->Add(this->score);
			this->Controls->Add(this->usrName);
			this->Controls->Add(this->Title);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Player_Congratulation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Player_Congratulation";
			this->Load += gcnew System::EventHandler(this, &Player_Congratulation::onLoad);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Player_Congratulation::ExitPerform);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void onLoad(System::Object^ sender, System::EventArgs^ e) {
			this->usrTxt->Text = usr->username;
			this->scoreTxt->Text = GameScore;
			this->hScoreTxt->Text = usr->getS2().ToString();
			this->rankTxt->Text = this->Ranking.ToString();
			this->settings = gcnew SettingManager();
			this->settings->Congrat_Sound(BGMusic);
		}
		private: System::Void Exit(System::Object^ sender, System::EventArgs^ e) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->settings->StopAxWMP(BGMusic);
			this->Close();
		}
	private: System::Void ExitPerform(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			e->SuppressKeyPress;
			Exit(sender, e);
		}
	}
	};
}
