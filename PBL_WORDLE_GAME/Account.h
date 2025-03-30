#pragma once
using namespace System;

namespace PBLWORDLEGAME {
	/// <summary>
	/// Summary for Account
	/// </summary>
	public ref class Account
	{
	private: String^ username;
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
		String^ ToTXTObject() {
			return "{\n  \"username\": \"" + username + "\",\n  \"password\": \"" + password + "\",\n}";
		}
	};
}
