#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Drawing;

namespace PBLWORDLEGAME {
	public ref class SettingManager {
		private: static SettingManager^ instance = nullptr;
		private: static Object^ lockObj = gcnew Object();
		private: String^ bgPath;
	private: SettingManager() {
		loadSetting();
	}
	private: System::Void loadSetting() {
		String^ settingFile = "setting.txt";
		if (File::Exists(settingFile)) {
			array<String^>^ lines = File::ReadAllLines(settingFile);
			if (lines->Length > 0) {
				this->bgPath = lines[0]->Trim();
			}
		}
		else {
			this->bgPath = nullptr;
		}
	}
	public: static SettingManager^ getInstance() {
		if (instance == nullptr) {
			System::Threading::Monitor::Enter(lockObj);
			try {
				if (instance == nullptr) {
					instance = gcnew SettingManager();
				}
			}
			finally {
				System::Threading::Monitor::Exit(lockObj);
			}
		}
		return instance;
	}
	public:property String^ bgImgPath{
		String^ get() {
			return bgPath;
		}
	}
	public: Bitmap^ loadBgImg() {
		if (!String::IsNullOrEmpty(bgPath) && File::Exists(bgPath)) {
			return gcnew Bitmap(bgPath);
		}
		return nullptr;
	}
	};
}