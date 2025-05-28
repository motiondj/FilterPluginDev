# Best Practices

*Read this in other languages: [English](BestPractices.md), [한국어](BestPractices_KR.md)*

Guidelines and recommendations for optimal use of Advanced Filters Plugin

## 📍 Navigation

- [← Back: Blueprint Examples](Examples.md)
- [→ Next: Performance Guide](Performance.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - [Installation Guide](Installation.md)
- **User Guides**
  - [User Manual](UserManual.md)
  - [Blueprint Examples](Examples.md)
  - **Best Practices** (You are here)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 📋 Table of Contents

1. [Filter Selection Guidelines](#filter-selection-guidelines)
2. [Blueprint Best Practices](#blueprint-best-practices)
3. [Performance Optimization](#performance-optimization)
4. [Common Patterns](#common-patterns)
5. [Anti-Patterns to Avoid](#anti-patterns-to-avoid)
6. [Advanced Techniques](#advanced-techniques)

---

## 🎯 Filter Selection Guidelines

### Choosing the Right Filter

Use this decision tree to select the optimal filter for your use case:

```
Start Here
    ↓
Is latency critical? (< 3 frames)
├─ Yes → Use One Euro Filter
│        ├─ VR/AR controllers
│        ├─ Mouse input
│        └─ Touch interfaces
└─ No → Need prediction?
         ├─ Yes → Use Kalman Filter
         │        ├─ AI movement
         │        ├─ Camera tracking
         │        └─ Physics objects
         └─ No → Either filter works
                  └─ Choose based on preference
```

### Filter Characteristics Summary

| Use Case | Recommended Filter | Preset | Reason |
|----------|-------------------|--------|---------|
| VR Hand Tracking | One Euro | Low | Minimal latency crucial |
| Camera Follow | Kalman | Medium | Smooth prediction needed |
| UI Elements | Kalman | High | Visual smoothness priority |
| Mouse Aiming | One Euro | Low | Instant response required |
| Health Bars | Kalman | High | Smooth transitions |
| Vehicle Movement | Kalman | Medium | Predictable motion |
| Touch Gestures | One Euro | Medium | Balance of smooth + responsive |

---

## 📘 Blueprint Best Practices

### 1. Filter ID Management

**✅ DO: Use Consistent IDs**
```blueprint
// Good - Same ID maintains filter state
Filter ID: "PlayerHealth"
Filter ID: "PlayerHealth"  // Reuses existing filter
```

**❌ DON'T: Create Dynamic IDs**
```blueprint
// Bad - Creates new filter every frame
Filter ID: "Health_" + FrameNumber
Filter ID: "Health_" + RandomInt
```

### 2. Filter Lifecycle

**✅ DO: Initialize Once**
```blueprint
// Good - Initialize in BeginPlay
Event BeginPlay
├─ Create Filter
├─ Initialize (Medium)
└─ Store in Variable

Event Tick
└─ Use stored filter
```

**❌ DON'T: Create Every Frame**
```blueprint
// Bad - Wasteful and resets state
Event Tick
├─ Create Filter  // Wrong!
├─ Initialize     // Wrong!
└─ Update
```

### 3. Delta Time Usage

**✅ DO: Always Connect Delta Time for One Euro**
```blueprint
// Good - Frame-rate independent
One Euro Filter Value
├─ Raw Value: Input
├─ Delta Time: Event Tick Delta ← Required!
└─ Filter ID: "MouseX"
```

**❌ DON'T: Use Fixed Values**
```blueprint
// Bad - Breaks at different frame rates
One Euro Filter Value
├─ Raw Value: Input
├─ Delta Time: 0.016  // Wrong!
└─ Filter ID: "MouseX"
```

### 4. Preset Selection

**✅ DO: Match Preset to Use Case**
```blueprint
// Good examples
UI Animation: High preset (maximum smoothness)
Player Input: Low preset (fast response)
General Use: Medium preset (balanced)
```

**❌ DON'T: Use One Preset for Everything**
```blueprint
// Bad - Suboptimal results
All filters: High preset  // Too much lag for input
All filters: Low preset   // Too jittery for UI
```

---

## ⚡ Performance Optimization

### 1. Conditional Updates

Only update filters when values change significantly:

```blueprint
// Efficient filtering
Get New Value
├─ Subtract Last Value
├─ Absolute Value
├─ Branch (> Threshold)
│   ├─ True: Update Filter
│   └─ False: Use Cached Value
└─ Store Result
```

### 2. LOD-Based Filtering

Adjust filter quality based on distance:

```blueprint
// Performance scaling
Get Distance to Camera
├─ < 10m: High preset (full quality)
├─ < 50m: Medium preset
├─ < 100m: Low preset
└─ > 100m: Skip filtering
```

### 3. Batch Processing

Process multiple values efficiently:

```blueprint
// Good - Single filter for array
For Each (Position Array)
├─ Update Filter (Same ID + Index)
└─ Store Result

// Better - Custom batch node
Update Filter Batch
├─ Input: Array
└─ Output: Filtered Array
```

### 4. Frame Rate Considerations

Adapt to performance:

```blueprint
// Dynamic quality adjustment
Get Frame Rate
├─ > 60 FPS: Use High presets
├─ > 30 FPS: Use Medium presets
└─ < 30 FPS: Use Low presets
```

---

## 🔄 Common Patterns

### Pattern 1: Smooth Camera System

```blueprint
// Professional camera following
Player Controller
├─ Get Desired Camera Location
├─ [Kalman Filter Vector]
│   ├─ Preset: Medium
│   └─ ID: "CameraPosition"
├─ Get Desired Camera Rotation
├─ [One Euro Filter] (as vector)
│   ├─ Preset: Low
│   ├─ Delta Time: Connected
│   └─ ID: "CameraRotation"
└─ Set Camera Transform
```

### Pattern 2: Input Smoothing

```blueprint
// Responsive but smooth input
Input Component
├─ Get Raw Input Axis
├─ [One Euro Filter Value]
│   ├─ Preset: Low
│   ├─ Delta Time: Connected
│   └─ ID: "Input_" + AxisName
├─ Apply Deadzone
└─ Add Movement Input
```

### Pattern 3: UI Animation

```blueprint
// Smooth UI transitions
Widget Blueprint
├─ On Value Changed
├─ [Kalman Filter Value]
│   ├─ Preset: High
│   └─ ID: WidgetName + "_Anim"
├─ Curve (Optional)
└─ Set Widget Property
```

### Pattern 4: Networked Movement

```blueprint
// Smooth networked positions
On Rep Position
├─ [Kalman Filter Vector]
│   ├─ Preset: Medium
│   └─ ID: "NetPos_" + PlayerID
├─ Interpolate to Position
└─ Set Actor Location
```

---

## ❌ Anti-Patterns to Avoid

### Anti-Pattern 1: Filter Chaining Abuse

**❌ Bad: Too Many Filters**
```blueprint
// Excessive - Adds latency
Value → Kalman → OneEuro → Kalman → Result
```

**✅ Good: Purposeful Chaining**
```blueprint
// Justified - Each serves a purpose
Value → OneEuro (remove jitter) → Kalman (smooth) → Result
```

### Anti-Pattern 2: Mismatched Presets

**❌ Bad: Wrong Context**
```blueprint
// High preset for mouse input = sluggish
Mouse Input → Kalman (High) → Camera Turn
```

**✅ Good: Context-Appropriate**
```blueprint
// Low preset for input = responsive
Mouse Input → One Euro (Low) → Camera Turn
```

### Anti-Pattern 3: Memory Leaks

**❌ Bad: Never Clearing Filters**
```blueprint
// Accumulates forever
Create Filter with Random ID
Never call Clear Filters
```

**✅ Good: Proper Cleanup**
```blueprint
// Clean up on level change
Event End Play
└─ Clear All Filters
```

### Anti-Pattern 4: Ignoring Frame Independence

**❌ Bad: Frame-Dependent Logic**
```blueprint
// Breaks at different FPS
If (FilteredValue - LastValue > 0.1)
    Do Something  // Threshold depends on FPS
```

**✅ Good: Frame-Independent**
```blueprint
// Works at any FPS
If (FilteredValue - LastValue > 0.1 * DeltaTime)
    Do Something  // Threshold scales with time
```

---

## 🚀 Advanced Techniques

### Technique 1: Adaptive Filtering

Dynamically adjust filter strength based on context:

```blueprint
// Context-aware filtering
Get Player State
├─ In Combat: Low preset (responsive)
├─ In Menu: High preset (smooth)
└─ Exploring: Medium preset (balanced)

// Speed-based adaptation
Get Velocity Magnitude
├─ Map to Range (0-1000 → 0.0-1.0)
├─ Create Custom Preset
│   └─ Beta: Mapped Value
└─ Apply to Filter
```

### Technique 2: Predictive Filtering

Use Kalman's prediction for look-ahead:

```blueprint
// Aim prediction
Get Target Velocity
├─ Kalman Filter (store reference)
├─ Call "Predict Next State"
│   └─ Steps: 5-10 frames
├─ Calculate Lead Position
└─ Aim at Predicted Position
```

### Technique 3: Filter Blending

Combine multiple filters for optimal results:

```blueprint
// Hybrid approach
Get Input Value
├─ Path 1: One Euro (Low) → 70% weight
├─ Path 2: Kalman (Medium) → 30% weight
├─ Weighted Average
└─ Final Result
```

### Technique 4: Performance Profiling

Monitor and optimize filter performance:

```blueprint
// Performance monitoring
Begin Play
└─ Start Filter Profiling (Debug builds)

Event End Play
├─ Stop Filter Profiling
├─ Log Average Time
├─ Log Peak Time
└─ Identify Bottlenecks
```

---

## 📊 Decision Matrix

### Quick Reference Guide

| Scenario | Filter | Preset | Delta Time | Notes |
|----------|--------|--------|------------|-------|
| FPS Aiming | One Euro | Low | Required | Minimal latency |
| Third Person Camera | Kalman | Medium | Not needed | Smooth follow |
| UI Animations | Kalman | High | Not needed | Visual priority |
| VR Controllers | One Euro | Low | Required | No motion sickness |
| Vehicle Physics | Kalman | Medium | Not needed | Predictable motion |
| Touch Gestures | One Euro | Medium | Required | Natural feel |
| Health/Mana Bars | Kalman | High | Not needed | Smooth changes |
| Particle Effects | Either | Low | Depends | Performance first |

---

## ✅ Checklist

Before shipping, verify:

- [ ] All filters use consistent IDs
- [ ] Delta Time connected for One Euro filters
- [ ] Appropriate presets for each use case
- [ ] No filters created in Tick events
- [ ] Memory cleanup on level transitions
- [ ] Performance tested at target frame rate
- [ ] LOD system implemented for many filters
- [ ] Error handling for edge cases

---

## 📚 Further Reading

- [Performance Guide](Performance.md) - Detailed optimization
- [Troubleshooting](Troubleshooting.md) - Common issues
- [API Reference](APIReference.md) - Technical details

---

Remember: The best filter is the one that solves your specific problem efficiently! 🎯