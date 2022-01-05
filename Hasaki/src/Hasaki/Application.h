#pragma once
#include "core.h"
#include "Window.h"
#include "Events/Event.h"

namespace HSK {
	class HSK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
	};

	// define in client
	Application* CreateApplication();
}
