#pragma once
#include "Core.h"

namespace Ori {

	class ORI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	//TODO in client
	Application* CreateApplication();

}
