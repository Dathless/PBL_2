#pragma once
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Data;

namespace PBLWORDLEGAME {
	/// <summary>
	/// Summary for Account
	/// </summary>
	public ref class Account
	{
	public: String^ username;
	private: String^ password;
	public:
		Account(String^ usr, String^ pwd)
		{
			username = usr;
			password = pwd;
		}
	protected:
		~Account() {};
		//Class data
	public:
		String^ ToData() {
			return username + " " + password;
		};
		String^ ToTXTObject() {
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