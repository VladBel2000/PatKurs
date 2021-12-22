#include "Form_main.h"

#include <Windows.h>

using namespace PatKurs;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Form_main);
    return 0;
}
