#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include "PageVertex.h"
#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json ;

class ImageTargets {

    std::vector<PageVertex> vertices;

    void processArray(json& j);

public:
    void processJSON(std::string jsonFilename);

};

