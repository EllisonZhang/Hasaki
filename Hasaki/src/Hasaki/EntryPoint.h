#pragma once
#include "Log.h"

#ifdef HSK_PLATFORM_WINDOWS

extern HSK::Application* HSK::CreateApplication();

int main(int argc, char** argv) {

	HSK::Log::Init();
	int a = 5;
	int b = 6;
	HSK_CORE_WARN("Initialized App Log!");
	HSK_CLIENT_ERROR("Initialized Core Log! Var={0} asd={1}", a, b);

	auto app = HSK::CreateApplication();

	app->Run();

	delete app;

}

#endif