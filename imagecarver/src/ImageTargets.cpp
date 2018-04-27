#include "ImageTargets.h"

void ImageTargets::processArray(json &j) {
    const int size = j["carvePosition"].size();
    for (size_t i{0}; i < size; i++) {
        int pageNumber = 0;
        int xCoord = 0;
        int yCoord = 0;
        for (auto it = j["carvePosition"][i].begin(); it != j["carvePosition"][i].end(); ++it) {
            if (it.key() == "page") {
                pageNumber = it.value();
            }
            if (it.key() == "xCoord") {
                xCoord = it.value();
            }
            if (it.key() == "yCoord") {
                yCoord = it.value();
            }
        }
        vertices.push_back(PageVertex(pageNumber, xCoord, yCoord));
    }
}

void ImageTargets::processJSON(const std::string jsonFilename) {

    std::ifstream inFile(jsonFilename);
    if (!inFile.is_open()) {
        std::cerr << "JSON file not found!\n";
        return;
    }
    json j = json::parse(inFile);
    if (j.size() != 1 || !j["carvePosition"].is_array()) {
        std::cerr << "JSON file incorrectly formatted\n";
        return;
    }
    processArray(j);

}


