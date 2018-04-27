#pragma once

#include <nlohmann/json.hpp>
#include <vector>
#include "PageVertex.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>

using json = nlohmann::json ;

class ImageTargets {

    std::vector<PageVertex> vertices;

    void processArray(json& j);

    void push(const int pageNumber, const int xCoord, const int yCoord);

    class TargetIterator {
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef PageVertex value_type;
        typedef ptrdiff_t difference_type;
        typedef PageVertex* pointer;
        typedef PageVertex& reference;
        TargetIterator();
        PageVertex& operator*();
        PageVertex* operator->();
        TargetIterator& operator++();
        TargetIterator operator++(const int amount);
    private:
        size_t activeIndex;
        friend class ImageTargets;

    };


public:
    void processJSON(std::string jsonFilename);

    const size_t size();

    PageVertex& operator[] (size_t index);

    PageVertex& front();
    PageVertex& back();

};

ImageTargets::TargetIterator::TargetIterator() {

}

PageVertex &ImageTargets::TargetIterator::operator*() {
    return <#initializer#>;
}

PageVertex *ImageTargets::TargetIterator::operator->() {
    return nullptr;
}

ImageTargets::TargetIterator &ImageTargets::TargetIterator::operator++() {
    return <#initializer#>;
}

ImageTargets::TargetIterator ImageTargets::TargetIterator::operator++(const int amount) {
    return ImageTargets::TargetIterator();
}

