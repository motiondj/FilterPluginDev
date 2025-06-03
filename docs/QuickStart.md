# Quick Start Guide (Improved Version)

*Read this in other languages: [English](QuickStart.md), [한국어](QuickStart_KR.md)*

Get started with Advanced Filters Plugin in just 5 minutes!

## 📍 Navigation

- [← Back to README](../README.md)
- [→ Next: User Manual](UserManual.md)

### 📖 All Documentation
- **Getting Started**
  - **Quick Start Guide** (You are here)
  - [Installation Guide](Installation.md)
- **User Guides**
  - [User Manual](UserManual.md)
  - [Blueprint Examples](Examples.md)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 🗂️ Finding Nodes in Blueprints

Once the plugin is installed, you can find nodes in the Blueprint editor by right-clicking and navigating to:

### Method 1: By Category
```
Advanced Filters
├── Core          → 3-node system (Create, Initialize, Update)
├── One-Click     → One-click macros (Kalman/OneEuro Filter Value/Vector)
├── Utility       → Utilities (Reset, Get Current Value, etc.)
└── (Other categories...)
```

### Method 2: By Search
- Search "Kalman" → Kalman filter related nodes
- Search "One Euro" → One Euro filter related nodes
- Search "Filter Value" → One-click macros

---

## 📋 Prerequisites

- Unreal Engine 5.5 or higher
- Basic knowledge of Blueprints
- Advanced Filters Plugin installed and enabled

## 🚀 Your First Filter in 3 Steps

### Step 1: Create a Test Actor

1. **Create a new Blueprint Actor**
   - Right-click in Content Browser
   - Select `Blueprint Class` → `Actor`
   - Name it `BP_MyFirstFilter`

2. **Add a Cube Mesh**
   - In Components panel, click `Add Component`
   - Select `Static Mesh`
   - Set Static Mesh to `Cube`
   - Scale to (0.5, 0.5, 0.5)

### Step 2: Add Filtering Logic

Open the Event Graph and create this simple setup:

![Quick Start Diagram](images/quickstart_diagram.png)

```blueprint
Event Tick
    ↓
[Get Game Time in Seconds]
    ↓
[Sin] (multiply by 100 for movement range)
    ↓
[Random Float in Range] (-10, 10) → [Add] (add noise)
    ↓
[Kalman Filter Value]  ← Category: Advanced Filters > One-Click
- Raw Value: (connect)
- Preset: Medium
- Filter ID: "Position"
    ↓
[Make Vector] (X: filtered value, Y: 0, Z: 0)
    ↓
[Set Actor Location]
```

### Step 3: See the Magic!

1. **Place the actor** in your level
2. **Press Play**
3. **Watch** your cube move smoothly despite the noise!

## 🎯 What Just Happened?

You created a cube that:
- ✅ Moves along a sine wave path
- ✅ Has random noise added (simulating sensor jitter)
- ✅ Uses Kalman filter to smooth the movement
- ✅ Results in clean, professional motion

---

## 🔥 Try These Variations

### 1. Compare Filtered vs Unfiltered

Add a second cube without filtering to see the difference:

```blueprint
Create two paths from the noisy signal:
Path 1: Noisy Signal → Kalman Filter → Cube 1 (smooth)
Path 2: Noisy Signal → Cube 2 (jittery)
```

### 2. Try Different Presets

Change the Preset parameter:
- **Low**: Less filtering, faster response
- **Medium**: Balanced (default)
- **High**: Maximum smoothing

### 3. Switch to One Euro Filter

Replace `Kalman Filter Value` with `One Euro Filter Value`:

```blueprint
[One Euro Filter Value]  ← Category: Advanced Filters > One-Click
├─ Raw Value: Noisy signal
├─ Delta Time: Event Tick's Delta Seconds ← Important!
├─ Preset: Medium
└─ Filter ID: "Position"
```

**Note**: One Euro filters require Delta Time!

---

## 💡 One-Click vs 3-Node System

### One-Click (What you just used)
**Category**: Advanced Filters > One-Click

```blueprint
[Sensor Value] → [Kalman Filter Value] → [Result]
```
✅ Pros: Super simple, one node does everything
❌ Cons: Creates new filter each time if Filter ID changes

### 3-Node System (More control)
**Category**: Advanced Filters > Core

```blueprint
Begin Play:
[Create Filter] → [Initialize] → [Save as Variable]

Event Tick:
[Variable] → [Update Estimate] → [Result]
```
✅ Pros: Full control, can change parameters at runtime
❌ Cons: Requires 3 nodes and variable management

---

## 🎮 Real-World Examples

### Smooth Mouse Look
```blueprint
Category: Advanced Filters > One-Click

[Mouse X] → [One Euro Filter Value] → [Add Controller Yaw Input]
            ├─ Delta Time: Required!
            └─ Filter ID: "MouseX"
```

### Stable Health Bar
```blueprint
Category: Advanced Filters > One-Click

[Current Health] → [Kalman Filter Value] → [Set Progress Bar Percent]
                   └─ Filter ID: "HealthBar"
```

### VR Hand Tracking
```blueprint
Category: Advanced Filters > One-Click

[Controller Position] → [One Euro Filter Vector] → [Set Hand Location]
                       ├─ Delta Time: Required!
                       └─ Filter ID: "RightHand"
```

---

## 🚀 Advanced Features Preview

### Creating Custom Presets
**Category**: Advanced Filters > Custom Preset

```blueprint
[Create Custom Preset]
├─ Preset Name: "MyVRPreset"
├─ Filter Type: OneEuro
├─ Process Noise/Min Cutoff: 0.3  ← Used as Min Cutoff for OneEuro
├─ Measurement Noise/Beta: 0.0001  ← Used as Beta for OneEuro
└─ DCutoff: 1.0
```

⚠️ **Note**: Parameter names have different meanings depending on filter type!

---

## ❓ Common Questions

**Q: Which filter should I use?**
- **Kalman**: Best for predictable motion (camera, AI)
- **One Euro**: Best for user input (mouse, VR controllers)

**Q: What does Filter ID do?**
- It identifies unique filter instances
- Use same ID = continue filtering
- Change ID = start fresh

**Q: Why is my filter not smooth?**
- Try "High" preset
- Check if Delta Time is connected (One Euro only)
- Ensure consistent Filter ID

**Q: Can't find the nodes?**
- Check if plugin is enabled
- Look under "Advanced Filters" category
- Search globally for "Kalman" or "One Euro"

---

## 🚨 Troubleshooting

| Problem | Solution |
|---------|----------|
| Can't find filter nodes | Check plugin is enabled in Plugins menu |
| Nodes not in specific category | Check "Advanced Filters > Subcategory" |
| Filter seems to lag | Normal for Kalman, try One Euro |
| Too much smoothing | Use "Low" preset |
| Not enough smoothing | Use "High" preset |
| One Euro acting weird | Check Delta Time connection! |

---

## 📚 Next Steps

Congratulations! You've successfully implemented professional noise filtering.

**Ready for more?**
- Read the [User Manual](UserManual.md) for all features
- Check [API Reference](APIReference.md) for technical details
- Explore [Example Projects](Examples.md) for advanced usage

---

## 🎯 Quick Reference - Node Locations

### Exact locations of frequently used nodes:

| Node Name | Category Path | Purpose |
|-----------|---------------|---------|
| **Kalman Filter Value** | Advanced Filters > One-Click | Float one-click Kalman filtering |
| **Kalman Filter Vector** | Advanced Filters > One-Click | Vector one-click Kalman filtering |
| **One Euro Filter Value** | Advanced Filters > One-Click | Float one-click One Euro filtering |
| **One Euro Filter Vector** | Advanced Filters > One-Click | Vector one-click One Euro filtering |
| **Create Filter** | Advanced Filters > Core | 3-node: Create filter |
| **Initialize Filter** | Advanced Filters > Core | 3-node: Initialize filter |
| **Update Filter** | Advanced Filters > Core | 3-node: Update filter |
| **Create Custom Preset** | Advanced Filters > Custom Preset | Create custom settings |
| **Reset Filter** | Advanced Filters > Utility | Reset filter |
| **Get Filter Statistics** | Advanced Filters > Debug | Debug information |

---

## 🚧 Features Not Yet Implemented

The following features are mentioned in documentation but not available in the current version:
- **Predict Next State** - Future state prediction (Kalman)
- **Get Predicted Value** - Get predicted value (Kalman)

These features will be added in future updates.

---

## 🆘 Need Help?

- 💬 [Discord Community](https://discord.gg/yourserver)
- 📧 support@yourcompany.com
- 🐛 [Report Issues](https://github.com/yourusername/AdvancedFilters/issues)

---

Happy Filtering! 🎉