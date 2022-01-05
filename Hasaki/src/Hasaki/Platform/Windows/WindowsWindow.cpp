#include "HasakiPCH.h"
#include "WindowsWindow.h"

namespace HSK {
	// 
	static bool isGLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow() 
	{
		ShutDown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.height = props.height;
		m_Data.width = props.width;
		m_Data.title = props.title;

		HSK_CORE_INFO("Creating window {0}, ({1}, {2})", props.title, props.width, props.height);
		glfwInit();
		win_Window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(win_Window);
		glfwSetWindowUserPointer(win_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::OnUpdate()
	{
		//glfwPollEvents();
		//glfwSwapBuffers(win_Window);
	}

	void WindowsWindow::SetEventCallBack(EventCallBackFnc func)
	{}

	void WindowsWindow::ShutDown()
	{
		//glfwDestroyWindow(win_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return VSync;
	}

}