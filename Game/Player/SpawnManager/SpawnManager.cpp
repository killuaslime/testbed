#include "SpawnManager.h"
#include "Loadout.h"
#include <array>

SpawnManager::SpawnManager() {
	//точки спавна для ct
	ctSpawns.push_back({ {310.0f, 750.0f, 0.0f} });
	ctSpawns.push_back({ {330.0f, 700.0f, 0.0f} });
	ctSpawns.push_back({ {308.0f, 660.0f, 0.0f} });
	ctSpawns.push_back({ {250.0f, 700.0f, 0.0f} });
	ctSpawns.push_back({ {280.0f, 719.0f, 0.0f} });
	//точки спавна для t
	tSpawns.push_back({ {875.0f, 320.0f, 0.0f} });
	tSpawns.push_back({ {875.0f, 360.0f, 0.0f} });
	tSpawns.push_back({ {875.0f, 400.0f, 0.0f} });
	tSpawns.push_back({ {910.0f, 340.0f, 0.0f} });
	tSpawns.push_back({ {910.0f, 380.0f, 0.0f} });

	colors[0] = sf::Color(80, 180, 255);  // голубой
	colors[1] = sf::Color(255, 220, 60);  // жёлтый
	colors[2] = sf::Color(70, 210, 120);  // зелёный
	colors[3] = sf::Color(180, 90, 230); // фиолетовый
	colors[4] = sf::Color(255, 145, 50); // оранжевый
}

void SpawnManager::spawnPlayer(Player& player, std::size_t spawnIndex)
{
	if (spawnIndex < ctSpawns.size() && player.getTeam() == Team::CT) {
		player.setPosition(ctSpawns[spawnIndex].position);
		player.setColor(colors[spawnIndex]);
		player.setWeapons(createStartingLoadout(Team::CT));

	}
	else if (spawnIndex < tSpawns.size() && player.getTeam() == Team::T) {
		player.setPosition(tSpawns[spawnIndex].position);
		player.setColor(colors[spawnIndex]);
		player.setWeapons(createStartingLoadout(Team::T));
	}
}