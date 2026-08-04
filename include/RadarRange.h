#pragma once
#include "RadarSpec.h"

// Returns max detection range in meters for a target with radar cross-section sigma (m^2)
double computeMaxRange(const RadarSpec& radar, double sigma);