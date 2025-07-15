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

                
                isPlayAnimation = true;
                --moveCount;
                if (Die()) return false;

                if (changeMoveCountFunc) {
                    changeMoveCountFunc(moveCount);
                }
                if (obs->GetObjectId() == SpriteTypes::OBSTACLE || obs->GetObjectId() == SpriteTypes::ENEMY) {
                    obs->Move(inputKey.x, inputKey.y);
                }
                else if (obs->GetObjectId() == SpriteTypes::GOLDKEY) {
                    isGetKey = true;
                    return true;
                }
                else if (obs->GetObjectId() == SpriteTypes::BOX && isGetKey) {
                    obs->SetActive(false);
                    return true;
                }
                ChangeAnimation(ANI_PATH"playerKick.csv");
                return false;
            }
        }
    }

    --moveCount;
    if (Die()) return false;
    if (changeMoveCountFunc) {
        changeMoveCountFunc(moveCount);
    }
    ChangeAnimation(ANI_PATH"playerMove.csv");
   
    return true;
}

Player::Player(const std::string texId, const std::string name)
    :MoveAbleObject(texId , name)
{
}

void Player::Exit()
{
}

void Player::Init()
{
    dieAnimationBackGround.setSize({ 1920 , 1080 });
    dieAnimationBackGround.setFillColor(sf::Color(2, 2 , 27));
    
    moveEffect.Init();

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
        if (changeMapAnimationFunc) {
            changeMapAnimationFunc();
        }
        isDie = false;
        isPlayAnimation = false;
    });
}

void Player::Update(float dt)
{
    animator.Update(dt);
    moveEffect.Update(dt);

    if (!isPlayAnimation) {
        
        if (INPUT_MGR.GetKeyDown(KEY::Left)) {
            inputKey = { -1,0 };
            Move(-1, 0);
        }
        if (INPUT_MGR.GetKeyDown(KEY::Right)) {
            inputKey = { 1,0 };
            Move(1, 0);
        }
        if (INPUT_MGR.GetKeyDown(KEY::Down)) {
            inputKey = { 0,1 };
            Move(0, 1);
        }
        if (INPUT_MGR.GetKeyDown(KEY::Up)) {
            inputKey = { 0,-1 };
            Move(0, -1);
        }
       
    }
    
}

void Player::Reset()
{
    MoveAbleObject::Reset();
    isGetKey = false;
    SetOrigin(Origins::MB);
    moveEffect.Reset();
    obstacleList.clear();
    //SetPosition({ GetPosition().x + plusPos.x , GetPosition().y + plusPos.y });
    animator.Play(ANI_PATH"playerIdle.csv");

}

void Player::Draw(sf::RenderWindow& window)
{
    
    if (isDie) {
        window.draw(dieAnimationBackGround);
    }
    if (moveEffect.GetActive()) {
        moveEffect.Draw(window);
    }
    
    MoveAbleObject::Draw(window);
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
    if (CheckBound(upX + x, upY + y)) {
        if(inputKey.x != 0) SetScale({ std::abs(GetScale().x) * inputKey.x , GetScale().y });
        
        moveEffect.SetPosition({GetPosition().x , GetPosition().y});
        moveEffect.Play();
        std::cout << GetPosition().x << "," << GetPosition().y << std::endl;
        MoveAbleObject::Move(upX, upY);
        
    }
}

bool Player::Die()
{
    if (moveCount == -1 && !isDie) {
        ChangeAnimation(ANI_PATH"playerDie.csv", true);
        SetPosition({ GetPosition().x , GetPosition().y - 170.f });
        isDie = true;
        isPlayAnimation = true;

        return true;
    }
    return false;
}
