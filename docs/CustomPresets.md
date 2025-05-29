# Custom Presets

*Read this in other languages: [English](CustomPresets.md), [한국어](CustomPresets_KR.md)*

Advanced guide to creating and managing custom filter presets

## 📍 Navigation

- [← Back: Best Practices](BestPractices.md)
- [→ Next: Filter Chaining](FilterChaining.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - [Installation Guide](Installation.md)
- **User Guides**
  - [User Manual](UserManual.md)
  - [Blueprint Examples](Examples.md)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)
- **Advanced Topics**
  - **Custom Presets** (You are here)
  - [Filter Chaining](FilterChaining.md)
  - [Migration Guide](Migration.md)

---

## 📋 Table of Contents

1. [Understanding Presets](#understanding-presets)
2. [Creating Custom Presets](#creating-custom-presets)
3. [Preset Management](#preset-management)
4. [Use Case Examples](#use-case-examples)
5. [Advanced Techniques](#advanced-techniques)
6. [Troubleshooting Presets](#troubleshooting-presets)

---

## 🎯 Understanding Presets

### What Are Presets?

Filter presets are pre-configured parameter sets that define how filters behave. Instead of manually adjusting individual parameters, presets provide optimized configurations for common scenarios.

### Built-in Presets

The plugin includes three built-in presets:

| Preset | Kalman Q | Kalman R | OneEuro MinCutoff | OneEuro Beta | Use Case |
|--------|----------|----------|-------------------|--------------|----------|
| **Low** | 0.1 | 0.01 | 1.0 | 0.001 | Fast response, minimal filtering |
| **Medium** | 0.01 | 0.1 | 0.5 | 0.007 | Balanced performance |
| **High** | 0.001 | 1.0 | 0.1 | 0.01 | Maximum smoothing |

### When to Create Custom Presets

Create custom presets when:
- ✅ Built-in presets don't meet your specific needs
- ✅ You have unique hardware characteristics (VR headsets, sensors)
- ✅ Your application has specific latency/smoothing requirements
- ✅ You want to standardize settings across your team

---

## 🛠️ Creating Custom Presets

### Method 1: Blueprint Creation

#### Basic Custom Preset
```blueprint
Event BeginPlay
    ↓
[Create Custom Preset]
├─ Preset Name: "MyVRController"
├─ Process Noise (Kalman Q): 0.05
├─ Measurement Noise (Kalman R): 0.02
├─ Min Cutoff (OneEuro): 0.3
├─ Beta (OneEuro): 0.0001
└─ DCutoff (OneEuro): 1.0
    ↓
[Success] → Store preset name for later use
```

#### Applying Custom Preset
```blueprint
[Create Filter] (Type: OneEuro)
    ↓
[Apply Custom Preset]
├─ Target: Filter Reference
└─ Preset Name: "MyVRController"
    ↓
[Filter now uses custom parameters]
```

### Method 2: Runtime Creation

Create presets dynamically based on conditions:

```blueprint
// Adaptive preset creation
Get Hardware Type
├─ Branch (Is Mobile Device?)
│   ├─ True: Create "MobileOptimized" preset
│   │   ├─ Q: 0.2 (faster response)
│   │   ├─ R: 0.01 (trust measurements)
│   │   ├─ MinCutoff: 1.5 (less smoothing)
│   │   └─ Beta: 0.0005
│   └─ False: Create "DesktopOptimized" preset
│       ├─ Q: 0.005 (smoother)
│       ├─ R: 0.5 (more filtering)
│       ├─ MinCutoff: 0.2 (more smoothing)
│       └─ Beta: 0.01
```

### Parameter Guidelines

#### Kalman Filter Parameters

**Process Noise (Q):**
- Higher values (0.1+): Trust new measurements more, faster adaptation
- Lower values (0.001-0.01): Trust predictions more, smoother output
- Typical range: 0.001 to 1.0

**Measurement Noise (R):**
- Higher values (1.0+): Assume measurements are noisy, more smoothing
- Lower values (0.01-0.1): Trust measurements, less smoothing
- Typical range: 0.01 to 10.0

#### One Euro Filter Parameters

**Min Cutoff:**
- Higher values (1.0+): Less smoothing, faster response
- Lower values (0.1-): More smoothing, slower response
- Typical range: 0.001 to 10.0

**Beta (Speed Coefficient):**
- Higher values (0.01+): More speed adaptation
- Lower values (0.0001-): Less speed adaptation
- Typical range: 0.0001 to 1.0

**DCutoff (Derivative Cutoff):**
- Usually set to 1.0
- Higher values: Smoother derivative calculation
- Range: 0.1 to 10.0

---

## 📚 Preset Management

### Saving and Loading Presets

#### Save Preset to File
```blueprint
[Create Custom Preset] → Success
    ↓
[Save Preset to Config]
├─ Preset Name: "MyPreset"
├─ File Path: "Config/FilterPresets.ini"
└─ Section: "CustomPresets"
```

#### Load Preset from File
```blueprint
Event BeginPlay
    ↓
[Load Preset from Config]
├─ Preset Name: "MyPreset"
├─ File Path: "Config/FilterPresets.ini"
└─ Section: "CustomPresets"
    ↓
[Apply to Filter]
```

### Preset Validation

Validate preset parameters to prevent errors:

```blueprint
[Validate Custom Preset]
├─ Preset Name: Input String
├─ Check Parameters:
│   ├─ Q > 0 and Q < 10
│   ├─ R > 0 and R < 100
│   ├─ MinCutoff > 0 and MinCutoff < 100
│   └─ Beta >= 0 and Beta <= 1
└─ Result: Valid/Invalid + Error Message
```

### Preset Collections

Organize multiple presets:

```blueprint
// Create preset collection for VR
[Create Preset Collection]
├─ Collection Name: "VR_Presets"
├─ Presets:
│   ├─ "VR_Head": High smoothing, low latency
│   ├─ "VR_Controllers": Medium smoothing, very low latency
│   └─ "VR_Haptics": Low smoothing, instant response
└─ Save Collection
```

---

## 🎮 Use Case Examples

### Example 1: VR Motion Controllers

Perfect for hand tracking with minimal latency:

```blueprint
[Create Custom Preset]
├─ Name: "VR_Hands"
├─ Process Noise: 0.0    // Not used for OneEuro
├─ Measurement Noise: 0.0 // Not used for OneEuro
├─ Min Cutoff: 0.4       // Moderate smoothing
├─ Beta: 0.00001         // Minimal speed adaptation
└─ DCutoff: 1.0          // Standard derivative
```

**Why these values?**
- Low MinCutoff: Reduces jitter without noticeable lag
- Very low Beta: Prevents over-adaptation to hand tremors
- Standard DCutoff: Reliable derivative calculation

### Example 2: High-Precision Mouse Aiming

For competitive gaming applications:

```blueprint
[Create Custom Preset]
├─ Name: "Gaming_Mouse"
├─ Process Noise: 0.0    // OneEuro only
├─ Measurement Noise: 0.0
├─ Min Cutoff: 2.0       // Minimal smoothing
├─ Beta: 0.001           // Light speed adaptation
└─ DCutoff: 2.0          // Faster derivative
```

**Characteristics:**
- High MinCutoff: Preserves quick movements
- Low Beta: Doesn't over-smooth rapid aiming
- Higher DCutoff: Responsive to speed changes

### Example 3: Cinematic Camera Smoothing

For smooth, professional camera movements:

```blueprint
[Create Custom Preset]
├─ Name: "Cinematic_Cam"
├─ Process Noise: 0.001  // High trust in predictions
├─ Measurement Noise: 2.0 // Assume noisy input
├─ Min Cutoff: 0.05      // Maximum smoothing
├─ Beta: 0.02            // Strong speed adaptation
└─ DCutoff: 0.5          // Smooth derivatives
```

**Kalman-focused preset:**
- Very low Q: Prioritizes smooth predictions
- High R: Heavily filters input noise
- For cinematic quality over responsiveness

### Example 4: Mobile Touch Interface

Optimized for touch screens with varying precision:

```blueprint
[Create Custom Preset]
├─ Name: "Mobile_Touch"
├─ Process Noise: 0.08   // Moderate adaptation
├─ Measurement Noise: 0.3 // Some noise expected
├─ Min Cutoff: 0.8       // Balanced smoothing
├─ Beta: 0.005           // Moderate speed response
└─ DCutoff: 1.5          // Stable derivatives
```

**Mobile considerations:**
- Accounts for finger size and imprecision
- Balances smoothness with responsiveness
- Works well across different screen sizes

### Example 5: Sensor Data Processing

For noisy sensor data (accelerometers, gyroscopes):

```blueprint
[Create Custom Preset]
├─ Name: "Sensor_Stable"
├─ Process Noise: 0.01   // Trust model predictions
├─ Measurement Noise: 5.0 // Very noisy sensors
├─ Min Cutoff: 0.1       // Heavy smoothing
├─ Beta: 0.001           // Minimal speed adaptation
└─ DCutoff: 0.3          // Very smooth derivatives
```

**Sensor-specific tuning:**
- High R value accommodates sensor noise
- Low Beta prevents over-reaction to vibrations
- Strong smoothing for stable output

---

## 🚀 Advanced Techniques

### Dynamic Preset Switching

Switch presets based on game state:

```blueprint
// Context-aware filtering
Get Game State
├─ Branch (Is in Combat?)
│   ├─ True: Apply "Combat_Responsive"
│   │   └─ Low latency, minimal smoothing
│   └─ False: Branch (Is in Menu?)
│       ├─ True: Apply "Menu_Smooth"
│       │   └─ High smoothing, visual priority
│       └─ False: Apply "Exploration_Balanced"
│           └─ Balanced settings
```

### Preset Interpolation

Smoothly transition between presets:

```blueprint
[Interpolate Between Presets]
├─ Preset A: "Current_Settings"
├─ Preset B: "Target_Settings"
├─ Alpha: 0.0-1.0 (transition progress)
└─ Output: Interpolated preset
    ↓
[Apply Interpolated Preset] to filter
```

### A/B Testing Presets

Compare different presets:

```blueprint
// Testing framework
[Create Test Session]
├─ Preset A: "Conservative"
├─ Preset B: "Aggressive"
├─ Switch every: 30 seconds
└─ Log user preference
    ↓
[Analyze Results] → Choose optimal preset
```

### Hardware-Specific Presets

Detect hardware and apply appropriate presets:

```blueprint
[Detect Hardware]
├─ Get Platform
├─ Get Input Device Type
└─ Get Performance Level
    ↓
[Select Preset]
├─ VR + High Performance: "VR_Premium"
├─ Mobile + Low Performance: "Mobile_Efficient"
├─ Desktop + Gaming: "Desktop_Responsive"
└─ Default: "Universal_Balanced"
```

---

## 🔧 Preset Optimization

### Performance Considerations

Some parameter combinations are more efficient:

**Fast Presets** (lower CPU usage):
- Higher MinCutoff values
- Lower Beta values
- Standard DCutoff (1.0)

**Quality Presets** (higher CPU usage):
- Lower MinCutoff values
- Higher Beta values
- Custom DCutoff values

### Memory Management

Custom presets use additional memory:

```blueprint
// Monitor preset memory usage
[Get Preset Memory Usage]
├─ Total Presets: Count
├─ Memory per Preset: ~50 bytes
└─ Total Memory: Count × 50 bytes
```

**Optimization tips:**
- Limit to 10-20 custom presets
- Clear unused presets with `Clear Custom Presets`
- Reuse presets across similar use cases

---

## 🔍 Troubleshooting Presets

### Common Issues

#### Preset Not Applied
**Problem:** Custom preset doesn't seem to work

**Solutions:**
1. Verify preset name matches exactly
2. Check if preset was created successfully
3. Ensure parameters are within valid ranges
4. Try recreating the preset

#### Parameters Don't Feel Right
**Problem:** Custom preset behavior is unexpected

**Debug approach:**
```blueprint
[Get Current Filter Parameters]
├─ Show actual Q, R values (Kalman)
├─ Show MinCutoff, Beta values (OneEuro)
└─ Compare with intended preset values
```

#### Performance Issues
**Problem:** Custom preset causes performance problems

**Solutions:**
1. Check if parameters are too extreme
2. Reduce Beta values for OneEuro
3. Increase MinCutoff for less processing
4. Profile with `Start Filter Profiling`

### Validation Tools

#### Parameter Range Checker
```blueprint
[Validate Preset Parameters]
├─ Input: Custom Preset
├─ Check: All parameters in valid ranges
├─ Warning: Parameters at extremes
└─ Output: Validation report
```

#### Preset Comparison Tool
```blueprint
[Compare Presets]
├─ Preset A: "Built-in Medium"
├─ Preset B: "Custom Settings"
├─ Test Input: Noisy sine wave
└─ Output: Side-by-side comparison
```

---

## 📊 Preset Library

### Community Presets

Tested presets from the community:

#### Gaming Presets
```cpp
// FPS Mouse Aiming
"FPS_Pro": MinCutoff=3.0, Beta=0.0008, DCutoff=2.5

// Racing Game Steering
"Racing_Wheel": Q=0.15, R=0.05

// RTS Camera
"Strategy_Cam": Q=0.005, R=1.5
```

#### VR/AR Presets
```cpp
// Hand Tracking
"VR_Hands_Stable": MinCutoff=0.3, Beta=0.00005, DCutoff=1.0

// Head Tracking
"VR_Head_Comfort": MinCutoff=0.6, Beta=0.0001, DCutoff=1.2

// Gaze Tracking
"AR_Gaze": MinCutoff=1.2, Beta=0.0003, DCutoff=1.5
```

#### Creative Applications
```cpp
// Digital Art
"Drawing_Smooth": MinCutoff=0.4, Beta=0.002, DCutoff=0.8

// 3D Modeling
"Modeling_Precise": Q=0.08, R=0.15

// Animation
"Keyframe_Smooth": Q=0.002, R=3.0
```

### Preset Templates

Starting points for common scenarios:

```blueprint
// Template: High Responsiveness
Process Noise: 0.1-0.5
Measurement Noise: 0.01-0.1
MinCutoff: 1.0-5.0
Beta: 0.0001-0.001

// Template: Maximum Smoothing
Process Noise: 0.001-0.01
Measurement Noise: 1.0-10.0
MinCutoff: 0.01-0.2
Beta: 0.005-0.02

// Template: Balanced Performance
Process Noise: 0.01-0.1
Measurement Noise: 0.1-1.0
MinCutoff: 0.2-1.0
Beta: 0.001-0.01
```

---

## 📝 Best Practices Summary

### Do's ✅
1. **Test thoroughly**: Always test custom presets with real data
2. **Document presets**: Keep notes on why you chose specific values
3. **Start conservative**: Begin with moderate values and adjust
4. **Use meaningful names**: "VR_Controllers" not "Preset1"
5. **Validate parameters**: Check ranges before applying

### Don'ts ❌
1. **Don't use extreme values**: Can cause instability
2. **Don't over-optimize**: Small differences often don't matter
3. **Don't forget context**: Same preset may not work everywhere
4. **Don't skip testing**: Always verify with actual use cases
5. **Don't ignore performance**: Monitor CPU/memory impact

---

## 🎯 Quick Reference

### Parameter Quick Guide

| Want More... | Kalman | OneEuro |
|--------------|--------|---------|
| **Responsiveness** | ↑ Q, ↓ R | ↑ MinCutoff, ↓ Beta |
| **Smoothness** | ↓ Q, ↑ R | ↓ MinCutoff, ↑ Beta |
| **Speed Adaptation** | Adjust Q/R ratio | ↑ Beta |
| **Stability** | Balance Q/R | ↓ Beta, tune MinCutoff |

### Common Preset Formulas

```cpp
// Gaming (fast response)
Q = 0.1, R = 0.01
MinCutoff = 2.0, Beta = 0.0005

// UI (smooth visuals)  
Q = 0.005, R = 1.0
MinCutoff = 0.1, Beta = 0.01

// VR (comfort first)
MinCutoff = 0.4, Beta = 0.00001

// Mobile (balanced)
Q = 0.05, R = 0.2
MinCutoff = 0.8, Beta = 0.003
```

---

Happy Preset Crafting! 🎨

For combining multiple filters, see [Filter Chaining](FilterChaining.md) →