#include <Ori.h>

class Sandbox : public Ori::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Ori::Application* Ori::CreateApplication() {
	return new Sandbox();
}