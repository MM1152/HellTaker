#include "stdafx.h"
#include "Boss.h"

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

    rightAni.Play(ANI_PATH"bossWakeUp.csv");
    leftAni.Play(ANI_PATH"bossWakeUp.csv");
}

void Boss::Reset()
{
    right.setTexture(TEXTURE_MGR.Get(texId));
    left.setTexture(TEXTURE_MGR.Get(texId));

    right.setScale({ 0.985, 1 });
    left.setScale({ -0.985 , 1 });

    UTILS.SetOrigins(right, Origins::RT);
    UTILS.SetOrigins(left, Origins::RT);

    right.setPosition({ 1920 / 2 - 20.f , 0 });
    left.setPosition({ 1920 / 2 - 20.f, 0 });
}

void Boss::Update(float dt)
{
    if (GetActive()) {
        leftAni.Update(dt);
        rightAni.Update(dt);
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
}

sf::FloatRect Boss::GetLocalBound()
{
    return sf::FloatRect();
}

sf::FloatRect Boss::GetGlobalBound()
{
    return sf::FloatRect();
}
