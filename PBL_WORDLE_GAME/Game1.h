#pragma once
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Net.Http.dll>
#using <System.Threading.Tasks.dll>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;

#include "SettingManager.h"
#include <cliext/vector>
#include "Game.h"
#include <random>
#include "User.h"
#include "CryptoUtils.h"


namespace PBLWORDLEGAME {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Net::Http;
    using namespace System::Threading::Tasks;

    public ref class Game1 : public System::Windows::Forms::Form
    {
    private:
        String^ uname;
        SettingManager^ settings;
        int remainingTime;
        String^ secretWord;
        String^ currentState;

    private:
        System::ComponentModel::IContainer^ components;
        System::Windows::Forms::Button^ GameStart;
        System::Windows::Forms::TextBox^ Test;
        System::Windows::Forms::Label^ Score;
        System::Windows::Forms::Panel^ GameAns;
        System::Windows::Forms::Button^ Exit;
        System::Windows::Forms::Button^ RulesButton;
        System::Windows::Forms::Timer^ countdownTimer;
        System::Windows::Forms::Label^ countdownLabel;
        System::Windows::Forms::Button^ SubmitGuessButton;
        AxWMPLib::AxWindowsMediaPlayer^ BGMusic;

    public:
        Game1(String^ usr)
        {
            InitializeComponent();
            uname = usr;
        }

    protected:
        ~Game1()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        void InitializeComponent(void)
        {

            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game1::typeid));
            this->GameStart = (gcnew System::Windows::Forms::Button());
            this->Test = (gcnew System::Windows::Forms::TextBox());
            this->Score = (gcnew System::Windows::Forms::Label());
            this->GameAns = (gcnew System::Windows::Forms::Panel());
            this->Exit = (gcnew System::Windows::Forms::Button());
            this->RulesButton = (gcnew System::Windows::Forms::Button());
            this->countdownTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->countdownLabel = (gcnew System::Windows::Forms::Label());
            this->SubmitGuessButton = (gcnew System::Windows::Forms::Button());
            this->BGMusic = (gcnew AxWMPLib::AxWindowsMediaPlayer());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->BeginInit();
            this->SuspendLayout();
            // 
            // GameStart
            // 
            this->GameStart->ForeColor = System::Drawing::Color::Coral;
            this->GameStart->Location = System::Drawing::Point(223, 91);
            this->GameStart->Name = L"GameStart";
            this->GameStart->Size = System::Drawing::Size(100, 30);
            this->GameStart->TabIndex = 0;
            this->GameStart->Text = L"Start Game";
            this->GameStart->Click += gcnew System::EventHandler(this, &Game1::Render);
            // 
            // Test
            // 
            this->Test->Location = System::Drawing::Point(223, 219);
            this->Test->Name = L"Test";
            this->Test->Size = System::Drawing::Size(100, 20);
            this->Test->TabIndex = 1;
            // 
            // Score
            // 
            this->Score->Location = System::Drawing::Point(100, 50);
            this->Score->Name = L"Score";
            this->Score->Size = System::Drawing::Size(100, 30);
            this->Score->TabIndex = 2;
            // 
            // GameAns
            // 
            this->GameAns->Location = System::Drawing::Point(175, 142);
            this->GameAns->Name = L"GameAns";
            this->GameAns->Size = System::Drawing::Size(200, 50);
            this->GameAns->TabIndex = 3;
            // 
            // Exit
            // 
            this->Exit->BackColor = System::Drawing::Color::Crimson;
            this->Exit->Location = System::Drawing::Point(223, 363);
            this->Exit->Name = L"Exit";
            this->Exit->Size = System::Drawing::Size(100, 30);
            this->Exit->TabIndex = 4;
            this->Exit->Text = L"Exit";
            this->Exit->UseVisualStyleBackColor = false;
            this->Exit->Click += gcnew System::EventHandler(this, &Game1::Exit_Click);
            // 
            // RulesButton
            // 
            this->RulesButton->ForeColor = System::Drawing::Color::Coral;
            this->RulesButton->Location = System::Drawing::Point(223, 311);
            this->RulesButton->Name = L"RulesButton";
            this->RulesButton->Size = System::Drawing::Size(100, 30);
            this->RulesButton->TabIndex = 5;
            this->RulesButton->Text = L"Game Rules";
            this->RulesButton->Click += gcnew System::EventHandler(this, &Game1::ShowRules);
            // 
            // countdownTimer
            // 
            this->countdownTimer->Interval = 1000;
            this->countdownTimer->Tick += gcnew System::EventHandler(this, &Game1::OnCountdownTick);
            // 
            // countdownLabel
            // 
            this->countdownLabel->Location = System::Drawing::Point(10, 10);
            this->countdownLabel->Name = L"countdownLabel";
            this->countdownLabel->Size = System::Drawing::Size(100, 30);
            this->countdownLabel->TabIndex = 7;
            // 
            // SubmitGuessButton
            // 
            this->SubmitGuessButton->ForeColor = System::Drawing::Color::Coral;
            this->SubmitGuessButton->Location = System::Drawing::Point(223, 259);
            this->SubmitGuessButton->Name = L"SubmitGuessButton";
            this->SubmitGuessButton->Size = System::Drawing::Size(100, 30);
            this->SubmitGuessButton->TabIndex = 6;
            this->SubmitGuessButton->Text = L"Submit Guess";
            this->SubmitGuessButton->Click += gcnew System::EventHandler(this, &Game1::SubmitGuess_Click);
            // 
            // BGMusic
            // 
            this->BGMusic->Enabled = true;
            this->BGMusic->Location = System::Drawing::Point(518, 0);
            this->BGMusic->Name = L"BGMusic";
            this->BGMusic->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"BGMusic.OcxState")));
            this->BGMusic->Size = System::Drawing::Size(75, 23);
            this->BGMusic->TabIndex = 8;
            this->BGMusic->Visible = false;
            // 
            // Game1
            // 
            this->BackColor = System::Drawing::Color::Cornsilk;
            this->ClientSize = System::Drawing::Size(594, 487);
            this->Controls->Add(this->BGMusic);
            this->Controls->Add(this->GameStart);
            this->Controls->Add(this->Test);
            this->Controls->Add(this->Score);
            this->Controls->Add(this->GameAns);
            this->Controls->Add(this->Exit);
            this->Controls->Add(this->RulesButton);
            this->Controls->Add(this->SubmitGuessButton);
            this->Controls->Add(this->countdownLabel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Game1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Load += gcnew System::EventHandler(this, &Game1::OnLoad);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        void OnLoad(Object^ sender, EventArgs^ e)
        {
            this->settings = gcnew SettingManager();
            this->settings->Game1_Music(BGMusic); // Load background music
        }

        void Exit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->settings->StopAxWMP(BGMusic); // Stop music when exiting
            this->Close(); // Close the form
        }

        void SubmitGuess_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ userGuess = this->Test->Text->ToUpper();

            // Validate the input
            if (userGuess->Length == this->secretWord->Length)
            {
                bool correctGuess = false;
                String^ updatedState = this->currentState;

                // Check if the guess is correct
                for (int i = 0; i < this->secretWord->Length; i++)
                {
                    if (userGuess[i] == this->secretWord[i])
                    {
                        updatedState = updatedState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                        correctGuess = true;
                    }
                }
                int currentScore;
                // Update the game state
                if (correctGuess)
                {
                    this->currentState = updatedState;
                    // Update UI
                    for (int i = 0; i < this->secretWord->Length; i++)
                    {
                        this->GameAns->Controls[i]->Text = this->currentState[i].ToString();
                    }
                    currentScore++;
                    this->Score->Text = "Score: " +currentScore.ToString(); // Tăng điểm
                }

                // Check if the game is won
                if (this->currentState == this->secretWord)
                {
                    MessageBox::Show("Congratulations! You guessed the word!");
                    this->GameStart->Enabled = true;
                }
            }
            else
            {
                MessageBox::Show("Please enter the correct number of letters.");
            }

            // Clear the input box after submission
            this->Test->Clear();
        }


        void Render(System::Object^ sender, System::EventArgs^ e)
        {
            this->GameStart->Enabled = false;
            this->Score->Text = "0";
            this->Test->Clear();
            FetchWord();
            StartCountdown(20); // Start countdown timer with 60 seconds
        }

        void ShowRules(System::Object^ sender, System::EventArgs^ e)
        {
            String^ rules = "1. A random word will be displayed.\n"
                "2. You need to guess the word by entering letters.\n"
                "3. Each correct letter will appear in the word.\n"
                "4. Incorrect guesses will reduce your score.\n"
                "5. The game ends when you guess the word or time runs out.\n"
                "6. You have a limited time to guess the word.";
            MessageBox::Show(rules, "Game Rules");
        }

        void FetchWord() {
            HttpClient^ client = gcnew HttpClient();
            String^ url = "https://api.datamuse.com/words?sp=?????&max=10"; // Lấy nhiều từ
            try {
                Task<String^>^ task = client->GetStringAsync(url);
                task->Wait();
                String^ response = task->Result;

                if (!String::IsNullOrEmpty(response)) {
                    // Lấy từ ngẫu nhiên từ danh sách kết quả
                    int start = response->IndexOf("\"word\":\"") + 8;
                    int end = response->IndexOf("\"", start);
                    String^ word = response->Substring(start, end - start);
                    StartGameWithWord(word);
                }
                else {
                    StartGameWithWord("Error fetching word");
                }
            }
            catch (Exception^ ex) {
                StartGameWithWord("API Error");
            }
        }



        void StartGameWithWord(String^ word)
        {
            // Clear any previous controls
            this->GameAns->Controls->Clear();

            // Create a FlowLayoutPanel to handle horizontal alignment
            FlowLayoutPanel^ flowPanel = gcnew FlowLayoutPanel();
            flowPanel->Dock = DockStyle::Top;  // Position it at the top of the parent panel
            flowPanel->FlowDirection = FlowDirection::LeftToRight;  // Horizontal layout
            flowPanel->AutoSize = true;  // Allow resizing based on content
            flowPanel->WrapContents = false;  // Prevent wrapping of controls to the next line

            // Loop through each character in the word and create a label for it
            for (int i = 0; i < word->Length; i++)
            {
                Label^ lbl = gcnew Label();
                lbl->Text = "_";  // Set initial label text to "_"
                lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));  // Adjust font size
                lbl->AutoSize = true;  // Allow label to resize based on text content
               lbl->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);  // Correct Set margin on all sides
                flowPanel->Controls->Add(lbl);  // Add label to the FlowLayoutPanel
            }

            // Add FlowLayoutPanel to the GameAns panel
            this->GameAns->Controls->Add(flowPanel);

            // Store the secret word and initialize currentState with underscores
            this->secretWord = word;
            this->currentState = gcnew String('_', word->Length);

            // Initialize the score and disable the start button (or enable based on game logic)
            this->Score->Text = "0";
            this->GameStart->Enabled = false;  // Disable start button during game play
        }



        void StartCountdown(int seconds)
        {
            this->remainingTime = seconds;
            this->countdownTimer->Start();
        }

        void OnCountdownTick(System::Object^ sender, System::EventArgs^ e)
        {
            this->countdownLabel->Text = "Time: " + this->remainingTime.ToString();
            if (--this->remainingTime <= 0)
            {
                this->countdownTimer->Stop();
                MessageBox::Show("Time's up!");
                MessageBox::Show("The word is: ");
            }
        }
    };
}
