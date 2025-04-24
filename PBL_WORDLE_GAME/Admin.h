#pragma once
#include "Account.h"
#include <fstream>
#include "CryptoUtils.h"

using namespace System;
using namespace System::IO;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace PBLWORDLEGAME {
	public ref class Admin : public Account
	{
	public:
		Admin(String^ usr, String^ pwd) : Account(usr, pwd) {
			role = "admin";
		};
		~Admin() {};
	public: System::Void changeAccLevel(System::String^ usr, System::String^ role) {
		System::String^ filePath = "UserList\\" + usr + ".txt";
		if (!File::Exists(filePath)) {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		try {
			array<String^>^ lines = File::ReadAllLines(filePath);
			if (lines->Length != 3 || lines->Length != 6) {
				MessageBox::Show("Invalid file format!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			lines[0] = role;
			File::WriteAllLines(filePath, lines);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
	}
	public:	String^ ToData() override {
			return role + "\n" + username + "\n" + CryptoUtils::EncryptAES(password);
		}
	public: Void WriteToFile() {
		String^ filePath = getPath();
		File::WriteAllText(filePath, ToData());
	}
	};
}