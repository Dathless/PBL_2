#pragma once
#include <cliext/vector>
#include "Account.h"
#include <fstream>
#include <vector>
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace PBLWORDLEGAME {
    public ref class Landing : public UserControl {
    public:
        String^ secretWord = "APPLE";
        String^ currentState = "_____";
        int score = 100;
        std::vector<std::pair<int, std::string>> highScores;
        Label^ displayWord;
        TextBox^ inputBox;
        Button^ guessButton;
        Label^ scoreLabel;
        Label^ highScoreLabel;
        Label^ highScoreHolderLabel;
        TextBox^ nameInputBox;
    
        Landing() {
            LoadHighScores();
            InitializeComponent();
        }
    
    protected:
        ~Landing() {
            if (components) delete components;
        }
    
    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent() {
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
            this->displayWord->AutoSize = true;

            this->inputBox->Location = Point(50, 80);
            this->inputBox->Width = 100;

            this->guessButton->Text = "Guess";
            this->guessButton->Location = Point(170, 80);
            this->guessButton->Click += gcnew System::EventHandler(this, &Landing::processGuess);

            this->scoreLabel->Text = "Score: " + score;
            this->scoreLabel->Location = Point(50, 120);
            this->scoreLabel->Font = gcnew System::Drawing::Font("Arial", 12);
            this->scoreLabel->AutoSize = true;
            
            this->highScoreLabel->Location = Point(50, 150);
            this->highScoreLabel->Font = gcnew System::Drawing::Font("Arial", 12);
            this->highScoreLabel->AutoSize = true;
            UpdateHighScoreLabel();

            this->nameInputBox->Location = Point(50, 210);
            this->nameInputBox->Width = 150;
            this->nameInputBox->PlaceholderText = "Enter your name";
            
            this->Controls->Add(displayWord);
            this->Controls->Add(inputBox);
            this->Controls->Add(guessButton);
            this->Controls->Add(scoreLabel);
            this->Controls->Add(highScoreLabel);
            this->Controls->Add(nameInputBox);
        }
    
        void processGuess(Object^ sender, EventArgs^ e) {
            String^ userGuess = inputBox->Text->ToUpper();
            if (userGuess->Length != secretWord->Length) return;

            bool correctGuess = false;
            for (int i = 0; i < secretWord->Length; i++) {
                if (userGuess[i] == secretWord[i]) {
                    if (currentState[i] == '_') {
                        currentState = currentState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                        correctGuess = true;
                    }
                }
            }
            
            if (!correctGuess) {
                score -= 10;
            }
            
            displayWord->Text = currentState;
            scoreLabel->Text = "Score: " + score;
            
            if (currentState == secretWord) {
                SaveHighScore();
            }
            
            inputBox->Clear();
        }

        void LoadHighScores() {
            std::ifstream file("highscore.txt");
            if (file.is_open()) {
                highScores.clear();
                int s;
                std::string n;
                while (file >> s) {
                    file.ignore();
                    std::getline(file, n);
                    highScores.push_back({s, n});
                }
                file.close();
                std::sort(highScores.rbegin(), highScores.rend());
            }
        }

        void SaveHighScore() {
            std::string playerName = msclr::interop::marshal_as<std::string>(nameInputBox->Text);
            highScores.push_back({score, playerName});
            std::sort(highScores.rbegin(), highScores.rend());
            if (highScores.size() > 3) highScores.pop_back();
            std::ofstream file("highscore.txt");
            if (file.is_open()) {
                for (const auto& hs : highScores) {
                    file << hs.first << std::endl << hs.second << std::endl;
                }
                file.close();
            }
            UpdateHighScoreLabel();
        }

        void UpdateHighScoreLabel() {
            std::string labelText = "Top 3 Players:\n";
            for (size_t i = 0; i < highScores.size(); ++i) {
                labelText += std::to_string(i + 1) + ". " + highScores[i].second + " - " + std::to_string(highScores[i].first) + "\n";
            }
            highScoreLabel->Text = gcnew String(labelText.c_str());
        }
    };
}
