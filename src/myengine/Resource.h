#pragma once

#include <string>

namespace myengine
{
	struct Resources;

	struct Resource
	{
		public:
			
		private:
			friend struct myengine::Resources;
			virtual void onInitialize();
			std::string path;
	};
}