#include "HasakiPCH.h"
#include "Application.h"

#include "Hasaki/Log.h"

#include <GLFW/glfw3.h>

namespace HSK {

#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application () {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FUNC(Application::OnEvent));
	}

	Application::~Application() 
	{
	}

	void Application::PushLayer(Layer* layer) {
		layerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		layerStack.PushOverLay(layer);
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));

		HSK_CORE_TRACE("on Event: {0}",e);

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled()) {
				break;
			}
		}

	}

	void Application::Run() {

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}   
	
	};

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
