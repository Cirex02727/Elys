#include "elyspch.h"
#include "Elys/Core/Window.h"

#ifdef ELYS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Elys
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef ELYS_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		ELYS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}
