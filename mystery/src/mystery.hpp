#pragma once

#include "core.hpp"
#include "log.hpp"

namespace Mystery {

	class MYSTERY_API MysteryApplication
	{
	public:
		MysteryApplication();
		virtual	~MysteryApplication();
		void Run();
	};

}