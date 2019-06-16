#pragma once
#include "stb_image.h"
#include "Shader.h"

class TextureManager {

public:
	TextureManager();
	­~TextureManager();

	bool CreateTexture(const char* name, const char* path);
};

