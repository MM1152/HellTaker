#pragma once
#include "Singleton.h"

enum class SoundTypes {
	GAMESCENE_BACKGROUND,
	ENEMY_KICK,
	PLAYER_MOVE,
	CHANGE_MAP,
};

class Sound;
class SoundMgr : public Singleton<SoundMgr>
{
	friend Singleton<SoundMgr>;
protected:
	SoundMgr() = default;
	~SoundMgr() = default;

	SoundMgr(const SoundMgr& copy) = default;
	SoundMgr& operator = (const SoundMgr& copy) = default;

	std::vector<Sound*> sounds;
	std::unordered_map<SoundTypes, sf::SoundBuffer> buffers;
public:	
	void Init();
	void Play(SoundTypes type , bool isLoop = false);
	void Stop(SoundTypes type);
	void Release();
};

#define SOUND_MGR SoundMgr::Instance()

