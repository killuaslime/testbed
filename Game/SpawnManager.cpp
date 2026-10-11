#include "SpawnManager.h"
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
}

void SpawnManager::spawnPlayer(Player& player, std::size_t spawnIndex)
{
	if (spawnIndex < ctSpawns.size() && player.team == "CT") {
		player.position = ctSpawns[spawnIndex].position;
	}
	else if (spawnIndex < tSpawns.size() && player.team == "T") {
		player.position = tSpawns[spawnIndex].position;
	}
}