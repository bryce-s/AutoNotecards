#include "Settings.h"

Settings &Settings::Get() {
    static Settings instance;
    return instance;
}

std::string Settings::getSample() {
    return sample;
}
