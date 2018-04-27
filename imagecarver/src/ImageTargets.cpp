#include "ImageTargets.h"

void ImageTargets::processJSON(std::string jsonFilename) {
    std::ifstream inFile(jsonFilename);
    if (!inFile.is_open()) {
        std::cerr << "file not found!";
    }
    json j = json::parse(inFile);

}
