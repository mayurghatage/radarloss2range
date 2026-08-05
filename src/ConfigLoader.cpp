#include "ConfigLoader.h"
#include "json.hpp"
#include <fstream>
#include <cmath>

using json = nlohmann::json;

RadarSpec loadRadarSpec(const std::string& configPath) {
    std::ifstream f(configPath);
    json data = json::parse(f);

    RadarSpec spec;
    spec.Pt = data["Pt"];
    double G_dB = data["G_dB"];
    spec.G = std::pow(10.0, G_dB / 10.0); // dB -> linear
    spec.freqHz = data["freq_Hz"];
    spec.Pmin = data["Pmin"];

    return spec;
}