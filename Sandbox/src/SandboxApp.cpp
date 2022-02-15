#include <Izzi.h>

class Sandbox : public Izzi::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Izzi::Application* Izzi::CreateApplication()
{
	return new Sandbox();
}