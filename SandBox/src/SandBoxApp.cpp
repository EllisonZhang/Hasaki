#include <Hasaki.h>

class SandBox : public HSK::Application {
public:
	SandBox() {
	}

	~SandBox() {
	}

};

HSK::Application* HSK::CreateApplication() {
	return new SandBox();
}