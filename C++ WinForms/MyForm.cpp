#include "MyForm.h"


using namespace System;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array< String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Company8::MyForm form;  //указать имя своего проекта
	Application::Run(% form);
}
