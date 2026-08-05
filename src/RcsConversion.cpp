#include "RcsConversion.h"
#include <cmath>

double sigmaFromReflectionLoss(double sigmaBaseline, double RL_dB) {
    double gamma = std::pow(10.0, -RL_dB / 20.0); // reflection coefficient
    return sigmaBaseline * gamma * gamma;          // sigma scales with |gamma|^2
}