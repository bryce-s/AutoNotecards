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
        push(pageNumber, xCoord, yCoord);
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

const size_t ImageTargets::size() {
    return vertices.size();
}

PageVertex &ImageTargets::operator[](size_t index) {
    return vertices[index];
}

void ImageTargets::push(const int pageNumber, const int xCoord, const int yCoord) {
    PageVertex targetVertex(pageNumber, xCoord, yCoord);
    auto lb = std::lower_bound(vertices.begin(), vertices.end(), targetVertex, [](auto& lhs, auto& rhs){
        if (lhs.pageNumber == rhs.pageNumber) {
            if (lhs.yCoord == rhs.yCoord) {
                // at this point, we sort arbitrarily
                return lhs.xCoord > rhs.xCoord;
            } return lhs.yCoord > rhs.yCoord;
        } return lhs.pageNumber > rhs.pageNumber;
    });
    vertices.insert(lb, targetVertex);
}

PageVertex &ImageTargets::front() {
    return this->vertices.front();
}

PageVertex &ImageTargets::back() {
    return this->vertices.back();
}

std::vector<PageVertex>::iterator ImageTargets::begin() {
    return this->vertices.begin();
}

std::vector<PageVertex>::iterator ImageTargets::end() {
    return this->vertices.end();
}

void ImageTargets::print(std::ostream &out) {
    for (size_t i{0}; i < vertices.size(); i++) {
        out << "Vertex:      " << i << "\n";
        out << "Page Number: " << vertices[i].pageNumber << "\n";
        out << "xCoord:      " << vertices[i].xCoord << "\n";
        out << "yCoord:      " << vertices[i].yCoord << "\n------\n";
    }
}



