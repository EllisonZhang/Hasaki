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
}

