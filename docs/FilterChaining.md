# Filter Chaining

*Read this in other languages: [English](FilterChaining.md), [한국어](FilterChaining_KR.md)*

Advanced guide to combining multiple filters for sophisticated signal processing

## 📍 Navigation

- [← Back: Custom Presets](CustomPresets.md)
- [→ Next: Migration Guide](Migration.md)

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
  - [Custom Presets](CustomPresets.md)
  - **Filter Chaining** (You are here)
  - [Migration Guide](Migration.md)

---

## 📋 Table of Contents

1. [What is Filter Chaining?](#what-is-filter-chaining)
2. [Chain Types](#chain-types)
3. [Creating Filter Chains](#creating-filter-chains)
4. [Advanced Chaining Techniques](#advanced-chaining-techniques)
5. [Performance Considerations](#performance-considerations)
6. [Real-World Applications](#real-world-applications)

---

## 🔗 What is Filter Chaining?

Filter chaining is the process of connecting multiple filters in sequence or parallel to achieve more sophisticated filtering results than any single filter could provide alone.

### Why Chain Filters?

**Single Filter Limitations:**
- Kalman: Great prediction, but can lag behind fast changes
- One Euro: Low latency, but limited noise reduction
- Both: Fixed characteristics for all scenarios

**Chaining Benefits:**
- ✅ Combine strengths of different filter types
- ✅ Compensate for individual filter weaknesses  
- ✅ Create adaptive filtering systems
- ✅ Handle complex signal characteristics
- ✅ Achieve optimal balance for specific use cases

### Basic Concept

```
Raw Signal → Filter 1 → Filter 2 → Filter 3 → Final Output
```

Each filter processes the output of the previous filter, allowing for multi-stage refinement.

---

## 🔧 Chain Types

### 1. Sequential Chains

Filters process data one after another in a linear sequence.

```blueprint
[Raw Input] → [Kalman (High)] → [OneEuro (Low)] → [Final Output]
```

**Use Cases:**
- Noise reduction followed by responsiveness tuning
- Coarse filtering then fine adjustment
- Multi-stage signal conditioning

### 2. Parallel Chains

Multiple filters process the same input simultaneously, then results are combined.

```blueprint
[Raw Input] ─┬─ [Kalman Filter] ─┐
              │                   ├─ [Blend] → [Output]
              └─ [OneEuro Filter] ─┘
```

**Use Cases:**
- Comparing different filtering approaches
- Weighted combination of filter strengths
- Fallback systems

### 3. Hierarchical Chains

Complex nested structures with multiple levels and branches.

```blueprint
[Raw Input] → [Pre-Filter] ─┬─ [Path A: Responsive] ─┐
                             │                        ├─ [Selector] → [Output]
                             └─ [Path B: Smooth] ──────┘
```

**Use Cases:**
- Context-aware filtering
- Adaptive systems
- Complex signal processing pipelines

### 4. Feedback Chains

Filters can influence earlier stages in the chain based on output characteristics.

```blueprint
[Input] → [Filter 1] → [Filter 2] → [Output]
            ↑                         │
            └─── [Feedback Logic] ←────┘
```

**Use Cases:**
- Self-tuning systems
- Adaptive parameter adjustment
- Error correction loops

---

## 🛠️ Creating Filter Chains

### Method 1: Manual Chain Construction

Build chains step by step using individual filters.

#### Sequential Chain Example
```blueprint
Event BeginPlay
├─ [Create Filter] (Type: Kalman) → Store as "Stage1"
├─ [Initialize Filter] (Stage1, Preset: High)
├─ [Create Filter] (Type: OneEuro) → Store as "Stage2"
└─ [Initialize Filter] (Stage2, Preset: Low)

Event Tick
├─ [Update Filter] (Stage1, Raw Input) → Intermediate
└─ [Update Filter] (Stage2, Intermediate) → Final Output
```

#### Parallel Chain Example
```blueprint
Event BeginPlay
├─ [Create Filter] (Type: Kalman) → Store as "PathA"
├─ [Create Filter] (Type: OneEuro) → Store as "PathB"
├─ [Initialize Filter] (PathA, Preset: Medium)
└─ [Initialize Filter] (PathB, Preset: Medium)

Event Tick
├─ [Update Filter] (PathA, Raw Input) → ResultA
├─ [Update Filter] (PathB, Raw Input) → ResultB
└─ [Lerp] (ResultA, ResultB, Alpha: 0.6) → Blended Output
```

### Method 2: Chain System Nodes

Use the built-in chain system for easier management.

#### Basic Chain Creation
```blueprint
Event BeginPlay
├─ [Create Filter Chain]
│  ├─ Chain Name: "SmoothResponsive"
│  ├─ Filters: [Kalman, OneEuro]
│  ├─ Presets: [High, Low]
│  └─ Blend Weights: [0.7, 0.3]
└─ Store Chain Reference

Event Tick
├─ [Process Through Chain]
│  ├─ Chain: Stored Reference
│  ├─ Input: Raw Signal
│  └─ Delta Time: Event Delta
└─ Get Final Output
```

#### Advanced Chain Configuration
```blueprint
[Create Advanced Chain]
├─ Chain Type: Hierarchical
├─ Stages:
│  ├─ Stage 1: Pre-processing
│  │  ├─ Filter: OneEuro (Very Low)
│  │  └─ Purpose: Remove high-frequency noise
│  ├─ Stage 2: Main Processing  
│  │  ├─ Path A: Kalman (High) - For smooth camera
│  │  ├─ Path B: OneEuro (Medium) - For responsive UI
│  │  └─ Selector: Based on input speed
│  └─ Stage 3: Post-processing
│     ├─ Filter: Custom preset
│     └─ Purpose: Final refinement
└─ Chain built and ready
```

---

## 🚀 Advanced Chaining Techniques

### 1. Adaptive Chain Selection

Dynamically choose which chain to use based on signal characteristics.

```blueprint
[Analyze Input Signal]
├─ Speed: Calculate velocity magnitude
├─ Noise Level: Measure signal variance
└─ Pattern: Detect periodic vs random

[Select Chain]
├─ IF Speed > Threshold AND Noise < Threshold
│  └─ Use "Responsive" chain (OneEuro + Light Kalman)
├─ ELSE IF Speed < Threshold AND Noise > Threshold  
│  └─ Use "Smooth" chain (Heavy Kalman + OneEuro)
└─ ELSE
   └─ Use "Balanced" chain (Medium settings)
```

### 2. Chain Morphing

Smoothly transition between different chain configurations.

```blueprint
[Chain Morphing System]
├─ Current Chain: "Configuration A"
├─ Target Chain: "Configuration B" 
├─ Morph Progress: 0.0 to 1.0
└─ Interpolated Chain: Blend of A and B

Event Tick
├─ Update Morph Progress (+Delta * MorphSpeed)
├─ [Interpolate Chain Parameters]
│  ├─ FilterA Weight: Lerp(WeightA1, WeightA2, Progress)
│  ├─ FilterB Weight: Lerp(WeightB1, WeightB2, Progress)
│  └─ Apply interpolated weights
└─ Process signal through morphed chain
```

### 3. Multi-Resolution Chains

Different filters handle different frequency components.

```blueprint
[Multi-Resolution Processing]
├─ Input Signal
├─ High-Freq Path: OneEuro (Very Low preset)
│  └─ Handles rapid changes
├─ Mid-Freq Path: OneEuro (Medium preset)  
│  └─ Handles normal movement
├─ Low-Freq Path: Kalman (High preset)
│  └─ Handles slow trends
└─ [Combine Frequencies] → Final Output
```

### 4. Predictive Chains

Use filter predictions to influence other filters.

```blueprint
[Predictive Chain System]
├─ [Kalman Filter] → Current Estimate + Prediction
├─ [Prediction Analyzer]
│  ├─ IF Prediction differs significantly from measurement
│  │  └─ Increase OneEuro responsiveness
│  └─ ELSE  
│     └─ Maintain normal OneEuro settings
└─ [OneEuro Filter] (with adaptive settings) → Final Output
```

### 5. Error-Correcting Chains

Chains that detect and correct their own errors.

```blueprint
[Error-Correcting Chain]
├─ [Primary Filter] → Primary Output
├─ [Secondary Filter] → Secondary Output  
├─ [Error Detection]
│  ├─ Compare Primary vs Secondary
│  ├─ Compare Output vs Raw Input
│  └─ Detect anomalies or divergence
├─ [Error Correction]
│  ├─ IF Error detected
│  │  ├─ Temporarily increase responsiveness
│  │  ├─ Reset filter states if needed
│  │  └─ Use secondary filter as primary
│  └─ ELSE maintain normal operation
└─ [Corrected Output]
```

---

## ⚡ Performance Considerations

### Chain Overhead

Each filter in a chain adds computational cost:

| Chain Length | CPU Impact | Memory Impact | Latency Impact |
|--------------|------------|---------------|----------------|
| 1 Filter | 1x | 1x | 1x |
| 2 Filters | 1.8x | 2x | 1.2x |
| 3 Filters | 2.5x | 3x | 1.5x |
| 4+ Filters | 3x+ | 4x+ | 2x+ |

### Optimization Strategies

#### 1. Conditional Processing
```blueprint
// Skip expensive filters when not needed
[Signal Analysis]
├─ IF Signal is stable (low variance)
│  └─ Skip expensive smoothing filters
├─ ELSE IF Signal is very noisy  
│  └─ Enable all noise reduction stages
└─ ELSE use standard chain
```

#### 2. Frame Rate Scaling
```blueprint
// Adjust chain complexity based on performance
[Performance Monitor]
├─ IF Frame Rate > 60 FPS
│  └─ Enable full chain (all filters)
├─ ELSE IF Frame Rate > 30 FPS
│  └─ Enable reduced chain (2 filters)  
└─ ELSE enable minimal chain (1 filter)
```

#### 3. LOD-Based Chains
```blueprint
// Distance-based chain complexity
[Distance-Based Chains]
├─ Distance < 10m: Full 4-stage chain
├─ Distance < 50m: 2-stage chain
├─ Distance < 100m: Single filter
└─ Distance > 100m: No filtering
```

#### 4. Batch Chain Processing
```blueprint
// Process multiple signals through same chain
[Batch Chain Processing]
├─ Input: Array of signals
├─ Process all through Stage 1
├─ Process all through Stage 2
├─ Process all through Stage 3
└─ Output: Array of filtered results
```

---

## 🎮 Real-World Applications

### Application 1: Professional Camera System

Multi-stage camera stabilization for film production.

```blueprint
[Professional Camera Chain]
├─ Stage 1: Jitter Removal
│  ├─ Filter: OneEuro (Very Low preset)
│  └─ Purpose: Remove high-frequency camera shake
├─ Stage 2: Motion Smoothing  
│  ├─ Filter: Kalman (Custom: Q=0.001, R=0.5)
│  └─ Purpose: Smooth camera movements
├─ Stage 3: Drift Correction
│  ├─ Filter: OneEuro (Custom: Very low Beta)
│  └─ Purpose: Prevent slow drift
└─ Stage 4: Final Polish
   ├─ Filter: Light Kalman (Q=0.01, R=0.1)
   └─ Purpose: Minor refinements
```

**Results:**
- 98% noise reduction
- Cinema-quality smoothness
- 2-3 frame latency (acceptable for recording)

### Application 2: VR Hand Tracking System

Adaptive hand tracking that balances comfort and precision.

```blueprint
[VR Hand Tracking Chain]
├─ Branch by Activity
│  ├─ Fine Motor (drawing, typing):
│  │  ├─ Stage 1: OneEuro (Ultra Low preset)
│  │  └─ Stage 2: Light Kalman for stability
│  └─ Gross Motor (gestures, pointing):
│     ├─ Stage 1: OneEuro (Low preset)  
│     └─ Stage 2: Medium Kalman for smoothness
├─ Comfort Layer:
│  ├─ Monitor motion sickness indicators
│  ├─ IF user shows discomfort
│  │  └─ Reduce filtering, increase responsiveness
│  └─ ELSE maintain quality filtering
└─ Final Output: Balanced comfort + precision
```

### Application 3: Mobile Game Input System

Touch input processing for different game genres.

```blueprint
[Mobile Game Input Chain]
├─ Genre Detection:
│  ├─ Racing Game:
│  │  ├─ OneEuro (Low) for steering
│  │  └─ No Kalman (latency critical)
│  ├─ Strategy Game:
│  │  ├─ Kalman (High) for smooth camera
│  │  └─ OneEuro (Medium) for unit selection
│  └─ Puzzle Game:
│     ├─ Kalman (High) for smooth interactions
│     └─ OneEuro (High) for precise placement
├─ Device Adaptation:
│  ├─ High-end device: Full chain
│  ├─ Mid-range device: Reduced chain
│  └─ Low-end device: Single filter
└─ Battery Optimization:
   ├─ IF Battery < 20%
   │  └─ Reduce chain complexity
   └─ ELSE maintain quality
```

### Application 4: Industrial Sensor Processing

Multi-sensor data fusion with error detection.

```blueprint
[Industrial Sensor Chain]
├─ Sensor Validation:
│  ├─ Check sensor health
│  ├─ Detect faulty readings
│  └─ Flag unreliable sensors
├─ Multi-Sensor Fusion:
│  ├─ Primary Sensor: Heavy Kalman filtering
│  ├─ Secondary Sensor: Medium filtering
│  ├─ Tertiary Sensor: Light filtering
│  └─ Weighted combination based on reliability
├─ Anomaly Detection:
│  ├─ Compare fused result with individual sensors
│  ├─ IF Anomaly detected
│  │  ├─ Increase filtering on unreliable sensors
│  │  └─ Alert maintenance system
│  └─ ELSE continue normal operation
└─ Safety Limits:
   ├─ Ensure output stays within safe ranges
   └─ Emergency shutoff if limits exceeded
```

### Application 5: Audio-Visual Synchronization

Synchronize visual effects with audio in real-time.

```blueprint
[Audio-Visual Sync Chain]
├─ Audio Analysis:
│  ├─ Beat Detection: OneEuro (Ultra Low)
│  ├─ Frequency Analysis: Kalman (Medium)
│  └─ Volume Envelope: OneEuro (Low)
├─ Visual Response:
│  ├─ Fast Effects (lights): Direct from OneEuro
│  ├─ Medium Effects (particles): From balanced chain
│  └─ Slow Effects (camera): From Kalman chain
├─ Synchronization:
│  ├─ Compensate for processing latency
│  ├─ Predict audio changes
│  └─ Adjust visual timing accordingly
└─ Final Output: Synchronized audio-visual experience
```

---

## 🔧 Chain Debugging and Monitoring

### Real-Time Chain Visualization

Monitor chain performance and behavior:

```blueprint
[Chain Debug System]
├─ [Visualize Chain Flow]
│  ├─ Show input signal (red)
│  ├─ Show intermediate stages (yellow)
│  └─ Show final output (green)
├─ [Monitor Performance]
│  ├─ CPU usage per stage
│  ├─ Memory allocation
│  └─ Processing latency
└─ [Quality Metrics]
   ├─ Noise reduction percentage
   ├─ Signal delay measurement
   └─ Stability metrics
```

### Chain Optimization Tools

```blueprint
[Chain Optimizer]
├─ [Analyze Signal Characteristics]
│  ├─ Frequency content
│  ├─ Noise patterns
│  └─ Motion patterns
├─ [Suggest Optimal Chain]
│  ├─ Recommend filter types
│  ├─ Suggest presets
│  └─ Propose chain structure
└─ [A/B Test Chains]
   ├─ Compare different configurations
   ├─ Measure objective quality metrics
   └─ User preference testing
```

---

## 📚 Chain Design Patterns

### Pattern 1: Noise Reduction → Responsiveness
```blueprint
// Clean the signal, then make it responsive
[High Noise Input] → [Heavy Kalman] → [Light OneEuro] → [Clean & Responsive]
```

### Pattern 2: Responsiveness → Stability  
```blueprint
// Quick response, then stabilize
[Jittery Input] → [OneEuro Low] → [Kalman Medium] → [Responsive & Stable]
```

### Pattern 3: Parallel Processing → Selection
```blueprint
// Multiple approaches, pick the best
[Input] ─┬─ [Smooth Path] ──┐
         ├─ [Fast Path] ────┼─ [Selector] → [Output]
         └─ [Balanced Path] ─┘
```

### Pattern 4: Cascade Refinement
```blueprint
// Progressive refinement
[Raw] → [Coarse Filter] → [Medium Filter] → [Fine Filter] → [Polished]
```

### Pattern 5: Feedback Control
```blueprint
// Self-adjusting system
[Input] → [Adaptive Filter] → [Output]
            ↑                    │
            └─ [Feedback] ←──────┘
```

---

## 📝 Best Practices

### Do's ✅
1. **Start Simple**: Begin with 2-filter chains before going complex
2. **Monitor Performance**: Always profile chain performance
3. **Use Appropriate Types**: Match filter types to their strengths
4. **Test Thoroughly**: Validate chains with real-world data
5. **Document Chains**: Explain why each filter is needed

### Don'ts ❌
1. **Don't Over-Chain**: More filters ≠ better results
2. **Don't Ignore Latency**: Each stage adds delay
3. **Don't Forget Context**: Chains should match use case
4. **Don't Skip Optimization**: Unused chains waste resources
5. **Don't Chain Randomly**: Each filter should have a purpose

---

## 🎯 Quick Reference

### Common Chain Patterns

| Use Case | Pattern | Filters |
|----------|---------|---------|
| **Gaming Input** | Fast→Polish | OneEuro Low → Kalman Low |
| **Camera Smooth** | Clean→Stabilize | Kalman High → OneEuro Medium |  
| **VR Comfort** | Balance | OneEuro Low + Kalman Medium (blended) |
| **Sensor Fusion** | Validate→Filter | Multiple Kalman → Weighted Average |
| **Audio Sync** | Multi-Rate | OneEuro Ultra + Kalman Medium (parallel) |

### Performance Guidelines

- **2 Filters**: Ideal for most use cases
- **3 Filters**: Use for complex scenarios
- **4+ Filters**: Only for specialized applications
- **Parallel Chains**: 2-3 branches maximum
- **Update Rate**: Consider reducing for distant objects

---

Ready to create sophisticated filtering systems! 🔗

For version migration guidance, see [Migration Guide](Migration.md) →