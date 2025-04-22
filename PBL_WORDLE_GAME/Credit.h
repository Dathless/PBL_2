#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace PBLWORDLEGAME {

	/// <summary>
	/// Summary for Credit
	/// </summary>
	public ref class Credit : public System::Windows::Forms::UserControl
	{
	public:
		event EventHandler^ goBack;
		Credit(void)
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
		~Credit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	protected:
	private: System::Windows::Forms::Label^ author;
	private: System::Windows::Forms::Label^ courseName;
	private: System::Windows::Forms::Label^ projName;
	private: System::Windows::Forms::Label^ instructor;
	private: System::Windows::Forms::TextBox^ proNametxt;
	private: System::Windows::Forms::TextBox^ couresNametxt;
	private: System::Windows::Forms::TextBox^ InsTxt;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::TextBox^ textBox3;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Credit::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->author = (gcnew System::Windows::Forms::Label());
			this->courseName = (gcnew System::Windows::Forms::Label());
			this->projName = (gcnew System::Windows::Forms::Label());
			this->instructor = (gcnew System::Windows::Forms::Label());
			this->proNametxt = (gcnew System::Windows::Forms::TextBox());
			this->couresNametxt = (gcnew System::Windows::Forms::TextBox());
			this->InsTxt = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 32, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(291, 35);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(178, 63);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Credit";
			// 
			// author
			// 
			this->author->AutoSize = true;
			this->author->BackColor = System::Drawing::Color::Transparent;
			this->author->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->author->ForeColor = System::Drawing::Color::White;
			this->author->Location = System::Drawing::Point(112, 322);
			this->author->Name = L"author";
			this->author->Size = System::Drawing::Size(108, 31);
			this->author->TabIndex = 1;
			this->author->Text = L"Authors";
			// 
			// courseName
			// 
			this->courseName->AutoSize = true;
			this->courseName->BackColor = System::Drawing::Color::Transparent;
			this->courseName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->courseName->ForeColor = System::Drawing::Color::White;
			this->courseName->Location = System::Drawing::Point(112, 201);
			this->courseName->Name = L"courseName";
			this->courseName->Size = System::Drawing::Size(181, 31);
			this->courseName->TabIndex = 2;
			this->courseName->Text = L"Course Name";
			// 
			// projName
			// 
			this->projName->AutoSize = true;
			this->projName->BackColor = System::Drawing::Color::Transparent;
			this->projName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->projName->ForeColor = System::Drawing::Color::White;
			this->projName->Location = System::Drawing::Point(112, 144);
			this->projName->Name = L"projName";
			this->projName->Size = System::Drawing::Size(178, 31);
			this->projName->TabIndex = 3;
			this->projName->Text = L"Project Name";
			// 
			// instructor
			// 
			this->instructor->AutoSize = true;
			this->instructor->BackColor = System::Drawing::Color::Transparent;
			this->instructor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructor->ForeColor = System::Drawing::Color::White;
			this->instructor->Location = System::Drawing::Point(112, 264);
			this->instructor->Name = L"instructor";
			this->instructor->Size = System::Drawing::Size(129, 31);
			this->instructor->TabIndex = 4;
			this->instructor->Text = L"Instructor";
			// 
			// proNametxt
			// 
			this->proNametxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->proNametxt->Location = System::Drawing::Point(337, 141);
			this->proNametxt->Name = L"proNametxt";
			this->proNametxt->ReadOnly = true;
			this->proNametxt->Size = System::Drawing::Size(339, 34);
			this->proNametxt->TabIndex = 5;
			this->proNametxt->Text = L"English Game";
			// 
			// couresNametxt
			// 
			this->couresNametxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->couresNametxt->Location = System::Drawing::Point(337, 198);
			this->couresNametxt->Name = L"couresNametxt";
			this->couresNametxt->Size = System::Drawing::Size(339, 34);
			this->couresNametxt->TabIndex = 6;
			this->couresNametxt->Text = L"PBL2";
			// 
			// InsTxt
			// 
			this->InsTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InsTxt->Location = System::Drawing::Point(337, 261);
			this->InsTxt->Name = L"InsTxt";
			this->InsTxt->Size = System::Drawing::Size(339, 34);
			this->InsTxt->TabIndex = 7;
			this->InsTxt->Text = L"Mai Văn Hà";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(337, 319);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(339, 34);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"Nguyễn Phương Đông";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(337, 378);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(339, 34);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"Phạm Quốc Đáng";
			// 
			// backBtn
			// 
			this->backBtn->BackColor = System::Drawing::Color::Transparent;
			this->backBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->backBtn->Location = System::Drawing::Point(27, 17);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(88, 37);
			this->backBtn->TabIndex = 10;
			this->backBtn->Text = L"Back";
			this->backBtn->UseVisualStyleBackColor = false;
			this->backBtn->Click += gcnew System::EventHandler(this, &Credit::backToLanding);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(337, 444);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(339, 34);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"Trương Quốc Cường";
			// 
			// Credit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->backBtn);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->InsTxt);
			this->Controls->Add(this->couresNametxt);
			this->Controls->Add(this->proNametxt);
			this->Controls->Add(this->instructor);
			this->Controls->Add(this->projName);
			this->Controls->Add(this->courseName);
			this->Controls->Add(this->author);
			this->Controls->Add(this->Title);
			this->Name = L"Credit";
			this->Size = System::Drawing::Size(782, 553);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void backToLanding(System::Object^ sender, System::EventArgs^ e) {
		goBack(this, e);
	}
	};
}
