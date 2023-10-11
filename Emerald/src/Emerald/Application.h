#pragma once

#include "Core.h"

namespace Emerald {
	class EMERALD_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client.
	Application* CreateApplication();
}