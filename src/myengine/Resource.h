#pragma once

#include <string>

namespace myengine
{
	struct Resources;

	struct Resource
	{
		public:
			std::string getPath();
		private:
			friend struct myengine::Resources;
			virtual void onInit();
			std::string path;
	};
}