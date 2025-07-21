#include "stdafx.h"
#include "SoundMgr.h"
#include "Sound.h";

void SoundMgr::Init()
{
	buffers.insert({ SoundTypes::GAMESCENE_BACKGROUND, SOUNDBUFFER_MGR.Get(SOUND_PATH"GameSceneSound.wav") });
	buffers.insert({ SoundTypes::CHANGE_MAP, SOUNDBUFFER_MGR.Get(SOUND_PATH"screen_changer_2_part1.wav") });
	buffers.insert({ SoundTypes::ENEMY_KICK, SOUNDBUFFER_MGR.Get(SOUND_PATH"enemy_kick_01.wav") });
	buffers.insert({ SoundTypes::PLAYER_MOVE, SOUNDBUFFER_MGR.Get(SOUND_PATH"character_move_01.wav") });
	buffers.insert({ SoundTypes::PLAYER_DEATH , SOUNDBUFFER_MGR.Get(SOUND_PATH"player_death_01.wav") });
	buffers.insert({ SoundTypes::ENEMY_DIE , SOUNDBUFFER_MGR.Get(SOUND_PATH"enemy_die_01.wav") });
	buffers.insert({ SoundTypes::SPIKE_HIT , SOUNDBUFFER_MGR.Get(SOUND_PATH"spikes_damage_01.wav") });
	buffers.insert({ SoundTypes::KEY_PICKUP , SOUNDBUFFER_MGR.Get(SOUND_PATH"key_pick_up_01.wav") });
	buffers.insert({ SoundTypes::STONE_KICK , SOUNDBUFFER_MGR.Get(SOUND_PATH"stone_kick_01.wav") });
	buffers.insert({ SoundTypes::STONE_MOVE , SOUNDBUFFER_MGR.Get(SOUND_PATH "stone_move_01.wav") });
	buffers.insert({ SoundTypes::DIALOGUE_OPEN , SOUNDBUFFER_MGR.Get(SOUND_PATH"dialogue_start_01.wav") });
	buffers.insert({ SoundTypes::BOSS_HIT , SOUNDBUFFER_MGR.Get(SOUND_PATH"boss2_damage_01.wav") });
	buffers.insert({ SoundTypes::BOSS_ATTACK , SOUNDBUFFER_MGR.Get(SOUND_PATH"boss2_hand_hit_01.wav") });
	buffers.insert({ SoundTypes::BOSS_WAKEUP , SOUNDBUFFER_MGR.Get(SOUND_PATH"boss2_battle_end_01.wav") });
	buffers.insert({ SoundTypes::BOSS_BEAM , SOUNDBUFFER_MGR.Get(SOUND_PATH"boss2_beam_01.wav") });
}

void SoundMgr::Play(SoundTypes type, bool isLoop)
{
	for (auto sound : sounds) {
		if (sound->GetStatus() == sf::Sound::Stopped) {
			sound->SetType(type);
			sound->SetBuffer(buffers[type]);
			sound->SetLoop(isLoop);
			sound->Play();
			return;
		}
	}

	Sound* sound = new Sound();
	sound->SetType(type);
	sound->SetBuffer(buffers[type]);
	sound->SetLoop(isLoop);
	sound->Play();

	sounds.push_back(sound);
}

void SoundMgr::Stop(SoundTypes type)
{
	for (auto sound : sounds) {
		if (sound->GetType() == type && sound->GetStatus() != sf::Sound::Stopped) {
			sound->Stop();
			return;
		}
	}
}

void SoundMgr::Release()
{
	for (auto sound : sounds) {
		delete sound;
	}
}
