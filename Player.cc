
#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
    {
        this->speed = speed;

    body.setSize(sf::Vector2f(32.0f,48.0f));
    body.setPosition(256.0f,256.0f);
    body.setTexture(texture);
    }  
Player::~Player()
{
}
void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        movement.y -= speed * deltaTime;
        row = 4;
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        movement.y += speed * deltaTime;
        row = 1;
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -= speed * deltaTime;
        row = 2;
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movement.x += speed * deltaTime;
        row = 3;
    }
     if(movement.x == 0 && movement.y == 0)
    {
       row = 0;
    } 

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);

}
void Player::Draw(sf::RenderWindow& window)
{

    window.draw(body);
}