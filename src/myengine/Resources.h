#pragma once

#include "Resource.h"

#include <vector>
#include <memory>
#include <string>

namespace myengine
{
	struct Resource;

	// Resources contains a vector of resource
	struct Resources
	{
		public:
			template <typename T>
			std::shared_ptr<T> load(const std::string& _path)
			{
				std::shared_ptr<T> rtn;

				for (size_t ri = 0; ri < resources.size(); ri++)
				{
					std::shared_ptr<Resource> r = resources.at(ri);
					if (r->path != _path) continue;
					rtn = std::dynamic_pointer_cast<T>(r);
					if (rtn) return rtn;
				}

				rtn = std::make_shared<T>();
				rtn->path = _path;
				//rtn->resources = self;
				rtn->onInitialize();
				resources.push_back(rtn);

				return rtn;
			}
		private:
			friend struct myengine::Resource;
			std::vector<std::shared_ptr<Resource>> resources;
	};
}