#pragma once
#include <cliext/vector>
#include "Game2_Char.h"
#include "Game.h"
#include <random>
#include "User.h"
#include "CryptoUtils.h"
#include "Player_Congratulation.h"

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Text::Json;
	using namespace System::Collections::Generic;
	using namespace System::Net::Http;
	using namespace System::Threading::Tasks;
	using namespace System::IO;
	using namespace System::Media;

	/// <summary>
	/// Summary for Game2
	/// </summary>
	public ref class Game2 : public Game
	{
	private: System::String^ username;
	private: Timer^ sidebarTimer;
	private: Timer^ gameTimer;
	private: bool isHidden = false;
	private: System::Windows::Forms::TextBox^ UserAns;
	private: cliext::vector<System::String^> wordList;
	private: Dictionary<String^, int>^ getWord = gcnew Dictionary<String^, int>();
	private: int n;
	private: int remainingTime;
	private: int score;
	private: System::Windows::Forms::Label^ AnsLabel;
	private: System::Windows::Forms::Label^ ScoreLabel;
	private: System::Windows::Forms::TextBox^ Score;
	private: System::Windows::Forms::Label^ errMes;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ GameState;
	private: System::Windows::Forms::Label^ countDown;
	private: SoundPlayer^ bgMusic;
	public:
		Game2(String^ uname)
		{
			InitializeComponent();
			this->username = uname;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ GameExit;
	private: System::Windows::Forms::Button^ GameStart;
	private: System::Windows::Forms::FlowLayoutPanel^ SideBar;

	private: System::Windows::Forms::Label^ Rank;
	private: System::Windows::Forms::Button^ showRule;


	private: System::Windows::Forms::Button^ toggleSidebar;
	private: System::Windows::Forms::Label^ HighestScore;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game2::typeid));
			this->GameExit = (gcnew System::Windows::Forms::Button());
			this->GameStart = (gcnew System::Windows::Forms::Button());
			this->SideBar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Rank = (gcnew System::Windows::Forms::Label());
			this->HighestScore = (gcnew System::Windows::Forms::Label());
			this->showRule = (gcnew System::Windows::Forms::Button());
			this->toggleSidebar = (gcnew System::Windows::Forms::Button());
			this->UserAns = (gcnew System::Windows::Forms::TextBox());
			this->AnsLabel = (gcnew System::Windows::Forms::Label());
			this->ScoreLabel = (gcnew System::Windows::Forms::Label());
			this->Score = (gcnew System::Windows::Forms::TextBox());
			this->errMes = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->GameState = (gcnew System::Windows::Forms::Label());
			this->countDown = (gcnew System::Windows::Forms::Label());
			this->SideBar->SuspendLayout();
			this->SuspendLayout();
			// 
			// GameExit
			// 
			this->GameExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameExit->Location = System::Drawing::Point(16, 34);
			this->GameExit->Name = L"GameExit";
			this->GameExit->Size = System::Drawing::Size(92, 32);
			this->GameExit->TabIndex = 0;
			this->GameExit->Text = L"Exit";
			this->GameExit->UseVisualStyleBackColor = true;
			this->GameExit->Click += gcnew System::EventHandler(this, &Game2::Exit);
			// 
			// GameStart
			// 
			this->GameStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameStart->Location = System::Drawing::Point(632, 471);
			this->GameStart->Name = L"GameStart";
			this->GameStart->Size = System::Drawing::Size(96, 32);
			this->GameStart->TabIndex = 1;
			this->GameStart->Text = L"Start";
			this->GameStart->UseVisualStyleBackColor = true;
			this->GameStart->Click += gcnew System::EventHandler(this, &Game2::Render);
			// 
			// SideBar
			// 
			this->SideBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->SideBar->Controls->Add(this->Rank);
			this->SideBar->Controls->Add(this->HighestScore);
			this->SideBar->Controls->Add(this->showRule);
			this->SideBar->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->SideBar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SideBar->ForeColor = System::Drawing::Color::White;
			this->SideBar->Location = System::Drawing::Point(1, 149);
			this->SideBar->Name = L"SideBar";
			this->SideBar->Size = System::Drawing::Size(183, 401);
			this->SideBar->TabIndex = 2;
			// 
			// Rank
			// 
			this->Rank->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Rank->AutoSize = true;
			this->Rank->BackColor = System::Drawing::Color::Transparent;
			this->Rank->Location = System::Drawing::Point(44, 30);
			this->Rank->Margin = System::Windows::Forms::Padding(0, 30, 0, 20);
			this->Rank->Name = L"Rank";
			this->Rank->Size = System::Drawing::Size(57, 25);
			this->Rank->TabIndex = 3;
			this->Rank->Text = L"Rank";
			// 
			// HighestScore
			// 
			this->HighestScore->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->HighestScore->AutoSize = true;
			this->HighestScore->BackColor = System::Drawing::Color::Transparent;
			this->HighestScore->Location = System::Drawing::Point(10, 95);
			this->HighestScore->Margin = System::Windows::Forms::Padding(10, 20, 0, 20);
			this->HighestScore->Name = L"HighestScore";
			this->HighestScore->Size = System::Drawing::Size(135, 25);
			this->HighestScore->TabIndex = 4;
			this->HighestScore->Text = L"Highest Score";
			// 
			// showRule
			// 
			this->showRule->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->showRule->ForeColor = System::Drawing::Color::Black;
			this->showRule->Location = System::Drawing::Point(35, 160);
			this->showRule->Margin = System::Windows::Forms::Padding(20, 20, 0, 20);
			this->showRule->Name = L"showRule";
			this->showRule->Size = System::Drawing::Size(94, 36);
			this->showRule->TabIndex = 3;
			this->showRule->Text = L"Rule";
			this->showRule->UseVisualStyleBackColor = true;
			// 
			// toggleSidebar
			// 
			this->toggleSidebar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toggleSidebar->Location = System::Drawing::Point(181, 216);
			this->toggleSidebar->Name = L"toggleSidebar";
			this->toggleSidebar->Size = System::Drawing::Size(53, 36);
			this->toggleSidebar->TabIndex = 3;
			this->toggleSidebar->Text = L"<<";
			this->toggleSidebar->UseVisualStyleBackColor = true;
			this->toggleSidebar->Click += gcnew System::EventHandler(this, &Game2::ToggleSidebar);
			// 
			// UserAns
			// 
			this->UserAns->Enabled = false;
			this->UserAns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserAns->Location = System::Drawing::Point(438, 303);
			this->UserAns->Name = L"UserAns";
			this->UserAns->Size = System::Drawing::Size(290, 38);
			this->UserAns->TabIndex = 4;
			this->UserAns->Enter += gcnew System::EventHandler(this, &Game2::UserAnsEnter);
			this->UserAns->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game2::CheckWord);
			this->UserAns->Leave += gcnew System::EventHandler(this, &Game2::UserAnsLeave);
			// 
			// AnsLabel
			// 
			this->AnsLabel->AutoSize = true;
			this->AnsLabel->BackColor = System::Drawing::Color::Transparent;
			this->AnsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AnsLabel->ForeColor = System::Drawing::Color::White;
			this->AnsLabel->Location = System::Drawing::Point(296, 309);
			this->AnsLabel->Name = L"AnsLabel";
			this->AnsLabel->Size = System::Drawing::Size(106, 25);
			this->AnsLabel->TabIndex = 7;
			this->AnsLabel->Text = L"Your Word";
			// 
			// ScoreLabel
			// 
			this->ScoreLabel->AutoSize = true;
			this->ScoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->ScoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScoreLabel->ForeColor = System::Drawing::Color::White;
			this->ScoreLabel->Location = System::Drawing::Point(296, 383);
			this->ScoreLabel->Name = L"ScoreLabel";
			this->ScoreLabel->Size = System::Drawing::Size(106, 25);
			this->ScoreLabel->TabIndex = 8;
			this->ScoreLabel->Text = L"Your score";
			// 
			// Score
			// 
			this->Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Score->Location = System::Drawing::Point(559, 384);
			this->Score->Name = L"Score";
			this->Score->ReadOnly = true;
			this->Score->Size = System::Drawing::Size(169, 38);
			this->Score->TabIndex = 9;
			this->Score->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// errMes
			// 
			this->errMes->AutoSize = true;
			this->errMes->BackColor = System::Drawing::Color::Transparent;
			this->errMes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->errMes->ForeColor = System::Drawing::Color::White;
			this->errMes->Location = System::Drawing::Point(386, 354);
			this->errMes->Name = L"errMes";
			this->errMes->Size = System::Drawing::Size(0, 25);
			this->errMes->TabIndex = 10;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(272, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(230, 63);
			this->Title->TabIndex = 11;
			this->Title->Text = L"GAME 2";
			// 
			// GameState
			// 
			this->GameState->AutoSize = true;
			this->GameState->BackColor = System::Drawing::Color::Transparent;
			this->GameState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameState->ForeColor = System::Drawing::Color::White;
			this->GameState->Location = System::Drawing::Point(318, 116);
			this->GameState->Name = L"GameState";
			this->GameState->Size = System::Drawing::Size(0, 25);
			this->GameState->TabIndex = 12;
			// 
			// countDown
			// 
			this->countDown->AutoSize = true;
			this->countDown->BackColor = System::Drawing::Color::Transparent;
			this->countDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countDown->ForeColor = System::Drawing::Color::White;
			this->countDown->Location = System::Drawing::Point(431, 216);
			this->countDown->Name = L"countDown";
			this->countDown->Size = System::Drawing::Size(102, 39);
			this->countDown->TabIndex = 13;
			this->countDown->Text = L"Time:";
			// 
			// Game2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->countDown);
			this->Controls->Add(this->GameState);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->errMes);
			this->Controls->Add(this->Score);
			this->Controls->Add(this->ScoreLabel);
			this->Controls->Add(this->AnsLabel);
			this->Controls->Add(this->UserAns);
			this->Controls->Add(this->toggleSidebar);
			this->Controls->Add(this->SideBar);
			this->Controls->Add(this->GameStart);
			this->Controls->Add(this->GameExit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Game2";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Game2";
			this->Load += gcnew System::EventHandler(this, &Game2::GameLoading);
			this->SideBar->ResumeLayout(false);
			this->SideBar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GameLoading(System::Object^ sender, System::EventArgs^ e) {
		userLoading(this->username);
		this->HighestScore->Text = "Highest Score: " + this->UserLogged->getS2();
		this->UserAns->Text = "Enter your word!";
		this->UserAns->ForeColor = System::Drawing::Color::Gray;
		loadAllUser(2);
		this->Rank->Text = "Rank: " + getRank(UserLogged->username);
		this->Score->Text = "0";
		this->gameTimer = gcnew Timer();
		this->gameTimer->Interval = 1000; // 1 second
		this->gameTimer->Tick += gcnew System::EventHandler(this, &Game2::GameRunning);
		this->sidebarTimer = gcnew Timer();
		this->sidebarTimer->Interval = 5;
		this->sidebarTimer->Tick += gcnew System::EventHandler(this, &Game2::AnimateSidebar);
		playMusic("continue");
	}
	private: System::Void playMusic(System::String^ filesound) {
		this->bgMusic->Stop();
		this->bgMusic = gcnew SoundPlayer("asset\\sound\\" + filesound + ".wav");
		this->bgMusic->PlayLooping();
	}
	private: System::Void ToggleSidebar(System::Object^ sender, System::EventArgs^ e) {
		(this->toggleSidebar->Text == "<<") ? this->toggleSidebar->Text = ">>" : this->toggleSidebar->Text = "<<";
		this->sidebarTimer->Start();
	}
	private: System::Void AnimateSidebar(System::Object^ sender, System::EventArgs^ e) {
		if (isHidden) {
			this->SideBar->Left += 10;
			this->toggleSidebar->Left += 10;
			if (SideBar->Left >= 0) {
				SideBar->Left = 0;
				sidebarTimer->Stop();
				isHidden = false;
			}
		}
		else {
			this->SideBar->Left -= 10;
			this->toggleSidebar->Left -= 10;
			if (SideBar->Left <= -SideBar->Width) {
				SideBar->Left = -SideBar->Width;
				sidebarTimer->Stop();
				isHidden = true;
			}
		}
	}
	protected: System::Void Exit(System::Object^ sender, System::EventArgs^ e) override {
		this->bgMusic->Stop();
		this->Close();
	}
	protected: System::Void Render(System::Object^ sender, System::EventArgs^ e) override {
		this->GameState->Text = "";
		this->score = 0;
		this->Score->Text = this->score.ToString();
		Game2_Char^ popup = gcnew Game2_Char();
		if (popup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->n = Int32::Parse(popup->NumberChar);
			this->UserAns->Enabled = true;
			this->GameStart->Enabled = false;
			FetchWord();
			this->remainingTime = 10;
			this->gameTimer->Start();
		}
	}
	private: System::Void GameRunning(System::Object^ sender, System::EventArgs^ e) {
		this->remainingTime--;
		this->countDown->Text = "Time: " + this->remainingTime + " s";
		if (this->remainingTime <= 0) {
			this->gameTimer->Stop();
			this->UserAns->Enabled = false;
			this->GameStart->Enabled = true;
			this->GameState->Text = "Game Over!";
			MessageBox::Show("Time's up!","Notification",MessageBoxButtons::OK,MessageBoxIcon::Information);
			this->errMes->Text = "";
			this->getWord->Clear();
			if (this->UserLogged->getS2() < this->score) {
				this->UserLogged->setS2(this->score);
				scoreUpdating(this->score);
			}
			userSaving(this->UserLogged);
			String^ currentScore = this->Score->Text;
			int ranking = getRank(this->username);
			Player_Congratulation^ player_congrat = gcnew Player_Congratulation(UserLogged, currentScore, ranking);
			player_congrat->ShowDialog();

		}
	}
	private: System::Void FetchWord() {
		this->GameState->Text = "Loading";
		try {
			String^ url = "https://api.datamuse.com/words?sp=" + getSizeOfWord(n) + "&max=10000";
			WebClient^ client = gcnew WebClient();
			String^ response = client->DownloadString(url);
			array<String^>^ words = response->Split('"');
			this->wordList.clear();
			String^ res = "";
			for (int i = 0; i < words->Length; i++) {
				if (words[i]->Length == n) { 
					if (!this->getWord->ContainsKey(words[i])) {
						this->getWord->Add(words[i], 0);
					}
				}
			}
			this->Invoke(gcnew Action<String^>(this, &Game2::LoadState),"Ready");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error fetching words: " + ex->Message);
			this->GameState->Text = "Error";
		}
	}
	private: System::Void CheckWord(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			e->SuppressKeyPress = true;
			String^ ans = this->UserAns->Text;
			int entered;
			if (ans == "" || ans->Length != n) {
				this->errMes->Text = "";
				this->errMes->Text = "The word is invalid!";
				this->errMes->ForeColor = System::Drawing::Color::Red;
				this->UserAns->Text = "";
				this->UserAns->Focus();
			}
			else {
				if (this->getWord->TryGetValue(ans, entered)) {
					if (entered == 0){
						this->getWord[ans] = 1;
						this->score += 10;
						this->Score->Text = score.ToString();
						this->errMes->Text = "";
						this->errMes->Text = "Correct!";
						this->errMes->ForeColor = System::Drawing::Color::Green;
						this->UserAns->Text = "";
						this->UserAns->Focus();
					}
					else {
						this->UserAns->Text = "";
						this->UserAns->Focus();
						this->errMes->Text = "";
						this->errMes->Text = "You have already entered this word!";
					}
				}
				else {
					this->errMes->Text = "";
					this->errMes->Text = "The word is not correct!";
					this->errMes->ForeColor = System::Drawing::Color::Red;
					this->UserAns->Text = "";
				}
			}
		}
	}
	private: System::Void UserAnsEnter(System::Object^ sender, System::EventArgs^ e) {
		if (this->UserAns->Text == "Enter your word!") {
			this->UserAns->Text = "";
			this->UserAns->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void UserAnsLeave(System::Object^ sender, System::EventArgs^ e) {
		if (this->UserAns->Text == "") {
			this->UserAns->Text = "Enter your word!";
			this->UserAns->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::String^ getSizeOfWord(int num) {
		String^ ans = "";
		for (int i = 0; i < num; i++) {
			ans += "?";
		}
		return ans;
	}
	private: System::Void LoadState(String^ state) {
		this->GameState->Text = state;
		this->UserAns->Focus();
	}
	public: System::Void scoreUpdating(int s) override {
		this->UserLogged->setS2(s);
		this->HighestScore->Text = "Highest Score: " + this->UserLogged->getS2();
	}
	
};
}
