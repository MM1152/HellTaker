#pragma once


#define RESOURCE_PATH "Resources/"
#define SPRITE_PATH "Resources/Sprite/"
#define FONT_PATH "Resources/Font/"
#define KEY sf::Keyboard::Key 
#define MOUSE sf::Mouse

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <list>
#include <map>
#include <assert.h>
#include <fstream>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Define.h"
#include "Framework.h"
#include "Singleton.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "Utils.h"

std::string MAP_DATA(int x);
std::string MAP_IMAGE(int x);