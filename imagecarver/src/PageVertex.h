#pragma once

// defines partition points for notecard sets.
class PageVertex {
public:
    const int pageNumber;
    const int xCoord;
    const int yCoord;
    PageVertex(const int pageNumber_in, const int xCoord_in, const int yCoord_in)
            : pageNumber(pageNumber_in), xCoord(xCoord_in), yCoord(yCoord_in) {

    }
private:

    const int getPageNumber();
    const int getxCoord();
    const int getyCoord();
};


