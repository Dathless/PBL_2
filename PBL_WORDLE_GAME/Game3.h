#pragma once
#include "Game.h"
#include "CryptoUtils.h"
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

namespace PBLWORDLEGAME {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class WordDefinition {
    public:
        String^ word;
        String^ definition;
        String^ difficulty;
        String^ firstLetter;
        int length;

        WordDefinition(String^ w, String^ def, String^ diff) {
            word = w;
            definition = def;
            difficulty = diff;
            firstLetter = w->Substring(0, 1);
            length = w->Length;
        }
    };

    public ref class Game3 : public System::Windows::Forms::Form {
    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ lblDefinition;
        System::Windows::Forms::TextBox^ txtAnswer;
        System::Windows::Forms::Button^ btnSubmit;
        System::Windows::Forms::Button^ btnHint;
        System::Windows::Forms::Label^ lblTimer;
        System::Windows::Forms::Label^ lblScore;
        System::Windows::Forms::Label^ lblDifficulty;
        System::Windows::Forms::ComboBox^ cmbDifficulty;
        System::Windows::Forms::Button^ btnBack;
        System::Windows::Forms::Label^ lblHint;
        System::Windows::Forms::Label^ lblMessage;
        System::Windows::Forms::ProgressBar^ progressBar;
        System::Windows::Forms::Button^ btnSkip;
        System::Windows::Forms::Button^ btnStart;
        System::Windows::Forms::Button^ btnEnd;
        int maxTime;

        List<WordDefinition^>^ basicWords;
        List<WordDefinition^>^ mediumWords;
        List<WordDefinition^>^ hardWords;
        List<WordDefinition^>^ currentList;
        int currentIndex;
        WordDefinition^ currentWord;
        int score;
        int timeLeft;
        System::Windows::Forms::Timer^ gameTimer;
        bool hintUsed;
        String^ username;

    public:
        Game3(String^ usr) {
            InitializeComponent();
            username = usr;
            LoadWords();
            PrepareForStart();
        }

    protected:
        ~Game3() {
            if (components) {
                delete components;
            }
        }

    private:
        void InitializeComponent(void) {
            this->components = gcnew System::ComponentModel::Container();
            this->lblDefinition = (gcnew System::Windows::Forms::Label());
            this->txtAnswer = (gcnew System::Windows::Forms::TextBox());
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->btnHint = (gcnew System::Windows::Forms::Button());
            this->lblTimer = (gcnew System::Windows::Forms::Label());
            this->lblScore = (gcnew System::Windows::Forms::Label());
            this->lblDifficulty = (gcnew System::Windows::Forms::Label());
            this->cmbDifficulty = (gcnew System::Windows::Forms::ComboBox());
            this->btnBack = (gcnew System::Windows::Forms::Button());
            this->lblHint = (gcnew System::Windows::Forms::Label());
            this->lblMessage = (gcnew System::Windows::Forms::Label());
            this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
            this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->btnSkip = (gcnew System::Windows::Forms::Button());
            this->btnStart = (gcnew System::Windows::Forms::Button());
            this->btnEnd = (gcnew System::Windows::Forms::Button());

            // Form settings
            this->ClientSize = System::Drawing::Size(800, 600);
            this->Name = L"Game3";
            this->Text = L"Word Definition Game";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->BackColor = System::Drawing::Color::LightCyan;

            // Definition label
            this->lblDefinition->AutoSize = true;
            this->lblDefinition->Font = gcnew System::Drawing::Font("Segoe UI", 18, System::Drawing::FontStyle::Bold);
            this->lblDefinition->Location = System::Drawing::Point(50, 100);
            this->lblDefinition->Size = System::Drawing::Size(700, 50);
            this->lblDefinition->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblDefinition->ForeColor = System::Drawing::Color::FromArgb(44, 62, 80); // Dark blue-gray

            // Answer textbox
            this->txtAnswer->Font = gcnew System::Drawing::Font("Segoe UI", 14);
            this->txtAnswer->Location = System::Drawing::Point(250, 200);
            this->txtAnswer->Size = System::Drawing::Size(300, 35);
            this->txtAnswer->BackColor = System::Drawing::Color::White;
            this->txtAnswer->ForeColor = System::Drawing::Color::FromArgb(44, 62, 80);
            this->txtAnswer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtAnswer->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;

            // Hint label
            this->lblHint->AutoSize = true;
            this->lblHint->Font = gcnew System::Drawing::Font("Segoe UI", 12, System::Drawing::FontStyle::Italic);
            this->lblHint->Location = System::Drawing::Point(250, 240);
            this->lblHint->Size = System::Drawing::Size(300, 30);
            this->lblHint->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblHint->ForeColor = System::Drawing::Color::FromArgb(230, 126, 34); // Orange

            // Submit button
            this->btnSubmit->Font = gcnew System::Drawing::Font("Segoe UI", 12, System::Drawing::FontStyle::Bold);
            this->btnSubmit->Location = System::Drawing::Point(350, 280);
            this->btnSubmit->Size = System::Drawing::Size(100, 40);
            this->btnSubmit->Text = L"Submit";
            this->btnSubmit->BackColor = System::Drawing::Color::FromArgb(52, 152, 219); // Blue
            this->btnSubmit->ForeColor = System::Drawing::Color::White;
            this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSubmit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(41, 128, 185);
            this->btnSubmit->FlatAppearance->BorderSize = 2;
            this->btnSubmit->Click += gcnew System::EventHandler(this, &Game3::btnSubmit_Click);

            // Hint button
            this->btnHint->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnHint->Location = System::Drawing::Point(250, 445);
            this->btnHint->Size = System::Drawing::Size(100, 40);
            this->btnHint->Text = L"Hint";
            this->btnHint->BackColor = System::Drawing::Color::LightSkyBlue;
            this->btnHint->ForeColor = System::Drawing::Color::White;
            this->btnHint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnHint->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
            this->btnHint->FlatAppearance->BorderSize = 2;
            this->btnHint->Click += gcnew System::EventHandler(this, &Game3::btnHint_Click);

            // Skip button
            this->btnSkip->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnSkip->Location = System::Drawing::Point(470, 445);
            this->btnSkip->Size = System::Drawing::Size(100, 40);
            this->btnSkip->Text = L"Skip";
            this->btnSkip->BackColor = System::Drawing::Color::LightCoral;
            this->btnSkip->ForeColor = System::Drawing::Color::White;
            this->btnSkip->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSkip->FlatAppearance->BorderColor = System::Drawing::Color::IndianRed;
            this->btnSkip->FlatAppearance->BorderSize = 2;
            this->btnSkip->Click += gcnew System::EventHandler(this, &Game3::btnSkip_Click);

            // Timer label
            this->lblTimer->AutoSize = true;
            this->lblTimer->Font = gcnew System::Drawing::Font("Segoe UI", 14, System::Drawing::FontStyle::Bold);
            this->lblTimer->Location = System::Drawing::Point(50, 50);
            this->lblTimer->Size = System::Drawing::Size(150, 30);
            this->lblTimer->ForeColor = System::Drawing::Color::FromArgb(231, 76, 60); // Red

            // Score label
            this->lblScore->AutoSize = true;
            this->lblScore->Font = gcnew System::Drawing::Font("Segoe UI", 14, System::Drawing::FontStyle::Bold);
            this->lblScore->Location = System::Drawing::Point(650, 50);
            this->lblScore->Size = System::Drawing::Size(150, 30);
            this->lblScore->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113); // Green

            // Difficulty label
            this->lblDifficulty->AutoSize = true;
            this->lblDifficulty->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->lblDifficulty->Location = System::Drawing::Point(50, 400);
            this->lblDifficulty->Size = System::Drawing::Size(100, 30);
            this->lblDifficulty->Text = L"Difficulty:";
            this->lblDifficulty->ForeColor = System::Drawing::Color::MidnightBlue;

            // Difficulty combobox
            this->cmbDifficulty->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->cmbDifficulty->Location = System::Drawing::Point(150, 400);
            this->cmbDifficulty->Size = System::Drawing::Size(150, 30);
            this->cmbDifficulty->BackColor = System::Drawing::Color::WhiteSmoke;
            this->cmbDifficulty->ForeColor = System::Drawing::Color::DarkSlateGray;
            this->cmbDifficulty->Items->AddRange(gcnew cli::array< System::Object^  > { L"Basic", L"Medium", L"Hard" });
            this->cmbDifficulty->SelectedIndex = 0;
            this->cmbDifficulty->SelectedIndexChanged += gcnew System::EventHandler(this, &Game3::cmbDifficulty_SelectedIndexChanged);

            // Back button
            this->btnBack->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnBack->Location = System::Drawing::Point(50, 500);
            this->btnBack->Size = System::Drawing::Size(100, 40);
            this->btnBack->Text = L"Back";
            this->btnBack->BackColor = System::Drawing::Color::Gray;
            this->btnBack->ForeColor = System::Drawing::Color::White;
            this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnBack->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
            this->btnBack->FlatAppearance->BorderSize = 2;
            this->btnBack->Click += gcnew System::EventHandler(this, &Game3::btnBack_Click);

            // Message label
            this->lblMessage->AutoSize = true;
            this->lblMessage->Font = gcnew System::Drawing::Font("Segoe UI", 12, System::Drawing::FontStyle::Bold);
            this->lblMessage->Location = System::Drawing::Point(250, 480);
            this->lblMessage->Size = System::Drawing::Size(300, 30);
            this->lblMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblMessage->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113); // Green

            // Progress bar
            this->progressBar->Location = System::Drawing::Point(50, 80);
            this->progressBar->Size = System::Drawing::Size(700, 15);
            this->progressBar->Maximum = 60;
            this->progressBar->Value = 60;
            this->progressBar->ForeColor = System::Drawing::Color::FromArgb(155, 89, 182); // Purple

            // Timer settings
            this->gameTimer->Interval = 1000;
            this->gameTimer->Tick += gcnew System::EventHandler(this, &Game3::gameTimer_Tick);

            // Start button
            this->btnStart->Font = gcnew System::Drawing::Font("Segoe UI", 12, System::Drawing::FontStyle::Bold);
            this->btnStart->Location = System::Drawing::Point(350, 350);
            this->btnStart->Size = System::Drawing::Size(100, 40);
            this->btnStart->Text = L"Start";
            this->btnStart->BackColor = System::Drawing::Color::MediumSeaGreen;
            this->btnStart->ForeColor = System::Drawing::Color::White;
            this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnStart->FlatAppearance->BorderColor = System::Drawing::Color::DarkGreen;
            this->btnStart->FlatAppearance->BorderSize = 2;
            this->btnStart->Click += gcnew System::EventHandler(this, &Game3::btnStart_Click);

            // End button
            this->btnEnd->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnEnd->Location = System::Drawing::Point(600, 350);
            this->btnEnd->Size = System::Drawing::Size(120, 40);
            this->btnEnd->Text = L"End Game";
            this->btnEnd->BackColor = System::Drawing::Color::SlateBlue;
            this->btnEnd->ForeColor = System::Drawing::Color::White;
            this->btnEnd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEnd->FlatAppearance->BorderColor = System::Drawing::Color::Indigo;
            this->btnEnd->FlatAppearance->BorderSize = 2;
            this->btnEnd->Click += gcnew System::EventHandler(this, &Game3::btnEnd_Click);

            // Add controls to form
            this->Controls->Add(this->lblDefinition);
            this->Controls->Add(this->txtAnswer);
            this->Controls->Add(this->btnSubmit);
            this->Controls->Add(this->btnHint);
            this->Controls->Add(this->lblTimer);
            this->Controls->Add(this->lblScore);
            this->Controls->Add(this->lblDifficulty);
            this->Controls->Add(this->cmbDifficulty);
            this->Controls->Add(this->btnBack);
            this->Controls->Add(this->lblHint);
            this->Controls->Add(this->lblMessage);
            this->Controls->Add(this->progressBar);
            this->Controls->Add(this->btnSkip);
            this->Controls->Add(this->btnStart);
            this->Controls->Add(this->btnEnd);
        }

        void LoadWords() {
            basicWords = gcnew List<WordDefinition^>();
            mediumWords = gcnew List<WordDefinition^>();
            hardWords = gcnew List<WordDefinition^>();
            // Basic: 3-6 ký tự
            basicWords->Add(gcnew WordDefinition("book", "A written or printed work consisting of pages", "Basic"));
            basicWords->Add(gcnew WordDefinition("house", "A building where people live", "Basic"));
            basicWords->Add(gcnew WordDefinition("apple", "A round fruit with red or green skin", "Basic"));
            basicWords->Add(gcnew WordDefinition("chair", "A piece of furniture for sitting", "Basic"));
            basicWords->Add(gcnew WordDefinition("table", "A piece of furniture with a flat top", "Basic"));
            basicWords->Add(gcnew WordDefinition("phone", "A device used to make calls", "Basic"));
            basicWords->Add(gcnew WordDefinition("water", "A clear liquid that we drink", "Basic"));
            basicWords->Add(gcnew WordDefinition("bread", "A food made from flour and baked", "Basic"));
            basicWords->Add(gcnew WordDefinition("clock", "A device that shows the time", "Basic"));
            basicWords->Add(gcnew WordDefinition("plant", "A living thing that grows in soil", "Basic"));
            basicWords->Add(gcnew WordDefinition("mouse", "A small animal or a computer device", "Basic"));
            basicWords->Add(gcnew WordDefinition("shirt", "A piece of clothing for the upper body", "Basic"));
            basicWords->Add(gcnew WordDefinition("glass", "A container for drinking", "Basic"));
            basicWords->Add(gcnew WordDefinition("train", "A vehicle that runs on tracks", "Basic"));
            basicWords->Add(gcnew WordDefinition("light", "Something that makes things visible", "Basic"));
            // Medium: 7-9 ký tự
            mediumWords->Add(gcnew WordDefinition("computer", "An electronic device for processing data", "Medium"));
            mediumWords->Add(gcnew WordDefinition("teacher", "A person who helps students learn", "Medium"));
            mediumWords->Add(gcnew WordDefinition("picture", "A drawing or photograph", "Medium"));
            mediumWords->Add(gcnew WordDefinition("holiday", "A day of celebration or rest", "Medium"));
            mediumWords->Add(gcnew WordDefinition("library", "A place where books are kept", "Medium"));
            mediumWords->Add(gcnew WordDefinition("battery", "A device that stores energy", "Medium"));
            mediumWords->Add(gcnew WordDefinition("diamond", "A precious stone, hardest mineral", "Medium"));
            mediumWords->Add(gcnew WordDefinition("monster", "A large, frightening creature", "Medium"));
            mediumWords->Add(gcnew WordDefinition("rainbow", "A colorful arc in the sky after rain", "Medium"));
            mediumWords->Add(gcnew WordDefinition("sandwich", "Food made with two slices of bread", "Medium"));
            mediumWords->Add(gcnew WordDefinition("airplane", "A vehicle that flies in the sky", "Medium"));
            mediumWords->Add(gcnew WordDefinition("balloon", "A rubber bag filled with air or gas", "Medium"));
            mediumWords->Add(gcnew WordDefinition("blanket", "A warm cover for a bed", "Medium"));
            mediumWords->Add(gcnew WordDefinition("cabinet", "A piece of furniture with shelves", "Medium"));
            mediumWords->Add(gcnew WordDefinition("diamond", "A precious stone, hardest mineral", "Medium"));
            // Hard: >=10 ký tự
            hardWords->Add(gcnew WordDefinition("electricity", "A form of energy from charged particles", "Hard"));
            hardWords->Add(gcnew WordDefinition("university", "A place for higher education", "Hard"));
            hardWords->Add(gcnew WordDefinition("microscope", "A device to see very small things", "Hard"));
            hardWords->Add(gcnew WordDefinition("astronaut", "A person trained to travel in space", "Hard"));
            hardWords->Add(gcnew WordDefinition("refrigerator", "A device to keep food cold", "Hard"));
            hardWords->Add(gcnew WordDefinition("binoculars", "A device for seeing distant objects", "Hard"));
            hardWords->Add(gcnew WordDefinition("dictionary", "A book with word meanings", "Hard"));
            hardWords->Add(gcnew WordDefinition("headphones", "A device worn on the ears to listen", "Hard"));
            hardWords->Add(gcnew WordDefinition("photograph", "A picture taken with a camera", "Hard"));
            hardWords->Add(gcnew WordDefinition("playground", "An outdoor area for children to play", "Hard"));
            hardWords->Add(gcnew WordDefinition("newspaper", "A printed publication with news", "Hard"));
            hardWords->Add(gcnew WordDefinition("backpack", "A bag carried on the back", "Hard"));
            hardWords->Add(gcnew WordDefinition("blackboard", "A board for writing with chalk", "Hard"));
            hardWords->Add(gcnew WordDefinition("calculator", "A device for mathematical calculations", "Hard"));
            hardWords->Add(gcnew WordDefinition("motorcycle", "A two-wheeled motor vehicle", "Hard"));
        }

        void PrepareForStart() {
            // Disable all controls except difficulty and start
            txtAnswer->Enabled = false;
            btnSubmit->Enabled = false;
            btnHint->Enabled = false;
            btnSkip->Enabled = false;
            progressBar->Value = 0;
            lblDefinition->Text = "";
            lblHint->Text = "";
            lblMessage->Text = "";
            lblScore->Text = "Score: 0";
            lblTimer->Text = "Time: 0";
            cmbDifficulty->Enabled = true;
            btnStart->Enabled = true;
            btnEnd->Enabled = false;
        }

        void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
            // Set maxTime theo mức độ
            String^ selectedDifficulty = cmbDifficulty->SelectedItem->ToString();
            if (selectedDifficulty == "Basic") maxTime = 60;
            else if (selectedDifficulty == "Medium") maxTime = 45;
            else maxTime = 30;
            // Khóa chọn mức độ
            cmbDifficulty->Enabled = false;
            btnStart->Enabled = false;
            // Enable controls chơi game
            txtAnswer->Enabled = true;
            btnSubmit->Enabled = true;
            btnHint->Enabled = true;
            btnSkip->Enabled = true;
            btnEnd->Enabled = true;
            InitializeGame();
        }

        void InitializeGame() {
            score = 0;
            UpdateScore();
            String^ selectedDifficulty = cmbDifficulty->SelectedItem->ToString();
            if (selectedDifficulty == "Basic") {
                currentList = basicWords;
            } else if (selectedDifficulty == "Medium") {
                currentList = mediumWords;
            } else {
                currentList = hardWords;
            }
            currentIndex = 0;
            SelectNewWord();
            timeLeft = maxTime;
            UpdateTimer();
            gameTimer->Start();
            hintUsed = false;
            lblHint->Text = "";
            lblMessage->Text = "";
        }

        void SelectNewWord() {
            if (currentIndex >= currentList->Count) {
                gameTimer->Stop();
                SaveScore();
                ShowCongratulations();
                PrepareForStart();
                return;
            }
            currentWord = currentList[currentIndex];
            lblDefinition->Text = currentWord->definition;
            currentIndex++;
            timeLeft = maxTime;
            UpdateTimer();
        }

        void UpdateScore() {
            lblScore->Text = "Score: " + score;
        }

        void UpdateTimer() {
            lblTimer->Text = "Time: " + timeLeft;
            progressBar->Value = timeLeft;
        }

        void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ answer = txtAnswer->Text->Trim()->ToLower();
            if (answer == currentWord->word->ToLower()) {
                score += hintUsed ? 5 : 10;
                UpdateScore();
                lblMessage->Text = "Correct! +" + (hintUsed ? "5" : "10") + " points";
                lblMessage->ForeColor = System::Drawing::Color::Green;
                SelectNewWord();
                txtAnswer->Clear();
                hintUsed = false;
                lblHint->Text = "";
            }
            else {
                lblMessage->Text = "Wrong! Try again";
                lblMessage->ForeColor = System::Drawing::Color::Red;
            }
        }

        void btnHint_Click(System::Object^ sender, System::EventArgs^ e) {
            if (!hintUsed) {
                lblHint->Text = "First letter: " + currentWord->firstLetter + 
                               " | Length: " + currentWord->length;
                hintUsed = true;
            }
        }

        void gameTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
            timeLeft--;
            UpdateTimer();
            if (timeLeft <= 0) {
                gameTimer->Stop();
                SaveScore();
                ShowCongratulations();
                PrepareForStart();
                this->Close();
            }
        }

        void cmbDifficulty_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            // Không làm gì khi đang chơi
            if (!cmbDifficulty->Enabled) return;
            // Reset giao diện khi đổi mức độ
            PrepareForStart();
        }

        void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveScore();
            this->Close();
        }

        void btnSkip_Click(System::Object^ sender, System::EventArgs^ e) {
            SelectNewWord();
            txtAnswer->Clear();
            hintUsed = false;
            lblHint->Text = "";
            lblMessage->Text = "";
        }

        void btnEnd_Click(System::Object^ sender, System::EventArgs^ e) {
            gameTimer->Stop();
            SaveScore();
            ShowCongratulations();
            PrepareForStart();
            this->Close();
        }

        void SaveScore() {
            try {
                String^ scoreFile = "UserList\\" + username + "_score.txt";
                String^ currentScore = "";
                if (File::Exists(scoreFile)) {
                    currentScore = File::ReadAllText(scoreFile);
                }
                int totalScore = score;
                if (currentScore != "") {
                    totalScore += Int32::Parse(currentScore);
                }
                File::WriteAllText(scoreFile, totalScore.ToString());
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error saving score: " + ex->Message);
            }
        }

        // Hàm xử lý sự kiện click nút OK cho popup Congratulations
        void ClosePopup(System::Object^ sender, System::EventArgs^ e) {
            System::Windows::Forms::Form^ popup = dynamic_cast<System::Windows::Forms::Form^>(((System::Windows::Forms::Button^)sender)->FindForm());
            if (popup != nullptr) popup->Close();
        }

        void ShowCongratulations() {
            System::Windows::Forms::Form^ popup = gcnew System::Windows::Forms::Form();
            popup->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            popup->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            popup->Size = System::Drawing::Size(450, 320);
            popup->BackColor = System::Drawing::Color::White;

            // Rainbow colors array
            array<System::Drawing::Color>^ colors = gcnew array<System::Drawing::Color> {
                System::Drawing::Color::Red,
                System::Drawing::Color::Orange,
                System::Drawing::Color::Gold,
                System::Drawing::Color::Green,
                System::Drawing::Color::DodgerBlue,
                System::Drawing::Color::BlueViolet,
                System::Drawing::Color::DeepPink,
                System::Drawing::Color::Turquoise,
                System::Drawing::Color::SaddleBrown,
                System::Drawing::Color::DarkMagenta,
                System::Drawing::Color::DarkCyan,
                System::Drawing::Color::Crimson,
                System::Drawing::Color::DarkOrange
            };
            System::String^ congratsText = L"Congratulations!";
            int n = congratsText->Length;
            int fontSize = 20;
            int spacing = 0;
            int totalWidth = 0;
            array<int>^ charWidths = gcnew array<int>(n);
            // Tính tổng chiều rộng để căn giữa
            for (int i = 0; i < n; ++i) {
                System::Windows::Forms::Label^ temp = gcnew System::Windows::Forms::Label();
                temp->Font = gcnew System::Drawing::Font("Segoe UI", (float)fontSize, System::Drawing::FontStyle::Italic);
                temp->Text = congratsText->Substring(i, 1);
                temp->AutoSize = true;
                charWidths[i] = temp->PreferredWidth;
                totalWidth += temp->PreferredWidth + spacing;
            }
            int x = (popup->ClientSize.Width - totalWidth) / 2;
            int y = 20;
            for (int i = 0; i < n; ++i) {
                System::Windows::Forms::Label^ letter = gcnew System::Windows::Forms::Label();
                letter->Font = gcnew System::Drawing::Font("Segoe UI", (float)fontSize, System::Drawing::FontStyle::Italic);
                letter->Text = congratsText->Substring(i, 1);
                letter->ForeColor = colors[i % colors->Length];
                letter->BackColor = System::Drawing::Color::Transparent;
                letter->AutoSize = true;
                letter->Location = System::Drawing::Point(x, y);
                popup->Controls->Add(letter);
                x += charWidths[i] + spacing;
            }

            // Label điểm số ngay dưới dòng Congratulations!
            System::Windows::Forms::Label^ lbl = gcnew System::Windows::Forms::Label();
            lbl->Text = L"Your score: " + score;
            lbl->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
            lbl->ForeColor = System::Drawing::Color::FromArgb(46, 204, 113);
            lbl->AutoSize = true;
            lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // Đặt lbl căn giữa và cách dòng trên 10px
            int lblY = y + fontSize + 10;
            int lblX = (popup->ClientSize.Width - lbl->PreferredWidth) / 2;
            lbl->Location = System::Drawing::Point(lblX, lblY);
            popup->Controls->Add(lbl);

            // Hiển thị hình ảnh Congratulations dưới hai dòng trên
            System::Windows::Forms::PictureBox^ pic = gcnew System::Windows::Forms::PictureBox();
            String^ imgPath = System::IO::Path::Combine(System::Windows::Forms::Application::StartupPath, "asset\\img\\conragulation.png");
            if (System::IO::File::Exists(imgPath)) {
                pic->Image = System::Drawing::Image::FromFile(imgPath);
            }
            pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            pic->Location = System::Drawing::Point(25, lblY + lbl->PreferredHeight + 10);
            pic->Size = System::Drawing::Size(400, 90);
            popup->Controls->Add(pic);

            // Nút OK
            System::Windows::Forms::Button^ btnOK = gcnew System::Windows::Forms::Button();
            btnOK->Text = L"OK";
            btnOK->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold);
            btnOK->Size = System::Drawing::Size(120, 50);
            btnOK->Location = System::Drawing::Point(165, 220);
            btnOK->BackColor = System::Drawing::Color::FromArgb(52, 152, 219);
            btnOK->ForeColor = System::Drawing::Color::White;
            btnOK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnOK->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(41, 128, 185);
            btnOK->FlatAppearance->BorderSize = 2;
            btnOK->Click += gcnew System::EventHandler(this, &Game3::ClosePopup);
            popup->Controls->Add(btnOK);

            popup->ShowDialog();
        }
    };
} 