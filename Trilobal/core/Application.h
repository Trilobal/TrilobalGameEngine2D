#pragma once

#include "core.h"

namespace Trilobal {
	class TRILOBAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void isRun();
	};

	Application* CreateApplication();
}
