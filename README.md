# RadarLoss2Range
 
Converts a coating's frequency-dependent reflection loss (RL) into real-world radar detection range using the radar range equation — a companion tool for the Stealthene project. Turns "reflection loss vs. frequency" into "detection range dropped from A km to B km across X-band," the number that actually matters for survivability.
 
## Why this exists
 
An RL(dB) curve from a VNA/waveguide measurement doesn't mean much on its own. This tool closes the loop: convert measured reflection loss into an effective RCS reduction, then run it through the radar range equation to get actual detection range, before vs. after coating, across the X-band. It's the difference between a materials-science result and an operational one.
 
## The Pipeline
 
1. **RL(f) → RCS reduction**: reflection coefficient `|Γ| = 10^(-RL/20)`, reflected power fraction `|Γ|²`, applied to a baseline reference RCS (σ_coated = σ_baseline × |Γ|²). Assumes normal incidence, single-layer coating — a stated simplification, not hidden.
2. **Radar range equation**:
   R_max = [ (Pt · G² · λ² · σ) / ((4π)³ · Pmin) ]^(1/4)
   - Pt — radar transmit power
   - G — antenna gain
   - λ — radar wavelength (from frequency)
   - σ — target RCS (from step 1)
   - Pmin — minimum detectable received power
3. **Sweep** across X-band (8–12 GHz) baseline vs. coated → CSV output.
4. **Plot**: detection range vs. frequency, before/after.
## Data source
 
Currently seeded with published/literature graphene RAM reflection-loss curves as a placeholder. Architecture is built to drop in real VNA-measured RL(f) data from the Stealthene research once available — no rework needed.
 
## Status
 
🚧 In progress. Core range equation, config loader, and RL→RCS conversion module implemented and sanity-tested in C++. Building the X-band sweep + CSV output next.
 
## Roadmap
 
- [x] Core radar range equation in C++ (sanity-tested)
- [x] Radar spec config (Pt, G, frequency, Pmin) — JSON, dB→linear conversion for gain
- [x] RL(f) → RCS conversion module
- [ ] RCS sweep (baseline vs. coated) → CSV output, X-band
- [ ] Python plot: detection range vs. frequency
## Tech Stack
 
- C++ (core calculation: radar spec struct, RL→RCS conversion, range equation, sweep logic)
- Python / matplotlib (plotting only)
## Known Limitations
 
- Not a full EM/geometry-based RCS solver — this is a detection-range estimator from measured/published reflection data, not first-principles RCS computation.
- RL→RCS conversion assumes normal incidence and a simplified baseline reference target.