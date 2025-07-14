#pragma once
class AnimationClip
{
public:
	AnimationClip() = default;
	~AnimationClip() = default;

	std::string id;
	std::unordered_map<std::string, std::string> id2csv;
	std::vector<std::string> frames;
	int fps = 30;

	void loadFromFile(const std::string& path);
};

