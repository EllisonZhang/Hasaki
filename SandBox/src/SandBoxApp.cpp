#include <Hasaki.h>

class ExampleLayer : public HSK::Layer {
public:

	ExampleLayer() : Layer("Example") {}
	
	void OnUpdate() override {
		HSK_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(HSK::Event& event) override {
		/* have some bugs using trace*/
		// HSK_CORE_TRACE("{0}", event);
		HSK_CLIENT_TRACE("ExampleLayer::OnEvent");
	}
};

class SandBox : public HSK::Application {
public:
	SandBox() {
		PushLayer(new ExampleLayer());
	}

	~SandBox() {
	}
};

HSK::Application* HSK::CreateApplication() {
	return new SandBox();
}