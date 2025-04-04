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
	//NOTE: Delete User
	public: System::Void UserDelete(System::String^ usr){
		System::String^ filePath = "UserList\\" + usr + ".txt";
		if (File::Exists(filePath)) {
			File::Delete(filePath);
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	//NOTE: Change Password
	public: System::Void ChangePassword(System::String^ newPwd) {
		System::String^ filePath = "UserList\\" + this->username + ".txt";
		if (File::Exists(filePath)) {
			StreamWriter^ file = gcnew StreamWriter(filePath);
			file->WriteLine(this->username + " " + newPwd);
			file->Close();
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	};
}