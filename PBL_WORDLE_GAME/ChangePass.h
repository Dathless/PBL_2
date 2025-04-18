#pragma once

namespace PBLWORDLEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangePass
	/// </summary>
	public ref class ChangePass : public System::Windows::Forms::Form
	{
	private: String^ currPass;
	private: System::Windows::Forms::CheckBox^ toggleOld;
	private: System::Windows::Forms::CheckBox^ toggleNew;
	private: System::Windows::Forms::CheckBox^ toggleReNew;
	private: String^ pwd;
	public:
		ChangePass(String^ oldPass)
		{
			InitializeComponent();
			currPass = oldPass;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChangePass()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Header;
	protected:
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::FlowLayoutPanel^ Footer;
	private: System::Windows::Forms::Button^ CancelBtn;
	private: System::Windows::Forms::Button^ OKbtn;
	private: System::Windows::Forms::Label^ oldpass;
	private: System::Windows::Forms::Label^ newPass;
	private: System::Windows::Forms::Label^ reNewPass;
	private: System::Windows::Forms::TextBox^ oldInp;
	private: System::Windows::Forms::TextBox^ newInp;
	private: System::Windows::Forms::TextBox^ renewInp;




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
			this->Footer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OKbtn = (gcnew System::Windows::Forms::Button());
			this->CancelBtn = (gcnew System::Windows::Forms::Button());
			this->oldpass = (gcnew System::Windows::Forms::Label());
			this->newPass = (gcnew System::Windows::Forms::Label());
			this->reNewPass = (gcnew System::Windows::Forms::Label());
			this->oldInp = (gcnew System::Windows::Forms::TextBox());
			this->newInp = (gcnew System::Windows::Forms::TextBox());
			this->renewInp = (gcnew System::Windows::Forms::TextBox());
			this->toggleOld = (gcnew System::Windows::Forms::CheckBox());
			this->toggleNew = (gcnew System::Windows::Forms::CheckBox());
			this->toggleReNew = (gcnew System::Windows::Forms::CheckBox());
			this->Header->SuspendLayout();
			this->Footer->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->Header->Controls->Add(this->Title);
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(500, 54);
			this->Header->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(110, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(267, 29);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Change User Password";
			// 
			// Footer
			// 
			this->Footer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->Footer->Controls->Add(this->CancelBtn);
			this->Footer->Controls->Add(this->OKbtn);
			this->Footer->Location = System::Drawing::Point(0, 215);
			this->Footer->Name = L"Footer";
			this->Footer->Size = System::Drawing::Size(500, 66);
			this->Footer->TabIndex = 1;
			// 
			// OKbtn
			// 
			this->OKbtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OKbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OKbtn->Location = System::Drawing::Point(304, 15);
			this->OKbtn->Margin = System::Windows::Forms::Padding(80, 15, 0, 0);
			this->OKbtn->Name = L"OKbtn";
			this->OKbtn->Size = System::Drawing::Size(104, 32);
			this->OKbtn->TabIndex = 1;
			this->OKbtn->Text = L"OK";
			this->OKbtn->UseVisualStyleBackColor = true;
			this->OKbtn->Click += gcnew System::EventHandler(this, &ChangePass::changePwd);
			// 
			// CancelBtn
			// 
			this->CancelBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CancelBtn->Location = System::Drawing::Point(120, 15);
			this->CancelBtn->Margin = System::Windows::Forms::Padding(120, 15, 0, 0);
			this->CancelBtn->Name = L"CancelBtn";
			this->CancelBtn->Size = System::Drawing::Size(104, 32);
			this->CancelBtn->TabIndex = 0;
			this->CancelBtn->Text = L"Cancel";
			this->CancelBtn->UseVisualStyleBackColor = true;
			this->CancelBtn->Click += gcnew System::EventHandler(this, &ChangePass::quit);
			// 
			// oldpass
			// 
			this->oldpass->AutoSize = true;
			this->oldpass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oldpass->Location = System::Drawing::Point(35, 79);
			this->oldpass->Name = L"oldpass";
			this->oldpass->Size = System::Drawing::Size(117, 24);
			this->oldpass->TabIndex = 2;
			this->oldpass->Text = L"Current Pass";
			// 
			// newPass
			// 
			this->newPass->AutoSize = true;
			this->newPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newPass->Location = System::Drawing::Point(35, 121);
			this->newPass->Name = L"newPass";
			this->newPass->Size = System::Drawing::Size(94, 24);
			this->newPass->TabIndex = 3;
			this->newPass->Text = L"New Pass";
			// 
			// reNewPass
			// 
			this->reNewPass->AutoSize = true;
			this->reNewPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reNewPass->Location = System::Drawing::Point(35, 165);
			this->reNewPass->Name = L"reNewPass";
			this->reNewPass->Size = System::Drawing::Size(118, 24);
			this->reNewPass->TabIndex = 4;
			this->reNewPass->Text = L"ReNew Pass";
			// 
			// oldInp
			// 
			this->oldInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->oldInp->Location = System::Drawing::Point(172, 74);
			this->oldInp->Name = L"oldInp";
			this->oldInp->Size = System::Drawing::Size(273, 30);
			this->oldInp->TabIndex = 5;
			this->oldInp->UseSystemPasswordChar = true;
			this->oldInp->Focus();
			this->oldInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChangePass::onEnter);
			// 
			// newInp
			// 
			this->newInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newInp->Location = System::Drawing::Point(172, 116);
			this->newInp->Name = L"newInp";
			this->newInp->Size = System::Drawing::Size(273, 30);
			this->newInp->TabIndex = 6;
			this->newInp->UseSystemPasswordChar = true;
			this->newInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChangePass::onEnter);
			// 
			// renewInp
			// 
			this->renewInp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->renewInp->Location = System::Drawing::Point(172, 160);
			this->renewInp->Name = L"renewInp";
			this->renewInp->Size = System::Drawing::Size(273, 30);
			this->renewInp->TabIndex = 7;
			this->renewInp->UseSystemPasswordChar = true;
			this->renewInp->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ChangePass::onEnter);
			// 
			// toggleOld
			// 
			this->toggleOld->AutoSize = true;
			this->toggleOld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toggleOld->Location = System::Drawing::Point(451, 79);
			this->toggleOld->Name = L"toggleOld";
			this->toggleOld->Size = System::Drawing::Size(18, 17);
			this->toggleOld->TabIndex = 8;
			this->toggleOld->UseVisualStyleBackColor = true;
			this->toggleOld->CheckedChanged += gcnew System::EventHandler(this, &ChangePass::toggleOP);
			// 
			// toggleNew
			// 
			this->toggleNew->AutoSize = true;
			this->toggleNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toggleNew->Location = System::Drawing::Point(451, 126);
			this->toggleNew->Name = L"toggleNew";
			this->toggleNew->Size = System::Drawing::Size(18, 17);
			this->toggleNew->TabIndex = 9;
			this->toggleNew->UseVisualStyleBackColor = true;
			this->toggleNew->CheckedChanged += gcnew System::EventHandler(this, &ChangePass::toggleNP);
			// 
			// toggleReNew
			// 
			this->toggleReNew->AutoSize = true;
			this->toggleReNew->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toggleReNew->Location = System::Drawing::Point(451, 171);
			this->toggleReNew->Name = L"toggleReNew";
			this->toggleReNew->Size = System::Drawing::Size(18, 17);
			this->toggleReNew->TabIndex = 10;
			this->toggleReNew->UseVisualStyleBackColor = true;
			this->toggleReNew->CheckedChanged += gcnew System::EventHandler(this, &ChangePass::toggleRNP);
			// 
			// ChangePass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->ClientSize = System::Drawing::Size(500, 280);
			this->Controls->Add(this->toggleReNew);
			this->Controls->Add(this->toggleNew);
			this->Controls->Add(this->toggleOld);
			this->Controls->Add(this->renewInp);
			this->Controls->Add(this->newInp);
			this->Controls->Add(this->oldInp);
			this->Controls->Add(this->reNewPass);
			this->Controls->Add(this->newPass);
			this->Controls->Add(this->oldpass);
			this->Controls->Add(this->Footer);
			this->Controls->Add(this->Header);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ChangePass";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"`";
			this->Load += gcnew System::EventHandler(this, &ChangePass::onLoad);
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->Footer->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void onLoad(Object^ sender, System::EventArgs^ e) {
		this->oldInp->Focus();
	}
	private: System::Void changePwd(System::Object^ sender, System::EventArgs^ e) {
		String^ oldPass = oldInp->Text;
		String^ newPass = newInp->Text;
		String^ reNewPass = renewInp->Text;
		if (oldPass == "" || newPass == "" || reNewPass == "") {
			MessageBox::Show("Please fill all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (oldPass != currPass) {
			MessageBox::Show("Current password is incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else
		if (oldPass == newPass) {
			MessageBox::Show("New password must be different from old password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (newPass != reNewPass){
			MessageBox::Show("New password and ReNew password must be the same", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (newPass->Length < 6) {
			MessageBox::Show("Password must be at least 6 characters", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->pwd = newPass;
			this->Close();
		}
	}
	private: System::Void onEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			e->SuppressKeyPress = true;
			changePwd(sender, e);
		}
	}
	private: System::Void toggleOP(System::Object^ sender, System::EventArgs^ e) {
		if (toggleOld->Checked) {
			oldInp->UseSystemPasswordChar = false;
		}
		else {
			oldInp->UseSystemPasswordChar = true;
		}
	}
	private: System::Void toggleNP(System::Object^ sender, System::EventArgs^ e) {
		if (toggleNew->Checked) {
			newInp->UseSystemPasswordChar = false;
		}
		else {
			newInp->UseSystemPasswordChar = true;
		}
	}
	private: System::Void toggleRNP(System::Object^ sender, System::EventArgs^ e) {
		if (toggleReNew->Checked) {
			renewInp->UseSystemPasswordChar = false;
		}
		else {
			renewInp->UseSystemPasswordChar = true;
		}
	}
	public: System::String^ getPass() {
		return this->pwd;
	}
	private: System::Void quit(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
