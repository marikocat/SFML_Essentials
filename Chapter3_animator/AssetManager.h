#pragma once
#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace sf;
using namespace std;

class AssetManager
{
	map<string, Texture> m_Textures;

	// AssetManager is a singleton, so only one instance can exist at a time
	// sInstance holds a static pointer to the single manager instance
	static AssetManager* sInstance;
public:
	AssetManager();

	static Texture& GetTexture(string const& filename);
};

#endif