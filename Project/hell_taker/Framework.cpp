#include "stdafx.h"
#include "Framework.h"

void Framework::Init(sf::Vector2f windowSize)
{
	window.create(sf::VideoMode(windowSize.x, windowSize.y) , "HELL TAKER");
	SCENE_MGR.Init();
	INPUT_MGR.Init();

}

void Framework::Update()
{
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        INPUT_MGR.Update(dt);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            INPUT_MGR.UpdateEvent(event);
        }



        SCENE_MGR.Update(dt);



        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
}

void Framework::Release()
{
    SCENE_MGR.Release();
}
