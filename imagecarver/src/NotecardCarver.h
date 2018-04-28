#pragma once

#include "ImageTargets.h"
#include "lodepng.h"
#include <string>
#include <vector>
class NotecardCarver {
    ImageTargets targets;
    PageVertex prev;

public:
    NotecardCarver(const ImageTargets targets_in) : targets(targets_in), prev(-1,-1,-1) {

    }

    void carveImage(PageVertex& vertex, std::vector<unsigned char>& image);

    void processImages(std::string inputDir);

};
s
