#include "elyspch.h"
#include "Elys/Core/Input.h"

#ifdef ELYS_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Elys {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef ELYS_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		ELYS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}