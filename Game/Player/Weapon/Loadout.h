#pragma once

#include "Team.h"
#include "Weapon.h"

#include <vector>
#include <string>

inline std::vector<Weapon> createStartingLoadout(Team team) {
    if (team == Team::CT) {
        return {
            Weapon(WeaponType::M4A4),
            Weapon(WeaponType::USP),
            Weapon(WeaponType::Knife)
        };
    }

    else if (team == Team::T) {
        return {
        Weapon(WeaponType::AK47),
        Weapon(WeaponType::Glock),
        Weapon(WeaponType::Knife)
        };

    }
    else {
        return {};
    }
}
