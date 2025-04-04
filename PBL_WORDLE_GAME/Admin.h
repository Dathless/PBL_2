#pragma once
#include "Account.h"
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace PBLWORDLEGAME {
	public ref class Admin : public Account
	{
	public:
		Admin(String^ usr, String^ pwd) : Account(usr, pwd) {
			role = "admin";
		};
		~Admin() {};
	};
}