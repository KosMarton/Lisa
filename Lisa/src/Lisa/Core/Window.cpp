#include "lspch.h"
#include "Lisa/Core/Window.h"

#ifdef LS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Lisa {

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef LS_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		LS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}