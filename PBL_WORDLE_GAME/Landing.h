#pragma once
#include "Login.h"
#include "fstream"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Landing
	/// </summary>
	public ref class Landing : public System::Windows::Forms::UserControl
	{
	public:
		event EventHandler^ enterLogin;
		event EventHandler^ enterRegis;
		event EventHandler^ enterCredit;
		event EventHandler^ enterSetting;
		event EventHandler^ quitForm;
		Landing(void)
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
		~Landing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ subTitle;
	private: System::Windows::Forms::LinkLabel^ loginLabel;
	private: System::Windows::Forms::LinkLabel^ RegisLabel;
	private: System::Windows::Forms::LinkLabel^ settingLabel;
	private: System::Windows::Forms::LinkLabel^ creLabel;
	private: System::Windows::Forms::LinkLabel^ quitLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Landing::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->subTitle = (gcnew System::Windows::Forms::Label());
			this->loginLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->RegisLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->settingLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->creLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->quitLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 44, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(94, 107);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(588, 85);
			this->Title->TabIndex = 0;
			this->Title->Text = L"GAME CENTER";
			// 
			// subTitle
			// 
			this->subTitle->AutoSize = true;
			this->subTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->subTitle->ForeColor = System::Drawing::Color::White;
			this->subTitle->Location = System::Drawing::Point(291, 78);
			this->subTitle->Name = L"subTitle";
			this->subTitle->Size = System::Drawing::Size(151, 29);
			this->subTitle->TabIndex = 1;
			this->subTitle->Text = L"Welcome To";
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->loginLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->loginLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->loginLabel->LinkColor = System::Drawing::Color::White;
			this->loginLabel->Location = System::Drawing::Point(3, 15);
			this->loginLabel->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(168, 36);
			this->loginLabel->TabIndex = 2;
			this->loginLabel->TabStop = true;
			this->loginLabel->Text = L"LOGIN";
			this->loginLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->loginLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Landing::openLogin);
			// 
			// RegisLabel
			// 
			this->RegisLabel->AutoSize = true;
			this->RegisLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->RegisLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->RegisLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->RegisLabel->LinkColor = System::Drawing::Color::White;
			this->RegisLabel->Location = System::Drawing::Point(3, 66);
			this->RegisLabel->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->RegisLabel->Name = L"RegisLabel";
			this->RegisLabel->Size = System::Drawing::Size(168, 36);
			this->RegisLabel->TabIndex = 3;
			this->RegisLabel->TabStop = true;
			this->RegisLabel->Text = L"REGISTER";
			this->RegisLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->RegisLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Landing::openRegis);
			// 
			// settingLabel
			// 
			this->settingLabel->AutoSize = true;
			this->settingLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->settingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->settingLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->settingLabel->LinkColor = System::Drawing::Color::White;
			this->settingLabel->Location = System::Drawing::Point(3, 117);
			this->settingLabel->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->settingLabel->Name = L"settingLabel";
			this->settingLabel->Size = System::Drawing::Size(168, 36);
			this->settingLabel->TabIndex = 4;
			this->settingLabel->TabStop = true;
			this->settingLabel->Text = L"SETTING";
			this->settingLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->settingLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Landing::openSetting);
			// 
			// creLabel
			// 
			this->creLabel->AutoSize = true;
			this->creLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->creLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->creLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->creLabel->LinkColor = System::Drawing::Color::White;
			this->creLabel->Location = System::Drawing::Point(3, 168);
			this->creLabel->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->creLabel->Name = L"creLabel";
			this->creLabel->Size = System::Drawing::Size(168, 36);
			this->creLabel->TabIndex = 5;
			this->creLabel->TabStop = true;
			this->creLabel->Text = L"CREDIT";
			this->creLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->creLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Landing::openCredit);
			// 
			// quitLabel
			// 
			this->quitLabel->AutoSize = true;
			this->quitLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->quitLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->quitLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->quitLabel->LinkColor = System::Drawing::Color::White;
			this->quitLabel->Location = System::Drawing::Point(3, 219);
			this->quitLabel->Margin = System::Windows::Forms::Padding(3, 15, 3, 0);
			this->quitLabel->Name = L"quitLabel";
			this->quitLabel->Size = System::Drawing::Size(168, 36);
			this->quitLabel->TabIndex = 6;
			this->quitLabel->TabStop = true;
			this->quitLabel->Text = L"QUIT";
			this->quitLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->quitLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Landing::closeLanding);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->loginLabel);
			this->flowLayoutPanel1->Controls->Add(this->RegisLabel);
			this->flowLayoutPanel1->Controls->Add(this->settingLabel);
			this->flowLayoutPanel1->Controls->Add(this->creLabel);
			this->flowLayoutPanel1->Controls->Add(this->quitLabel);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(282, 259);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(204, 277);
			this->flowLayoutPanel1->TabIndex = 7;
			// 
			// Landing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->subTitle);
			this->Controls->Add(this->Title);
			this->Name = L"Landing";
			this->Size = System::Drawing::Size(782, 553);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void openLogin(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			enterLogin(this, e);
		}
		private: System::Void openRegis(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			enterRegis(this, e);
		}
		private: System::Void openSetting(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			enterSetting(this, e);
		}
		private: System::Void openCredit(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			enterCredit(this, e);
		}
		private: System::Void closeLanding(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			quitForm(this, e);
		}
};
}
