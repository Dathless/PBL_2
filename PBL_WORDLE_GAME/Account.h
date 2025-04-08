#pragma once
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace PBLWORDLEGAME {
	/// <summary>
	/// Summary for Account
	/// </summary>
	public ref class Account
	{
	protected: String^ username;
	protected: String^ password;
	protected: String^ role;
	public:
		Account(String^ usr, String^ pwd)
		{
			username = usr;
			password = pwd;
			role = "";
		}
	protected:
		~Account() {};
		//Class data
	public:
		virtual System::String^ ToData() {
			return role + "\n" + username + "\n" + password;
		};
		System::String^ ToTXTObject() {
			return "{\n  \"username\": \"" + username + "\",\n  \"password\": \"" + password + "\",\n}";
		}
	public: System::Void deletAccount(System::String^ usr) {
		System::String^ filePath = "UserList\\" + usr + ".txt";
		if (File::Exists(filePath)) {
			File::Delete(filePath);
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	public: System::Void changePassword(System::String^ usr, System::String^ newPwd) {
		System::String^ filePath = "UserList\\" + usr + ".txt";
		if (File::Exists(filePath)) {
			StreamWriter^ file = gcnew StreamWriter(filePath);
			file->WriteLine(usr + " " + newPwd);
			file->Close();
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	};
}