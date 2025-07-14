#include "stdafx.h"
#include "Player.h"
#include "NPC.h"
#include "GameScene.h"
void Player::TestPrint()
{
    for (int i = 0; i < GameScene::mapData.size(); i++) {
        for (int j = 0; j < GameScene::mapData[i].size(); j++) {
            std::cout << GameScene::mapData[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
bool Player::CheckBound(int row, int height)
{
    for (auto obs : obstacleList) {
        if (obs->GetType() == SpriteTypes::MAP1NPC) {
            sf::Vector2i pos = obs->GetXY();
            if (std::abs(pos.x - row) + std::abs(pos.y - height) == 1) {
                std::cout << "END GAME" << std::endl;
                ((NPC*)obs)->ClearMap();
                return true;
            }
        }
    }

    if (!MoveAbleObject::CheckBound(row , height)) {
        return false;
    }
       
    if (GameScene::mapData[height][row] != 1) {
        for (auto obs : obstacleList) {
            if (height == obs->GetXY().y && row == obs->GetXY().x) {
                obs->Move(inputKey.x, inputKey.y);
                return false;
            }
        }
    }

    //플레이어의 추가적인 로직 추가
    return true;
}

Player::Player(const std::string texId, const std::string name)
    :MoveAbleObject(texId , name)
{
}

void Player::Init()
{
    animator.SetTarget(&sprite);

    
}

void Player::Update(float dt)
{
    animator.Update(dt);
    if (INPUT_MGR.GetKeyDown(KEY::Left)) {
        inputKey = { -1,0 };
        if (CheckBound(x - 1, y)) {
            SetScale({ -(std::abs(GetScale().x)) , GetScale().y });
            Move(-1 , 0);
            SetPosition({ GetPosition().x + plusPos.x, GetPosition().y + plusPos.y});
            TestPrint();
        }
    }
    if (INPUT_MGR.GetKeyDown(KEY::Right)) {
        inputKey = { 1,0 };
        if (CheckBound(x + 1, y)) {
            SetScale({ std::abs(GetScale().x) , GetScale().y });
            Move(1 , 0);
            SetPosition({ GetPosition().x + plusPos.x, GetPosition().y + plusPos.y });
            TestPrint();
        }
    }
    if (INPUT_MGR.GetKeyDown(KEY::Down)) {
        inputKey = { 0,1 };
        if (CheckBound(x, y + 1)) {
            Move(0 , 1);
            SetPosition({ GetPosition().x + plusPos.x, GetPosition().y + plusPos.y });
            TestPrint();
        }
    }
    if (INPUT_MGR.GetKeyDown(KEY::Up)) {
        inputKey = { 0,-1 };
        if (CheckBound(x, y - 1)) {
            Move(0 , -1);
            SetPosition({ GetPosition().x + plusPos.x, GetPosition().y + plusPos.y });
            TestPrint();
        }
    }
}

void Player::Reset()
{
    MoveAbleObject::Reset();
    obstacleList.clear();
    SetOrigin(Origins::MC);
    SetScale({ 0.8f , 0.8f });
    animator.Play(ANI_PATH"playerIdle.csv");
}

void Player::AddObstacle(Obstacle* obs)
{
    obstacleList.push_back(obs);
}
