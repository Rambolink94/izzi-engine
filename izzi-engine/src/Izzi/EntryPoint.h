#pragma once

#ifdef IZ_PLATFORM_WINDOWS

extern Izzi::Application* Izzi::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Izzi::CreateApplication();
	app->Run();
	delete app;
}

#endif