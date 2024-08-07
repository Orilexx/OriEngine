#pragma once

//Entry point inside the Ori engine

#ifdef ORI_PLATFORM_WINDOWS

extern Ori::Application* Ori::CreateApplication();

int main(int argc, char** argv) {

	auto app = Ori::CreateApplication();
	app->Run();

	delete app;
}

#endif