#include "stdafx.h"
#include "AnimationClip.h"
#include "rapidcsv.h"
void AnimationClip::loadFromFile(const std::string& path)
{
	rapidcsv::Document doc(path);

	id = doc.GetCell<std::string>(0, 0);
	fps = doc.GetCell<int>(1, 0);
	
	frames.clear();

	auto row = doc.GetRow<std::string>(2);
	for (int i = 0; i < row.size(); i++) {
		TEXTURE_MGR.Load(row[i]);
		frames.push_back(row[i]);
	}

	id2csv.insert({ id , frames[0] });
}
