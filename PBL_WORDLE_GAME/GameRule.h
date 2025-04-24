#pragma once

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameRule
	/// </summary>
	public ref class GameRule : public System::Windows::Forms::Form
	{
	private: String^ rule;
	public:
		GameRule(String^ GameRule)
		{
			InitializeComponent();
			this->rule = GameRule;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameRule()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Header;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ RuleContent;
	private: System::Windows::Forms::Button^ OKBtn;
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
			this->Header = (gcnew System::Windows::Forms::Panel());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->RuleContent = (gcnew System::Windows::Forms::Label());
			this->OKBtn = (gcnew System::Windows::Forms::Button());
			this->Header->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->Header->Controls->Add(this->Title);
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Margin = System::Windows::Forms::Padding(4);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(511, 63);
			this->Header->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(155, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(163, 36);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Game Rule";
			// 
			// RuleContent
			// 
			this->RuleContent->AutoSize = true;
			this->RuleContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RuleContent->Location = System::Drawing::Point(40, 95);
			this->RuleContent->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->RuleContent->Name = L"RuleContent";
			this->RuleContent->Size = System::Drawing::Size(101, 20);
			this->RuleContent->TabIndex = 1;
			this->RuleContent->Text = L"RuleContent";
			this->RuleContent->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OKBtn
			// 
			this->OKBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OKBtn->Location = System::Drawing::Point(194, 239);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(98, 36);
			this->OKBtn->TabIndex = 2;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &GameRule::Exit);
			// 
			// GameRule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(207)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->ClientSize = System::Drawing::Size(485, 302);
			this->Controls->Add(this->OKBtn);
			this->Controls->Add(this->RuleContent);
			this->Controls->Add(this->Header);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GameRule";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"GameRule";
			this->Load += gcnew System::EventHandler(this, &GameRule::OnLoad);
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: Void OnLoad(Object^ sendr, EventArgs^ e) {
			this->RuleContent->Text = this->rule;
		}
		private: Void Exit(Object^ sender, EventArgs^ e) {
			this->Close();
		}
	};
}
