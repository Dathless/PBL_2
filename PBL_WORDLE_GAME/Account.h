#pragma once
using namespace System;

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
		}
	};
}
