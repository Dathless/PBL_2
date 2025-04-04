#pragma once
#include "Account.h"
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace PBLWORDLEGAME {
	public ref class User : public Account
	{
	private: int game1Score;
	private: int game2Score;
	private: int game3Score;

	public:
		User(String^ usr, String^ pwd, int s1, int s2, int s3) :Account(usr, pwd) {
			role = "user";
			game1Score = s1;
			game2Score = s2;
			game3Score = s3;
		}
		User(String^ usr, String^ pwd) : Account(usr, pwd) {
			role = "user";
			game1Score = 0;
			game2Score = 0;
			game3Score = 0;
		};
	public: ~User() {};
	public: System::String^ ToData() override {
		return role + "\n" + username + "\n" + password + "\n" + game1Score.ToString() + "\n" + game2Score.ToString() + "\n" + game3Score.ToString();
	}
	public:
		int getS1() { return game1Score; }
		int getS2() { return game2Score; }
		int getS3() { return game3Score; }
		System::Void setS1(int s1) { game1Score = s1; }
		System::Void setS2(int s2) { game1Score = s2; }
		System::Void setS3(int s3) { game1Score = s3; }
	};
}