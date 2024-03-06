#pragma once

extern Krakatoa::Application* Krakatoa::createApplication();

int main(int argc, char** argv)
{
	Krakatoa::Debug::init();
	KRAKATOA_CORE_INFO("HELLO");

	auto application = Krakatoa::createApplication();
	application->run();
	delete application;
}