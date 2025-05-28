# Blueprint Examples

*Read this in other languages: [English](Examples.md), [한국어](Examples_KR.md)*

Practical examples and use cases for Advanced Filters Plugin

## 📍 Navigation

- [← Back: API Reference](APIReference.md)
- [→ Next: Best Practices](BestPractices.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - [Installation Guide](Installation.md)
- **User Guides**
  - [User Manual](UserManual.md)
  - **Blueprint Examples** (You are here)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 📋 Table of Contents

1. [Basic Examples](#basic-examples)
2. [Game Mechanics](#game-mechanics)
3. [UI Examples](#ui-examples)
4. [VR/AR Examples](#vrar-examples)
5. [Advanced Techniques](#advanced-techniques)
6. [Performance Examples](#performance-examples)

---

## 🎮 Basic Examples

### Example 1: Smooth Camera Follow

Create a camera that follows the player smoothly without jitter.

**Blueprint Setup:**
```blueprint
Event Tick
├─ Get Player Location
├─ [Kalman Filter Vector]
│  ├─ Raw Value: Player Location
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraFollow"
└─ Set Camera Location (with offset)
```

**Key Points:**
- Uses Kalman filter for predictive smoothing
- Medium preset balances responsiveness and smoothness
- Add offset to keep camera behind/above player

**Variations:**
- Low preset for action games (faster response)
- High preset for cinematic sequences
- Add rotation filtering for complete smoothness

---

### Example 2: Mouse Look Smoothing

Reduce jittery mouse movement for better aiming.

**Blueprint Setup:**
```blueprint
Event Tick
├─ Get Mouse Delta
├─ Break Vector2D (X, Y)
├─ [One Euro Filter Value] (X)
│  ├─ Raw Value: Mouse X
│  ├─ Delta Time: Event Delta
│  ├─ Preset: Low
│  └─ Filter ID: "MouseX"
├─ [One Euro Filter Value] (Y)
│  ├─ Raw Value: Mouse Y
│  ├─ Delta Time: Event Delta
│  ├─ Preset: Low
│  └─ Filter ID: "MouseY"
└─ Add Controller Input (Yaw, Pitch)
```

**Key Points:**
- One Euro filter for minimal latency
- Low preset maintains responsiveness
- Separate filters for X and Y axes

---

## 🎯 Game Mechanics

### Example 3: Health Bar Animation

Smooth health bar changes for professional UI feel.

**Blueprint Setup:**
```blueprint
On Health Changed Event
├─ [Kalman Filter Value]
│  ├─ Raw Value: New Health
│  ├─ Preset: High
│  └─ Filter ID: "HealthBar"
├─ Divide (by Max Health)
└─ Set Progress Bar Percent
```

**Timeline Alternative:**
```blueprint
// For more control over animation
On Health Changed
├─ Get Current Display Health
├─ [Kalman Filter Value] → Target Health
├─ Create Timeline
│  ├─ Start: Current Display Health
│  ├─ End: Target Health
│  └─ Duration: 0.5 seconds
└─ Update Progress Bar
```

---

### Example 4: AI Path Smoothing

Make AI movement more natural and less robotic.

**Blueprint Setup:**
```blueprint
// In AI Controller
Event Receive Move Completed
├─ Get Next Path Point
├─ [Kalman Filter Vector]
│  ├─ Raw Value: Path Point
│  ├─ Preset: Medium
│  └─ Filter ID: "AI_" + Character Name
└─ Move To Location (Filtered)
```

**Advanced Version:**
```blueprint
// Smooth entire path
Get Path Points Array
├─ For Each Loop
│  ├─ [Kalman Filter Vector]
│  │  ├─ Raw Value: Path Point
│  │  ├─ Preset: Low
│  │  └─ Filter ID: "PathSmooth"
│  └─ Add to Smoothed Path
└─ Follow Smoothed Path
```

---

## 🖼️ UI Examples

### Example 5: Animated Menu Cursor

Create a smooth, lag-free menu cursor.

**Blueprint Setup:**
```blueprint
// In UI Widget
Event Tick
├─ Get Mouse Position
├─ [One Euro Filter Vector]
│  ├─ Raw Value: Mouse Position
│  ├─ Delta Time: UI Delta Time
│  ├─ Preset: Medium
│  └─ Filter ID: "MenuCursor"
└─ Set Cursor Widget Position
```

**Enhanced Version with Acceleration:**
```blueprint
// Add "floaty" feel
Get Mouse Position
├─ [One Euro Filter Vector] (Low preset)
├─ [Kalman Filter Vector] (High preset)
├─ Blend (0.7 OneEuro, 0.3 Kalman)
└─ Set Position with Interpolation
```

---

### Example 6: Damage Numbers

Smooth floating damage numbers.

**Blueprint Setup:**
```blueprint
// In Damage Number Widget
Event Construct
├─ Random Offset (-50, 50)
├─ [Kalman Filter Value]
│  ├─ Raw Value: Random X Offset
│  ├─ Preset: High
│  └─ Filter ID: "DamageFloat"
└─ Set Initial Position

Event Tick
├─ Current Position + (0, 0, Delta * Speed)
├─ [Kalman Filter Vector]
│  ├─ Raw Value: New Position
│  ├─ Preset: Medium
│  └─ Filter ID: "DamagePos"
└─ Set Widget Position
```

---

## 🥽 VR/AR Examples

### Example 7: VR Hand Tracking

Reduce controller jitter for stable hand presence.

**Blueprint Setup:**
```blueprint
// In VR Pawn
Event Tick
├─ Get Controller Location (Right)
├─ [One Euro Filter Vector]
│  ├─ Raw Value: Controller Location
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: Low
│  └─ Filter ID: "RightHand"
├─ Get Controller Rotation
├─ [One Euro Filter Vector] (Convert to Vector)
│  ├─ Raw Value: Rotation as Vector
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: Medium
│  └─ Filter ID: "RightHandRot"
└─ Set Hand Mesh Transform
```

**Custom Preset for VR:**
```blueprint
Begin Play
├─ [Create Custom Preset]
│  ├─ Name: "VR_Controllers"
│  ├─ Process Noise: 0.0
│  ├─ Measurement Noise: 0.0
│  ├─ Min Cutoff: 0.3
│  ├─ Beta: 0.00001
│  └─ DCutoff: 1.0
└─ Apply to Both Hands
```

---

### Example 8: AR Object Placement

Stabilize AR object placement on surfaces.

**Blueprint Setup:**
```blueprint
// AR Placement Manager
On Surface Detected
├─ Get Surface Point
├─ [Kalman Filter Vector]
│  ├─ Raw Value: Hit Location
│  ├─ Preset: High
│  └─ Filter ID: "ARSurface"
├─ Get Surface Normal
├─ [Kalman Filter Vector]
│  ├─ Raw Value: Hit Normal
│  ├─ Preset: High
│  └─ Filter ID: "ARNormal"
└─ Place AR Object (Filtered Transform)
```

---

## 🚀 Advanced Techniques

### Example 9: Filter Chaining

Combine multiple filters for sophisticated effects.

**Blueprint Setup:**
```blueprint
// Double filtering for ultra-smooth camera
Event Tick
├─ Get Target Location
├─ [One Euro Filter Vector] (Low preset)
│  └─ Filter ID: "CameraStage1"
├─ [Kalman Filter Vector] (Medium preset)
│  └─ Filter ID: "CameraStage2"
└─ Set Camera Location
```

**Filter Chain Node:**
```blueprint
// Using the chain system
Begin Play
├─ [Create Filter Chain]
│  ├─ Types: [OneEuro, Kalman]
│  └─ Presets: [Low, High]
└─ Save as FilterChain

Event Tick
├─ [Process Through Chain]
│  ├─ Chain: FilterChain
│  ├─ Value: Target Location
│  └─ Delta Time: Delta Seconds
└─ Use Result
```

---

### Example 10: Adaptive Filtering

Change filter strength based on gameplay state.

**Blueprint Setup:**
```blueprint
// Dynamic preset switching
Event Tick
├─ Branch (Is Aiming?)
│  ├─ True: Set Preset = Low
│  └─ False: Set Preset = High
├─ [One Euro Filter Value]
│  ├─ Raw Value: Input
│  ├─ Preset: Dynamic Preset
│  └─ Filter ID: "AdaptiveAim"
└─ Apply to Camera
```

**Speed-Based Adaptation:**
```blueprint
// Faster movement = less filtering
Get Velocity → Length
├─ Map Range (0-600 → 0-1)
├─ [Create Custom Preset]
│  └─ Beta: Mapped Velocity
└─ Apply to Movement Filter
```

---

### Example 11: Prediction Showcase

Use Kalman filter's prediction for look-ahead.

**Blueprint Setup:**
```blueprint
// Predictive targeting
Event Tick
├─ Get Target Velocity
├─ Get Target Position
├─ [Kalman Filter Vector] → Current Filtered
├─ [Get Predicted Value] (custom node)
│  ├─ Filter: Kalman Instance
│  └─ Steps Ahead: 10
├─ Draw Debug Sphere (Current - Blue)
└─ Draw Debug Sphere (Predicted - Red)
```

---

## ⚡ Performance Examples

### Example 12: LOD-Based Filtering

Optimize by filtering based on distance.

**Blueprint Setup:**
```blueprint
// In Character Tick
Get Distance to Camera
├─ Select Preset
│  ├─ < 10m: High (smooth animations)
│  ├─ < 50m: Medium
│  └─ > 50m: Low (or skip)
├─ [Kalman Filter Vector]
│  ├─ Preset: Selected
│  └─ Filter ID: "Character_" + Index
└─ Apply to Skeletal Mesh
```

---

### Example 13: Batch Processing

Filter multiple values efficiently.

**Blueprint Setup:**
```blueprint
// Process array of positions
Get All Particle Positions
├─ For Each Loop
│  ├─ [Kalman Filter Vector]
│  │  └─ Filter ID: "Particle_" + Index
│  └─ Add to Filtered Array
└─ Update All Particles
```

**Optimized Version:**
```blueprint
// Process only visible particles
Get Visible Particles
├─ Filter by Distance
├─ Batch Update (custom C++)
└─ Apply Results
```

---

### Example 14: Conditional Filtering

Save performance by filtering only when needed.

**Blueprint Setup:**
```blueprint
// Smart filtering
Event Tick
├─ Get Change Amount (Current - Last)
├─ Branch (Change > Threshold?)
│  ├─ True: Update Filter
│  └─ False: Use Cached Value
└─ Apply Result
```

---

## 📝 Complete Example Project

### Smooth FPS Controller

A complete first-person controller with filtered input.

**Player Controller Setup:**
```blueprint
// Input smoothing
Input Axis MoveForward
├─ [One Euro Filter Value]
│  ├─ Preset: Low
│  └─ Filter ID: "MoveForward"
└─ Add Movement Input

Input Axis Turn
├─ [One Euro Filter Value]
│  ├─ Preset: Low
│  ├─ Delta Time: Delta
│  └─ Filter ID: "MouseTurn"
└─ Add Controller Yaw
```

**Camera Setup:**
```blueprint
// Camera smoothing
Event Tick
├─ Get Socket Location "Head"
├─ [Kalman Filter Vector]
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraPos"
├─ Get Control Rotation
├─ [One Euro Filter] (Rotator as Vector)
│  ├─ Preset: Low
│  └─ Filter ID: "CameraRot"
└─ Set Camera Transform
```

**Weapon Sway:**
```blueprint
// Weapon lag
Event Tick
├─ Get Look Velocity
├─ [Kalman Filter Vector]
│  ├─ Preset: High
│  └─ Filter ID: "WeaponSway"
├─ Map to Sway Offset
└─ Add to Weapon Position
```

---

## 🎯 Tips for Examples

1. **Start Simple** - Test with one filter before chaining
2. **Visualize** - Use debug draws to see filter effects
3. **Profile** - Monitor performance with profiling nodes
4. **Experiment** - Try different presets for your use case
5. **Save Presets** - Create custom presets for reuse

---

## 📚 Further Reading

- [Best Practices](BestPractices.md) - Optimization tips
- [Performance Guide](Performance.md) - Detailed benchmarks
- [Troubleshooting](Troubleshooting.md) - Common issues

---

Happy Filtering! 🎉