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
	};
}