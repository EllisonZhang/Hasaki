#include "HasakiPCH.h"
#include "LayerStack.h"

namespace HSK {

	LayerStack::LayerStack() 
	{
		layerInsert = layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void LayerStack::PushOverLay(Layer* overlay) {
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);

		if (it != layers.end()) {
			layers.erase(it);
			layerInsert--;
		}
	}

	void LayerStack::PopOverLay(Layer* overlay) {
		auto it = std::find(layers.begin(), layers.end(), overlay);

		if (it != layers.end()) {
			layers.erase(it);
		}
	}

}

