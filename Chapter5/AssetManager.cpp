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
		texture.loadFromFile(filename, IntRect(0, 0, 32, 32));
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