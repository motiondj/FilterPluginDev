# Quick Start Guide

*Read this in other languages: [English](QuickStart.md), [한국어](QuickStart_KR.md)*

Get started with Advanced Filters Plugin in just 5 minutes!

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
[Kalman Filter Value]
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
- Add `Delta Time` input from Event Tick
- Notice the faster response!

## 💡 One-Click vs 3-Node System

### One-Click (What you just used)
```blueprint
[Sensor Value] → [Kalman Filter Value] → [Result]
```
✅ Pros: Super simple, one node does everything
❌ Cons: Creates new filter each time if Filter ID changes

### 3-Node System (More control)
```blueprint
Begin Play:
[Create Filter] → [Initialize] → [Save as Variable]

Event Tick:
[Variable] → [Update Estimate] → [Result]
```
✅ Pros: Full control, can change parameters at runtime
❌ Cons: Requires 3 nodes and variable management

## 🎮 Real-World Examples

### Smooth Mouse Look
```blueprint
[Mouse X] → [One Euro Filter Value] → [Add Controller Yaw Input]
```

### Stable Health Bar
```blueprint
[Current Health] → [Kalman Filter Value] → [Set Progress Bar Percent]
```

### VR Hand Tracking
```blueprint
[Controller Position] → [One Euro Filter Vector] → [Set Hand Location]
```

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

## 🚨 Troubleshooting

| Problem | Solution |
|---------|----------|
| Can't find filter nodes | Check plugin is enabled in Plugins menu |
| Filter seems to lag | Normal for Kalman, try One Euro |
| Too much smoothing | Use "Low" preset |
| Not enough smoothing | Use "High" preset |

## 📚 Next Steps

Congratulations! You've successfully implemented professional noise filtering. 

**Ready for more?**
- Read the [User Manual](UserManual.md) for all features
- Check [API Reference](APIReference.md) for technical details
- Explore [Example Projects](Examples.md) for advanced usage

## 🆘 Need Help?

- 💬 [Discord Community](https://discord.gg/yourserver)
- 📧 support@yourcompany.com
- 🐛 [Report Issues](https://github.com/yourusername/AdvancedFilters/issues)

---

Happy Filtering! 🎉