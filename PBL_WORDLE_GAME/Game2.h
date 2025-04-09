#pragma once
#include <cliext/vector>
#include <random>

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
	public ref class Game2 : public System::Windows::Forms::Form
	{
	private: Timer^ sidebarTimer;
	private: bool isHidden = false;
	private: System::Windows::Forms::TextBox^ APIContent;
	private: cliext::vector<System::String^> wordList;
	private: SoundPlayer^ bgMusic;														
	public:
		Game2(void)
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
			this->APIContent = (gcnew System::Windows::Forms::TextBox());
			this->SideBar->SuspendLayout();
			this->SuspendLayout();
			// 
			// GameExit
			// 
			this->GameExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameExit->Location = System::Drawing::Point(12, 22);
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
			this->GameStart->Location = System::Drawing::Point(607, 471);
			this->GameStart->Name = L"GameStart";
			this->GameStart->Size = System::Drawing::Size(96, 32);
			this->GameStart->TabIndex = 1;
			this->GameStart->Text = L"Start";
			this->GameStart->UseVisualStyleBackColor = true;
			this->GameStart->Click += gcnew System::EventHandler(this, &Game2::Render);
			// 
			// SideBar
			// 
			this->SideBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(236)));
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
			this->Rank->Location = System::Drawing::Point(39, 30);
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
			this->HighestScore->Location = System::Drawing::Point(0, 95);
			this->HighestScore->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->HighestScore->Name = L"HighestScore";
			this->HighestScore->Size = System::Drawing::Size(135, 25);
			this->HighestScore->TabIndex = 4;
			this->HighestScore->Text = L"Highest Score";
			// 
			// showRule
			// 
			this->showRule->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->showRule->ForeColor = System::Drawing::Color::Black;
			this->showRule->Location = System::Drawing::Point(20, 160);
			this->showRule->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
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
			this->toggleSidebar->Location = System::Drawing::Point(40, 125);
			this->toggleSidebar->Name = L"toggleSidebar";
			this->toggleSidebar->Size = System::Drawing::Size(96, 30);
			this->toggleSidebar->TabIndex = 3;
			this->toggleSidebar->Text = L"SideBar";
			this->toggleSidebar->UseVisualStyleBackColor = true;
			this->toggleSidebar->Click += gcnew System::EventHandler(this, &Game2::ToggleSidebar);
			// 
			// APIContent
			// 
			this->APIContent->Location = System::Drawing::Point(364, 149);
			this->APIContent->Multiline = true;
			this->APIContent->Name = L"APIContent";
			this->APIContent->Size = System::Drawing::Size(357, 297);
			this->APIContent->TabIndex = 4;
			// 
			// Game2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->APIContent);
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
		playMusic("continue");
	}
	private: System::Void playMusic(System::String^ filesound) {
		this->bgMusic->Stop();
		this->bgMusic = gcnew SoundPlayer("asset\\sound\\" + filesound + ".wav");
		this->bgMusic->PlayLooping();
	}
	private: System::Void ToggleSidebar(System::Object^ sender, System::EventArgs^ e) {
		this->sidebarTimer->Start();
	}
	/*private: System::Void AnimateSidebar(System::Object^ sender, System::EventArgs^ e) {
		if (isHidden) {
			this->SideBar->Left += 10;
			if (SideBar->Left >= 0) {
				SideBar->Left = 0;
				sidebarTimer->Stop();
				isHidden = false;
			}
		}
		else {
			SideBar->Left -= 10;
			if (SideBar->Left <= -SideBar->Width) {
				SideBar->Left = -SideBar->Width;
				sidebarTimer->Stop();
				isHidden = true;
			}
		}

	}*/
	private: System::Void Exit(System::Object^ sender, System::EventArgs^ e) {
		this->bgMusic->Stop();
		this->Close();
	}
	private: System::Void Render(System::Object^ sender, System::EventArgs^ e) {
		Task::Run(gcnew Action(this, &Game2::FetchWord));
	}
	private: System::Void FetchWord() {
		try {
			String^ url = "https://api.datamuse.com/words?sp=?????&max=10";
			WebClient^ client = gcnew WebClient();
			String^ response = client->DownloadString(url);
			array<String^>^ words = response->Split('"');
			this->wordList.clear();
			String^ res = "";
			for (int i = 0; i < words->Length; i++) {
				if (words[i]->Length == 5) { // Only valid 5-letter words
					/*this->wordList.push_back(words[i]);*/
					res += words[i] + " ";
				}
			}
			/*String^ selectedWord = "";
			if (!this->wordList.empty()) {
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(0, this->wordList.size() - 1);
				int randomIndex = dis(gen);
				selectedWord = this->wordList[randomIndex];
			}*/
			this->Invoke(gcnew Action<String^>(this, &Game2::UpdateUI), res);

		}
		catch (Exception^ ex) {
			MessageBox::Show("Error fetching words: " + ex->Message);
		}
	}
	private: System::Void UpdateUI(String^ word) {
		this->APIContent->Text = word;
	}
};
}
