#pragma once

#include <string>

namespace Elys {

	class FileDialogs
	{
		public:
			// These return empty string if canceled
			static std::string OpenFile(const char* filter);
			static std::string SaveFile(const char* filter);
	};
}
