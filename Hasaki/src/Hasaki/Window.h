#pragma once

#include "HasakiPCH.h"
#include "Events/Event.h"

namespace HSK {

	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& t = "Hasaki Engine",
			unsigned int w = 1280, unsigned int h = 720)
			: title(t), width(w), height(h) {}
	};

	// A Interface representing a desktop system based window
	class HSK_API Window
	{
	public:
		using EventCallBackFnc = std::function<void(Event&)>;
		virtual ~Window() {};
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// window attributes
		virtual void SetEventCallBack(EventCallBackFnc func) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& = WindowProps());
	};
}