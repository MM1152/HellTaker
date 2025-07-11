#include "stdafx.h"
#include "SpriteGo.h"
#include "GameScene.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    INPUT_MGR.Init();
    
    GameScene Scene;
    Scene.Init();
    Scene.Reset();

    
    while (window.isOpen())
    {
        INPUT_MGR.Update(0);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            INPUT_MGR.UpdateEvent(event);
        }

        if (INPUT_MGR.GetKeyDown(KEY::A)) {
            std::cout << "A Å° ´­¸²" << std::endl;
        }

        Scene.Update(0);
        
        window.clear();
        Scene.Draw(window);
        window.display();
    }

    return 0;
}