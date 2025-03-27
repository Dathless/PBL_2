#pragma once
#include <cliext/vector>
#include "Account.h"

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
	public: cliext::vector<Account> accList;
	public:
		Landing(void)
		{
			InitializeComponent();

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
	private: System::Windows::Forms::Label^ Desc;
	private: System::Windows::Forms::TextBox^ numberWord;
	private: System::Windows::Forms::Button^ GameStart;
	private: System::Windows::Forms::Button^ GameExit;
	private: System::Windows::Forms::FlowLayoutPanel^ gameDomain;
	private: System::Windows::Forms::FlowLayoutPanel^ gameAns;
	private: cliext::vector<System::Windows::Forms::TextBox^> charBoxes;

	protected:

	private: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code

		void InitializeComponent()
		{
		
		}
#pragma endregion
	public: virtual System::Void showRule() {};
	public: virtual System::Void gameGenerate() {};
	public: System::Void addTxtBox(System::Windows::Forms::FlowLayoutPanel^ container, int x, int y) {
		System::Windows::Forms::TextBox^ newBox = gcnew TextBox();
		newBox->Size = System::Drawing::Size(30, 30);
		newBox->Location = System::Drawing::Point(x, y);
		charBoxes.push_back(newBox);
		container->Controls->Add(newBox);
	}
	public: System::Void clearBox(System::Windows::Forms::FlowLayoutPanel^ container) {
		for each (System::Windows::Forms::TextBox ^ box in charBoxes) {
			container->Controls->Remove(box);
		}
	}
};
}