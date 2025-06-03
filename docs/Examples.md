# Blueprint Examples (Improved Version)

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

## 🗂️ Node Category Quick Reference

Quick reference for node locations used in these examples:

| Frequency | Node | Category |
|-----------|------|----------|
| ⭐⭐⭐ | Kalman/OneEuro Filter Value/Vector | Advanced Filters > One-Click |
| ⭐⭐ | Create/Initialize/Update Filter | Advanced Filters > Core |
| ⭐⭐ | Create/Apply Custom Preset | Advanced Filters > Custom Preset |
| ⭐ | Create Filter Chain | Advanced Filters > Chain |
| ⭐ | Get Filter Statistics | Advanced Filters > Debug |

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
├─ [Kalman Filter Vector]  ← Category: Advanced Filters > One-Click
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
├─ [One Euro Filter Value] (X)  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Mouse X
│  ├─ Delta Time: Event Delta ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseX"
├─ [One Euro Filter Value] (Y)  ← Same category
│  ├─ Raw Value: Mouse Y
│  ├─ Delta Time: Event Delta ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseY"
└─ Add Controller Input (Yaw, Pitch)
```

**Key Points:**
- One Euro filter for minimal latency
- Low preset maintains responsiveness
- Separate filters for X and Y axes
- ⚠️ **One Euro requires Delta Time!**

---

## 🎯 Game Mechanics

### Example 3: Health Bar Animation

Smooth health bar changes for professional UI feel.

**Blueprint Setup:**
```blueprint
On Health Changed Event
├─ [Kalman Filter Value]  ← Category: Advanced Filters > One-Click
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
├─ [Kalman Filter Vector]  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Path Point
│  ├─ Preset: Medium
│  └─ Filter ID: "AI_" + Character Name
└─ Move To Location (Filtered)
```

**Advanced Version (Using 3-Node System):**
```blueprint
// Category: Advanced Filters > Core
Begin Play:
├─ [Create Filter] (Type: Kalman)
├─ [Initialize Filter] (Preset: Low)
└─ Store as AIPathFilter

// Smooth entire path
Get Path Points Array
├─ For Each Loop
│  ├─ [Update Filter Vector]
│  │  ├─ Target: AIPathFilter
│  │  └─ Raw Value: Path Point
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
├─ [One Euro Filter Vector]  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Mouse Position
│  ├─ Delta Time: UI Delta Time ← Required!
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
├─ [Kalman Filter Value]  ← Category: Advanced Filters > One-Click
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

**Custom Preset Creation (Important!):**
```blueprint
// Category: Advanced Filters > Custom Preset
Begin Play:
[Create Custom Preset]
├─ Preset Name: "VR_Hands"
├─ Filter Type: OneEuro ← Selection important!
├─ Process Noise/Min Cutoff: 0.4  ← Min Cutoff for OneEuro
├─ Measurement Noise/Beta: 0.00001  ← Beta for OneEuro
└─ DCutoff: 1.0
    ↓
Store as VRHandPreset
```

**Filter Application:**
```blueprint
// In VR Pawn
Event Tick
├─ Get Controller Location (Right)
├─ [One Euro Filter Vector]  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Controller Location
│  ├─ Delta Time: Delta Seconds ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "RightHand"
├─ Get Controller Rotation
├─ [One Euro Filter Vector] (Convert to Vector)
│  ├─ Raw Value: Rotation as Vector
│  ├─ Delta Time: Delta Seconds ← Required!
│  ├─ Preset: Medium
│  └─ Filter ID: "RightHandRot"
└─ Set Hand Mesh Transform
```

⚠️ **VR Considerations:**
- One Euro filter is better for VR (lower latency)
- Delta Time connection is mandatory
- Too much filtering can cause motion sickness

---

### Example 8: AR Object Placement

Stabilize AR object placement on surfaces.

**Blueprint Setup:**
```blueprint
// AR Placement Manager
On Surface Detected
├─ Get Surface Point
├─ [Kalman Filter Vector]  ← Category: Advanced Filters > One-Click
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

**Chain Creation:**
```blueprint
// Category: Advanced Filters > Chain
Begin Play:
[Create Filter Chain]
├─ Filter Types: [Kalman, OneEuro]
├─ Presets: [High, Low]
└─ Store as FilterChain
```

**Chain Usage:**
```blueprint
Event Tick
├─ Get Target Location
├─ [Process Through Chain]
│  ├─ Filter Chain: FilterChain
│  ├─ Raw Value: Target Location (Float only supported)
│  └─ Delta Time: Delta Seconds
└─ Use Result
```

⚠️ **Current Limitation:** Chains only support Float values. Process Vector by each axis separately.

---

### Example 10: Adaptive Filtering

Change filter strength based on gameplay state.

**Dynamic Preset Switching:**
```blueprint
Event Tick
├─ Branch (Is Aiming?)
│  ├─ True: Set Preset = Low
│  └─ False: Set Preset = High
├─ [One Euro Filter Value]  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Input
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: Dynamic Preset
│  └─ Filter ID: "AdaptiveAim"
└─ Apply to Camera
```

**Advanced: Runtime Parameter Changes with 3-Node:**
```blueprint
// Category: Advanced Filters > Core + Advanced
Get Velocity → Length
├─ Map Range (0-600 → 0.0-1.0)
├─ [Set Beta]  ← Category: Advanced Filters > Advanced
│  ├─ Target: Filter Instance
│  └─ Beta: Mapped Velocity
└─ Apply to Movement Filter
```

---

### Example 11: Debug Visualization

See filter behavior in real-time.

**Statistics Display:**
```blueprint
// Category: Advanced Filters > Debug
Event Tick (Every 30 frames)
├─ [Get Filter Statistics]
│  └─ Target: Filter to Debug
├─ Print String
│  └─ Duration: 0.5 seconds
└─ Draw Debug Info
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
├─ [Kalman Filter Vector]  ← Category: Advanced Filters > One-Click
│  ├─ Preset: Selected
│  └─ Filter ID: "Character_" + Index
└─ Apply to Skeletal Mesh
```

---

### Example 13: Performance Profiling

Measure filter performance.

**Profiling Setup:**
```blueprint
// Category: Advanced Filters > Performance
Begin Play:
[Start Filter Profiling]
└─ Profile ID: "MainCharacterFilter"

End Play:
[Stop Filter Profiling]
├─ Profile ID: "MainCharacterFilter"
└─ Log Results:
    ├─ Average Time MS
    ├─ Peak Time MS
    └─ Update Count
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
├─ [One Euro Filter Value]  ← Category: Advanced Filters > One-Click
│  ├─ Raw Value: Axis Value
│  ├─ Delta Time: World Delta ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "MoveForward"
└─ Add Movement Input

Input Axis Turn
├─ [One Euro Filter Value]
│  ├─ Raw Value: Axis Value
│  ├─ Delta Time: World Delta ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseTurn"
└─ Add Controller Yaw
```

**Camera Setup:**
```blueprint
// Camera smoothing
Event Tick
├─ Get Socket Location "Head"
├─ [Kalman Filter Vector]  ← Category: Advanced Filters > One-Click
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraPos"
├─ Get Control Rotation
├─ [One Euro Filter Vector] (Rotator as Vector)
│  ├─ Delta Time: World Delta ← Required!
│  ├─ Preset: Low
│  └─ Filter ID: "CameraRot"
└─ Set Camera Transform
```

---

## 🚧 Known Limitations

1. **Filter chains only support Float** - Process Vector by each axis
2. **Prediction features not implemented** - Predict Next State not yet available
3. **One Euro requires Delta Time** - Will behave strangely without it

---

## 🎯 Example Tips

1. **Start Simple** - Test with one-click macros first, then move to 3-node if needed
2. **Visualize** - Use Get Filter Statistics to see behavior
3. **Profile** - Use Start/Stop Profiling when performance matters
4. **Experiment** - Try different presets and filter types
5. **Remember Categories** - Check categories if you can't find nodes

---

## 📚 Further Reading

- [Best Practices](BestPractices.md) - Optimization tips
- [Performance Guide](Performance.md) - Detailed benchmarks
- [Troubleshooting](Troubleshooting.md) - Common issues

---

Happy Filtering! 🎉