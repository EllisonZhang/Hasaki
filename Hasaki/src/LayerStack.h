#pragma once

#include "Hasaki/Core.h"
#include "Layer.h"

#include <vector>

namespace HSK {

	class HSK_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverLay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }
	private:
		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layerInsert;
	};
}