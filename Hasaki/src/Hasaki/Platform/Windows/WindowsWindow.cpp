#include "HasakiPCH.h"
#include "WindowsWindow.h"
#include "Hasaki/Core.h"
#include "Hasaki/Events/ApplicationEvent.h"
#include "Hasaki/Events/KeyEvent.h"
#include "Hasaki/Events/MouseEvent.h"



namespace HSK {
	
	static bool isGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		HSK_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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

		if (!isGLFWInitialized) 
		{
			int sucess = glfwInit();
			HSK_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			isGLFWInitialized = true;
		}
		
		win_Window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(win_Window);
		glfwSetWindowUserPointer(win_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(win_Window, [](GLFWwindow* win_Window, int width, int height)
		{
			WindowData& data =  *(WindowData*)glfwGetWindowUserPointer(win_Window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.EventCallBack(event);
		});

		glfwSetWindowCloseCallback(win_Window, [](GLFWwindow* win_Window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win_Window);

			WindowCloseEvent event;
			data.EventCallBack(event);
		});

		glfwSetKeyCallback(win_Window, [] (GLFWwindow* win_Window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win_Window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallBack(event);
					break;
				}
				
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallBack(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallBack(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(win_Window, [](GLFWwindow* win_Window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win_Window);
			
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallBack(event);
					break;
				}

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallBack(event);
					break;
				}
			}		
		});

		glfwSetScrollCallback(win_Window, [](GLFWwindow* win_Window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win_Window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallBack(event);
		});

		glfwSetCursorPosCallback(win_Window, [](GLFWwindow* win_Window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win_Window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallBack(event);
		});

	}

	void WindowsWindow::OnUpdate()
	{	
		glfwPollEvents();
		glfwSwapBuffers(win_Window);	
	}


	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(win_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		} else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}