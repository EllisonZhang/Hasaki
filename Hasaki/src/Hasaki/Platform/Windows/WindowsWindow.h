#pragma once

#include "Hasaki/Window.h"
#include <GLFW/glfw3.h>

namespace HSK {
	
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		virtual void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.width;};
		inline unsigned int GetHeight() const override { return m_Data.height;};

		// window attributes
		virtual void SetEventCallBack(EventCallBackFnc func) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

		EventCallBackFnc EventCallBack;
		bool VSync;
		GLFWwindow* win_Window;
		WindowProps m_Data;
	};
}