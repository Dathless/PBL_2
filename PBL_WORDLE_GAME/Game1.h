#pragma once
#include <cliext/vector>
#include "Account.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace PBLWORDLEGAME {
    public ref class Landing : public UserControl {
    public:
        String^ secretWord = "APPLE";
        String^ currentState = "_____";
        Label^ displayWord;
        TextBox^ inputBox;
        Button^ guessButton;
    
        Landing() {
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

            // Label hiển thị từ cần đoán
            this->displayWord->Text = currentState;
            this->displayWord->Location = Point(50, 30);
            this->displayWord->Font = gcnew System::Drawing::Font("Arial", 16);
            this->displayWord->AutoSize = true;

            // Ô nhập từ đoán
            this->inputBox->Location = Point(50, 80);
            this->inputBox->Width = 100;

            // Nút đoán từ
            this->guessButton->Text = "Guess";
            this->guessButton->Location = Point(170, 80);
            this->guessButton->Click += gcnew System::EventHandler(this, &Landing::processGuess);

            this->Controls->Add(displayWord);
            this->Controls->Add(inputBox);
            this->Controls->Add(guessButton);
        }
    
        void processGuess(Object^ sender, EventArgs^ e) {
            String^ userGuess = inputBox->Text->ToUpper();
            if (userGuess->Length != secretWord->Length) return; // Đảm bảo đúng độ dài

            for (int i = 0; i < secretWord->Length; i++) {
                if (userGuess[i] == secretWord[i]) {
                    currentState = currentState->Remove(i, 1)->Insert(i, userGuess[i].ToString());
                }
            }

            displayWord->Text = currentState;
            inputBox->Clear();
        }
    };
}
