#include "stdafx.h"
#include "SpriteGo.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    INPUT_MGR.Init();
    

    TEXTURE_MGR.Load(SPRITE_PATH"assets100V20053.png");

    SpriteGo sp(SPRITE_PATH"assets100V20053.png");
    sp.Reset();

    UTILS.SetOrigins(sp.GetSprite(), Origins::MC);
    sp.SetPosition({ 1280 / 2 , 720 / 2 });

    
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

        

        window.clear();
        sp.Draw(window);
        window.display();
    }

    return 0;
}