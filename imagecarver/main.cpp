#include <iostream>
#include "src/Settings.h"

int main() {
    std::cout << Settings::Get().getSample();
    return 0;
}
