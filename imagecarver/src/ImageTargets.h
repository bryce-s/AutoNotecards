#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include "PageVertex.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>

using json = nlohmann::json ;

class ImageTargets {

    std::vector<PageVertex> vertices;

    void processArray(json& j);






public:
    void processJSON(std::string jsonFilename);

    void push(const int pageNumber, const int xCoord, const int yCoord);

    void print(std::ostream& out);

    const size_t size();

    PageVertex& operator[] (size_t index);

    PageVertex& front();
    PageVertex& back();

    std::vector<PageVertex>::iterator begin();
    std::vector<PageVertex>::iterator end();

};


