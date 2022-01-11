#pragma once
#include "core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Hasaki/Events/ApplicationEvent.h"

namespace HSK {
	class HSK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// define in client
	Application* CreateApplication();
}
