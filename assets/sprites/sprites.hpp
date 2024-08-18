//
//  sprites.hpp
//  sfmlgame2
//
//  Created by Sunmyoung Yun on 2024/08
//

#ifndef sprites_hpp
#define sprites_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "global.hpp"
#include <ctime>

class Sprite{
public:
    Sprite(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect> animationRects);
    virtual ~Sprite();
    void updatePos();
    void setRect(int animNum); 
    sf::Vector2f const getSpritePos() const { return position; };
    sf::Sprite const returnSpritesShape(){ return *spriteCreated; }
    bool const getVisibleState() const { return visibleState; }
    void setVisibleState(bool VisibleState){ visibleState = VisibleState; }
    bool const getMoveState() const { return moveState; }
    void setMoveState(bool newState) { moveState = newState; }

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture* skin = nullptr;
    std::vector<sf::IntRect> animationRects; 
    sf::Sprite* spriteCreated;
    bool visibleState;
    bool moveState;
    float speed;
    int animNum; 
};

class Background : public Sprite{
public:
    Background(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect>  animationRectsh) : Sprite(position, size, texturePath, animationRects) {}
    ~Background( ) override{ };
    void updateBackground();
};

//player class
class Player : public Sprite{
public:
    Player(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect>  animationRects) : Sprite(position, size, texturePath, animationRects) {}
    ~Player( ) override{ };
    void updatePlayer();
};

//enemy class
class Rain : public Sprite{
public:
    Rain(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect> animationRects) : Sprite(position, size, texturePath, animationRects) {}
    ~Rain( ) override{ };
    void updateRain();
    
private:
    float speed = 100;
};

class Lightning : public Sprite{
    public:
    Lightning(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect> animationRects) : Sprite(position, size, texturePath, animationRects) {}
    ~Lightning() override{};
};

class Coin : public Sprite{
public:
    Coin(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect> animationRects) : Sprite(position, size, texturePath, animationRects) {}
    ~Coin() override{};
    void updateCoin(); 
};

class Heart : public Sprite{
public:
    Heart(sf::Vector2f position, sf::Vector2f size, const std::string& texturePath, const std::vector<sf::IntRect> animationRects) : Sprite(position, size, texturePath, animationRects) {}
    ~Heart() override{};
}; 

#endif /* sprites_hpp */
