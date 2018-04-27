#include <iostream>
#include "src/Settings.h"
#include "src/ImageTargets.h"

int main(int argc, char* argv[]) {
    //std::cout << Settings::Get().getSample();
    ImageTargets targets;
    targets.processJSON("tests/test_in.json");
    targets.print(std::cout);
    return 0;
}
