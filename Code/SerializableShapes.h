#ifndef SERIALIZABLESHAPES_H
#define SERIALIZABLESHAPES_H

#include <fstream>
#include <SFML/Graphics.hpp>

class SerializableCircleShape : public sf::CircleShape {
public:
    void serialize(std::ofstream& file) const;
    void deserialize(std::ifstream& file);
};

class SerializableRectangleShape : public sf::RectangleShape {
public:
    void serialize(std::ofstream& file) const;
    void deserialize(std::ifstream& file);
};

class SerializableSprite : public sf::Sprite {
public:
    void serialize(std::ofstream& file, sf::Texture& imageTextures) const;
    void deserialize(std::ifstream& file, std::vector<sf::Texture>* imageTextures);
};

#endif // SERIALIZABLESHAPES_H
