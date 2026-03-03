#pragma once

#include "Lisa/Renderer/Texture.h"

#include <filesystem>

namespace Lisa {

	struct MSDFData;

	class Font
	{
	public:
		Font(const std::filesystem::path& filePath);
		~Font();

		Ref<Texture2D> GetAtlasTexture() const { return m_AtlasTexture; }
	private:
		MSDFData* m_Data;
		Ref<Texture2D> m_AtlasTexture;
	};

}