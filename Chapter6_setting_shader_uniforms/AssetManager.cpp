#include "AssetManager.h"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	assert(sInstance == nullptr);
	sInstance = this;
}

Texture& AssetManager::GetTexture(string const& filename)
{
	auto& texMap = sInstance->m_Textures;

	auto pairFound = texMap.find(filename);
	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

SoundBuffer& AssetManager::GetSoundBuffer(string const& filename)
{
	auto& sBufferMap = sInstance->m_SoundsBuffers;

	auto pairFound = sBufferMap.find(filename);
	if (pairFound != sBufferMap.end())
	{
		return pairFound->second;
	}
	else
	{
		// Create an element in the SoundBuffer map
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

Font& AssetManager::GetFont(string const& filename)
{
	auto& fontMap = sInstance->m_Fonts;

	auto pairFound = fontMap.find(filename);
	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		// Create an element in the Fonts map
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

Shader* AssetManager::GetShader(string const& vsFile, string const& fsFile)
{
	auto& shaderMap = sInstance->m_Shaders;

	auto combinedKey = vsFile + ";" + fsFile;
	auto pairFound = shaderMap.find(combinedKey);
	if (pairFound != shaderMap.end())
	{
		return pairFound->second.get();
	}
	else
	{
		auto& shader = (shaderMap[combinedKey] = unique_ptr<Shader>(new Shader()));
		shader->loadFromFile(vsFile, fsFile);
		return shader.get();
	}
}