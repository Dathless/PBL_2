#pragma once
#include "Game.h"
#include <cliext/vector>
#include "Account.h"
#include <fstream>
//#include <vector>
//#include <algorithm>

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
	/// Summary for Game1
	/// </summary>
	public ref class Game1 : public System::Windows::Forms::Form
	{
	private: cliext::vector<System::String^> wordList;
    /*public:
        String^ secretWord = "APPLE";
        String^ currentState = "_____";
        int score = 100;
        std::vector<std::pair<int, std::string>> highScores;*/
        /*Label^ displayWord;
        TextBox^ inputBox;
        Button^ guessButton;
        Label^ scoreLabel;
        Label^ highScoreLabel;
        Label^ highScoreHolderLabel;
        TextBox^ nameInputBox;*/
    
        /*Landing() {*/
	private: SoundPlayer^ bgMusic;
	public:	
		Game1(){
            /*LoadHighScores();*/
            InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
        }
    
    protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game1()
		{
			if (components)
			{
				delete components;
        }
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	protected:
	private: System::Windows::Forms::Label^ GameRule;
	private: System::Windows::Forms::Label^ HighestScore;
	private: System::Windows::Forms::Label^ Rank;
	private: System::Windows::Forms::TextBox^ ScoreContent;
	private: System::Windows::Forms::TextBox^ RankContent;
	private: System::Windows::Forms::Button^ GameStart;
	private: System::Windows::Forms::Button^ GameExit;
	private: System::Windows::Forms::Button^ showRule;
	private: System::Windows::Forms::Label^ ansLabel;
	private: System::Windows::Forms::Label^ usrAnsLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ GameAns;
	private: System::Windows::Forms::FlowLayoutPanel^ GameDomain;
	private: System::Windows::Forms::Label^ ScoreLabel;
	private: System::Windows::Forms::TextBox^ Score;
	private: System::Windows::Forms::TextBox^ Test;
    
    /*private:
        System::ComponentModel::Container^ components;*/

        /*void InitializeComponent() {
            this->displayWord = gcnew Label();
            this->inputBox = gcnew TextBox();
            this->guessButton = gcnew Button();
            this->scoreLabel = gcnew Label();
            this->highScoreLabel = gcnew Label();
            this->highScoreHolderLabel = gcnew Label();
            this->nameInputBox = gcnew TextBox();

            this->displayWord->Text = currentState;
            this->displayWord->Location = Point(50, 30);
            this->displayWord->Font = gcnew System::Drawing::Font("Arial", 16);
            this->displayWord->AutoSize = true;*/
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game1::typeid));
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

            // Title
            this->Title->AutoSize = true;
            this->Title->BackColor = System::Drawing::Color::Transparent;
            this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Title->ForeColor = System::Drawing::Color::White;
            this->Title->Location = System::Drawing::Point(298, 36);
            this->Title->Name = L"Title";
            this->Title->Size = System::Drawing::Size(150, 46);
            this->Title->TabIndex = 0;
            this->Title->Text = L"Game1";
            this->Title->Focus();

            // GameRule
            this->GameRule->AutoSize = true;
            this->GameRule->BackColor = System::Drawing::Color::Transparent;
            this->GameRule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->GameRule->ForeColor = System::Drawing::Color::White;
            this->GameRule->Location = System::Drawing::Point(16, 253);
            this->GameRule->Name = L"GameRule";
            this->GameRule->Size = System::Drawing::Size(51, 25);
            this->GameRule->TabIndex = 1;
            this->GameRule->Text = L"Rule";

            // HighestScore
            this->HighestScore->AutoSize = true;
            this->HighestScore->BackColor = System::Drawing::Color::Transparent;
            this->HighestScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->HighestScore->ForeColor = System::Drawing::Color::White;
            this->HighestScore->Location = System::Drawing::Point(21, 303);
            this->HighestScore->Name = L"HighestScore";
            this->HighestScore->Size = System::Drawing::Size(179, 29);
            this->HighestScore->TabIndex = 3;
            this->HighestScore->Text = L"Your highest score";
            this->HighestScore->UseCompatibleTextRendering = true;

            // Rank
            this->Rank->AutoSize = true;
            this->Rank->BackColor = System::Drawing::Color::Transparent;
            this->Rank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Rank->ForeColor = System::Drawing::Color::White;
            this->Rank->Location = System::Drawing::Point(16, 353);
            this->Rank->Name = L"Rank";
            this->Rank->Size = System::Drawing::Size(103, 25);
            this->Rank->TabIndex = 5;
            this->Rank->Text = L"Your Rank";

            // ScoreContent
            this->ScoreContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->ScoreContent->Location = System::Drawing::Point(205, 308);
            this->ScoreContent->Name = L"ScoreContent";
            this->ScoreContent->ReadOnly = true;
            this->ScoreContent->Size = System::Drawing::Size(77, 30);
            this->ScoreContent->TabIndex = 4;
            this->ScoreContent->Text = L"99";
            this->ScoreContent->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;

            // RankContent
            this->RankContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->RankContent->Location = System::Drawing::Point(205, 365);
            this->RankContent->Name = L"RankContent";
            this->RankContent->ReadOnly = true;
            this->RankContent->Size = System::Drawing::Size(77, 30);
            this->RankContent->TabIndex = 6;
            this->RankContent->Text = L"1";
            this->RankContent->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;

            // GameStart
            this->GameStart->Cursor = System::Windows::Forms::Cursors::Hand;
            this->GameStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->GameStart->Location = System::Drawing::Point(558, 462);
            this->GameStart->Name = L"GameStart";
            this->GameStart->Size = System::Drawing::Size(80, 35);
            this->GameStart->TabIndex = 8;
            this->GameStart->Text = L"Start";
            this->GameStart->UseVisualStyleBackColor = true;
            this->GameStart->Click += gcnew System::EventHandler(this, &Game1::Render);

            // GameExit
            this->GameExit->Cursor = System::Windows::Forms::Cursors::Hand;
            this->GameExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->GameExit->Location = System::Drawing::Point(21, 36);
            this->GameExit->Name = L"GameExit";
            this->GameExit->Size = System::Drawing::Size(80, 35);
            this->GameExit->TabIndex = 7;
            this->GameExit->Text = L"Exit";
            this->GameExit->UseVisualStyleBackColor = true;
            this->GameExit->Click += gcnew System::EventHandler(this, &Game1::Exit);

            // showRule
            this->showRule->Cursor = System::Windows::Forms::Cursors::Hand;
            this->showRule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->showRule->Location = System::Drawing::Point(205, 250);
            this->showRule->Name = L"showRule";
            this->showRule->Size = System::Drawing::Size(80, 35);
            this->showRule->TabIndex = 9;
            this->showRule->Text = L"Show";
            this->showRule->UseVisualStyleBackColor = true;
            this->showRule->Click += gcnew System::EventHandler(this, &Game1::ShowRules);

            // ansLabel
            this->ansLabel->AutoSize = true;
            this->ansLabel->BackColor = System::Drawing::Color::Transparent;
            this->ansLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->ansLabel->ForeColor = System::Drawing::Color::White;
            this->ansLabel->Location = System::Drawing::Point(333, 183);
            this->ansLabel->Name = L"ansLabel";
            this->ansLabel->Size = System::Drawing::Size(49, 20);
            this->ansLabel->TabIndex = 10;
            this->ansLabel->Text = L"Word";

            // usrAnsLabel
            this->usrAnsLabel->AutoSize = true;
            this->usrAnsLabel->BackColor = System::Drawing::Color::Transparent;
            this->usrAnsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->usrAnsLabel->ForeColor = System::Drawing::Color::White;
            this->usrAnsLabel->Location = System::Drawing::Point(333, 257);
            this->usrAnsLabel->Name = L"usrAnsLabel";
            this->usrAnsLabel->Size = System::Drawing::Size(79, 20);
            this->usrAnsLabel->TabIndex = 11;
            this->usrAnsLabel->Text = L"User Ans";

            // GameAns
            this->GameAns->BackColor = System::Drawing::Color::Transparent;
            this->GameAns->Location = System::Drawing::Point(440, 174);
            this->GameAns->Name = L"GameAns";
            this->GameAns->Size = System::Drawing::Size(330, 40);
            this->GameAns->TabIndex = 12;

            // GameDomain
            this->GameDomain->BackColor = System::Drawing::Color::Transparent;
            this->GameDomain->ForeColor = System::Drawing::Color::Black;
            this->GameDomain->Location = System::Drawing::Point(440, 254);
            this->GameDomain->Name = L"GameDomain";
            this->GameDomain->Size = System::Drawing::Size(330, 40);
            this->GameDomain->TabIndex = 13;

            // ScoreLabel
            this->ScoreLabel->AutoSize = true;
            this->ScoreLabel->BackColor = System::Drawing::Color::Transparent;
            this->ScoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->ScoreLabel->ForeColor = System::Drawing::Color::White;
            this->ScoreLabel->Location = System::Drawing::Point(333, 338);
            this->ScoreLabel->Name = L"ScoreLabel";
            this->ScoreLabel->Size = System::Drawing::Size(53, 20);
            this->ScoreLabel->TabIndex = 14;
            this->ScoreLabel->Text = L"Score";

            // Score
            this->Score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Score->Location = System::Drawing::Point(440, 336);
            this->Score->Name = L"Score";
            this->Score->ReadOnly = true;
            this->Score->Size = System::Drawing::Size(100, 26);
            this->Score->TabIndex = 15;

            // Test
            this->Test->Location = System::Drawing::Point(439, 381);
            this->Test->Name = L"Test";
            this->Test->Size = System::Drawing::Size(287, 22);
            this->Test->TabIndex = 16;
            this->Test->TextChanged += gcnew System::EventHandler(this, &Game1::UpdateScore);

            // Game1
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoScroll = true;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
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
            this->Text = L"Game1";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private: System::Void Render(System::Object^ sender, System::EventArgs^ e) {
        this->GameStart->Enabled = false;  // Disable "Start" button to prevent multiple starts
        this->Score->Text = "0";  // Reset score
        this->Test->Clear();  // Clear the input box
        FetchWord();  // Fetch a random word from the API (đảm bảo không mở cửa sổ mới)
    }


    private: System::Void Exit(System::Object^ sender, System::EventArgs^ e) {
        this->Close();  // Close the game window
    }

    private: System::Void ShowRules(System::Object^ sender, System::EventArgs^ e) {
        String^ rules = "1. A random word will be displayed.\n"
            "2. You need to guess the word by entering letters.\n"
            "3. Each correct letter will appear in the word.\n"
            "4. Incorrect guesses will reduce your score.\n"
            "5. The game ends when you guess the word.";
        MessageBox::Show(rules, "Game Rules"); // Hiển thị quy tắc ngay trên cửa sổ hiện tại
    }

           void FetchWord() {
               HttpClient^ client = gcnew HttpClient();
               String^ url = "https://api.datamuse.com/words?sp=?????&max=1"; // Example for 5-letter words
               try {
                   Task<String^>^ task = client->GetStringAsync(url);
                   task->Wait();
                   String^ response = task->Result;

                   if (!String::IsNullOrEmpty(response)) {
                       int start = response->IndexOf("\"word\":\"") + 8;
                       int end = response->IndexOf("\"", start);
                       String^ word = response->Substring(start, end - start);

                       // Gọi phương thức StartGameWithWord để bắt đầu trò chơi với từ ngẫu nhiên
                       this->StartGameWithWord(word);
                   }
                   else {
                       this->StartGameWithWord("Error fetching word");
                   }
               }
               catch (Exception^ ex) {
                   this->StartGameWithWord("API Error");
               }
           }


    private: System::Void StartGameWithWord(String^ word) {
        this->GameAns->Controls->Clear();  // Clear previous word

        // Display word as underscores
        for (int i = 0; i < word->Length; i++) {
            Label^ lbl = gcnew Label();
            lbl->Text = "_";
            lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            lbl->AutoSize = true;
            this->GameAns->Controls->Add(lbl);
        }

        this->secretWord = word;  // Store the word for comparison
        this->currentState = "_"; // Reset the current state
        this->Score->Text = "0";  // Reset score
        this->GameStart->Enabled = true;  // Re-enable start button
    }


    private: System::Void UpdateScore(System::Object^ sender, System::EventArgs^ e) {
        String^ userGuess = this->Test->Text->ToUpper();

        // Kiểm tra nếu người chơi đã nhập đủ độ dài của từ bí mật
        if (userGuess->Length == this->secretWord->Length) {
            bool correctGuess = false;
            String^ updatedState = this->currentState;

            // Kiểm tra nếu currentState và secretWord không phải là null hoặc rỗng
            if (String::IsNullOrEmpty(this->secretWord) || String::IsNullOrEmpty(this->currentState)) {
                MessageBox::Show("There was an error with the secret word or current status.");
                return;
            }

            // So sánh từng ký tự của người chơi với từ bí mật
            for (int i = 0; i < this->secretWord->Length; i++) {
                if (userGuess[i] == this->secretWord[i]) {
                    // Cập nhật trạng thái của từ
                    updatedState = updatedState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                    correctGuess = true;
                }
            }

            // Nếu có dự đoán đúng, cập nhật currentState
            if (correctGuess) {
                this->currentState = updatedState;

                // Cập nhật hiển thị với trạng thái mới
                for (int i = 0; i < this->secretWord->Length; i++) {
                    this->GameAns->Controls[i]->Text = this->currentState[i].ToString();
                }
            }

            // Kiểm tra nếu người chơi đã đoán đúng toàn bộ từ
            if (this->currentState == this->secretWord) {
                MessageBox::Show("Congratulations! You guessed the right word!"); // Hiển thị thông báo
                // Optional: Reset or re-enable game actions here
            }
        }
        else {
            // Nếu độ dài của từ người chơi nhập không khớp với từ bí mật
            MessageBox::Show("Please enter the correct number of letters.");
        }
    }



           private:
               String^ secretWord;   // Từ bí mật mà người chơi cần đoán
               String^ currentState; // Trạng thái hiện tại của từ (hiển thị dưới dạng gạch dưới)
	private: System::Void UpdateUI(System::String^ word) {
		this->Score->Text = word;
		this->GameStart->Enabled = true;
        }
	private: System::Void playMusic(System::String^ filesound) {
		this->bgMusic->Stop();
		this->bgMusic = gcnew SoundPlayer("asset\\sound\\" + filesound + ".wav");
		this->bgMusic->PlayLooping();
	}
    };
}
