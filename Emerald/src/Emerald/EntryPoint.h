#pragma once

#include "../Emerald.h"

#ifdef EMERALD_PLATFORM_WINDOWS

extern Emerald::Application* Emerald::CreateApplication();

int main(int argc, char** argv) {
	Emerald::Log::Init();

	EMERALD_CORE_WARN("Initialized Log!");
	EMERALD_INFO("We're in the Emerald Game Engine!");

	auto app = Emerald::CreateApplication();
	app->Run();
	delete app;
}

#endif