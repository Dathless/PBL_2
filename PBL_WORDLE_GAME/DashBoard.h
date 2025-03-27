#pragma once
#include "fstream"

using namespace System;
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
	public:
		event EventHandler^ goBack;
		DashBoard(void)
		{
			InitializeComponent();
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
			this->logOut = (gcnew System::Windows::Forms::Label());
			this->listTitle = (gcnew System::Windows::Forms::Label());
			this->dashboardLayout->SuspendLayout();
			this->playerInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->BeginInit();
			this->SuspendLayout();
			// 
			// dashboardLayout
			// 
			this->dashboardLayout->BackColor = System::Drawing::Color::Transparent;
			this->dashboardLayout->ColumnCount = 2;
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20.33248F)));
			this->dashboardLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				79.66752F)));
			this->dashboardLayout->Controls->Add(this->Title, 1, 0);
			this->dashboardLayout->Controls->Add(this->playerInfo, 0, 1);
			this->dashboardLayout->Controls->Add(this->listTitle, 1, 1);
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
			this->usrName->Size = System::Drawing::Size(68, 25);
			this->usrName->TabIndex = 2;
			this->usrName->Text = L"Admin";
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
			this->logOut->Click += gcnew System::EventHandler(this, &DashBoard::backToLanding);
			// 
			// listTitle
			// 
			this->listTitle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->listTitle->AutoSize = true;
			this->listTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listTitle->ForeColor = System::Drawing::Color::White;
			this->listTitle->Location = System::Drawing::Point(384, 125);
			this->listTitle->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->listTitle->Name = L"listTitle";
			this->listTitle->Size = System::Drawing::Size(171, 39);
			this->listTitle->TabIndex = 2;
			this->listTitle->Text = L"Game List";
			// 
			// DashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = gcnew System::Drawing::Bitmap("asset\\img\\bg1.jpg");
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->dashboardLayout);
			this->Name = L"DashBoard";
			this->Size = System::Drawing::Size(782, 553);
			this->Load += gcnew System::EventHandler(this, &DashBoard::DashBoard_Load);
			this->dashboardLayout->ResumeLayout(false);
			this->dashboardLayout->PerformLayout();
			this->playerInfo->ResumeLayout(false);
			this->playerInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->avtBox))->EndInit();
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
	}
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
	};
}
