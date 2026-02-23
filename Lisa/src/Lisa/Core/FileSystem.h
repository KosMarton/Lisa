#pragma once

#include "Lisa/Core/Buffer.h"

namespace Lisa {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}