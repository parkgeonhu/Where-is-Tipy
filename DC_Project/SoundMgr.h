#pragma once
#include "fmod.hpp"

using namespace FMOD;

enum SOUND_ID {
	BUTTON_BGM,
	CLEAR_BGM,
	INGAME_BGM,
	MAIN_BGM,
	STAR_BGM,
	STORY1_BGM,
	STORY2_BGM,
	PLAYERUP_BGM,
	PLAYERDOWN_BGM,
	DEAD_BGM,
	BOSS_BGM,
	SOUND_END
};

class SoundMgr {
public:
	SoundMgr();
	~SoundMgr();

	bool NowPlaying[SOUND_END];

	void Update();
	void addSound(int num, char *path);
	void Play(int num);
	void Playis(int num);
	void Stop(int num);
	void SetVolume(int num, float fv);
};