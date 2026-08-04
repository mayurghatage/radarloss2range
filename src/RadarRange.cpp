#include "RadarRange.h"
#include <cmath>

constexpr double C = 299792458.0;  // speed of light, m/s
constexpr double PI = 3.14159265358979323846;

double computeMaxRange(const RadarSpec& radar, double sigma) {
    double lambda = C / radar.freqHz;  // wavelength from frequency

    double numerator = radar.Pt * std::pow(radar.G, 2) * std::pow(lambda, 2) * sigma;
    double denominator = std::pow(4.0 * PI, 3) * radar.Pmin;

    return std::pow(numerator / denominator, 0.25);
}