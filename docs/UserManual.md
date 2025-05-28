# User Manual

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
[Noisy Value] → [Kalman Filter Value] → [Smooth Result]
                  │
                  ├─ Preset: Low/Medium/High
                  └─ Filter ID: "UniqueID"
```

#### Vector Filtering
```blueprint
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
[Create Custom Preset]
├─ Name: "MyVRController"
├─ Kalman Process Noise: 0.1
├─ Kalman Measurement Noise: 0.05
├─ OneEuro Min Cutoff: 0.5
├─ OneEuro Beta: 0.0001
└─ OneEuro DCutoff: 1.0
    ↓
[Apply Custom Preset]
├─ Filter: Target Filter
└─ Preset Name: "MyVRController"
```

### Filter Chaining

Combine multiple filters for sophisticated processing.

```blueprint
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
[Blend Filter Outputs]
├─ Filter A: Kalman Result
├─ Filter B: OneEuro Result
├─ Weight: 0.0-1.0 (runtime adjustable)
└─ Output: Weighted Average
```

### Performance Profiling

Monitor filter performance in real-time.

```blueprint
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
[Enable Auto Tune]
├─ Filter: Target Filter
├─ Sample Count: 100
└─ Target Smoothness: 0.8
    ↓
[Filter automatically adjusts based on signal characteristics]
```

### Filter Statistics

Access detailed filter information for debugging.

```blueprint
[Get Filter Statistics]
├─ Current Value: 45.2
├─ Predicted Value: 45.8
├─ Kalman Gain: 0.82
├─ Error Covariance: 0.03
├─ Update Count: 523
└─ Last Update Time: 0.016ms
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
- Clear unused filters with `Clear All Filters` node
- Monitor memory with `Get Filter Memory Usage`

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
   [Update Filter Batch]
   ├─ Values: Array of Floats
   └─ Output: Array of Filtered Values
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
   Near: High Preset
   Medium: Medium Preset
   Far: Low Preset or Skip
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
[Set Filter Debug Mode]
├─ Filter: Target Filter
├─ Show Graph: True
├─ Show Statistics: True
└─ Graph Size: 200x100
```

### Common Issues

| Problem | Cause | Solution |
|---------|-------|----------|
| No smoothing | Wrong Filter ID | Use consistent ID |
| Too much lag | High preset | Switch to Low/Medium |
| Jumpy output | Missing Delta Time | Connect Delta Time |
| Memory growth | Creating new filters | Reuse Filter IDs |

---

## 📝 Summary

The Advanced Filters Plugin empowers you to create professional, polished experiences with minimal effort. Whether you're building a VR application, stabilizing camera movement, or processing sensor data, these filters provide the tools you need.

**Key Takeaways:**
- 🎯 Choose Kalman for prediction and stability
- ⚡ Choose One Euro for low latency
- 📊 Start with presets, customize as needed
- 🔧 Use one-click for simplicity, 3-node for control
- 📈 Monitor performance with built-in profiling

---

Happy Filtering! 🎉

For technical details, see the [API Reference](APIReference.md) →