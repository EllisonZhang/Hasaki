#pragma once

#include "Event.h"

namespace HSK {
	
	class HSK_API MouseMovedEvent : public Event{
	public:
		MouseMovedEvent(float X, float Y) : mPositionX(X), mPositionY(Y) {}

		inline float GetX() const {return mPositionX;}
		inline float GetY() const {return mPositionY;}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent " << mPositionX << ", " << mPositionY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse) 
	private:
		float mPositionX, mPositionY;
	};

	class HSK_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float X, float Y) : xOffset(X), yOffset(Y) {}

		inline float GetXOffset() { return xOffset; }
		inline float GetYOffset() { return yOffset; }

		std::string ToString()
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: "<< xOffset << "," << yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse)

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