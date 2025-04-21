#pragma once
#include "User.h"
#include "CryptoUtils.h"
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Media;

namespace PBLWORDLEGAME {
	public ref class Game : public System::Windows::Forms::Form
	{
	protected: User^ UserLogged;
	protected: SoundPlayer^ bgMusic;
	private: Dictionary<String^, int>^ Ranking = gcnew Dictionary<String^, int>();
	protected: virtual System::Void Render(System::Object^ sender, System::EventArgs^ e) = 0;
	protected: virtual System::Void Exit(System::Object^ sender, System::EventArgs^e) {}
	protected: System::Void userLoading(String^ usr) {
		String^ encryptUser = CryptoUtils::ComputeSHA256(usr);
		String^ userPath = "UserList\\" + encryptUser + ".txt";

		if (File::Exists(userPath)) {
			array<String^>^ lines = File::ReadAllLines(userPath);
			String^ decryptedPassword = CryptoUtils::DecryptAES(lines[2]);
			UserLogged = gcnew User(lines[1], decryptedPassword, Int32::Parse(lines[3]), Int32::Parse(lines[4]), Int32::Parse(lines[5]));
		}
		else {
			MessageBox::Show("User not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	public: virtual System::Void scoreUpdating(int score) {}
	protected: System::Void userSaving(User^ usr) {
		String^ pwd = CryptoUtils::EncryptAES(usr->getPwd());
		String^ saver = "user" + "\n" + usr->username + "\n" + pwd + "\n" + usr->getS1().ToString() + "\n" + usr->getS2().ToString() + "\n" + usr->getS3().ToString();
		String^ filePath = "UserList\\" + CryptoUtils::ComputeSHA256(usr->username) + ".txt";
		File::WriteAllText(filePath, saver);
	}
	protected: System::Void loadAllUser(int pos) {
		String^ folderPath = "UserList\\";
		array<String^>^ files = Directory::GetFiles(folderPath, "*.txt");
		for each(String ^ file in files) {
			array<String^>^ lines = File::ReadAllLines(file);
			if (lines[0] == "user") {
				String^ uname = lines[1];
				int score = Int32::Parse(lines[2 + pos]);//Game1 pos=1, Game2 pos=2, Game3 pos=3
				Ranking[uname] = score;
			}
		}
	}
	protected: int getRank(String^ usr) {
		List<KeyValuePair<String^, int>>^ sortedRank = gcnew List<KeyValuePair<String^, int>>(Ranking);
		for (int i = 0; i < sortedRank->Count - 1; i++) {
			for (int j = i + 1; j < sortedRank->Count; j++) {
				if (sortedRank[i].Value < sortedRank[j].Value) { // Descending order
					KeyValuePair<String^, int> temp = sortedRank[i];
					sortedRank[i] = sortedRank[j];
					sortedRank[j] = temp;
				}
			}
		}
		for (int i = 0; i < sortedRank->Count; i++) {
			if (sortedRank[i].Key == usr) {
				return i + 1;
			}
		}
		return -1;
	}
	};
}