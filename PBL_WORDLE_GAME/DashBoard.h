#pragma once
#include "fstream"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "User.h"
#include "Delete_Acc.h"
#include "CryptoUtils.h"
#include "ChangePass.h"

using namespace System;
using namespace System::Media;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for DashBoard
	/// </summary>
	public ref class DashBoard : public System::Windows::Forms::UserControl
	{
	private: System::String^ usrname;
	private: System::String^ usrPwd;
	public:
		public: SoundPlayer^ bgMusic;
		public: SoundPlayer^ clickTrack;
	private: System::Windows::Forms::Label^ DelAcc;
	public:
		event EventHandler^ goBack;
		event EventHandler^ enterGame;
		public: User^ UserLogged;
		event EventHandler^ backDashBoard;
		DashBoard(System::String^ usr)
		{
			InitializeComponent();
			this->usrName->Text = usr;
			this->usrname = usr;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DashBoard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ dashboardLayout;
	protected:

	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::FlowLayoutPanel^ playerInfo;

	private: System::Windows::Forms::PictureBox^ avtBox;
	private: System::Windows::Forms::Label^ usrName;
	private: System::Windows::Forms::Label^ changePass;
	private: System::Windows::Forms::Label^ setting;
	private: System::Windows::Forms::Label^ logOut;
	private: System::Windows::Forms::Label^ listTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ GameContainer;
	private: System::Windows::Forms::FlowLayoutPanel^ Game1Panel;
	private: System::Windows::Forms::Label^ GameTitle1;
	private: System::Windows::Forms::Label^ GameName1;
	private: System::Windows::Forms::Button^ Game1Btn;
	private: System::Windows::Forms::FlowLayoutPanel^ Game2Panel;
	private: System::Windows::Forms::Label^ GameTitle2;
	private: System::Windows::Forms::Label^ GameName2;
	private: System::Windows::Forms::FlowLayoutPanel^ Game3Panel;
	private: System::Windows::Forms::Button^ GameBtn2;
	private: System::Windows::Forms::Label^ GameTitle3;
	private: System::Windows::Forms::Label^ GameName3;
	private: System::Windows::Forms::Button^ GameBtn3;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DashBoard::typeid));
			this->dashboardLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->playerInfo = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->avtBox = (gcnew System::Windows::Forms::PictureBox());
			this->usrName = (gcnew System::Windows::Forms::Label());
			this->changePass = (gcnew System::Windows::Forms::Label());
			this->setting = (gcnew System::Windows::Forms::Label());
			this->DelAcc = (gcnew System::Windows::Forms::Label());
			this->logOut = (gcnew System::Windows::Forms::Label());
			this->GameContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->listTitle = (gcnew System::Windows::Forms::Label());
			this->Game1Panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GameTitle1 = (gcnew System::Windows::Forms::Label());
			this->GameName1 = (gcnew System::Windows::Forms::Label());
			this->Game1Btn = (gcnew System::Windows::Forms::Button());
			this->Game2Panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GameTitle2 = (gcnew System::Windows::Forms::Label());
			this->GameName2 = (gcnew System::Windows::Forms::Label());
			this->GameBtn2 = (gcnew System::Windows::Forms::Button());
			this->Game3Panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GameTitle3 = (gcnew System::Windows::Forms::Label());
			this->GameName3 = (gcnew System::Windows::Forms::Label());
			this->GameBtn3 = (gcnew System::Windows::Forms::Button());
			this->dashboardLayout->SuspendLayout();
			this->playerInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->BeginInit();
			this->GameContainer->SuspendLayout();
			this->Game1Panel->SuspendLayout();
			this->Game2Panel->SuspendLayout();
			this->Game3Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// dashboardLayout
			// 
			this->dashboardLayout->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->dashboardLayout->BackColor = System::Drawing::Color::Transparent;
			this->dashboardLayout->ColumnCount = 2;
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20.33248F)));
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				79.66752F)));
			this->dashboardLayout->Controls->Add(this->Title, 1, 0);
			this->dashboardLayout->Controls->Add(this->playerInfo, 0, 1);
			this->dashboardLayout->Controls->Add(this->GameContainer, 1, 1);
			this->dashboardLayout->Location = System::Drawing::Point(0, 0);
			this->dashboardLayout->Name = L"dashboardLayout";
			this->dashboardLayout->RowCount = 2;
			this->dashboardLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.8915F)));
			this->dashboardLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80.1085F)));
			this->dashboardLayout->Size = System::Drawing::Size(782, 553);
			this->dashboardLayout->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Bold));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(268, 28);
			this->Title->Margin = System::Windows::Forms::Padding(110, 0, 3, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(280, 54);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Dash Board";
			// 
			// playerInfo
			// 
			this->playerInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->playerInfo->Controls->Add(this->avtBox);
			this->playerInfo->Controls->Add(this->usrName);
			this->playerInfo->Controls->Add(this->changePass);
			this->playerInfo->Controls->Add(this->setting);
			this->playerInfo->Controls->Add(this->DelAcc);
			this->playerInfo->Controls->Add(this->logOut);
			this->playerInfo->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->playerInfo->Location = System::Drawing::Point(3, 113);
			this->playerInfo->Name = L"playerInfo";
			this->playerInfo->Size = System::Drawing::Size(152, 437);
			this->playerInfo->TabIndex = 1;
			// 
			// avtBox
			// 
			this->avtBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->avtBox->BackColor = System::Drawing::Color::Transparent;
			this->avtBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"avtBox.Image")));
			this->avtBox->Location = System::Drawing::Point(25, 15);
			this->avtBox->Margin = System::Windows::Forms::Padding(25, 15, 3, 3);
			this->avtBox->Name = L"avtBox";
			this->avtBox->Size = System::Drawing::Size(100, 100);
			this->avtBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->avtBox->TabIndex = 2;
			this->avtBox->TabStop = false;
			// 
			// usrName
			// 
			this->usrName->AutoSize = true;
			this->usrName->BackColor = System::Drawing::Color::Transparent;
			this->usrName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usrName->ForeColor = System::Drawing::Color::White;
			this->usrName->Location = System::Drawing::Point(20, 128);
			this->usrName->Margin = System::Windows::Forms::Padding(20, 10, 0, 10);
			this->usrName->Name = L"usrName";
			this->usrName->Size = System::Drawing::Size(0, 25);
			this->usrName->TabIndex = 2;
			// 
			// changePass
			// 
			this->changePass->AutoSize = true;
			this->changePass->BackColor = System::Drawing::Color::Transparent;
			this->changePass->Cursor = System::Windows::Forms::Cursors::Hand;
			this->changePass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->changePass->ForeColor = System::Drawing::Color::White;
			this->changePass->Location = System::Drawing::Point(20, 173);
			this->changePass->Margin = System::Windows::Forms::Padding(20, 10, 0, 10);
			this->changePass->Name = L"changePass";
			this->changePass->Size = System::Drawing::Size(98, 50);
			this->changePass->TabIndex = 2;
			this->changePass->Text = L"Change Password";
			this->changePass->Click += gcnew System::EventHandler(this, &DashBoard::passChanging);
			// 
			// setting
			// 
			this->setting->AutoSize = true;
			this->setting->BackColor = System::Drawing::Color::Transparent;
			this->setting->Cursor = System::Windows::Forms::Cursors::Hand;
			this->setting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->setting->ForeColor = System::Drawing::Color::White;
			this->setting->Location = System::Drawing::Point(20, 243);
			this->setting->Margin = System::Windows::Forms::Padding(20, 10, 0, 10);
			this->setting->Name = L"setting";
			this->setting->Size = System::Drawing::Size(73, 25);
			this->setting->TabIndex = 2;
			this->setting->Text = L"Setting";
			// 
			// DelAcc
			// 
			this->DelAcc->AutoSize = true;
			this->DelAcc->BackColor = System::Drawing::Color::Transparent;
			this->DelAcc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DelAcc->ForeColor = System::Drawing::Color::White;
			this->DelAcc->Location = System::Drawing::Point(22, 288);
			this->DelAcc->Margin = System::Windows::Forms::Padding(22, 10, 3, 10);
			this->DelAcc->Name = L"DelAcc";
			this->DelAcc->Size = System::Drawing::Size(84, 50);
			this->DelAcc->TabIndex = 3;
			this->DelAcc->Text = L"Delete Account";
			this->DelAcc->Click += gcnew System::EventHandler(this, &DashBoard::AccountDelete);
			// 
			// logOut
			// 
			this->logOut->AutoSize = true;
			this->logOut->BackColor = System::Drawing::Color::Transparent;
			this->logOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->logOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logOut->ForeColor = System::Drawing::Color::White;
			this->logOut->Location = System::Drawing::Point(20, 358);
			this->logOut->Margin = System::Windows::Forms::Padding(20, 10, 0, 10);
			this->logOut->Name = L"logOut";
			this->logOut->Size = System::Drawing::Size(82, 25);
			this->logOut->TabIndex = 2;
			this->logOut->Text = L"Log Out";
			this->logOut->Click += gcnew System::EventHandler(this, &DashBoard::backToLanding);
			// 
			// GameContainer
			// 
			this->GameContainer->Controls->Add(this->listTitle);
			this->GameContainer->Controls->Add(this->Game1Panel);
			this->GameContainer->Controls->Add(this->Game2Panel);
			this->GameContainer->Controls->Add(this->Game3Panel);
			this->GameContainer->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->GameContainer->Location = System::Drawing::Point(161, 113);
			this->GameContainer->Name = L"GameContainer";
			this->GameContainer->Size = System::Drawing::Size(618, 437);
			this->GameContainer->TabIndex = 3;
			// 
			// listTitle
			// 
			this->listTitle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->listTitle->AutoSize = true;
			this->listTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listTitle->ForeColor = System::Drawing::Color::White;
			this->listTitle->Location = System::Drawing::Point(223, 10);
			this->listTitle->Margin = System::Windows::Forms::Padding(0, 10, 3, 0);
			this->listTitle->Name = L"listTitle";
			this->listTitle->Size = System::Drawing::Size(171, 39);
			this->listTitle->TabIndex = 2;
			this->listTitle->Text = L"Game List";
			// 
			// Game1Panel
			// 
			this->Game1Panel->Controls->Add(this->GameTitle1);
			this->Game1Panel->Controls->Add(this->GameName1);
			this->Game1Panel->Controls->Add(this->Game1Btn);
			this->Game1Panel->Location = System::Drawing::Point(3, 52);
			this->Game1Panel->Name = L"Game1Panel";
			this->Game1Panel->Size = System::Drawing::Size(615, 112);
			this->Game1Panel->TabIndex = 3;
			// 
			// GameTitle1
			// 
			this->GameTitle1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameTitle1->AutoSize = true;
			this->GameTitle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameTitle1->ForeColor = System::Drawing::Color::White;
			this->GameTitle1->Location = System::Drawing::Point(10, 30);
			this->GameTitle1->Margin = System::Windows::Forms::Padding(10, 30, 3, 0);
			this->GameTitle1->Name = L"GameTitle1";
			this->GameTitle1->Size = System::Drawing::Size(150, 46);
			this->GameTitle1->TabIndex = 0;
			this->GameTitle1->Text = L"Game1";
			// 
			// GameName1
			// 
			this->GameName1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameName1->AutoSize = true;
			this->GameName1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameName1->ForeColor = System::Drawing::Color::White;
			this->GameName1->Location = System::Drawing::Point(178, 33);
			this->GameName1->Margin = System::Windows::Forms::Padding(15, 30, 3, 0);
			this->GameName1->Name = L"GameName1";
			this->GameName1->Size = System::Drawing::Size(237, 39);
			this->GameName1->TabIndex = 1;
			this->GameName1->Text = L"Game Name 1";
			// 
			// Game1Btn
			// 
			this->Game1Btn->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Game1Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Game1Btn->Location = System::Drawing::Point(438, 31);
			this->Game1Btn->Margin = System::Windows::Forms::Padding(20, 30, 3, 3);
			this->Game1Btn->Name = L"Game1Btn";
			this->Game1Btn->Size = System::Drawing::Size(100, 40);
			this->Game1Btn->TabIndex = 2;
			this->Game1Btn->Text = L"Start";
			this->Game1Btn->UseVisualStyleBackColor = true;
			this->Game1Btn->Click += gcnew System::EventHandler(this, &DashBoard::openGame1);
			// 
			// Game2Panel
			// 
			this->Game2Panel->Controls->Add(this->GameTitle2);
			this->Game2Panel->Controls->Add(this->GameName2);
			this->Game2Panel->Controls->Add(this->GameBtn2);
			this->Game2Panel->Location = System::Drawing::Point(3, 170);
			this->Game2Panel->Name = L"Game2Panel";
			this->Game2Panel->Size = System::Drawing::Size(615, 108);
			this->Game2Panel->TabIndex = 4;
			// 
			// GameTitle2
			// 
			this->GameTitle2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameTitle2->AutoSize = true;
			this->GameTitle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameTitle2->ForeColor = System::Drawing::Color::White;
			this->GameTitle2->Location = System::Drawing::Point(10, 30);
			this->GameTitle2->Margin = System::Windows::Forms::Padding(10, 30, 3, 0);
			this->GameTitle2->Name = L"GameTitle2";
			this->GameTitle2->Size = System::Drawing::Size(150, 46);
			this->GameTitle2->TabIndex = 0;
			this->GameTitle2->Text = L"Game2";
			// 
			// GameName2
			// 
			this->GameName2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameName2->AutoSize = true;
			this->GameName2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameName2->ForeColor = System::Drawing::Color::White;
			this->GameName2->Location = System::Drawing::Point(178, 33);
			this->GameName2->Margin = System::Windows::Forms::Padding(15, 30, 3, 0);
			this->GameName2->Name = L"GameName2";
			this->GameName2->Size = System::Drawing::Size(237, 39);
			this->GameName2->TabIndex = 1;
			this->GameName2->Text = L"Game Name 2";
			// 
			// GameBtn2
			// 
			this->GameBtn2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameBtn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameBtn2->Location = System::Drawing::Point(438, 31);
			this->GameBtn2->Margin = System::Windows::Forms::Padding(20, 30, 3, 3);
			this->GameBtn2->Name = L"GameBtn2";
			this->GameBtn2->Size = System::Drawing::Size(100, 40);
			this->GameBtn2->TabIndex = 2;
			this->GameBtn2->Text = L"Start";
			this->GameBtn2->UseVisualStyleBackColor = true;
			this->GameBtn2->Click += gcnew System::EventHandler(this, &DashBoard::openGame2);
			// 
			// Game3Panel
			// 
			this->Game3Panel->Controls->Add(this->GameTitle3);
			this->Game3Panel->Controls->Add(this->GameName3);
			this->Game3Panel->Controls->Add(this->GameBtn3);
			this->Game3Panel->Location = System::Drawing::Point(3, 284);
			this->Game3Panel->Name = L"Game3Panel";
			this->Game3Panel->Size = System::Drawing::Size(615, 115);
			this->Game3Panel->TabIndex = 5;
			// 
			// GameTitle3
			// 
			this->GameTitle3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameTitle3->AutoSize = true;
			this->GameTitle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameTitle3->ForeColor = System::Drawing::Color::White;
			this->GameTitle3->Location = System::Drawing::Point(10, 30);
			this->GameTitle3->Margin = System::Windows::Forms::Padding(10, 30, 3, 0);
			this->GameTitle3->Name = L"GameTitle3";
			this->GameTitle3->Size = System::Drawing::Size(150, 46);
			this->GameTitle3->TabIndex = 0;
			this->GameTitle3->Text = L"Game3";
			// 
			// GameName3
			// 
			this->GameName3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameName3->AutoSize = true;
			this->GameName3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameName3->ForeColor = System::Drawing::Color::White;
			this->GameName3->Location = System::Drawing::Point(178, 33);
			this->GameName3->Margin = System::Windows::Forms::Padding(15, 30, 3, 0);
			this->GameName3->Name = L"GameName3";
			this->GameName3->Size = System::Drawing::Size(237, 39);
			this->GameName3->TabIndex = 1;
			this->GameName3->Text = L"Game Name 3";
			// 
			// GameBtn3
			// 
			this->GameBtn3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GameBtn3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GameBtn3->Location = System::Drawing::Point(438, 31);
			this->GameBtn3->Margin = System::Windows::Forms::Padding(20, 30, 3, 3);
			this->GameBtn3->Name = L"GameBtn3";
			this->GameBtn3->Size = System::Drawing::Size(100, 40);
			this->GameBtn3->TabIndex = 2;
			this->GameBtn3->Text = L"Start";
			this->GameBtn3->UseVisualStyleBackColor = true;
			this->GameBtn3->Click += gcnew System::EventHandler(this, &DashBoard::GameBtn3_Click);
			// 
			// DashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->dashboardLayout);
			this->Name = L"DashBoard";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &DashBoard::DashBoard_Load);
			this->dashboardLayout->ResumeLayout(false);
			this->dashboardLayout->PerformLayout();
			this->playerInfo->ResumeLayout(false);
			this->playerInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->EndInit();
			this->GameContainer->ResumeLayout(false);
			this->GameContainer->PerformLayout();
			this->Game1Panel->ResumeLayout(false);
			this->Game1Panel->PerformLayout();
			this->Game2Panel->ResumeLayout(false);
			this->Game2Panel->PerformLayout();
			this->Game3Panel->ResumeLayout(false);
			this->Game3Panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void makeCircle(PictureBox^ pic) {
		GraphicsPath^ gp = gcnew GraphicsPath();
		gp->AddEllipse(0, 0, pic->Width, pic->Height);
		pic->Region = gcnew System::Drawing::Region(gp);
	}
	private: System::Void DashBoard_Load(System::Object^ sender, System::EventArgs^ e) {
		makeCircle(avtBox);
		LoadUser();
	}
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
	private: System::Void passChanging(System::Object^ sender, System::EventArgs^ e){
		ChangePass^ passPopup = gcnew ChangePass(this->UserLogged->getPwd());
		if (passPopup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->UserLogged->changePassword(passPopup->getPass());
		}
	}
	private: Void AccountDelete(Object^ sender, EventArgs^ e) {
		Delete_Acc^ delPopup = gcnew Delete_Acc(this->UserLogged->getPwd());
		if (delPopup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			UserLogged->deletAccount();
		}
		goBack(this, e);
	}
	private: Void LoadUser() {
		String^ encryptUser = CryptoUtils::ComputeSHA256(usrname);
		String^ userPath = "UserList\\" + encryptUser + ".txt";
		if (File::Exists(userPath)) {
			array<String^>^ lines = File::ReadAllLines(userPath);
			String^ decryptedPassword = CryptoUtils::DecryptAES(lines[2]);
			UserLogged = gcnew User(lines[1], decryptedPassword, Int32::Parse(lines[3]), Int32::Parse(lines[4]), Int32::Parse(lines[5]));
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void openGame1(System::Object^ sender, System::EventArgs^ e) {
		enterGame(this, e);
		Game1^ game1 = gcnew Game1(this->usrname);
		game1->ShowDialog();
		backDashBoard(this, e);
	}
	private: System::Void openGame2(System::Object^ sender, System::EventArgs^ e) {
		enterGame(this, e);
		Game2^ game2 = gcnew Game2(this->usrname);
		game2->ShowDialog();
		backDashBoard(this, e);
	}
	private: System::Void GameBtn3_Click(System::Object^ sender, System::EventArgs^ e) {
		Game3^ game3 = gcnew Game3(usrname);
		game3->ShowDialog();
	}
};
}
