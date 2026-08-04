#include <iostream>
#include "RadarSpec.h"
#include "RadarRange.h"

int main() {
    RadarSpec radar;
    radar.Pt = 500000.0;        // 500 kW
    radar.G = 2511.9;           // 34 dB converted to linear (10^(34/10))
    radar.freqHz = 3e9;         // 3 GHz
    radar.Pmin = 1e-13;         // typical minimum detectable power, watts

    double sigma = 1.0;         // 1 m^2 target, simple reference case

    double range = computeMaxRange(radar, sigma);

    std::cout << "Max detection range: " << range / 1000.0 << " km\n";

    return 0;
}