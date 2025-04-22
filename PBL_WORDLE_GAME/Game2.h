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
        int score;
        int attemptsLeft;
        bool gameActive;

    private:
        System::Windows::Forms::Label^ HighestScore;
        Dictionary<String^, int>^ getWord = gcnew Dictionary<String^, int>();
        User^ UserLogged;
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
        System::Windows::Forms::Label^ AttemptsLabel;
        AxWMPLib::AxWindowsMediaPlayer^ BGMusic;
        System::Windows::Forms::Button^ HintButton;
        cliext::vector<int> hiddenIndices;

    public:
        Game1(String^ usr)
        {
            InitializeComponent();
            uname = usr;
            gameActive = false;
            score = 0;
            HideAllElements(); // Hide everything initially
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
            this->HighestScore = (gcnew System::Windows::Forms::Label());
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
            this->AttemptsLabel = (gcnew System::Windows::Forms::Label());
            this->HintButton = (gcnew System::Windows::Forms::Button());
            this->BGMusic = (gcnew AxWMPLib::AxWindowsMediaPlayer());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->BeginInit();
            this->SuspendLayout();
            // 
            // HighestScore
            // 
            this->HighestScore->AutoSize = true;
            this->HighestScore->BackColor = System::Drawing::Color::Transparent;
            this->HighestScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->HighestScore->ForeColor = System::Drawing::Color::White;
            this->HighestScore->Location = System::Drawing::Point(400, 100); // Adjust position as needed
            this->HighestScore->Name = L"HighestScore";
            this->HighestScore->Size = System::Drawing::Size(135, 25);
            this->HighestScore->TabIndex = 15;
            this->HighestScore->Text = L"Highest Score: 0";
            //
            // HintButton
            //
            this->HintButton->ForeColor = System::Drawing::Color::DarkGreen;
            this->HintButton->Location = System::Drawing::Point(350, 259);
            this->HintButton->Name = L"HintButton";
            this->HintButton->Size = System::Drawing::Size(100, 30);
            this->HintButton->TabIndex = 10;
            this->HintButton->Text = L"Hint";
            this->HintButton->Click += gcnew System::EventHandler(this, &Game1::HintButton_Click);
            // 
            // GameStart
            // 
            this->GameStart->ForeColor = System::Drawing::Color::Coral;
            this->GameStart->Location = System::Drawing::Point(223, 91);
            this->GameStart->Name = L"GameStart";
            this->GameStart->Size = System::Drawing::Size(100, 30);
            this->GameStart->TabIndex = 0;
            this->GameStart->Text = L"Play";
            this->GameStart->Click += gcnew System::EventHandler(this, &Game1::StartGame);
            // 
            // Test
            // 
            this->Test->Enabled = false;
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
            this->Score->Text = L"Score: 0";
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
            this->countdownLabel->Text = L"Time: 0";
            // 
            // SubmitGuessButton
            // 
            this->SubmitGuessButton->Enabled = false;
            this->SubmitGuessButton->ForeColor = System::Drawing::Color::Coral;
            this->SubmitGuessButton->Location = System::Drawing::Point(223, 259);
            this->SubmitGuessButton->Name = L"SubmitGuessButton";
            this->SubmitGuessButton->Size = System::Drawing::Size(100, 30);
            this->SubmitGuessButton->TabIndex = 6;
            this->SubmitGuessButton->Text = L"Submit Guess";
            this->SubmitGuessButton->Click += gcnew System::EventHandler(this, &Game1::SubmitGuess_Click);
            // 
            // AttemptsLabel
            // 
            this->AttemptsLabel->Location = System::Drawing::Point(400, 50);
            this->AttemptsLabel->Name = L"AttemptsLabel";
            this->AttemptsLabel->Size = System::Drawing::Size(100, 30);
            this->AttemptsLabel->TabIndex = 9;
            this->AttemptsLabel->Text = L"Attempts: 0";
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
            this->Controls->Add(this->AttemptsLabel);
            this->Controls->Add(this->BGMusic);
            this->Controls->Add(this->GameStart);
            this->Controls->Add(this->Test);
            this->Controls->Add(this->Score);
            this->Controls->Add(this->GameAns);
            this->Controls->Add(this->Exit);
            this->Controls->Add(this->RulesButton);
            this->Controls->Add(this->SubmitGuessButton);
            this->Controls->Add(this->countdownLabel);
            this->Controls->Add(this->HintButton);
            this->Controls->Add(this->HighestScore);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Game1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Load += gcnew System::EventHandler(this, &Game1::OnLoad);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:

        void HideAllElements()
        {
            // Hide all elements except the Start Game button
            this->Test->Visible = false;
            this->Score->Visible = false;
            this->GameAns->Visible = false;
            this->Exit->Visible = false;
            this->RulesButton->Visible = false;
            this->countdownLabel->Visible = false;
            this->SubmitGuessButton->Visible = false;
            this->AttemptsLabel->Visible = false;

            // Center the Start Game button
            this->GameStart->Location = System::Drawing::Point(
                (this->ClientSize.Width - this->GameStart->Width) / 2,
                (this->ClientSize.Height - this->GameStart->Height) / 2);
            this->HintButton->Visible = false;
            this->GameStart->Text = L"Start Game";
        }

        void ShowAllElements()
        {
            // Show all elements
            this->Test->Visible = true;
            this->Score->Visible = true;
            this->GameAns->Visible = true;
            this->Exit->Visible = true;
            this->RulesButton->Visible = true;
            this->countdownLabel->Visible = true;
            this->SubmitGuessButton->Visible = true;
            this->AttemptsLabel->Visible = true;

            // Reset positions to original layout
            this->GameStart->Location = System::Drawing::Point(223, 91);
            this->Test->Location = System::Drawing::Point(223, 219);
            this->Score->Location = System::Drawing::Point(100, 50);
            this->GameAns->Location = System::Drawing::Point(175, 142);
            this->Exit->Location = System::Drawing::Point(223, 363);
            this->RulesButton->Location = System::Drawing::Point(223, 311);
            this->countdownLabel->Location = System::Drawing::Point(10, 10);
            this->SubmitGuessButton->Location = System::Drawing::Point(223, 259);
            this->AttemptsLabel->Location = System::Drawing::Point(400, 50);

            // Change text to "Replay"
            this->GameStart->Text = L"Replay";
            this->HintButton->Visible = true;
        }

        void OnLoad(Object^ sender, EventArgs^ e)
        {
            this->settings = gcnew SettingManager();
            this->settings->Game1_Music(BGMusic);
        }

        void Exit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->settings->StopAxWMP(BGMusic);
            this->Close();
        }

        void StartGame(System::Object^ sender, System::EventArgs^ e)
        {
            ShowAllElements(); // Show all elements when game starts
            this->gameActive = true;
            this->GameStart->Enabled = false;
            this->Test->Enabled = true;
            this->SubmitGuessButton->Enabled = true;
            this->score = 0;
            this->attemptsLeft = 6;
            this->Score->Text = "Score: 0";
            this->AttemptsLabel->Text = "Attempts: " + attemptsLeft.ToString();
            this->Test->Clear();
            FetchWord();
            StartCountdown(60); // 60 seconds countdown
        }

        void SubmitGuess_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (!gameActive) return;

            String^ userGuess = this->Test->Text->ToUpper();

            // Validate the input
            if (userGuess->Length != this->secretWord->Length)
            {
                MessageBox::Show("Please enter a " + this->secretWord->Length + "-letter word.");
                return;
            }

            // Process the guess
            bool correctGuess = false;
            String^ updatedState = this->currentState;

            // Check each letter in the guess
            for (int i = 0; i < this->secretWord->Length; i++)
            {
                if (userGuess[i] == this->secretWord[i])
                {
                    // Correct letter in correct position
                    updatedState = updatedState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                    correctGuess = true;
                }
            }

            // Update the game state
            this->currentState = updatedState;
            UpdateWordDisplay();

            // Update score and attempts
            if (correctGuess)
            {
                score += 10; // Award points for correct letters
                this->Score->Text = "Score: " + score.ToString();
            }
            else
            {
                attemptsLeft--;
                this->AttemptsLabel->Text = "Attempts: " + attemptsLeft.ToString();
            }

            // Check for win/lose conditions
            if (this->currentState == this->secretWord)
            {
                EndGame(true);
            }
            else if (attemptsLeft <= 0)
            {
                EndGame(false);
            }

            // Clear the input box
            this->Test->Clear();
        }

        void UpdateWordDisplay()
        {
            this->GameAns->Controls->Clear();
            FlowLayoutPanel^ flowPanel = gcnew FlowLayoutPanel();
            flowPanel->Dock = DockStyle::Top;
            flowPanel->FlowDirection = FlowDirection::LeftToRight;
            flowPanel->AutoSize = true;
            flowPanel->WrapContents = false;

            for (int i = 0; i < this->currentState->Length; i++)
            {
                Label^ lbl = gcnew Label();
                lbl->Text = this->currentState[i].ToString();
                lbl->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20);
                lbl->AutoSize = true;
                lbl->Margin = System::Windows::Forms::Padding(5);

                // Highlight revealed letters in green
                if (this->currentState[i] != '_') {
                    lbl->ForeColor = System::Drawing::Color::Green;
                }

                flowPanel->Controls->Add(lbl);
            }

            this->GameAns->Controls->Add(flowPanel);
        }

        void EndGame(bool won)
        {
            this->gameActive = false;
            this->countdownTimer->Stop();
            this->GameStart->Enabled = true;
            this->Test->Enabled = false;
            this->SubmitGuessButton->Enabled = false;

            if (won)
            {
                MessageBox::Show("Congratulations! You guessed the word: " + this->secretWord, "You Win!");
            }
            else
            {
                MessageBox::Show("Game Over! The word was: " + this->secretWord, "Try Again");
            }
        }

        void ShowRules(System::Object^ sender, System::EventArgs^ e)
        {
            String^ rules = "Word Guessing Game Rules:\n\n"
                "1. A random word will be selected (all uppercase)\n"
                "2. You have 6 attempts to guess the word\n"
                "3. Each attempt must be the same length as the secret word\n"
                "4. Correct letters will be revealed in their positions\n"
                "5. You earn 10 points for each correct letter\n"
                "6. You have 60 seconds to guess the word\n"
                "7. The game ends when you guess the word or run out of attempts/time";
            MessageBox::Show(rules, "Game Rules");
        }

        void FetchWord()
        {
            // For testing, use a local word list
            array<String^>^ wordList = gcnew array<String^> {
                "APPLE", "BRAIN", "CHAIR", "DANCE", "EAGLE",
                    "FRUIT", "GHOST", "HOUSE", "IGLOO", "JUICE",
                    "KOALA", "LEMON", "MUSIC", "NIGHT", "OCEAN"
            };

            // Select a random word from the list
            Random^ rand = gcnew Random();
            int index = rand->Next(wordList->Length);
            StartGameWithWord(wordList[index]);
        }

        void StartGameWithWord(String^ word)
        {
            this->secretWord = word->ToUpper();
            this->currentState = gcnew String('_', word->Length);

            // Initialize hidden indices
            hiddenIndices.clear();
            for (int i = 0; i < word->Length; i++) {
                hiddenIndices.push_back(i);
            }

            UpdateWordDisplay();
        }

        void HintButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (!gameActive || hiddenIndices.empty()) return;

            // Deduct points for using hint
            score = Math::Max(0, score - 5); // Deduct 5 points for each hint
            this->Score->Text = "Score: " + score.ToString();

            // Select a random hidden letter to reveal
            Random^ rand = gcnew Random();
            int hintIndex = rand->Next(hiddenIndices.size());
            int charIndex = hiddenIndices[hintIndex];

            // Update the current state
            this->currentState = this->currentState->Remove(charIndex, 1)->Insert(charIndex, this->secretWord[charIndex].ToString());

            // Remove this index from hidden indices
            hiddenIndices.erase(hiddenIndices.begin() + hintIndex);

            // Update display
            UpdateWordDisplay();

            // Check if game is won
            if (this->currentState == this->secretWord) {
                EndGame(true);
            }
        }

        void StartCountdown(int seconds)
        {
            this->remainingTime = seconds;
            this->countdownLabel->Text = "Time: " + seconds.ToString();
            this->countdownTimer->Start();
        }

        void OnCountdownTick(System::Object^ sender, System::EventArgs^ e)
        {
            this->remainingTime--;
            this->countdownLabel->Text = "Time: " + this->remainingTime.ToString();

            if (this->remainingTime <= 0)
            {
                EndGame(false);
            }
        }
    };
}
