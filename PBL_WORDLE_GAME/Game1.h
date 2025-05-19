#pragma once
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Net.Http.dll>
#using <System.Threading.Tasks.dll>

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

    public enum class Difficulty {
        Easy,
        Medium,
        Hard
    };

    public enum class Topic {
        Animals,
        Food,
        Countries,
        Sports,
        Random
    };

    public ref class Game1 : public Game
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
        Difficulty currentDifficulty;
        Topic currentTopic;

        // Word banks organized by topic and difficulty
        static Dictionary<Topic, Dictionary<Difficulty, array<String^>^>^>^ wordBanks;

        static Game1() {
            wordBanks = InitializeWordBanks();
        }

    private: Dictionary<String^, int>^ Ranking = gcnew Dictionary<String^, int>();
    private:
        System::Windows::Forms::Label^ HighestScore;
        System::Windows::Forms::Label^ Rank;
        Dictionary<String^, int>^ getWord = gcnew Dictionary<String^, int>();
        System::ComponentModel::IContainer^ components;
        System::Windows::Forms::Button^ GameStart;
        System::Windows::Forms::TextBox^ Test;
        System::Windows::Forms::Label^ Score;
        System::Windows::Forms::Panel^ GameAns;
        System::Windows::Forms::Button^ ExitBtn;
        System::Windows::Forms::Button^ RulesButton;
        System::Windows::Forms::Timer^ countdownTimer;
        System::Windows::Forms::Label^ countdownLabel;
        System::Windows::Forms::Button^ SubmitGuessButton;
        System::Windows::Forms::Label^ AttemptsLabel;
        System::Windows::Forms::Button^ HintButton;
        System::Windows::Forms::ComboBox^ difficultyComboBox;
        System::Windows::Forms::ComboBox^ topicComboBox;
        System::Windows::Forms::Label^ difficultyLabel;
        System::Windows::Forms::Label^ topicLabel;

        cliext::vector<int> hiddenIndices;

    public:
        Game1(String^ usr)
        {
            InitializeComponent();
            uname = usr;
            gameActive = false;
            score = 0;
            isShowed = false;
            currentDifficulty = Difficulty::Medium; // Default difficulty
            currentTopic = Topic::Random; // Default topic
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
        static Dictionary<Topic, Dictionary<Difficulty, array<String^>^>^>^ InitializeWordBanks()
        {
            auto banks = gcnew Dictionary<Topic, Dictionary<Difficulty, array<String^>^>^>();

            // Animals topic
            auto animals = gcnew Dictionary<Difficulty, array<String^>^>();
            animals[Difficulty::Easy] = gcnew array<String^> {"CAT", "DOG", "COW", "PIG", "RAT", "BAT", "FOX", "OWL", "BEE", "ANT"};
            animals[Difficulty::Medium] = gcnew array<String^> {"LION", "BEAR", "FROG", "DEER", "GOAT", "DUCK", "WOLF", "FISH", "CRAB", "SWAN"};
            animals[Difficulty::Hard] = gcnew array<String^> {"TIGER", "EAGLE", "ZEBRA", "HIPPO", "PANDA", "KOALA", "OTTER", "RHINO", "LLAMA", "QUAIL"};
            banks[Topic::Animals] = animals;

            // Food topic
            auto food = gcnew Dictionary<Difficulty, array<String^>^>();
            food[Difficulty::Easy] = gcnew array<String^> {"EGG", "PIE", "TEA", "HAM", "OIL", "FIG", "PEA", "JAM", "NUT", "RYE"};
            food[Difficulty::Medium] = gcnew array<String^> {"APPLE", "BREAD", "CHEESE", "DONUT", "GRAPE", "HONEY", "LEMON", "ONION", "PIZZA", "SALAD"};
            food[Difficulty::Hard] = gcnew array<String^> {"AVOCADO", "BANANA", "CARROT", "DURIAN", "EGGPLANT", "FALAFEL", "GUAVA", "JICAMA", "KALE", "LASAGNA"};
            banks[Topic::Food] = food;

            // Countries topic
            auto countries = gcnew Dictionary<Difficulty, array<String^>^>();
            countries[Difficulty::Easy] = gcnew array<String^> {"USA", "UK", "CAN", "MEX", "JPN", "FRA", "GER", "ITA", "CHN", "IND"};
            countries[Difficulty::Medium] = gcnew array<String^> {"BRAZIL", "EGYPT", "GREECE", "ISRAEL", "KENYA", "NEPAL", "QATAR", "SPAIN", "SWEDEN", "TURKEY"};
            countries[Difficulty::Hard] = gcnew array<String^> {"ARGENTINA", "BANGLADESH", "COLOMBIA", "DOMINICA", "ETHIOPIA", "GUATEMALA", "KAZAKHSTAN", "MONGOLIA", "PHILIPPINES", "VENEZUELA"};
            banks[Topic::Countries] = countries;

            // Sports topic
            auto sports = gcnew Dictionary<Difficulty, array<String^>^>();
            sports[Difficulty::Easy] = gcnew array<String^> {"RUN", "GOLF", "TENNIS", "SWIM", "BIKE", "SKI", "JOG", "DART", "ROW", "JUDO"};
            sports[Difficulty::Medium] = gcnew array<String^> {"SOCCER", "HOCKEY", "BOXING", "BOWLING", "SURFING", "FENCING", "KARATE", "VOLLEY", "CURLING", "ARCHERY"};
            sports[Difficulty::Hard] = gcnew array<String^> {"BADMINTON", "BASEBALL", "BASKETBALL", "FOOTBALL", "GOLFING", "HANDBALL", "LACROSSE", "RUGBY", "SKATEBOARD", "SNOWBOARD"};
            banks[Topic::Sports] = sports;

            // Random topic (mix of all topics)
            auto random = gcnew Dictionary<Difficulty, array<String^>^>();
            random[Difficulty::Easy] = gcnew array<String^> {"CAT", "DOG", "EGG", "PIE", "USA", "UK", "RUN", "GOLF", "TEA", "JAM"};
            random[Difficulty::Medium] = gcnew array<String^> {"APPLE", "BREAD", "BRAZIL", "EGYPT", "SOCCER", "HOCKEY", "LION", "BEAR", "CHEESE", "DONUT"};
            random[Difficulty::Hard] = gcnew array<String^> {"AVOCADO", "BANANA", "ARGENTINA", "BANGLADESH", "BADMINTON", "BASEBALL", "TIGER", "EAGLE", "EGGPLANT", "FALAFEL"};
            banks[Topic::Random] = random;

            return banks;
        }

    public:
        void Exit(System::Object^ sender, System::EventArgs^ e) override
        {
            this->settings->StopAxWMP(BGMusic);
            // Close the application when the Exit button is clicked  
            this->Close();
        }

    private:
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game1::typeid));
            this->HighestScore = (gcnew System::Windows::Forms::Label());
            this->Rank = (gcnew System::Windows::Forms::Label());
            this->GameStart = (gcnew System::Windows::Forms::Button());
            this->Test = (gcnew System::Windows::Forms::TextBox());
            this->Score = (gcnew System::Windows::Forms::Label());
            this->GameAns = (gcnew System::Windows::Forms::Panel());
            this->ExitBtn = (gcnew System::Windows::Forms::Button());
            this->RulesButton = (gcnew System::Windows::Forms::Button());
            this->countdownTimer = (gcnew System::Windows::Forms::Timer(this->components));
            this->countdownLabel = (gcnew System::Windows::Forms::Label());
            this->SubmitGuessButton = (gcnew System::Windows::Forms::Button());
            this->AttemptsLabel = (gcnew System::Windows::Forms::Label());
            this->HintButton = (gcnew System::Windows::Forms::Button());
            this->difficultyComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->topicComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->difficultyLabel = (gcnew System::Windows::Forms::Label());
            this->topicLabel = (gcnew System::Windows::Forms::Label());
            this->BGMusic = (gcnew AxWMPLib::AxWindowsMediaPlayer());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->BeginInit();
            this->SuspendLayout();

            // HighestScore
            this->HighestScore->AutoSize = true;
            this->HighestScore->BackColor = System::Drawing::Color::Transparent;
            this->HighestScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->HighestScore->ForeColor = System::Drawing::Color::Transparent;
            this->HighestScore->Location = System::Drawing::Point(400, 100);
            this->HighestScore->Name = L"HighestScore";
            this->HighestScore->Size = System::Drawing::Size(127, 20);
            this->HighestScore->TabIndex = 15;
            this->HighestScore->Text = L"Highest Score: 0";

            // Rank
            this->Rank->AutoSize = true;
            this->Rank->BackColor = System::Drawing::Color::Transparent;
            this->Rank->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->Rank->ForeColor = System::Drawing::Color::Transparent;
            this->Rank->Location = System::Drawing::Point(400, 150);
            this->Rank->Name = L"Rank";
            this->Rank->Size = System::Drawing::Size(64, 20);
            this->Rank->TabIndex = 16;
            this->Rank->Text = L"Rank: 0";

            // GameStart
            this->GameStart->ForeColor = System::Drawing::Color::Coral;
            this->GameStart->Location = System::Drawing::Point(223, 91);
            this->GameStart->Name = L"GameStart";
            this->GameStart->Size = System::Drawing::Size(100, 30);
            this->GameStart->TabIndex = 0;
            this->GameStart->Text = L"Play";
            this->GameStart->Click += gcnew System::EventHandler(this, &Game1::StartGame);

            // Test
            this->Test->Enabled = false;
            this->Test->Location = System::Drawing::Point(223, 219);
            this->Test->Name = L"Test";
            this->Test->Size = System::Drawing::Size(100, 20);
            this->Test->TabIndex = 1;

            // Score
            this->Score->Location = System::Drawing::Point(100, 50);
            this->Score->Name = L"Score";
            this->Score->Size = System::Drawing::Size(100, 30);
            this->Score->TabIndex = 2;
            this->Score->Text = L"Score: 0";

            // GameAns
            this->GameAns->Location = System::Drawing::Point(175, 142);
            this->GameAns->Name = L"GameAns";
            this->GameAns->Size = System::Drawing::Size(200, 50);
            this->GameAns->TabIndex = 3;

            // ExitBtn
            this->ExitBtn->BackColor = System::Drawing::Color::Crimson;
            this->ExitBtn->Location = System::Drawing::Point(223, 363);
            this->ExitBtn->Name = L"Exit";
            this->ExitBtn->Size = System::Drawing::Size(100, 30);
            this->ExitBtn->TabIndex = 4;
            this->ExitBtn->Text = L"Exit";
            this->ExitBtn->UseVisualStyleBackColor = false;
            this->ExitBtn->Click += gcnew System::EventHandler(this, &Game1::Exit);

            // RulesButton
            this->RulesButton->ForeColor = System::Drawing::Color::Coral;
            this->RulesButton->Location = System::Drawing::Point(223, 311);
            this->RulesButton->Name = L"RulesButton";
            this->RulesButton->Size = System::Drawing::Size(100, 30);
            this->RulesButton->TabIndex = 5;
            this->RulesButton->Text = L"Game Rules";
            this->RulesButton->Click += gcnew System::EventHandler(this, &Game1::ShowRules);

            // countdownTimer
            this->countdownTimer->Interval = 1000;
            this->countdownTimer->Tick += gcnew System::EventHandler(this, &Game1::OnCountdownTick);

            // countdownLabel
            this->countdownLabel->Location = System::Drawing::Point(10, 10);
            this->countdownLabel->Name = L"countdownLabel";
            this->countdownLabel->Size = System::Drawing::Size(100, 30);
            this->countdownLabel->TabIndex = 7;
            this->countdownLabel->Text = L"Time: 0";

            // SubmitGuessButton
            this->SubmitGuessButton->Enabled = false;
            this->SubmitGuessButton->ForeColor = System::Drawing::Color::Coral;
            this->SubmitGuessButton->Location = System::Drawing::Point(223, 259);
            this->SubmitGuessButton->Name = L"SubmitGuessButton";
            this->SubmitGuessButton->Size = System::Drawing::Size(100, 30);
            this->SubmitGuessButton->TabIndex = 6;
            this->SubmitGuessButton->Text = L"Submit Guess";
            this->SubmitGuessButton->Click += gcnew System::EventHandler(this, &Game1::SubmitGuess_Click);

            // AttemptsLabel
            this->AttemptsLabel->Location = System::Drawing::Point(400, 50);
            this->AttemptsLabel->Name = L"AttemptsLabel";
            this->AttemptsLabel->Size = System::Drawing::Size(100, 30);
            this->AttemptsLabel->TabIndex = 9;
            this->AttemptsLabel->Text = L"Attempts: 0";

            // HintButton
            this->HintButton->ForeColor = System::Drawing::Color::DarkGreen;
            this->HintButton->Location = System::Drawing::Point(350, 259);
            this->HintButton->Name = L"HintButton";
            this->HintButton->Size = System::Drawing::Size(100, 30);
            this->HintButton->TabIndex = 10;
            this->HintButton->Text = L"Hint";
            this->HintButton->Click += gcnew System::EventHandler(this, &Game1::HintButton_Click);

            // difficultyComboBox
            this->difficultyComboBox->FormattingEnabled = true;
            this->difficultyComboBox->Items->AddRange(gcnew array<String^> { "Easy", "Medium", "Hard" });
            this->difficultyComboBox->Location = System::Drawing::Point(100, 100);
            this->difficultyComboBox->Name = L"difficultyComboBox";
            this->difficultyComboBox->Size = System::Drawing::Size(100, 21);
            this->difficultyComboBox->TabIndex = 17;
            this->difficultyComboBox->SelectedIndex = 1; // Default to Medium

            // topicComboBox
            this->topicComboBox->FormattingEnabled = true;
            this->topicComboBox->Items->AddRange(gcnew array<String^> { "Animals", "Food", "Countries", "Sports", "Random" });
            this->topicComboBox->Location = System::Drawing::Point(100, 150);
            this->topicComboBox->Name = L"topicComboBox";
            this->topicComboBox->Size = System::Drawing::Size(100, 21);
            this->topicComboBox->TabIndex = 18;
            this->topicComboBox->SelectedIndex = 4; // Default to Random

            // difficultyLabel
            this->difficultyLabel->AutoSize = true;
            this->difficultyLabel->Location = System::Drawing::Point(100, 80);
            this->difficultyLabel->Name = L"difficultyLabel";
            this->difficultyLabel->Size = System::Drawing::Size(52, 13);
            this->difficultyLabel->TabIndex = 19;
            this->difficultyLabel->Text = L"Difficulty:";

            // topicLabel
            this->topicLabel->AutoSize = true;
            this->topicLabel->Location = System::Drawing::Point(100, 130);
            this->topicLabel->Name = L"topicLabel";
            this->topicLabel->Size = System::Drawing::Size(36, 13);
            this->topicLabel->TabIndex = 20;
            this->topicLabel->Text = L"Topic:";

            // BGMusic
            this->BGMusic->Enabled = true;
            this->BGMusic->Location = System::Drawing::Point(518, 0);
            this->BGMusic->Name = L"BGMusic";
            this->BGMusic->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"BGMusic.OcxState")));
            this->BGMusic->Size = System::Drawing::Size(75, 23);
            this->BGMusic->TabIndex = 8;
            this->BGMusic->Visible = false;

            // Game1
            this->BackColor = System::Drawing::Color::Cornsilk;
            this->ClientSize = System::Drawing::Size(594, 487);
            this->Controls->Add(this->topicLabel);
            this->Controls->Add(this->difficultyLabel);
            this->Controls->Add(this->topicComboBox);
            this->Controls->Add(this->difficultyComboBox);
            this->Controls->Add(this->AttemptsLabel);
            this->Controls->Add(this->BGMusic);
            this->Controls->Add(this->GameStart);
            this->Controls->Add(this->Test);
            this->Controls->Add(this->Score);
            this->Controls->Add(this->GameAns);
            this->Controls->Add(this->ExitBtn);
            this->Controls->Add(this->RulesButton);
            this->Controls->Add(this->SubmitGuessButton);
            this->Controls->Add(this->countdownLabel);
            this->Controls->Add(this->HintButton);
            this->Controls->Add(this->HighestScore);
            this->Controls->Add(this->Rank);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Game1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Load += gcnew System::EventHandler(this, &Game1::Render);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BGMusic))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    public:
        void Render(Object^ sender, EventArgs^ e) override
        {
            this->settings = gcnew SettingManager();
            this->settings->Game1_Music(BGMusic);
            userLoading(this->uname);
            this->HighestScore->Text = "Highest Score: " + this->UserLogged->getS1();
            loadAllUser(1);
            this->Rank->Text = "Rank: " + getRank(UserLogged->username);
        }

    private:
        void Test_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
            if (e->KeyCode == Keys::Enter && gameActive) {
                e->SuppressKeyPress = true; // Prevent the ding sound
                // Call the same method as the Submit button
                SubmitGuess_Click(sender, e);
            }
        }

        void HideAllElements()
        {
            // Hide all elements except the Start Game button and settings
            this->Test->Visible = false;
            this->Score->Visible = false;
            this->GameAns->Visible = false;
            this->ExitBtn->Visible = false;
            this->RulesButton->Visible = false;
            this->countdownLabel->Visible = false;
            this->SubmitGuessButton->Visible = false;
            this->AttemptsLabel->Visible = false;
            this->HighestScore->Visible = false;
            this->Rank->Visible = false;
            this->HintButton->Visible = false;

            // Show difficulty and topic selectors
            this->difficultyComboBox->Visible = true;
            this->topicComboBox->Visible = true;
            this->difficultyLabel->Visible = true;
            this->topicLabel->Visible = true;

            // Center the Start Game button
            this->GameStart->Location = System::Drawing::Point(
                (this->ClientSize.Width - this->GameStart->Width) / 2,
                (this->ClientSize.Height - this->GameStart->Height) / 2);
            this->GameStart->Text = L"Start Game";
        }

        void ShowAllElements()
        {
            // Show all elements
            this->Test->Visible = true;
            this->Score->Visible = true;
            this->GameAns->Visible = true;
            this->ExitBtn->Visible = true;
            this->RulesButton->Visible = true;
            this->countdownLabel->Visible = true;
            this->SubmitGuessButton->Visible = true;
            this->AttemptsLabel->Visible = true;
            this->HighestScore->Visible = true;
            this->Rank->Visible = true;
            this->HintButton->Visible = true;

            // Hide difficulty and topic selectors during game
            this->difficultyComboBox->Visible = false;
            this->topicComboBox->Visible = false;
            this->difficultyLabel->Visible = false;
            this->topicLabel->Visible = false;

            // Reset positions to original layout
            this->GameStart->Location = System::Drawing::Point(223, 91);
            this->Test->Location = System::Drawing::Point(223, 219);
            this->Score->Location = System::Drawing::Point(100, 50);
            this->GameAns->Location = System::Drawing::Point(175, 142);
            this->ExitBtn->Location = System::Drawing::Point(223, 363);
            this->RulesButton->Location = System::Drawing::Point(223, 311);
            this->countdownLabel->Location = System::Drawing::Point(10, 10);
            this->SubmitGuessButton->Location = System::Drawing::Point(223, 259);
            this->AttemptsLabel->Location = System::Drawing::Point(400, 50);

            // Change text to "Replay"
            this->GameStart->Text = L"Replay";
        }

        void StartGame(System::Object^ sender, System::EventArgs^ e)
        {
            // Get selected difficulty and topic
            currentDifficulty = static_cast<Difficulty>(difficultyComboBox->SelectedIndex);
            currentTopic = static_cast<Topic>(topicComboBox->SelectedIndex);

            ShowAllElements(); // Show all elements when game starts
            this->gameActive = true;
            this->GameStart->Enabled = false;
            this->Test->Enabled = true;
            this->Test->Focus();
            this->SubmitGuessButton->Enabled = true;
            this->score = 0;

            // Set attempts based on difficulty
            switch (currentDifficulty) {
            case Difficulty::Easy:
                attemptsLeft = 8;
                StartCountdown(90); // 90 seconds for easy
                break;
            case Difficulty::Medium:
                attemptsLeft = 6;
                StartCountdown(60); // 60 seconds for medium
                break;
            case Difficulty::Hard:
                attemptsLeft = 4;
                StartCountdown(45); // 45 seconds for hard
                break;
            }

            this->Score->Text = "Score: 0";
            this->AttemptsLabel->Text = "Attempts: " + attemptsLeft.ToString();
            this->Test->Clear();
            SelectRandomWord();
        }

        void SelectRandomWord()
        {
            try {
                Random^ rand = gcnew Random();

                // Get the word bank for selected topic and difficulty
                array<String^>^ words = wordBanks[currentTopic][currentDifficulty];

                // Select a random word
                int index = rand->Next(words->Length);
                StartGameWithWord(words[index]);
            }
            catch (Exception^ ex) {
                // Fallback to default words if something goes wrong
                MessageBox::Show("Error selecting word. Using default word.", "Error");
                StartGameWithWord("DEFAULT");
            }
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
            this->Test->Focus();
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

    public:
        System::Void scoreUpdating(int score) override
        {
            this->UserLogged->setS1(score);
        }

    private:
        void EndGame(bool won)
        {
            this->gameActive = false;
            this->countdownTimer->Stop();
            this->GameStart->Enabled = true;
            this->Test->Enabled = false;
            this->SubmitGuessButton->Enabled = false;

            if (won)
            {
                // Bonus points based on remaining time and attempts
                int timeBonus = remainingTime * 2;
                int attemptsBonus = attemptsLeft * 5;
                score += timeBonus + attemptsBonus;

                this->Score->Text = "Score: " + score.ToString();
                MessageBox::Show("Congratulations! You guessed the word: " + this->secretWord +
                    "\nTime Bonus: +" + timeBonus +
                    "\nAttempts Bonus: +" + attemptsBonus,
                    "You Win!");

                // Update high score if current score is higher
                if (score > this->UserLogged->getS1()) {
                    scoreUpdating(score);
                    userSaving(this->UserLogged);
                }
            }
            else
            {
                MessageBox::Show("Game Over! The word was: " + this->secretWord, "Try Again");
            }

            // Show difficulty and topic selectors again
            this->difficultyComboBox->Visible = true;
            this->topicComboBox->Visible = true;
            this->difficultyLabel->Visible = true;
            this->topicLabel->Visible = true;
        }

        void ShowRules(System::Object^ sender, System::EventArgs^ e)
        {
            String^ rules = "Word Guessing Game Rules:\n\n"
                "1. Select a topic and difficulty level\n"
                "2. A random word will be selected based on your choices\n"
                "3. You have limited attempts to guess the word:\n"
                "   - Easy: 8 attempts, 90 seconds\n"
                "   - Medium: 6 attempts, 60 seconds\n"
                "   - Hard: 4 attempts, 45 seconds\n"
                "4. Each attempt must be the same length as the secret word\n"
                "5. Correct letters will be revealed in their positions\n"
                "6. You earn 10 points for each correct letter\n"
                "7. Bonus points for remaining time and attempts when you win\n"
                "8. The game ends when you guess the word or run out of attempts/time";
            MessageBox::Show(rules, "Game Rules");
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
                if (score > this->UserLogged->getS1()) {
                    scoreUpdating(score);
                }
                userSaving(this->UserLogged);
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

    private:
        System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
        }
    };
}
