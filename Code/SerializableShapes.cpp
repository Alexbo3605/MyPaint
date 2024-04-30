#include "SerializableShapes.h"

void SerializableCircleShape::serialize(std::ofstream& file) const 
{
    std::string objectType = "CircleShape";
    size_t len = objectType.length() + 1;       // нульовий байт

    sf::Vector2f position = this->getPosition();
    sf::Vector2f origin = this->getOrigin();

    sf::Color fillColor = this->getFillColor();
    sf::Color outlineColor = this->getOutlineColor();
    float outlineTrickness = this->getOutlineThickness();

    float radius = this->getRadius();
    size_t pointCount = this->getPointCount();

    
    file.write((char*)&len, sizeof(len));
    file.write((char*)objectType.c_str(), len);

    file.write(reinterpret_cast<const char*>(&position), sizeof(sf::Vector2f));
    file.write(reinterpret_cast<const char*>(&origin), sizeof(sf::Vector2f));

    file.write(reinterpret_cast<const char*>(&fillColor), sizeof(sf::Color));
    file.write(reinterpret_cast<const char*>(&outlineColor), sizeof(sf::Color));
    file.write(reinterpret_cast<const char*>(&outlineTrickness), sizeof(float));

    file.write(reinterpret_cast<const char*>(&radius), sizeof(float));
    file.write(reinterpret_cast<const char*>(&pointCount), sizeof(size_t));
}

void SerializableCircleShape::deserialize(std::ifstream& file) 
{
    sf::Vector2f position;
    file.read(reinterpret_cast<char*>(&position), sizeof(sf::Vector2f));
    this->setPosition(position);

    sf::Vector2f origin;
    file.read(reinterpret_cast<char*>(&origin), sizeof(sf::Vector2f));
    this->setOrigin(origin);

    sf::Color fillColor;
    file.read(reinterpret_cast<char*>(&fillColor), sizeof(sf::Color));
    this->setFillColor(fillColor);

    sf::Color outlineColor;
    file.read(reinterpret_cast<char*>(&outlineColor), sizeof(sf::Color));
    this->setOutlineColor(outlineColor);

    float outlineThickness;
    file.read(reinterpret_cast<char*>(&outlineThickness), sizeof(float));
    this->setOutlineThickness(outlineThickness);

    float radius;
    file.read(reinterpret_cast<char*>(&radius), sizeof(float));
    this->setRadius(radius);

    size_t pointCount;
    file.read(reinterpret_cast<char*>(&pointCount), sizeof(size_t));
    this->setPointCount(pointCount);
}

void SerializableRectangleShape::serialize(std::ofstream& file) const 
{
    std::string objectType = "RectangleShape";
    size_t len = objectType.length() + 1;

    sf::Vector2f position = this->getPosition();
    sf::Vector2f size = this->getSize();

    sf::Color fillColor = this->getFillColor();
    sf::Color outlineColor = this->getOutlineColor();
    float outlineTrickness = this->getOutlineThickness();

    
    file.write((char*)&len, sizeof(len));
    file.write((char*)objectType.c_str(), len);

    file.write(reinterpret_cast<const char*>(&position), sizeof(sf::Vector2f));
    file.write(reinterpret_cast<const char*>(&size), sizeof(sf::Vector2f));

    file.write(reinterpret_cast<const char*>(&fillColor), sizeof(sf::Color));
    file.write(reinterpret_cast<const char*>(&outlineColor), sizeof(sf::Color));
    file.write(reinterpret_cast<const char*>(&outlineTrickness), sizeof(float));
}

void SerializableRectangleShape::deserialize(std::ifstream& file) 
{
    sf::Vector2f position;
    file.read(reinterpret_cast<char*>(&position), sizeof(sf::Vector2f));
    this->setPosition(position);

    sf::Vector2f size;
    file.read(reinterpret_cast<char*>(&size), sizeof(sf::Vector2f));
    this->setSize(size);

    sf::Color fillColor;
    file.read(reinterpret_cast<char*>(&fillColor), sizeof(sf::Color));
    this->setFillColor(fillColor);

    sf::Color outlineColor;
    file.read(reinterpret_cast<char*>(&outlineColor), sizeof(sf::Color));
    this->setOutlineColor(outlineColor);

    float outlineThickness;
    file.read(reinterpret_cast<char*>(&outlineThickness), sizeof(float));
    this->setOutlineThickness(outlineThickness);
}

void SerializableSprite::serialize(std::ofstream& file,  sf::Texture& imageTextures) const
{

    
    std::string objectType = "Sprite";
    size_t len = objectType.length() + 1;

    sf::Vector2f position = this->getPosition();

    sf::Vector2u textureSize = imageTextures.getSize();
    size_t textureDataSize = textureSize.x * textureSize.y * sizeof(sf::Uint8) * 4; // 4 - RGBA

    
    file.write((char*)&len, sizeof(len));
    file.write((char*)objectType.c_str(), len);
    
    file.write(reinterpret_cast<const char*>(&position), sizeof(sf::Vector2f));

    file.write(reinterpret_cast<const char*>(&textureSize), sizeof(sf::Vector2u));
    file.write(reinterpret_cast<const char*>(&textureDataSize), sizeof(size_t));
    file.write(reinterpret_cast<const char*>(imageTextures.copyToImage().getPixelsPtr()), textureDataSize);

   
}


void SerializableSprite::deserialize(std::ifstream& file, std::vector<sf::Texture>* imageTextures)
{
    sf::Vector2f position;
    file.read(reinterpret_cast<char*>(&position), sizeof(sf::Vector2f));
    this->setPosition(position);

    // Розмір текстури
    sf::Vector2u textureSize;
    file.read(reinterpret_cast<char*>(&textureSize), sizeof(sf::Vector2u));

    // Розмір даних текстури
    size_t textureDataSize;
    file.read(reinterpret_cast<char*>(&textureDataSize), sizeof(size_t));

    // Дані текстури
    char* textureDataBuffer = new char[textureDataSize];
    file.read(textureDataBuffer, textureDataSize);

    // Створення текстури з отриманих даних
    sf::Texture texture;
    texture.create(textureSize.x, textureSize.y);
    texture.update(reinterpret_cast<sf::Uint8*>(textureDataBuffer));

    imageTextures->push_back(texture);

    // Створення спрайту з отриманими даними
    this->setTexture(imageTextures->back());
    
    // Очищення буфера
    delete[] textureDataBuffer;
}