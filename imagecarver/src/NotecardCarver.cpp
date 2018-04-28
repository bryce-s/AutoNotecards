#include "NotecardCarver.h"

void NotecardCarver::carveImage(PageVertex &vertex, std::vector<unsigned char> &image) {

    if (vertex.pageNumber == prev.pageNumber) {
        // then we we carve from there..
        // also, vertex.pageNumber >= 0
        assert(vertex.pageNumber >= 0);

    }
    prev = vertex;
}

void NotecardCarver::processImages(std::string inputDir) {
    for (size_t i{0}; i < targets.size(); i++) {
        std::vector<unsigned char> image;
        unsigned width, height;
        // decode
        unsigned error = lodepng::decode(image, width, height, "tests/1.png")
        if (error) {
            std::cout << "decode error " << error << ": " << lodepng_error_text(error) << "\n";
        } else {
            carveImage(targets[i], image);
        }
    }
}


