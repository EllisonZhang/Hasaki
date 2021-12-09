#pragma once

#include "Application.h"
#include <stdio.h>

#ifdef HSK_PLATFORM_WINDOWS

extern HSK::Application* HSK::CreateApplication();

int main(int argc, char** argv) {

	printf("welcome to Hasaki!");

	auto app = HSK::CreateApplication();

	app->Run();

	delete app;
}

#endif