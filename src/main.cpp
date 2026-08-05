#include <iostream>
#include "RadarSpec.h"
#include "RadarRange.h"
#include "ConfigLoader.h"

int main() {
    RadarSpec radar = loadRadarSpec("data/config.json");

    double sigma = 1.0;         // 1 m^2 target, simple reference case

    double range = computeMaxRange(radar, sigma);

    std::cout << "Max detection range: " << range / 1000.0 << " km\n";

    return 0;
}