#include "stdafx.h"
#include "Player.h"
#include "NPC.h"
#include "GameScene.h"
#include "UpDownHudle.h"
#include "MoveEffect.h"
#include "HitEffect.h"
#include "Enemy.h"
#include "KickEffect.h"
bool Player::CheckBound(int row, int height)
{
    if (!MoveAbleObject::CheckBound(row , height)) {
        return false;
    }
    
    moveCount--;
    SOUND_MGR.Play(SoundTypes::PLAYER_MOVE);
    if (inputKey.x != 0) SetScale({ std::abs(GetScale().x) * inputKey.x , GetScale().y });

    for (auto obs : obstacleList) {
        if (obs->GetType() == SpriteTypes::UPDOWNHUDLE || obs->GetType() == SpriteTypes::DOWNUPHUDDLE) {
            ((UpDownHudle*)obs)->Play();
        }
    }
    for (auto enemy : obstacleList) {
        if (enemy->GetType() == SpriteTypes::ENEMY) {
            ((Enemy*)enemy)->CheckUnderHuddle();
        }
    }

    bool moveAble = true;
    for (auto obs : obstacleList) {
        if (height == obs->GetXY().y && row == obs->GetXY().x) {
            
            // 여기서 각 장애물마다 수행해야되는 부분으로 짧게 짤수 있을거같음
            // 플레이어랑 장애물이랑 거리값 넘겨줘서 해당하면 수행하게 하면될듯
            if (isDie) return false;
            if (!obs->GetActive()) return true;
            if (obs->GetObjectId() == SpriteTypes::OBSTACLE || obs->GetObjectId() == SpriteTypes::ENEMY) {
                obs->Move(inputKey.x, inputKey.y);
                moveAble = false;
            }
     /*       else if (obs->GetObjectId() == SpriteTypes::HUDLE) {
                moveCount--;
            }*/
            else if (obs->GetObjectId() == SpriteTypes::GOLDKEY) {
                isGetKey = true;
                obs->Interaction();
            }
            else if (obs->GetObjectId() == SpriteTypes::BOX && isGetKey) {
                obs->Interaction();
            }
            else if (obs->GetObjectId() == SpriteTypes::BOX && !isGetKey) {
                moveAble = false;
            }
            else if (obs->GetObjectId() == SpriteTypes::BOSSMAPLASER) {
                moveAble = false;
            }
            else if (obs->GetObjectId() == SpriteTypes::BOSS) {
                moveAble = false;
                obs->Interaction();
            }

            //isPlayAnimation = true;
        }
    }
     
    if (!moveAble) {
        ChangeAnimation(ANI_PATH"playerKick.csv");
        PlayEffectAnimation(EffectType::Kick);
        effectAnimation[EffectType::Kick]->SetPosition({ row * gridSize.x, height * gridSize.y - 20.f});
    }
    return moveAble;
}

void Player::PlayEffectAnimation(EffectType type)
{
    effectAnimation[type]->SetPosition(GetPosition());
    effectAnimation[type]->Play();
}

Player::Player(const std::string texId, const std::string name)
    :MoveAbleObject(texId , name)
{
    sortingLayer = SortingLayers::FORGROUND;
    sortingOrder = 5;
}

void Player::Exit()
{
}

void Player::Init()
{
    dieAnimationBackGround.setSize({ 1920 , 1080 });
    dieAnimationBackGround.setFillColor(sf::Color(2, 2 , 27));
    
    effectAnimation.insert({ EffectType::Move , new MoveEffect() });
    effectAnimation.insert({ EffectType::Hit , new HitEffect() });
    effectAnimation.insert({ EffectType::Kick , new KickEffect() });

    animator.SetTarget(&sprite);
    SetScale({ 0.8f , 0.8f });
    animator.SetEvent("playerKick", -1, [this]() {
        ChangeAnimation(ANI_PATH"playerIdle.csv");
        //SetPosition({ GetPosition().x , GetPosition().y });
        isPlayAnimation = false;
        });
    animator.SetEvent("playerMove", -1, [this]() {
        ChangeAnimation(ANI_PATH"playerIdle.csv");
        //SetPosition({ GetPosition().x , GetPosition().y });
        isPlayAnimation = false;
       });
    animator.SetEvent("playerDie", -1, [this]() {
        animator.Stop();
        if (changeMapAnimationFunc) {
            changeMapAnimationFunc();
        }
    });

    for (auto effect : effectAnimation) {
        effect.second->Init();
    }
}

void Player::Update(float dt)
{
    animator.Update(dt);
    
    MoveAbleObject::Update(dt);
  
    for (auto effect : effectAnimation) {
        effect.second->Update(dt);
    }
    if (isHit && !isMoveAble) {
        PlayEffectAnimation(EffectType::Hit);
        isHit = false;
    }

    if (!isPlayAnimation && !MAP.isClear) {
    
        if (INPUT_MGR.GetKeyDown(KEY::Left)) {
            inputKey = { -1,0 };
            Move(-1, 0);
        }
        else if (INPUT_MGR.GetKeyDown(KEY::Right)) {
            inputKey = { 1,0 };
            Move(1, 0);
        }
        else if (INPUT_MGR.GetKeyDown(KEY::Down)) {
            inputKey = { 0,1 };
            Move(0, 1);
        }
        else if (INPUT_MGR.GetKeyDown(KEY::Up)) {
            inputKey = { 0,-1 };
            Move(0, -1);
        }  
    }
    
}

void Player::Reset()
{
    MoveAbleObject::Reset();
    isGetKey = false;
    isDie = false;
    isPlayAnimation = false;
    SetOrigin(Origins::MC);
    obstacleList.clear();
    //SetPosition({ GetPosition().x + plusPos.x , GetPosition().y + plusPos.y });
    ChangeAnimation(ANI_PATH"playerIdle.csv");

    for (auto effect : effectAnimation) {
        effect.second->Reset();
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    
    if (isDie) {
        window.draw(dieAnimationBackGround);
    }
    
    MoveAbleObject::Draw(window);
    for (auto effect : effectAnimation) {
        if (effect.second->GetActive()) {
            effect.second->Draw(window);
        }
    }
}

void Player::Release()
{
    MoveAbleObject::Release();
    for (auto effect : effectAnimation) {
        delete effect.second;
    }
    effectAnimation.clear();
}

void Player::AddObstacle(Obstacle* obs)
{
    obstacleList.push_back(obs);
}

void Player::ChangeAnimation(const std::string& id , bool resetTextureRect)
{
    if (id == ANI_PATH"playerIdle.csv") {
        sprite.setTextureRect(sf::IntRect(0, 30, 100, 100));
    }
    else {
        sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
    }
    animator.Play(id , resetTextureRect);
    SetOrigin(Origins::MC);
}

void Player::Move(int upX, int upY)
{   
    if (Die()) return;
    if (CheckBound(upX + x, upY + y)) {
        //if(inputKey.x != 0) SetScale({ std::abs(GetScale().x) * inputKey.x , GetScale().y });
        ChangeAnimation(ANI_PATH"playerMove.csv");
        PlayEffectAnimation(EffectType::Move);
        MoveAbleObject::Move(upX, upY);
    }
    
    for (auto obs : obstacleList) {
        if (obs->GetType() == SpriteTypes::HUDLE || obs->GetType() == SpriteTypes::UPDOWNHUDLE || obs->GetType() == SpriteTypes::DOWNUPHUDDLE) {
            if (obs->GetXY().x == x && obs->GetXY().y == y && ((Huddle*)obs)->GetHitAble()) {
                isHit = true;
                gameScene->SetCameraShake();
                moveCount--;
            }
        }
    }
    for (auto obs : obstacleList) {
        if (obs->GetType() == SpriteTypes::MAP1NPC) {
            sf::Vector2i pos = obs->GetXY();
            if (std::abs(pos.x - x) + std::abs(pos.y - y) == 1) {
                std::cout << "END GAME" << std::endl;
                ((NPC*)obs)->ClearMap();
            }
        }
    }

    changeMoveCountFunc(moveCount);
}

bool Player::Die()
{
    if (moveCount <= 0 && !isDie) {
        ChangeAnimation(ANI_PATH"playerDie.csv", true);
        SetPosition({ GetPosition().x , GetPosition().y - 180.f});
        isDie = true;
        isPlayAnimation = true;

        return isDie;
    }
    return isDie;
}
