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
/// Summary for Game
/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	/*protected: System::Windows::Forms::Label^ Title;
	protected: System::Windows::Forms::Label^ Desc;
	protected: System::Windows::Forms::TextBox^ numberWord;
	protected: System::Windows::Forms::Button^ GameStart;
	protected: System::Windows::Forms::Button^ GameExit;
	protected: System::Windows::Forms::FlowLayoutPanel^ gameDomain;
	protected: System::Windows::Forms::FlowLayoutPanel^ gameAns;
	protected: cliext::vector<System::Windows::Forms::TextBox^> charBoxes;*/
	protected: System::Windows::Forms::Label^ Title;
	protected:

	protected:
	protected: System::Windows::Forms::Label^ GameRule;
	protected: System::Windows::Forms::Label^ HighestScore;
	protected: System::Windows::Forms::Label^ Rank;
	protected: System::Windows::Forms::TextBox^ ScoreContent;
	protected: System::Windows::Forms::TextBox^ RankContent;
	protected: System::Windows::Forms::Button^ GameStart;
	protected: System::Windows::Forms::Button^ GameExit;
	protected: System::Windows::Forms::Button^ showRule;
	protected: System::Windows::Forms::Label^ ansLabel;
	protected: System::Windows::Forms::Label^ usrAnsLabel;
	protected: System::Windows::Forms::FlowLayoutPanel^ GameAns;
	protected: System::Windows::Forms::FlowLayoutPanel^ GameDomain;
	protected: System::Windows::Forms::Label^ ScoreLabel;
	protected: System::Windows::Forms::TextBox^ Score;
	protected: System::Windows::Forms::TextBox^ Test;

	protected:

	protected: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->GameRule = (gcnew System::Windows::Forms::Label());
			this->HighestScore = (gcnew System::Windows::Forms::Label());
			this->Rank = (gcnew System::Windows::Forms::Label());
			this->ScoreContent = (gcnew System::Windows::Forms::TextBox());
			this->RankContent = (gcnew System::Windows::Forms::TextBox());
			this->GameStart = (gcnew System::Windows::Forms::Button());
			this->GameExit = (gcnew System::Windows::Forms::Button());
			this->showRule = (gcnew System::Windows::Forms::Button());
			this->ansLabel = (gcnew System::Windows::Forms::Label());
			this->usrAnsLabel = (gcnew System::Windows::Forms::Label());
			this->GameAns = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GameDomain = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ScoreLabel = (gcnew System::Windows::Forms::Label());
			this->Score = (gcnew System::Windows::Forms::TextBox());
			this->Test = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(298, 36);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(150, 46);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Game1";
			// 
			// GameRule
			// 
			this->GameRule->AutoSize = true;
			this->GameRule->BackColor = System::Drawing::Color::Transparent;
			this->GameRule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameRule->ForeColor = System::Drawing::Color::White;
			this->GameRule->Location = System::Drawing::Point(16, 253);
			this->GameRule->Name = L"GameRule";
			this->GameRule->Size = System::Drawing::Size(51, 25);
			this->GameRule->TabIndex = 1;
			this->GameRule->Text = L"Rule";
			// 
			// HighestScore
			// 
			this->HighestScore->AutoSize = true;
			this->HighestScore->BackColor = System::Drawing::Color::Transparent;
			this->HighestScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HighestScore->ForeColor = System::Drawing::Color::White;
			this->HighestScore->Location = System::Drawing::Point(21, 303);
			this->HighestScore->Name = L"HighestScore";
			this->HighestScore->Size = System::Drawing::Size(179, 29);
			this->HighestScore->TabIndex = 3;
			this->HighestScore->Text = L"Your highest score";
			this->HighestScore->UseCompatibleTextRendering = true;
			// 
			// Rank
			// 
			this->Rank->AutoSize = true;
			this->Rank->BackColor = System::Drawing::Color::Transparent;
			this->Rank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rank->ForeColor = System::Drawing::Color::White;
			this->Rank->Location = System::Drawing::Point(16, 353);
			this->Rank->Name = L"Rank";
			this->Rank->Size = System::Drawing::Size(103, 25);
			this->Rank->TabIndex = 5;
			this->Rank->Text = L"Your Rank";
			// 
			// ScoreContent
			// 
			this->ScoreContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScoreContent->Location = System::Drawing::Point(205, 308);
			this->ScoreContent->Name = L"ScoreContent";
			this->ScoreContent->ReadOnly = true;
			this->ScoreContent->Size = System::Drawing::Size(77, 30);
			this->ScoreContent->TabIndex = 4;
			this->ScoreContent->Text = L"99";
			this->ScoreContent->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// RankContent
			// 
			this->RankContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RankContent->Location = System::Drawing::Point(205, 365);
			this->RankContent->Name = L"RankContent";
			this->RankContent->ReadOnly = true;
			this->RankContent->Size = System::Drawing::Size(77, 30);
			this->RankContent->TabIndex = 6;
			this->RankContent->Text = L"1";
			this->RankContent->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// GameStart
			// 
			this->GameStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameStart->Location = System::Drawing::Point(558, 462);
			this->GameStart->Name = L"GameStart";
			this->GameStart->Size = System::Drawing::Size(80, 35);
			this->GameStart->TabIndex = 8;
			this->GameStart->Text = L"Start";
			this->GameStart->UseVisualStyleBackColor = true;
			this->GameStart->Click += gcnew System::EventHandler(this, &Game::Render);
			// 
			// GameExit
			// 
			this->GameExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameExit->Location = System::Drawing::Point(21, 36);
			this->GameExit->Name = L"GameExit";
			this->GameExit->Size = System::Drawing::Size(80, 35);
			this->GameExit->TabIndex = 7;
			this->GameExit->Text = L"Exit";
			this->GameExit->UseVisualStyleBackColor = true;
			this->GameExit->Click += gcnew System::EventHandler(this, &Game::Exit);
			// 
			// showRule
			// 
			this->showRule->Cursor = System::Windows::Forms::Cursors::Hand;
			this->showRule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showRule->Location = System::Drawing::Point(205, 255);
			this->showRule->Name = L"showRule";
			this->showRule->Size = System::Drawing::Size(80, 25);
			this->showRule->TabIndex = 9;
			this->showRule->Text = L"Show";
			this->showRule->UseVisualStyleBackColor = true;
			// 
			// ansLabel
			// 
			this->ansLabel->AutoSize = true;
			this->ansLabel->BackColor = System::Drawing::Color::Transparent;
			this->ansLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ansLabel->ForeColor = System::Drawing::Color::White;
			this->ansLabel->Location = System::Drawing::Point(333, 183);
			this->ansLabel->Name = L"ansLabel";
			this->ansLabel->Size = System::Drawing::Size(49, 20);
			this->ansLabel->TabIndex = 10;
			this->ansLabel->Text = L"Word";
			// 
			// usrAnsLabel
			// 
			this->usrAnsLabel->AutoSize = true;
			this->usrAnsLabel->BackColor = System::Drawing::Color::Transparent;
			this->usrAnsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usrAnsLabel->ForeColor = System::Drawing::Color::White;
			this->usrAnsLabel->Location = System::Drawing::Point(333, 257);
			this->usrAnsLabel->Name = L"usrAnsLabel";
			this->usrAnsLabel->Size = System::Drawing::Size(79, 20);
			this->usrAnsLabel->TabIndex = 11;
			this->usrAnsLabel->Text = L"User Ans";
			// 
			// GameAns
			// 
			this->GameAns->BackColor = System::Drawing::Color::Transparent;
			this->GameAns->Location = System::Drawing::Point(440, 174);
			this->GameAns->Name = L"GameAns";
			this->GameAns->Size = System::Drawing::Size(330, 40);
			this->GameAns->TabIndex = 12;
			// 
			// GameDomain
			// 
			this->GameDomain->BackColor = System::Drawing::Color::Transparent;
			this->GameDomain->ForeColor = System::Drawing::Color::Black;
			this->GameDomain->Location = System::Drawing::Point(440, 254);
			this->GameDomain->Name = L"GameDomain";
			this->GameDomain->Size = System::Drawing::Size(330, 40);
			this->GameDomain->TabIndex = 13;
			// 
			// ScoreLabel
			// 
			this->ScoreLabel->AutoSize = true;
			this->ScoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->ScoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScoreLabel->ForeColor = System::Drawing::Color::White;
			this->ScoreLabel->Location = System::Drawing::Point(333, 338);
			this->ScoreLabel->Name = L"ScoreLabel";
			this->ScoreLabel->Size = System::Drawing::Size(53, 20);
			this->ScoreLabel->TabIndex = 14;
			this->ScoreLabel->Text = L"Score";
			// 
			// Score
			// 
			this->Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Score->Location = System::Drawing::Point(440, 336);
			this->Score->Name = L"Score";
			this->Score->ReadOnly = true;
			this->Score->Size = System::Drawing::Size(100, 26);
			this->Score->TabIndex = 15;
			// 
			// Test
			// 
			this->Test->Location = System::Drawing::Point(439, 381);
			this->Test->Name = L"Test";
			this->Test->Size = System::Drawing::Size(287, 22);
			this->Test->TabIndex = 16;
			this->Test->TextChanged += gcnew System::EventHandler(this, &Game::UpdateScore);
			// 
			// Game1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			/*this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));*/
			this->BackgroundImage = gcnew System::Drawing::Bitmap("asset//img//bg1.jpg");
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->Test);
			this->Controls->Add(this->Score);
			this->Controls->Add(this->ScoreLabel);
			this->Controls->Add(this->GameDomain);
			this->Controls->Add(this->GameAns);
			this->Controls->Add(this->usrAnsLabel);
			this->Controls->Add(this->ansLabel);
			this->Controls->Add(this->showRule);
			this->Controls->Add(this->GameExit);
			this->Controls->Add(this->GameStart);
			this->Controls->Add(this->RankContent);
			this->Controls->Add(this->ScoreContent);
			this->Controls->Add(this->Rank);
			this->Controls->Add(this->HighestScore);
			this->Controls->Add(this->GameRule);
			this->Controls->Add(this->Title);
			this->Name = L"Game1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Game1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*public: virtual System::Void showRule() {};
	public: virtual System::Void gameGenerate() {};*/
	/*public: System::Void addTxtBox(System::Windows::Forms::FlowLayoutPanel^ container, int x, int y, System::String^ ch) {
		System::Windows::Forms::TextBox^ newBox = gcnew TextBox();
		newBox->Size = System::Drawing::Size(30, 30);
		newBox->Location = System::Drawing::Point(x, y);
		newBox->Text = ch;
		charBoxes.push_back(newBox);
		container->Controls->Add(newBox);
	}
	public: System::Void clearBox(System::Windows::Forms::FlowLayoutPanel^ container) {
		for each (System::Windows::Forms::TextBox ^ box in charBoxes) {
			container->Controls->Remove(box);
		}
	}*/
	protected: System::Void Render(System::Object^ sender, System::EventArgs^ e) {
		/*this->GameRule->Visible = false;
		this->RuleContent->Visible = false;
		this->HighestScore->Visible = false;
		this->ScoreContent->Visible = false;
		this->Rank->Visible = false;
		this->RankContent->Visible = false;*/
	}
	protected: System::Void Exit(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	protected: System::Void UpdateScore(System::Object^ sender, System::EventArgs^ e) {
		this->Score->Text = Test->Text->Length.ToString();
	}
};
}