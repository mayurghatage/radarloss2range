# RCS Detection Range Calculator

Converts radar cross-section (RCS) values into radar detection range using the radar range equation. Built as a companion tool for the Stealthene project — turns "we reduced RCS by X%" into "detection range dropped from A km to B km."

## What it does
Given radar transmit power, antenna gain, frequency, and target RCS (σ), computes max detection range:

R_max = [ (Pt · G² · λ² · σ) / ((4π)³ · Pmin) ]^(1/4)

Sweeps across RCS values (baseline vs. graphene-coated) to show real-world impact of stealth coating research.

## Status
🚧 In progress — core equation + config structure being built.

## Tech
C++ (core calculation) + Python (plotting)
