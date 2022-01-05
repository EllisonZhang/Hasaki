#include "HasakiPCH.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace HSK {

	Application::Application () {
		m_Window = std::unique_ptr<Window>(Window::Create());

	}
	Application::~Application() {

	}
	void Application::Run() {

		while (true);
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}

	};
}
