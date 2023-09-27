#pragma once
#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <memory>

using namespace sf;
using namespace std;

class AssetManager
{
	map<string, Texture> m_Textures;
	map<string, SoundBuffer> m_SoundsBuffers;
	map<string, Font> m_Fonts;
	map<string, unique_ptr<Shader>> m_Shaders;

	// AssetManager is a singleton, so only one instance can exist at a time
	// sInstance holds a static pointer to the single manager instance
	static AssetManager* sInstance;
public:
	AssetManager();

	static Texture& GetTexture(string const& filename);
	static SoundBuffer& GetSoundBuffer(string const& filename);
	static Font& GetFont(string const& filename);
	static Shader* GetShader(string const& vsFile, string const& fsFile);
};

#endif