#pragma once
#include "User.h"
#include "CryptoUtils.h"
#include "Admin.h"
#include <fstream>
#include "ChangePass.h"
using namespace System;
using namespace System::Media;
using namespace System::IO;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;


namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Dashboard_Admin
	/// </summary>
	public ref class Dashboard_Admin : public System::Windows::Forms::UserControl
	{
	public: SoundPlayer^ bgMusic;
	private: List<User^>^ userList;
	private: System::String^ uname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ usr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pwd;
	private: System::Windows::Forms::DataGridViewButtonColumn^ togglePwd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ s1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ s2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ s3;
	private: System::Windows::Forms::DataGridViewLinkColumn^ changePwd;
	private: System::Windows::Forms::DataGridViewButtonColumn^ deleteAcc;
	private: Admin^ admin;
	public: event EventHandler^ goBack;
	private: String^ newPass;
	public:
		Dashboard_Admin(System::String^ usrName)
		{
			InitializeComponent();
			this->uname = usrName;
			this->usrName->Text = this->uname;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard_Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ dashboardLayout;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ playerInfo;
	private: System::Windows::Forms::PictureBox^ avtBox;
	private: System::Windows::Forms::Label^ usrName;
	private: System::Windows::Forms::Label^ changePass;
	private: System::Windows::Forms::Label^ setting;
	private: System::Windows::Forms::Label^ logOut;
	private: System::Windows::Forms::DataGridView^ userTable;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard_Admin::typeid));
			this->dashboardLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->playerInfo = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->avtBox = (gcnew System::Windows::Forms::PictureBox());
			this->usrName = (gcnew System::Windows::Forms::Label());
			this->changePass = (gcnew System::Windows::Forms::Label());
			this->setting = (gcnew System::Windows::Forms::Label());
			this->logOut = (gcnew System::Windows::Forms::Label());
			this->userTable = (gcnew System::Windows::Forms::DataGridView());
			this->usr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pwd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->togglePwd = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->s1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->s2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->s3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->changePwd = (gcnew System::Windows::Forms::DataGridViewLinkColumn());
			this->deleteAcc = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->dashboardLayout->SuspendLayout();
			this->playerInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTable))->BeginInit();
			this->SuspendLayout();
			// 
			// dashboardLayout
			// 
			this->dashboardLayout->BackColor = System::Drawing::Color::Transparent;
			this->dashboardLayout->ColumnCount = 2;
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				17.00767F)));
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				82.99232F)));
			this->dashboardLayout->Controls->Add(this->label1, 1, 0);
			this->dashboardLayout->Controls->Add(this->playerInfo, 0, 1);
			this->dashboardLayout->Controls->Add(this->userTable, 1, 1);
			this->dashboardLayout->Location = System::Drawing::Point(0, 0);
			this->dashboardLayout->Name = L"dashboardLayout";
			this->dashboardLayout->RowCount = 2;
			this->dashboardLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.79566F)));
			this->dashboardLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 79.20434F)));
			this->dashboardLayout->Size = System::Drawing::Size(782, 553);
			this->dashboardLayout->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(252, 30);
			this->label1->Margin = System::Windows::Forms::Padding(120, 0, 3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 54);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dash Board";
			// 
			// playerInfo
			// 
			this->playerInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->playerInfo->Controls->Add(this->avtBox);
			this->playerInfo->Controls->Add(this->usrName);
			this->playerInfo->Controls->Add(this->changePass);
			this->playerInfo->Controls->Add(this->setting);
			this->playerInfo->Controls->Add(this->logOut);
			this->playerInfo->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->playerInfo->Location = System::Drawing::Point(3, 118);
			this->playerInfo->Name = L"playerInfo";
			this->playerInfo->Size = System::Drawing::Size(126, 432);
			this->playerInfo->TabIndex = 2;
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
			// logOut
			// 
			this->logOut->AutoSize = true;
			this->logOut->BackColor = System::Drawing::Color::Transparent;
			this->logOut->Cursor = System::Windows::Forms::Cursors::Hand;
			this->logOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logOut->ForeColor = System::Drawing::Color::White;
			this->logOut->Location = System::Drawing::Point(20, 288);
			this->logOut->Margin = System::Windows::Forms::Padding(20, 10, 0, 10);
			this->logOut->Name = L"logOut";
			this->logOut->Size = System::Drawing::Size(82, 25);
			this->logOut->TabIndex = 2;
			this->logOut->Text = L"Log Out";
			// 
			// userTable
			// 
			this->userTable->AllowUserToAddRows = false;
			this->userTable->AllowUserToDeleteRows = false;
			this->userTable->AllowUserToResizeColumns = false;
			this->userTable->AllowUserToResizeRows = false;
			this->userTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->userTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->usr, this->pwd,
					this->togglePwd, this->s1, this->s2, this->s3, this->changePwd, this->deleteAcc
			});
			this->userTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->userTable->Location = System::Drawing::Point(135, 118);
			this->userTable->Name = L"userTable";
			this->userTable->RowHeadersVisible = false;
			this->userTable->RowHeadersWidth = 51;
			this->userTable->RowTemplate->Height = 24;
			this->userTable->Size = System::Drawing::Size(644, 432);
			this->userTable->TabIndex = 3;
			this->userTable->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Dashboard_Admin::cellClick);
			// 
			// usr
			// 
			this->usr->HeaderText = L"Username";
			this->usr->MinimumWidth = 6;
			this->usr->Name = L"usr";
			this->usr->ReadOnly = true;
			this->usr->ToolTipText = L"Username";
			this->usr->Width = 74;
			// 
			// pwd
			// 
			this->pwd->HeaderText = L"Password";
			this->pwd->MinimumWidth = 6;
			this->pwd->Name = L"pwd";
			this->pwd->ReadOnly = true;
			this->pwd->ToolTipText = L"Password";
			this->pwd->Width = 70;
			// 
			// togglePwd
			// 
			this->togglePwd->HeaderText = L"Show";
			this->togglePwd->MinimumWidth = 6;
			this->togglePwd->Name = L"togglePwd";
			this->togglePwd->ReadOnly = true;
			this->togglePwd->Text = L"Show";
			this->togglePwd->ToolTipText = L"Show account password";
			this->togglePwd->Width = 50;
			// 
			// s1
			// 
			this->s1->HeaderText = L"Score1";
			this->s1->MinimumWidth = 6;
			this->s1->Name = L"s1";
			this->s1->ReadOnly = true;
			this->s1->ToolTipText = L"Game 1 score";
			this->s1->Width = 50;
			// 
			// s2
			// 
			this->s2->HeaderText = L"Score2";
			this->s2->MinimumWidth = 6;
			this->s2->Name = L"s2";
			this->s2->ReadOnly = true;
			this->s2->ToolTipText = L"Game 2 score";
			this->s2->Width = 50;
			// 
			// s3
			// 
			this->s3->HeaderText = L"Score3";
			this->s3->MinimumWidth = 6;
			this->s3->Name = L"s3";
			this->s3->ReadOnly = true;
			this->s3->ToolTipText = L"Game 3 score";
			this->s3->Width = 50;
			// 
			// changePwd
			// 
			this->changePwd->HeaderText = L"Change Pass";
			this->changePwd->LinkColor = System::Drawing::Color::Black;
			this->changePwd->MinimumWidth = 6;
			this->changePwd->Name = L"changePwd";
			this->changePwd->ReadOnly = true;
			this->changePwd->Text = L"Change";
			this->changePwd->ToolTipText = L"Change this account\'s password";
			this->changePwd->VisitedLinkColor = System::Drawing::Color::Black;
			this->changePwd->Width = 55;
			// 
			// deleteAcc
			// 
			this->deleteAcc->HeaderText = L"Delete";
			this->deleteAcc->MinimumWidth = 6;
			this->deleteAcc->Name = L"deleteAcc";
			this->deleteAcc->ReadOnly = true;
			this->deleteAcc->Text = L"Del";
			this->deleteAcc->ToolTipText = L"Delete this account";
			this->deleteAcc->Width = 50;
			// 
			// Dashboard_Admin
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->dashboardLayout);
			this->Name = L"Dashboard_Admin";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &Dashboard_Admin::onLoad);
			this->dashboardLayout->ResumeLayout(false);
			this->dashboardLayout->PerformLayout();
			this->playerInfo->ResumeLayout(false);
			this->playerInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void makeCircle(PictureBox^ pic) {
		GraphicsPath^ gp = gcnew GraphicsPath();
		gp->AddEllipse(0, 0, pic->Width, pic->Height);
		pic->Region = gcnew System::Drawing::Region(gp);
	}
	private: System::Void playMusic(System::String^ filesound) {
		this->bgMusic->Stop();
		this->bgMusic = gcnew SoundPlayer("asset\\sound\\" + filesound + ".wav");
		this->bgMusic->PlayLooping();
	}
	private: System::Void onLoad(System::Object^ sender, System::EventArgs^ e){
		makeCircle(avtBox);
		playMusic("bgMusic");
		dataLoading();
	}
	private: System::Void dataLoading(){
		this->userTable->Rows->Clear();
		this->userList = gcnew List<User^>();
		array<String^>^ lines = Directory::GetFiles("UserList", "*.txt");
		for each (String ^ line in lines) {
			array<String^>^ data = File::ReadAllLines(line);
			if (data[0] == "user") {
				String^ uname = data[1];
				String^ pwd = CryptoUtils::DecryptAES(data[2]);
				int s1 = Int32::Parse(data[3]);
				int s2 = Int32::Parse(data[4]);
				int s3 = Int32::Parse(data[5]);
				User^ user = gcnew User(uname, pwd, s1, s2, s3);
				this->userList->Add(user);
				String^ massPwd = gcnew String('*', user->getPwd()->Length);
				this->userTable->Rows->Add(uname, massPwd , "Show", s1.ToString(), s2.ToString(), s3.ToString(), "Change", "Delete");
			}
		}
	}
	private: System::Void cellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		int col = e->RowIndex;
		User^ user = this->userList[e->RowIndex];
		if (e->ColumnIndex == 2) {
			if (this->userTable->Rows[col]->Cells[2]->Value->ToString() == "Show") {
				this->userTable->Rows[col]->Cells[1]->Value = user->getPwd();
				this->userTable->Rows[col]->Cells[2]->Value = "Hide";
			}
			else {
				String^ massPwd = gcnew String('*', user->getPwd()->Length);
				this->userTable->Rows[col]->Cells[1]->Value = massPwd;
				this->userTable->Rows[col]->Cells[2]->Value = "Show";
			}
		}
		else if (e->ColumnIndex == 6) {
			ChangePass^ changePass = gcnew ChangePass(user->getPwd());
			changePass->ShowDialog();
			if (changePass->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				this->newPass = changePass->getPass();
				user->setPwd(this->newPass);
				user->writeToFile();
			}
		}
		else if (e->ColumnIndex == 7) {
			if (MessageBox::Show("Are you sure you want to delete this account?", "Delete Account", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {
				user->deletAccount();
				this->userTable->Rows->RemoveAt(col);
				this->userList->RemoveAt(col);
			}
		}
	}
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
	};
}
