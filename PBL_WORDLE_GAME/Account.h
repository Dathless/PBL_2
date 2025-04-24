#pragma once
#include <fstream>
#include "CryptoUtils.h"

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
	public: String^ username;
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
		virtual System::String^ ToData() = 0;
		System::String^ ToTXTObject() {
			return "{\n  \"username\": \"" + username + "\",\n  \"password\": \"" + password + "\",\n}";
		}
	public: System::Void deletAccount() {
		System::String^ filePath = "UserList\\" + CryptoUtils::ComputeSHA256(username) + ".txt";
		if (File::Exists(filePath)) {
			File::Delete(filePath);
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	public: virtual System::Void changePassword(System::String^ usr, System::String^ newPwd) {}
	public: System::Void setPwd(System::String^ pwd) {
		this->password = pwd;
	}
	public: System::String^ getPwd() {
		return password;
	}
	protected: String^ getPath() {
		return "UserList\\" + CryptoUtils::ComputeSHA256(username) + ".txt";
	}
	};
}