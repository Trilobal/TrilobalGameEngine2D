#pragma once

#include "Application.h"

#ifdef TL_PLATFORM_WINDOWS

extern Trilobal::Application* Trilobal::CreateApplication();

int main(int argc, char** argv)
{
	Trilobal::log::Init();
	TL_CORE_WARN("Initialized Log!");
	TL_CLIENT_INFO("Welcome to use Trilobal Game Engine!");

	auto app = Trilobal::CreateApplication();
	app->isRun();
	delete app;
}

#endif
