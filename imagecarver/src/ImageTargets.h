#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include "PageVertex.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using json = nlohmann::json ;

class ImageTargets {

    std::vector<PageVertex> vertices;

    void processArray(json& j);

    void push(const int pageNumber, const int xCoord, const int yCoord);

public:
    void processJSON(std::string jsonFilename);

    const size_t size();

    PageVertex& operator[] (size_t index);

};

