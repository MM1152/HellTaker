#include "stdafx.h"
#include "Boss.h"
#include "GameScene.h"
Boss::Boss(const std::string& texId, const std::string& name)
    :GameObject(name)
    ,texId(texId)
{
}

void Boss::SetPosition(const sf::Vector2f pos)
{
    position = pos;
    right.setPosition(pos);
    left.setPosition(pos);
}

void Boss::SetRotaion(const float rot)
{
    rotation = rot;
    right.setRotation(rot);
    left.setRotation(rot);
}

void Boss::SetOrigin(Origins preset)
{
    originPreset = preset;
    UTILS.SetOrigins(right, preset);
    UTILS.SetOrigins(left, preset);
}

void Boss::SetOrigin(sf::Vector2f ori)
{
    originPreset = Origins::Custom;
    right.setOrigin(ori);
    left.setOrigin(ori);
}

void Boss::SetScale(sf::Vector2f scale)
{
    this->scale = scale;
    right.setScale(scale);
    left.setScale(scale);
}

void Boss::Init()
{
    rightAni.SetTarget(&right);
    leftAni.SetTarget(&left);

    rightAni.SetEvent("bossWakeUp", -1, [this]() {
        rightAni.Play(ANI_PATH"bossAttack1.csv");
        leftAni.Play(ANI_PATH"bossAttack1.csv");
    });
    
    rightAni.SetEvent("bossAttack1", -1, [this]() {
        rightAni.Stop();
        leftAni.Stop();
        gameScene->SetCameraShake();
        Attack1(huddleCount , spawnHuddleX , spawnHuddleY);
    });
    rightAni.SetEvent("bossAttackRight", -1, [this]() {
        rightAni.Stop();
        gameScene->SetCameraShake();
        Attack1(huddleCount, spawnHuddleX, spawnHuddleY);
     });

    leftAni.SetEvent("bossAttack1", -1, [this]() {
        leftAni.Stop();
        gameScene->SetCameraShake();
        Attack1(huddleCount, spawnHuddleX, spawnHuddleY);
    });
}

void Boss::Reset()
{
    rightAni.Stop();
    leftAni.Stop();

    right.setTexture(TEXTURE_MGR.Get(texId));
    left.setTexture(TEXTURE_MGR.Get(texId));

    right.setScale({ 0.985, 1 });
    left.setScale({ -0.985 , 1 });

    UTILS.SetOrigins(right, Origins::RT);
    UTILS.SetOrigins(left, Origins::RT);

    right.setPosition({ 1920 / 2 - 20.f , 0 });
    left.setPosition({ 1920 / 2 - 20.f, 0 });

    rightAni.Play(ANI_PATH"bossWakeUp.csv" , true);
    leftAni.Play(ANI_PATH"bossWakeUp.csv" , true);

}

void Boss::Update(float dt)
{
    if (GetActive()) {
        leftAni.Update(dt);
        rightAni.Update(dt);
    }

    auto iter = bossHuddles.begin();

    while (iter != bossHuddles.end()) {
        if (!(*iter)->GetActive()) {
            bossHuddlsPool.push_back(*iter);
            iter = bossHuddles.erase(iter);
        }
        else {
            (*iter)->Update(dt);
            iter++;
        }
    }
}

void Boss::Exit()
{
}

void Boss::Release()
{
}

void Boss::Draw(sf::RenderWindow& window)
{
    window.draw(right);
    window.draw(left);

    for (auto huddle : bossHuddles) {
        if (huddle->GetActive()) {
            huddle->Draw(window);
        }
    }
}

sf::FloatRect Boss::GetLocalBound()
{
    return sf::FloatRect();
}

sf::FloatRect Boss::GetGlobalBound()
{
    return sf::FloatRect();
}

void Boss::Attack1(int count ,int row, int height)
{
    
    for (int i = 0; i < count; i++) {
        BossHuddle* bossHuddle;
        if (bossHuddlsPool.empty()) {
            bossHuddle = new BossHuddle();
            bossHuddle->Init();
            bossHuddle->Reset();
            bossHuddle->SetPlayer(player);
            
            bossHuddle->plusPos = { 50.f , 80.f };
            bossHuddle->callBack = [this](int row ,int height) {
                SetNextHuddle(row , height);
            };
            
        }
        else {
            bossHuddle = bossHuddlsPool.front();
            bossHuddlsPool.pop_front();
        }
       
        bossHuddle->SetReset();
        bossHuddle->SetMapData(MAP.GetGridSize() / 0.7f, row + i, height, SpriteTypes::NONE);
        bossHuddles.push_back(bossHuddle);
    }
    
    attackCount++;
    if (attackCount == 1) {
        huddleCount = 5;
        spawnHuddleX = workAbleRow;
        spawnHuddleY = workAbleHeight;
    }
}

void Boss::SetNextHuddle(int row , int height)
{
    if (height > 3) {
        rightAni.Play(ANI_PATH"bossAttackRight.csv" , true);
    }

    if (height <= workAbleMaxHeight) {
        Attack1(1, row, height);
    }
}


