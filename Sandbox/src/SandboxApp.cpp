#include "Emerald.h"

class Sandbox : public Emerald::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Emerald::Application* Emerald::CreateApplication() {
	return new Sandbox();
}