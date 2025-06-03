# User Manual (Improved Version)

*Read this in other languages: [English](UserManual.md), [한국어](UserManual_KR.md)*

Complete guide to Advanced Filters Plugin for Unreal Engine

## 📍 Navigation

- [← Back: Quick Start Guide](QuickStart.md)
- [→ Next: API Reference](APIReference.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - [Installation Guide](Installation.md)
- **User Guides**
  - **User Manual** (You are here)
  - [Blueprint Examples](Examples.md)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 🗂️ Blueprint Node Location Guide

### Node Category Map

When right-clicking in the Blueprint editor, you can find nodes in these categories:

```
Advanced Filters
├── Core (Core 3-node system)
│   ├── Create Filter
│   ├── Initialize Filter
│   └── Update Filter (Float/Vector)
├── One-Click (One-click macros)
│   ├── Kalman Filter Value
│   ├── Kalman Filter Vector
│   ├── One Euro Filter Value
│   └── One Euro Filter Vector
├── Utility (Utilities)
│   ├── Reset Filter
│   ├── Get Current Value
│   ├── Is Filter Initialized
│   └── Cleanup All Filters
├── Advanced (Advanced features)
│   ├── Set Process Noise
│   ├── Set Measurement Noise
│   ├── Set Min Cutoff
│   └── Set Beta
├── Custom Preset (Custom presets)
│   ├── Create Custom Preset
│   └── Apply Custom Preset
├── Chain (Filter chains)
│   ├── Create Filter Chain
│   └── Process Through Chain
├── Performance (Performance)
│   ├── Start Profiling
│   └── Stop Profiling
├── Debug (Debug)
│   └── Get Filter Statistics
└── Recommendation (Recommendations)
    └── Recommend Filter Type
```

**💡 Tip**: Type "Advanced Filters" in the search box to see all related nodes!

---

## 📋 Table of Contents

1. [Introduction](#introduction)
2. [Filter Types](#filter-types)
3. [Basic Usage](#basic-usage)
4. [Advanced Features](#advanced-features)
5. [Best Practices](#best-practices)
6. [Performance Optimization](#performance-optimization)

---

## 🎯 Introduction

The Advanced Filters Plugin provides two industry-standard filtering algorithms that help you create professional, polished experiences in Unreal Engine. Whether you're dealing with noisy sensor data, jittery input, or unpredictable movement, these filters will help you achieve smooth, stable results.

### When to Use Filters

Filters are essential when you need to:
- ✅ Remove noise from sensor data
- ✅ Smooth user input (mouse, touch, VR controllers)
- ✅ Stabilize camera movement
- ✅ Create professional UI animations
- ✅ Improve AI movement patterns

---

## 🔧 Filter Types

### Kalman Filter

The Kalman filter is an optimal state estimator that predicts future states based on past observations.

**Characteristics:**
- 🎯 Excellent noise reduction (95%+)
- 📊 Predictive capabilities
- ⏱️ 5-10 frame latency
- 🔄 Consistent smoothing

**Best Use Cases:**
- Camera stabilization
- AI pathfinding
- Sensor data processing
- Physics simulations
- Health/mana bars

### One Euro Filter

The One Euro filter is an adaptive filter that adjusts its smoothing based on signal speed.

**Characteristics:**
- ⚡ Low latency (0-3 frames)
- 🎮 Speed-adaptive filtering
- 📈 85%+ noise reduction
- 🔀 Dynamic response

**Best Use Cases:**
- VR/AR controllers
- Mouse input
- Touch interfaces
- Real-time interactions
- Drawing applications

---

## 💡 Basic Usage

### Method 1: One-Click Macros (Simplest)

Perfect for beginners or quick prototyping.

#### Float Filtering
```blueprint
Category: Advanced Filters > One-Click

[Noisy Value] → [Kalman Filter Value] → [Smooth Result]
                  │
                  ├─ Preset: Low/Medium/High
                  └─ Filter ID: "UniqueID"
```

#### Vector Filtering
```blueprint
Category: Advanced Filters > One-Click

[Noisy Position] → [One Euro Filter Vector] → [Smooth Position]
                    │
                    ├─ Preset: Medium
                    ├─ Delta Time: Event Tick Delta
                    └─ Filter ID: "Position"
```

### Method 2: 3-Node System (Full Control)

Offers complete control over filter lifecycle and parameters.

#### Setup Phase
```blueprint
Category: Advanced Filters > Core

Begin Play:
[Create Filter] → [Initialize Filter] → [Store in Variable]
       │                    │
       │                    └─ Preset: Medium
       └─ Type: Kalman/OneEuro
```

#### Update Phase
```blueprint
Event Tick:
[Get Filter Variable] → [Update Filter] → [Get Result]
                              │
                              └─ New Value: Sensor Reading
```

### Preset System

Each filter includes three presets optimized for different scenarios:

| Preset | Response | Smoothing | Use Case |
|--------|----------|-----------|----------|
| **Low** | Fast | Minimal | Quick reactions needed |
| **Medium** | Balanced | Moderate | General purpose |
| **High** | Slow | Maximum | Smooth visuals priority |

---

## 🚀 Advanced Features

### Custom Presets

Create tailored filter configurations for specific needs.

```blueprint
Category: Advanced Filters > Custom Preset

[Create Custom Preset]
├─ Name: "MyVRController"
├─ Filter Type: OneEuro when selected
│  ├─ Process Noise/Min Cutoff: 0.5 (Used as Min Cutoff)
│  ├─ Measurement Noise/Beta: 0.0001 (Used as Beta)
│  └─ DCutoff: 1.0
└─ Filter Type: Kalman when selected
   ├─ Process Noise/Min Cutoff: 0.05 (Used as Process Noise)
   ├─ Measurement Noise/Beta: 0.1 (Used as Measurement Noise)
   └─ DCutoff: (Ignored)
```

⚠️ **Important**: Parameter names have different meanings depending on filter type!
- **Kalman Filter**: First = Process Noise (Q), Second = Measurement Noise (R)
- **OneEuro Filter**: First = Min Cutoff, Second = Beta

### Filter Chaining

Combine multiple filters for sophisticated processing.

```blueprint
Category: Advanced Filters > Chain

[Create Filter Chain]
├─ Filter 1: Kalman (High)    // Remove large noise
├─ Filter 2: OneEuro (Low)    // Maintain responsiveness
└─ Blend Weight: 0.7          // 70% first, 30% second
    ↓
[Process Through Chain]
├─ Input: Raw Signal
└─ Output: Double-filtered Result
```

### Filter Blending

Mix outputs from multiple filters dynamically.

```blueprint
Category: Advanced Filters > Chain

[Blend Filter Outputs]
├─ Filter A: Kalman Result
├─ Filter B: OneEuro Result
├─ Weight: 0.0-1.0 (runtime adjustable)
└─ Output: Weighted Average
```

### Performance Profiling

Monitor filter performance in real-time.

```blueprint
Category: Advanced Filters > Performance

[Start Filter Profiling]
    ↓
[... Your Filtering Logic ...]
    ↓
[Stop Filter Profiling]
    ↓
[Get Profile Data]
├─ Average Time: 0.02ms
├─ Peak Time: 0.05ms
├─ Update Count: 1847
└─ Memory Usage: 128 bytes
```

### Auto-Tuning

Let the system automatically adjust filter parameters.

```blueprint
Category: Advanced Filters > Advanced

[Auto Tune Filter]
├─ Filter: Target Filter
├─ Recent Values: Array of 100 recent values
└─ Success: Auto-tune success status
    ↓
[Filter automatically adjusts based on signal characteristics]
```

### Filter Statistics

Access detailed filter information for debugging.

```blueprint
Category: Advanced Filters > Debug

[Get Filter Statistics]
├─ Target: Filter Instance
└─ Output: Statistics String
    - Filter Type
    - Current Value
    - Kalman Gain (Kalman only)
    - Current Cutoff (OneEuro only)
    - Update Count
```

---

## 📚 Best Practices

### 1. Filter Selection

Choose the right filter for your use case:

```
Is latency critical? (VR/AR/Mouse)
    ├─ Yes → One Euro Filter
    └─ No → Is prediction needed?
              ├─ Yes → Kalman Filter
              └─ No → Either works
```

### 2. Consistent Filter IDs

Always use the same Filter ID for continuous filtering:

✅ **Good:**
```blueprint
Filter ID: "PlayerHealth"  // Same ID every frame
```

❌ **Bad:**
```blueprint
Filter ID: "Health_" + FrameCount  // Creates new filter each frame!
```

### 3. Delta Time for One Euro

Always connect Delta Time for One Euro filters:

```blueprint
[One Euro Filter Value]
├─ Raw Value: Input
├─ Delta Time: Event Tick Delta ← Don't forget!
├─ Preset: Medium
└─ Filter ID: "MouseX"
```

### 4. Preset Selection Guide

- **Low**: User inputs, fast gameplay
- **Medium**: Most situations
- **High**: Cinematic cameras, UI elements

### 5. Memory Management

Filters are automatically managed, but follow these guidelines:
- Reuse Filter IDs when possible
- Clear unused filters with `Cleanup All Filters` node (Advanced Filters > Utility)
- Monitor memory with `Get Filter Memory Usage` (Advanced Filters > Performance)

---

## ⚡ Performance Optimization

### Performance Characteristics

| Operation | Time | Memory |
|-----------|------|--------|
| Create Filter | 0.1ms | 100-150 bytes |
| Update (Float) | 0.01ms | 0 bytes |
| Update (Vector) | 0.03ms | 0 bytes |
| Custom Preset | 0.02ms | 50 bytes |

### Optimization Tips

1. **Batch Processing**
   ```blueprint
   // Process multiple values with same filter
   [For Each Loop]
   └─ [Update Filter] (Use same filter instance)
   ```

2. **Conditional Updates**
   ```blueprint
   // Only update when value changes significantly
   If (Abs(NewValue - LastValue) > Threshold)
       → Update Filter
   ```

3. **LOD-Based Filtering**
   ```blueprint
   // Use different presets based on distance
   Near: High preset
   Medium: Medium preset
   Far: Low preset or Skip
   ```

4. **Frame Rate Independence**
   ```blueprint
   // Ensure consistent behavior across frame rates
   Always use Delta Time for One Euro
   Consider frame rate in custom presets
   ```

---

## 🔍 Debugging

### Visual Debugging

Enable visual debugging to see filter behavior:

```blueprint
Category: Advanced Filters > Debug

[Get Filter Statistics]
├─ Filter: Target Filter
└─ Display output with Print String
```

### Common Issues

| Problem | Cause | Solution |
|---------|-------|----------|
| No smoothing | Wrong Filter ID | Use consistent ID |
| Too much lag | High preset | Switch to Low/Medium |
| Jumpy output | Missing Delta Time | Connect Delta Time |
| Memory growth | Creating new filters | Reuse Filter IDs |

---

## 🚧 Features Not Yet Implemented

The following features are described in documentation but not implemented in the current version:

### Prediction Features (Coming in Future Updates)
- **Predict Next State**: Future state prediction for Kalman filters
- **Get Predicted Value**: Get current predicted value

These features will be added in the next version.

---

## 📝 Summary

The Advanced Filters Plugin empowers you to create professional, polished experiences with minimal effort. Whether you're building a VR application, stabilizing camera movement, or processing sensor data, these filters provide the tools you need.

**Key Takeaways:**
- 🎯 Choose Kalman for prediction and stability
- ⚡ Choose One Euro for low latency
- 📊 Start with presets, customize as needed
- 🔧 Use one-click for simplicity, 3-node for control
- 📈 Monitor performance with built-in profiling
- 🗂️ Understanding categories makes finding nodes easier!

---

Happy Filtering! 🎉

For technical details, see the [API Reference](APIReference.md) →