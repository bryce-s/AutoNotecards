#pragma once

#include "ImageTargets.h"
#include <string>

class NotecardCarver {
    ImageTargets targets;

public:
    NotecardCarver(const ImageTargets targets_in) : targets(targets_in) {

    }

    void processImages(std::string inputDir);

};

