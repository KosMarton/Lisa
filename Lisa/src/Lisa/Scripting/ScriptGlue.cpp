#include "lspch.h"
#include "Lisa/Scripting/ScriptGlue.h"

#include <mono/metadata/object.h>

namespace Lisa {

#define LS_ADD_INTERNAL_CALL(Name) mono_add_internal_call("Lisa.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
		std::cout << str << ", " << parameter << std::endl;
	}

	static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		//LS_CORE_WARN("Value: {0}", *parameter);
		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		//LS_CORE_WARN("Value: {0}", *parameter);
		return glm::dot(*parameter, *parameter);
	}

	void ScriptGlue::RegisterFunctions()
	{
		LS_ADD_INTERNAL_CALL(NativeLog);
		LS_ADD_INTERNAL_CALL(NativeLog_Vector);
		LS_ADD_INTERNAL_CALL(NativeLog_VectorDot);
	}

}