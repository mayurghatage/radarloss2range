#pragma once

struct RadarSpec {
    double Pt;      // transmit power, watts
    double G;       // antenna gain, linear (not dB)
    double freqHz;  // operating frequency, Hz
    double Pmin;    // minimum detectable received power, watts
};
