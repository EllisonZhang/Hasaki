#pragma once

#include "Hasaki/Core.h"
#include "Hasaki/Events/Event.h"

namespace HSK{

	class HSK_API Layer 
	{
	public:
		Layer(const std::string& name = "Default Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnAttach() {}
		virtual void OnAttach() {}

		inline std::string& GetName() const { return debugName; }

	protected:
		std::string debugName;
	};
}