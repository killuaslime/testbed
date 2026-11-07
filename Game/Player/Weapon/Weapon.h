
#pragma once

#include <cstdint>
#include <string_view>

enum class WeaponType {
    M4A4,
    AK47,
    USP,
    Glock,
    Knife
};

struct WeaponData {
    std::string_view name;
    int damage;
    int magazineCapacity;
    int reserveAmmo;
};

constexpr WeaponData getWeaponData(WeaponType type) {
    switch (type) {
    case WeaponType::M4A4:
        return { "M4A4", 33, 30, 90 };

    case WeaponType::AK47:
        return { "AK-47", 36, 30, 90 };

    case WeaponType::USP:
        return { "USP-S", 35, 12, 24 };

    case WeaponType::Glock:
        return { "Glock-18", 30, 20, 120 };

    case WeaponType::Knife:
        return { "Knife", 50, 0, 0 };
    }

    return { "Unknown", 0, 0, 0 };
}

class Weapon {
public:
    explicit Weapon(WeaponType type)
        : type(type),
        data(getWeaponData(type)),
        ammoInMagazine(data.magazineCapacity),
        reserveAmmo(data.reserveAmmo) {
    }

    WeaponType getType() const {
        return type;
    }

    std::string_view getName() const {
        return data.name;
    }

    int getDamage() const {
        return data.damage;
    }

    int getAmmoInMagazine() const {
        return ammoInMagazine;
    }

    int getReserveAmmo() const {
        return reserveAmmo;
    }

    bool shoot() {
        if (type == WeaponType::Knife ||
            ammoInMagazine <= 0) {
            return false;
        }

        --ammoInMagazine;
        return true;
    }

private:
    WeaponType type;
    WeaponData data;

    int ammoInMagazine;
    int reserveAmmo;
};
