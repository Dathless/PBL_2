#pragma once

#include <cliext/vector>
#include "Game.h"
#include <random>
#include "User.h"
#include "CryptoUtils.h"

namespace WordGuessGame {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Net::Http;
    using namespace System::Media;
    using namespace System::Threading::Tasks;

    public ref class Game1 : public System::Windows::Forms::Form
    {
    private: String^ uname;
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
        System::Media::SoundPlayer^ bgMusic;
        String^ secretWord;
        String^ currentState;
        int remainingTime;

    private:
        void InitializeComponent(void)
        {
            this->GameStart = gcnew System::Windows::Forms::Button();
            this->Test = gcnew System::Windows::Forms::TextBox();
            this->Score = gcnew System::Windows::Forms::Label();
            this->GameAns = gcnew System::Windows::Forms::Panel();
            this->Exit = gcnew System::Windows::Forms::Button();
            this->RulesButton = gcnew System::Windows::Forms::Button();
            this->countdownTimer = gcnew System::Windows::Forms::Timer();
            this->countdownLabel = gcnew System::Windows::Forms::Label();
            this->SubmitGuessButton = gcnew System::Windows::Forms::Button();

            // GameStart Button
            this->GameStart->Location = System::Drawing::Point(100, 150);
            this->GameStart->Size = System::Drawing::Size(100, 30);
            this->GameStart->Text = "Start Game";
            this->GameStart->Click += gcnew System::EventHandler(this, &Game1::Render);

            // Test TextBox
            this->Test->Location = System::Drawing::Point(100, 100);
            this->Test->Size = System::Drawing::Size(100, 30);

            // Score Label
            this->Score->Location = System::Drawing::Point(100, 50);
            this->Score->Size = System::Drawing::Size(100, 30);

            // GameAns Panel
            this->GameAns->Location = System::Drawing::Point(100, 200);
            this->GameAns->Size = System::Drawing::Size(200, 50);

            // Exit Button
            this->Exit->Location = System::Drawing::Point(100, 250);
            this->Exit->Size = System::Drawing::Size(100, 30);
            this->Exit->Text = "Exit";
            this->Exit->Click += gcnew System::EventHandler(this, &Game1::Exit_Click);

            // RulesButton
            this->RulesButton->Location = System::Drawing::Point(100, 300);
            this->RulesButton->Size = System::Drawing::Size(100, 30);
            this->RulesButton->Text = "Game Rules";
            this->RulesButton->Click += gcnew System::EventHandler(this, &Game1::ShowRules);

            // SubmitGuessButton
            this->SubmitGuessButton->Location = System::Drawing::Point(100, 350);
            this->SubmitGuessButton->Size = System::Drawing::Size(100, 30);
            this->SubmitGuessButton->Text = "Submit Guess";
            this->SubmitGuessButton->Click += gcnew System::EventHandler(this, &Game1::SubmitGuess_Click);

            // CountdownLabel
            this->countdownLabel->Location = System::Drawing::Point(10, 10);
            this->countdownLabel->Size = System::Drawing::Size(100, 30);

            // Timer Setup
            this->countdownTimer->Interval = 1000;
            this->countdownTimer->Tick += gcnew System::EventHandler(this, &Game1::OnCountdownTick);

            // Form Setup
            this->ClientSize = System::Drawing::Size(400, 400);
            this->Controls->Add(this->GameStart);
            this->Controls->Add(this->Test);
            this->Controls->Add(this->Score);
            this->Controls->Add(this->GameAns);
            this->Controls->Add(this->Exit);
            this->Controls->Add(this->RulesButton);
            this->Controls->Add(this->SubmitGuessButton);
            this->Controls->Add(this->countdownLabel);
        }

    private:
        // Event handler for Exit button
        void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        // Event handler for Submit Guess button
        void SubmitGuess_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ userGuess = this->Test->Text->ToUpper();

            // Validate that the input is correct length
            if (userGuess->Length == this->secretWord->Length) {
                bool correctGuess = false;
                String^ updatedState = this->currentState;

                for (int i = 0; i < this->secretWord->Length; i++) {
                    if (userGuess[i] == this->secretWord[i]) {
                        updatedState = updatedState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                        correctGuess = true;
                    }
                }

                if (correctGuess) {
                    this->currentState = updatedState;

                    // Update the displayed word in the GameAns panel
                    for (int i = 0; i < this->secretWord->Length; i++) {
                        this->GameAns->Controls[i]->Text = this->currentState[i].ToString();
                    }
                }

                // Check if the word is completely guessed
                if (this->currentState == this->secretWord) {
                    MessageBox::Show("Congratulations! You guessed the right word!");
                    this->GameStart->Enabled = true;  // Re-enable the game start button
                }
            }
            else {
                MessageBox::Show("Please enter the correct number of letters.");
            }

            // Clear the TextBox after submission
            this->Test->Clear();
        }

        // Event handler to start the game
        void Render(System::Object^ sender, System::EventArgs^ e) {
            this->GameStart->Enabled = false;
            this->Score->Text = "0";
            this->Test->Clear();
            FetchWord();
            StartCountdown(60); // Start countdown with 60 seconds
        }

        // Display game rules
        void ShowRules(System::Object^ sender, System::EventArgs^ e) {
            String^ rules = "1. A random word will be displayed.\n"
                "2. You need to guess the word by entering letters.\n"
                "3. Each correct letter will appear in the word.\n"
                "4. Incorrect guesses will reduce your score.\n"
                "5. The game ends when you guess the word or time runs out.\n"
                "6. You have a limited time to guess the word.";
            MessageBox::Show(rules, "Game Rules");
        }

        // Fetch a random word from an API
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

        // Initialize the game with the fetched word
        void StartGameWithWord(String^ word) {
            this->GameAns->Controls->Clear();
            for (int i = 0; i < word->Length; i++) {
                Label^ lbl = gcnew Label();
                lbl->Text = "_";
                lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
                lbl->AutoSize = true;
                this->GameAns->Controls->Add(lbl);
            }

            // Set the currentState to the correct number of underscores (equal to the word length)
            this->secretWord = word;
            this->currentState = gcnew String('_', word->Length);  // Create a string with the correct number of underscores
            this->Score->Text = "0";
            this->GameStart->Enabled = true;
        }


        // Countdown timer logic
        void StartCountdown(int seconds) {
            this->remainingTime = seconds;
            this->countdownTimer->Start();
        }

        // Event for countdown timer
        void OnCountdownTick(System::Object^ sender, System::EventArgs^ e) {
            this->countdownLabel->Text = "Time: " + this->remainingTime.ToString();

            if (--this->remainingTime <= 0) {
                this->countdownTimer->Stop();
                MessageBox::Show("Time's up!");
                // Optionally reset the game here
            }
        }
    };
}
