#pragma once

#include "Event.h"

namespace HSK {
	
	class HSK_API MouseMovedEvent : Event{
	public:
		MouseMovedEvent(float X, float Y) : mPositionX(X), mPositionY(Y) {}

		inline float GetX() {return mPositionX;}
		inline float GetY() {return mPositionY;}

		std::string ToString() 
		{
			std::stringstream ss;
			ss << "MouseMovedEvent " << "X:" << mPositionX << "Y:" << mPositionY;
			ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse) 
	private:
		float mPositionX, mPositionY;
	};

	class HSK_API MouseScrolledEvent : Event {
	public:
		MouseScrolledEvent(float X, float Y) : xOffset(X), yOffset(Y) {}

		inline float GetXOffset() { return xOffset; }
		inline float GetYOffset() { return yOffset; }

		std::string ToString()
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent " << "X:" << xOffset << "Y:" << yOffset;
			ss.str();
		}

	private:
		float xOffset, yOffset;
	};

	class HSK_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class HSK_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MousePressed)
	};

	class HSK_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseReleased)
	};

}