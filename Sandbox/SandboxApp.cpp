#include <Trilobal.h>

class Sandbox : public Trilobal::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}

};

Trilobal::Application* Trilobal::CreateApplication()
{
	TL_CLIENT_INFO("CREATE SUCCESSFULLY");
	return new Sandbox();
}