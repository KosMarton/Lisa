#include "lspch.h"
#include "Lisa/Core/Input.h"

#ifdef LS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Lisa {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
	#ifdef LS_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
	#else
		LS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}