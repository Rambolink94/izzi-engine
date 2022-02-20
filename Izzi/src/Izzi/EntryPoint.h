#pragma once

#ifdef IZ_PLATFORM_WINDOWS

extern Izzi::Application* Izzi::CreateApplication();

int main(int argc, char** argv)
{
	Izzi::Log::Init();
	IZ_CORE_WARN("Initialized Log!");
	IZ_INFO("Sup Bitch!");
	int a = 7;
	IZ_INFO("This a motha fuckin' variable {0}", a);

	auto app = Izzi::CreateApplication();
	app->Run();
	delete app;
}

#endif