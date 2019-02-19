#pragma once

#include "core.hpp"
#include "log.hpp"

namespace mystery {

	class MYSTERY_API MysteryApplication
	{
	public:
		MysteryApplication();
		virtual	~MysteryApplication();
		void Run();
	};

}