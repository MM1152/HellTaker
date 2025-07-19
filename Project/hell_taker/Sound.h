#pragma once
class Sound
{
protected:
	SoundTypes type;
	sf::Sound sound;
public:
	void Play() { sound.play(); };
	void Stop() { sound.stop(); };

	sf::Sound::Status GetStatus() { return sound.getStatus(); };
	void SetLoop(bool isLoop) { sound.setLoop(isLoop); };
	void SetBuffer(sf::SoundBuffer& buffer) { sound.setBuffer(buffer); };
	void SetType(SoundTypes type) { this->type = type; };
	SoundTypes GetType() { return type; };
};

