# RCS Detection Range Calculator

Converts radar cross-section (RCS) values into real-world radar detection range using the radar range equation — a companion tool for the Stealthene project. Turns "we reduced RCS by X%" into "detection range dropped from A km to B km," the number that actually matters for survivability.

## Why this exists

An RCS reduction percentage alone doesn't mean much on its own. This tool closes the loop: plug in a target's RCS (before/after graphene RAM coating) and get the actual distance at which a given radar can detect it. It's the difference between a materials science result and an operational one.

## The Physics

Radar range equation:

R_max = [ (Pt · G² · λ² · σ) / ((4π)³ · Pmin) ]^(1/4)

- Pt — radar transmit power
- G — antenna gain
- λ — radar wavelength (from frequency)
- σ — target RCS
- Pmin — minimum detectable received power

Sweep σ across baseline vs. coated values to generate a direct before/after detection-range comparison.

## Status

🚧 In progress — building core equation and config structure.

## Roadmap

- [ ] Core radar range equation in C++
- [ ] Radar spec config (Pt, G, frequency, Pmin) — JSON, same pattern as ASTRA
- [ ] RCS sweep (baseline vs. coated) → CSV output
- [ ] Python plot: detection range vs. RCS

## Tech Stack

- C++ (core calculation)
- Python / matplotlib (plotting)
