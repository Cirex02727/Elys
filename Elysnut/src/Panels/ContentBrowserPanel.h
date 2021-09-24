#pragma once

#include <filesystem>

namespace Elys {

	class ContentBrowserPanel
	{
		public:
			ContentBrowserPanel();

			void OnImGuiRender();

		private:
			std::filesystem::path m_CurrentDirectory;
	};
}
