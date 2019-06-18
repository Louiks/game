#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode( 512, 512),"Just a guy"); 
    sf::Texture playerTexture; 
    playerTexture.loadFromFile("black.png");


    Player player(&playerTexture, sf::Vector2u(4,5), 0.25f, 64.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;


    while (window.isOpen())
    {

        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                
           
           
           }
        }



        player.Update(deltaTime);

        window.clear ();
        player.Draw(window);
        window.display();

    }
    


    return 0;
}