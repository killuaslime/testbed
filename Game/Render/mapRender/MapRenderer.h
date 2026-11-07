#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class MapRenderer {
private:
	sf::Texture map;
	sf::Sprite mapSprite;
public:
	MapRenderer();
	bool loadMap() {
		if (!map.loadFromFile("assets/maps/de_mirage.png")) {
			std::cerr << "Не удалось загрузить карту!\n";
			return false;
		}
		mapSprite = sf::Sprite(map);
		return true;
	}
	void drawMap(sf::RenderWindow& window) {
		window.draw(mapSprite);
	}

};


