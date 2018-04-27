#pragma once
#include <algorithm>
#include <string>


class Settings {
public:
    // returns the object; creates if not already present.
    static Settings& Get();

private:
    std::string sample;
    Settings() : sample(""){};

    ~Settings();

public:
    std::string getSample();
};


