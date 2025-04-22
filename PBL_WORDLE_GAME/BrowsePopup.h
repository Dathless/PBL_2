#pragma once
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace PBLWORDLEGAME {
	public ref class browseManager {
	private: static String^ relativePath = "..\\..\\PBL_WORDLE_GAME\\asset";
	private: static String^ storageFile = "setting.txt";
	public:
		static String^ getImage() {
			OpenFileDialog^ browser = gcnew OpenFileDialog();
			String^ imgRelativePath = relativePath + "\\img";
			String^ fullPath = Path::Combine(Application::StartupPath, imgRelativePath);
			String^ loadPath = Path::GetFullPath(fullPath);
			browser->InitialDirectory = loadPath;
			browser->Title = "Select image";
			browser->Filter = "Image Files|*.jpg;*.jpeg;*.png";
			if (browser->ShowDialog() == DialogResult::OK) {
				createCopy(loadPath, browser->FileName);
				return Path::GetFileName(browser->FileName);
			}
			return nullptr;
		}
		static String^ getMusic() {
			OpenFileDialog^ browser = gcnew OpenFileDialog();
			String^ musicRelativePath = relativePath + "\\sound";
			String^ fullPath = Path::Combine(Application::StartupPath, musicRelativePath);
			String^ loadPath = Path::GetFullPath(fullPath);
			browser->InitialDirectory = loadPath;
			browser->Title = "Select audio";
			browser->Filter = "Image Files|*.mp3;*.wav;*.wma;*.aac;*.m4a|All Files|*.*";
			if (browser->ShowDialog() == DialogResult::OK) {
				createCopy(loadPath, browser->FileName);
				return Path::GetFileName(browser->FileName);
			}
			return nullptr;
		}
		static String^ convertImgPath(String^ filename) {
			return "asset\\img\\" + filename;
		}
		static String^ convertMusicPath(String^ filename) {
			return "asset\\sound\\" + filename;
		}
		static System::Void createCopy(String^ initPath , String^ selectedPath) {
			if (!selectedPath->StartsWith(initPath)) {
				String^ filename = Path::GetFileName(selectedPath);
				String^ copyFile = Path::Combine(initPath, filename);
				//Make sure copy file dont have the same filename with existed file
				int counter = 1;
				String^ nameOnly = Path::GetFileNameWithoutExtension(filename);
				String^ ext = Path::GetExtension(filename);
				while (File::Exists(copyFile)) {
					copyFile = Path::Combine(initPath, nameOnly + "_" + counter + ext);
					counter++;
				}
				File::Copy(selectedPath, copyFile);
			}
		}
		static array<String^>^ getSetting() {
			array<String^>^ lines = File::ReadAllLines(storageFile);
			return lines;
		}
		static System::Void saveSetting(array<String^>^ lines) {
			try {
				File::WriteAllLines(storageFile, lines);
			}
			catch (IOException^ ex) {
				MessageBox::Show("An error occurred while saving the file: " + ex->Message);
			}
		}
	};
}