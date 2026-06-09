# Moping-Robot with a ESP32-S3
**Authors:** Alishba & Jhanan Vaca

---

## Inspiration / Reference Ideas

- [Havi Floor Cleaner Project](https://www.havi.co/blogs/floor-cleaner-project?srsltid=AfmBOoqOccJ5COKm2vzfY6Hxk0a07Qe32Pf9K7XTadpMRjth3KNCQVvt)

  
[<img width="1280" height="720" alt="image" src="https://github.com/user-attachments/assets/2f6f3a67-d713-4d2c-9018-d1df5c03a047" />](https://i.ytimg.com/vi/X3OkfQ8OLaM/maxresdefault.jpg))
The second picture in the reference was the main inspiration. Dimensions are not finalized yet — the plan is to start small and scale up. Further design/product references are also welcome.

---

## Components List

| Component | Type | Specs | Dimensions / Weight | Qty |
|---|---|---|---|---|
| ESP32 | Main microcontroller | 3.3V logic · WiFi/Bluetooth · 240MHz · 30 GPIO pins | 32 × 54 × 3 mm · ~5g | 1 |
| TT Yellow Motor 6V 1:220 | DC motor with gearbox | 6V · ~55 RPM · 1:220 gear ratio · high torque | 70 × 37 × 22 mm · ~30g each | 2 |
| TT Wheels + caster wheel | Wheel kit | Ø65mm · TT motor shaft compatible · caster ~20mm | Ø65 × 26 mm | 1 |
| Driver TB6612FNG | Dual motor driver | 15V max · 1.2A/channel continuous · 3.2A peak · low voltage drop | 26 × 20 × 3 mm · ~3g | 1 |
| Step-down MP1584EN 3A | Voltage regulator | Input 4.5–28V · Adjustable output → 5V · 3A | 22 × 17 × 4 mm · ~3g | 1 |
| 18650 Cell 3000mAh | Rechargeable Li-ion battery | 3.7V nominal · 3000mAh · 2 in series = 7.4V | Ø18 × 65 mm · ~48g each | 2 |
| 2×18650 Battery holder (series) | Battery holder IN SERIES | Output 7.4V · red/black wires included | 75 × 40 × 22 mm · ~15g | 1 |
| ON/OFF Switch | Power switch | SPDT or DPDT · min. 2A capacity | 20 × 15 × 10 mm · ~3g | 1 |
| IR Sensor FC-51 | Obstacle detector | 3.3–5V · 2–30cm adjustable range · digital output | 32 × 14 × 7 mm · ~3g each | 2 |
| IR Sensor TCRT5000 | Edge/cliff detector | 3.3–5V · digital and analog · points downward | 32 × 14 × 7 mm · ~3g each | 2 |

> **Note:** Passive components like resistors and capacitors are not listed but should be considered. The IR sensors must be located at the front of the chassis.

---

## Prototyping Notes

- Breadboards are acceptable for the prototyping phase.
- Long-term goal: custom **PCB** with integrated chassis.
- Batteries are the most critical missing part; IR sensors are also important for chassis design.

---

## Challenges

### 1. Mopping Mechanism

The mopping action itself is the core challenge — more important than the chassis design. Water dispensing is **out of scope** for now.

- **Option A:** Oscillating/pad mechanism — potentially very effective. Open to ideas.
- **Option B:** Roller mechanism — considered but likely less effective.

### 2. Material Selection

The chosen material must be robust enough to withstand crashes or drops. Structure and material have not been finalized yet.

---

## Tasks

- [ ] Design chassis options (compact and simple for first prototype)
- [ ] Design mopping mechanics
- [ ] Create a **Flowchart/FCM** using [Mermaid Live](https://mermaid.live) for the embedded systems professor
- [ ] Iterate on designs collaboratively

---

## Logbook

This document serves as the project logbook. All progress, decisions, and changes should be recorded here for future reference and formal documentation.

