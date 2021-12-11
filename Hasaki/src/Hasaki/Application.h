#pragma once
#include "core.h"

namespace HSK {
	class HSK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// define in client
	Application* CreateApplication();
}
