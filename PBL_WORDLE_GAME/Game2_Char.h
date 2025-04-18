#pragma once

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game2_Char
	/// </summary>
	public ref class Game2_Char : public System::Windows::Forms::Form
	{
	public: System::String^ numberChar;
	private: int n;
	public:
		Game2_Char(void)
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
		~Game2_Char()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ header;
	private: System::Windows::Forms::Label^ PopupTitle;
	private: System::Windows::Forms::FlowLayoutPanel^ footer;
	private: System::Windows::Forms::Button^ CancelBtn;
	private: System::Windows::Forms::Button^ OKBtn;
	private: System::Windows::Forms::TextBox^ numChar;
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
			this->header = (gcnew System::Windows::Forms::Panel());
			this->PopupTitle = (gcnew System::Windows::Forms::Label());
			this->footer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->OKBtn = (gcnew System::Windows::Forms::Button());
			this->numChar = (gcnew System::Windows::Forms::TextBox());
			this->header->SuspendLayout();
			this->footer->SuspendLayout();
			this->SuspendLayout();
			// 
			// header
			// 
			this->header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->header->Controls->Add(this->PopupTitle);
			this->header->Location = System::Drawing::Point(-1, -1);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(501, 49);
			this->header->TabIndex = 0;
			// 
			// PopupTitle
			// 
			this->PopupTitle->AutoSize = true;
			this->PopupTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PopupTitle->Location = System::Drawing::Point(69, 11);
			this->PopupTitle->Name = L"PopupTitle";
			this->PopupTitle->Size = System::Drawing::Size(367, 25);
			this->PopupTitle->TabIndex = 0;
			this->PopupTitle->Text = L"Enter the number char that you wanna try";
			// 
			// footer
			// 
			this->footer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->footer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->footer->Controls->Add(this->CancelBtn);
			this->footer->Controls->Add(this->OKBtn);
			this->footer->Location = System::Drawing::Point(-1, 133);
			this->footer->Name = L"footer";
			this->footer->Size = System::Drawing::Size(501, 65);
			this->footer->TabIndex = 1;
			// 
			// CancelBtn
			// 
			this->CancelBtn->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CancelBtn->Location = System::Drawing::Point(100, 20);
			this->CancelBtn->Margin = System::Windows::Forms::Padding(100, 20, 0, 0);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(80, 30);
			this->CancelBtn->TabIndex = 1;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			this->CancelBtn->Click += gcnew System::EventHandler(this, &Game2_Char::Quit);
			// 
			// OKBtn
			// 
			this->OKBtn->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OKBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OKBtn->Location = System::Drawing::Point(300, 20);
			this->OKBtn->Margin = System::Windows::Forms::Padding(120, 20, 0, 0);
			this->OKBtn->Name = L"OKBtn";
			this->OKBtn->Size = System::Drawing::Size(80, 30);
			this->OKBtn->TabIndex = 0;
			this->OKBtn->Text = L"OK";
			this->OKBtn->UseVisualStyleBackColor = true;
			this->OKBtn->Click += gcnew System::EventHandler(this, &Game2_Char::clickOK);
			// 
			// numChar
			// 
			this->numChar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numChar->Location = System::Drawing::Point(79, 76);
			this->numChar->Name = L"numChar";
			this->numChar->Size = System::Drawing::Size(356, 30);
			this->numChar->TabIndex = 2;
			this->numChar->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numChar->Enter += gcnew System::EventHandler(this, &Game2_Char::Entering);
			this->numChar->Leave += gcnew System::EventHandler(this, &Game2_Char::Leaving);
			this->numChar->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game2_Char::pressEnter);
			// 
			// Game2_Char
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(500, 199);
			this->Controls->Add(this->numChar);
			this->Controls->Add(this->footer);
			this->Controls->Add(this->header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Game2_Char";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Game2_Char";
			this->Load += gcnew System::EventHandler(this, &Game2_Char::OnLoad);
			this->header->ResumeLayout(false);
			this->header->PerformLayout();
			this->footer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OnLoad(System::Object^ sender, System::EventArgs^ e) {
		this->numChar->Text = "2->5";
		this->numChar->ForeColor = System::Drawing::Color::Gray;
		this->numChar->Focus();
		this->numChar->SelectAll();
	}
	private: System::Void Quit(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	public: property System::String^ NumberChar
	{
		System::String^ get() { return numChar->Text; }
	}
	public: System::Void clickOK(System::Object^ sender, System::EventArgs^ e) {
		if (Int32::TryParse(this->numChar->Text,n) && n >= 2 && n<=5) {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else {
			MessageBox::Show("Please enter a number between 2 and 5", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->numChar->Text = "";
			this->numChar->Focus();
			
		}
	}
	private: System::Void Entering(System::Object^ sender, System::EventArgs^ e) {
		if (this->numChar->Text == "2->5") {
			this->numChar->Text = "";
			this->numChar->ForeColor = System::Drawing::Color::Black;
		}
	}
	private: System::Void Leaving(System::Object^ sender, System::EventArgs^ e) {
		if (this->numChar->Text == "") {
			this->numChar->Text = "2->5";
			this->numChar->ForeColor = System::Drawing::Color::Gray;
		}
	}
	private: System::Void pressEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			e->SuppressKeyPress = true;
			this->clickOK(sender, e);
		}
	}
};
}
