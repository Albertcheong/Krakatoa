#include <Krakatoa.hpp>

class Sandbox : public Krakatoa::Application
{
	public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
	
};

Krakatoa::Application* Krakatoa::createApplication()
{
	return new Sandbox;
}