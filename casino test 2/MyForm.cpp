#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	casinotest2::MyForm form;
	Application::Run(% form);
	return 0;
}

