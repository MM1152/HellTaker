#pragma once
#include "Singleton.h"

template<typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend class Singleton<ResourceMgr<T>>;

protected:
	ResourceMgr() = default;
	~ResourceMgr() = default;

	std::unordered_map<std::string, T*> map;
	T empty;
public:
	void Load(const std::string id) {

		if (map.find(id) == map.end()) {
			T* item = new T();
			item->loadFromFile(id);
			map.insert({ id , item });
		}
	}
	void Load(const std::vector<std::string> ids) {
		for (std::string : ids) {
			Load(ids);
		}
	}
	T& Get(const std::string id) {
		if (map.find(id) == map.end()) {
			std::cout << "FAIL TO LOAD " << id << std::endl;
			return empty;
		}

		return *map[id];
	}

	void UnLoad() {
		for (auto item : map) {
			delete item.second;
		}

		map.clear();
	}
};

#define TEXTURE_MGR ResourceMgr<sf::Texture>::Instance()

