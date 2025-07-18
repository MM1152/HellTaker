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
        attackCount++;
        
        rightAni.Stop();
        leftAni.Stop();
    
        gameScene->SetCameraShake();

       
        Attack1(huddleCount , spawnHuddleX , spawnHuddleY);

        
        if (attackCount == 1) {
            huddleCount = 5;
            spawnHuddleX = workAbleRow;
            spawnHuddleY = workAbleHeight;
        }
        else if(attackCount == 2){
            huddleCount = 5;
            spawnHuddleX = workAbleMaxRow - 4;
            spawnHuddleY = workAbleHeight;
        }
        else if (attackCount == 3) {
            huddleCount = 7;
            spawnHuddleX = 6;
            spawnHuddleY = 6;
        }
        else if (attackCount == 4) {
            ShootLayser();
        }
    });

}

void Boss::Reset()
{
    layserBlocks.clear();
    layserIdx = 0;
    attackCount = 0;
    huddleCount = 7;
    spawnHuddleX = 6;
    spawnHuddleY = 6;

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

    for (auto huddle : bossHuddles) {
        huddle->SetActive(false);
        bossHuddlsPool.push_back(huddle);
    }
    bossHuddles.clear();
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
    for (auto huddle : bossHuddles) {
        delete huddle;
    }
    bossHuddles.clear();

    for (auto huddle : bossHuddlsPool) {
        delete huddle;
    }
    bossHuddlsPool.clear();
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
    startAnimation = false;
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
    

}

void Boss::SetNextHuddle(int row , int height)
{
    if (height == workAbleRow + 2 && !startAnimation && attackCount < 4) {
        rightAni.Play(ANI_PATH"bossAttack1.csv");
        leftAni.Play(ANI_PATH"bossAttack1.csv");
        startAnimation = true;
    }
    

    if (height <= workAbleMaxHeight ) {
        Attack1(1, row, height);
    }
}

void Boss::ShootLayser()
{
    if (layserIdx >= layserOrder.size()) return;
    layserBlocks[layserOrder[layserIdx++] - 1]->SetShoot();  
}

void Boss::SetLayserBlock(LayserBlock* layser)
{
    layserBlocks.push_back(layser); 
    layser->shootNextLayser = [this]() {
        ShootLayser();
    };
}


