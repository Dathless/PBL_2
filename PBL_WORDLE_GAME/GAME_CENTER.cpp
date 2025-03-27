#include "GAME_CENTER.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PBLWORDLEGAME::GAME_CENTER form;
	Application::Run(% form);
}
