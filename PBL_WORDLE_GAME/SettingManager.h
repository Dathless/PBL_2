#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Media;
using namespace AxWMPLib;
using namespace WMPLib;

namespace PBLWORDLEGAME {
	public ref class SettingManager {
		private: String^ settingFile = "setting.txt";
		private: String^ bgPath;
		private: String^ landingMusic;
		private: String^ dashboardMusic;
		private: String^ Game1Music;
		private: String^ Game2Music;
		private: String^ Game3Music;
		private: int vol;
	public: SettingManager() {
		loadSetting();
	}
	private: System::Void loadSetting() {
		if (File::Exists(settingFile)) {
			array<String^>^ lines = File::ReadAllLines(settingFile);
			if (lines->Length > 0) {
				this->bgPath = lines[0]->Trim();
				this->landingMusic = lines[1]->Trim();
				this->dashboardMusic = lines[2]->Trim();
				this->Game1Music = lines[3]->Trim();
				this->Game2Music = lines[4]->Trim();
				this->Game3Music = lines[5]->Trim();
				int savedVol = Convert::ToInt32(lines[6]->Trim());
				if (savedVol >= 0 && savedVol <= 100) this->vol = savedVol;
				else MessageBox::Show("Volume Error!");

			}
			else {
				MessageBox::Show("Invalid file format!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->bgPath = "";
				this->landingMusic = "";
				this->vol = 50;
				return;
			}
		}
		else {
			this->bgPath = nullptr;
		}
	}
	public: String^ getFile() {
		return this->settingFile;
	}
	public: System::Void Landing_BgImg(Form^ form) {
		if (String::IsNullOrWhiteSpace(bgPath)) return;
		if (File::Exists(bgPath)) {
			form->BackgroundImage = Image::FromFile(bgPath);
			form->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		}
	}
	public: System::Void Landing_Music(AxWindowsMediaPlayer^ wmp) {
		if (String::IsNullOrWhiteSpace(landingMusic)) return;
		wmp->URL = this->landingMusic;
		wmp->settings->volume = vol;
		wmp->settings->setMode("loop", true);
		wmp->settings->autoStart = true;
	}
	public: System::Void Dashboard_Music(AxWindowsMediaPlayer^ wmp) {
		if (String::IsNullOrWhiteSpace(landingMusic)) return;
		wmp->URL = this->dashboardMusic;
		wmp->settings->volume = vol;
		wmp->settings->setMode("loop", true);
		wmp->settings->autoStart = true;
	}
	public: System::Void Game1_Music(AxWindowsMediaPlayer^ wmp) {
		if (String::IsNullOrWhiteSpace(Game1Music)) return;
		wmp->URL = this->Game1Music;
		wmp->settings->volume = vol;
		wmp->settings->setMode("loop", true);
		wmp->settings->autoStart = true;
	}
	public: System::Void Game2_Music(AxWindowsMediaPlayer^ wmp) {
		if (String::IsNullOrWhiteSpace(Game2Music)) return;
		wmp->URL = this->Game2Music;
		wmp->settings->volume = vol;
		wmp->settings->setMode("loop", true);
		wmp->settings->autoStart = true;
	}
	public: Void Congrat_Sound(AxWindowsMediaPlayer^ wmp) {
		String^ soundPath = "asset\\sound\\Applause.wav";
		wmp->URL = soundPath;
		wmp->settings->volume = 100;
		ContinueAxWMP(wmp);
	}
	public: System::Void VolumeChanging(AxWindowsMediaPlayer^ wmp, int volu) {
		wmp->settings->volume = volu;
	}
	public: System::Void PauseAxWMP(AxWindowsMediaPlayer^ wmp) {
		wmp->Ctlcontrols->pause();
	}
	public: System::Void ContinueAxWMP(AxWindowsMediaPlayer^ wmp) {
		wmp->Ctlcontrols->play();
	}
	public: System::Void StopAxWMP(AxWindowsMediaPlayer^ wmp) {
		wmp->Ctlcontrols->stop();
	}
	};
}