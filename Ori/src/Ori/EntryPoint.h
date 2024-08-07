#pragma once

//Entry point inside the Ori engine

#ifdef ORI_PLATFORM_WINDOWS

extern Ori::Application* Ori::CreateApplication();

int main(int argc, char** argv) {

	Ori::Log::Init(); // Temporary, will be moved in a proper system initialization function

	ORI_CORE_WARN("Core Logger initialized !");
	ORI_INFO("Client Logger initialized !");

	auto app = Ori::CreateApplication();
	app->Run();

	delete app;
}

#endif