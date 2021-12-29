#pragma once

#include "Event.h"

namespace HSK {
	/*Abstract Class of keyboard input*/
	class HSK_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int kc) : keyCode(kc) {}

		int keyCode;
	};

	// 
	class HSK_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int kc, int rc) : KeyEvent(kc), repeatCount(rc) {}
		inline int GetRepeatCount() { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << "(" << repeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int repeatCount;
	};

	class HSK_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int kc) :KeyEvent(kc) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}
