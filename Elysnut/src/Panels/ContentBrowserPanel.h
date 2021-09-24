#pragma once

#include <filesystem>

#include "Elys/Renderer/Texture.h"

namespace Elys {

	class ContentBrowserPanel
	{
		public:
			ContentBrowserPanel();

			void OnImGuiRender();

		private:
			std::filesystem::path m_CurrentDirectory;
			Ref<Texture2D> m_DirectoryIcon;
			Ref<Texture2D> m_FileIcon;
	};
}