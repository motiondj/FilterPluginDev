# API Reference

*Read this in other languages: [English](APIReference.md), [한국어](APIReference_KR.md)*

Complete technical reference for all nodes and functions in Advanced Filters Plugin

## 📍 Navigation

- [← Back: User Manual](UserManual.md)
- [→ Next: Blueprint Examples](Examples.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - [Installation Guide](Installation.md)
- **User Guides**
  - [User Manual](UserManual.md)
  - [Blueprint Examples](Examples.md)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - **API Reference** (You are here)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 📋 Table of Contents

1. [Core Nodes](#core-nodes)
2. [One-Click Macros](#one-click-macros)
3. [Advanced Nodes](#advanced-nodes)
4. [Utility Nodes](#utility-nodes)
5. [Data Types](#data-types)
6. [Enumerations](#enumerations)

---

## 🔧 Core Nodes

### Create Filter

Creates a new filter instance of specified type.

```
Create Filter
├─ Input
│  └─ Filter Type (EFilterType): Kalman or OneEuro
└─ Output
   └─ Filter Object (UBaseFilterObject*): Created filter instance
```

**Usage Example:**
```blueprint
[Create Filter (Kalman)] → [Variable: MyFilter]
```

**Notes:**
- Creates uninitialized filter
- Must call Initialize before use
- Memory managed automatically

---

### Initialize Filter

Initializes a filter with specified preset.

```
Initialize Filter
├─ Input
│  ├─ Target (UBaseFilterObject*): Filter to initialize
│  └─ Preset (EFilterPreset): Low, Medium, or High
└─ Output
   └─ Success (bool): True if initialized successfully
```

**Preset Values:**

| Preset | Kalman Q | Kalman R | OneEuro MinCutoff | OneEuro Beta |
|--------|----------|----------|-------------------|--------------|
| Low | 0.1 | 0.01 | 1.0 | 0.001 |
| Medium | 0.01 | 0.1 | 0.5 | 0.007 |
| High | 0.001 | 1.0 | 0.1 | 0.01 |

---

### Update Filter Float

Updates filter with new float value and returns filtered result.

```
Update Filter Float
├─ Input
│  ├─ Target (UBaseFilterObject*): Filter instance
│  └─ Raw Value (float): New measurement
└─ Output
   └─ Filtered Value (float): Filtered result
```

**Algorithm:**
- Kalman: Predict → Update → Return estimate
- OneEuro: Low-pass with adaptive cutoff

---

### Update Filter Vector

Updates filter with new vector value and returns filtered result.

```
Update Filter Vector
├─ Input
│  ├─ Target (UBaseFilterObject*): Filter instance
│  └─ Raw Value (FVector): New measurement
└─ Output
   └─ Filtered Value (FVector): Filtered result
```

**Notes:**
- Filters X, Y, Z independently
- Maintains separate state for each axis

---

## 🎯 One-Click Macros

### Kalman Filter Value

One-click Kalman filtering for float values.

```
Kalman Filter Value
├─ Input
│  ├─ Raw Value (float): Value to filter
│  ├─ Preset (EFilterPreset): Filter strength
│  └─ Filter ID (FString): Unique identifier
└─ Output
   └─ Return Value (float): Filtered result
```

**Features:**
- Automatically creates/reuses filter based on ID
- No initialization needed
- Thread-safe instance management

---

### Kalman Filter Vector

One-click Kalman filtering for vector values.

```
Kalman Filter Vector
├─ Input
│  ├─ Raw Value (FVector): Vector to filter
│  ├─ Preset (EFilterPreset): Filter strength
│  └─ Filter ID (FString): Unique identifier
└─ Output
   └─ Return Value (FVector): Filtered result
```

---

### One Euro Filter Value

One-click One Euro filtering for float values.

```
One Euro Filter Value
├─ Input
│  ├─ Raw Value (float): Value to filter
│  ├─ Delta Time (float): Time since last update
│  ├─ Preset (EFilterPreset): Filter strength
│  └─ Filter ID (FString): Unique identifier
└─ Output
   └─ Return Value (float): Filtered result
```

**Important:**
- Delta Time is required
- Use Event Tick's Delta Seconds
- Adaptive to signal speed

---

### One Euro Filter Vector

One-click One Euro filtering for vector values.

```
One Euro Filter Vector
├─ Input
│  ├─ Raw Value (FVector): Vector to filter
│  ├─ Delta Time (float): Time since last update
│  ├─ Preset (EFilterPreset): Filter strength
│  └─ Filter ID (FString): Unique identifier
└─ Output
   └─ Return Value (FVector): Filtered result
```

---

## 🚀 Advanced Nodes

### Set Process Noise (Kalman)

Adjusts Kalman filter process noise (Q parameter).

```
Set Process Noise
├─ Input
│  ├─ Target (UKalmanFilter*): Kalman filter instance
│  └─ Process Noise (float): Q value (0.0001 - 1.0)
└─ Output
   └─ Success (bool): True if set successfully
```

**Effects:**
- Higher Q = Trusts measurements more
- Lower Q = Trusts predictions more

---

### Set Measurement Noise (Kalman)

Adjusts Kalman filter measurement noise (R parameter).

```
Set Measurement Noise
├─ Input
│  ├─ Target (UKalmanFilter*): Kalman filter instance
│  └─ Measurement Noise (float): R value (0.001 - 10.0)
└─ Output
   └─ Success (bool): True if set successfully
```

---

### Set Min Cutoff (One Euro)

Adjusts One Euro filter minimum cutoff frequency.

```
Set Min Cutoff
├─ Input
│  ├─ Target (UOneEuroFilter*): One Euro filter instance
│  └─ Min Cutoff (float): Frequency in Hz (0.001 - 10.0)
└─ Output
   └─ Success (bool): True if set successfully
```

**Effects:**
- Lower = More smoothing
- Higher = Less smoothing

---

### Set Beta (One Euro)

Adjusts One Euro filter speed coefficient.

```
Set Beta
├─ Input
│  ├─ Target (UOneEuroFilter*): One Euro filter instance
│  └─ Beta (float): Speed coefficient (0.0 - 1.0)
└─ Output
   └─ Success (bool): True if set successfully
```

**Effects:**
- Lower = More stable
- Higher = More responsive to speed

---

### Create Custom Preset

Creates a custom filter preset with specific parameters.

```
Create Custom Preset
├─ Input
│  ├─ Preset Name (FString): Unique name
│  ├─ Process Noise (float): Kalman Q
│  ├─ Measurement Noise (float): Kalman R
│  ├─ Min Cutoff (float): OneEuro frequency
│  ├─ Beta (float): OneEuro speed coefficient
│  └─ DCutoff (float): OneEuro derivative cutoff
└─ Output
   └─ Success (bool): True if created
```

---

### Apply Custom Preset

Applies a previously created custom preset to a filter.

```
Apply Custom Preset
├─ Input
│  ├─ Target (UBaseFilterObject*): Filter instance
│  └─ Preset Name (FString): Name of custom preset
└─ Output
   └─ Success (bool): True if applied
```

---

### Create Filter Chain

Creates a chain of multiple filters for sequential processing.

```
Create Filter Chain
├─ Input
│  ├─ Filter Types (TArray<EFilterType>): List of filter types
│  └─ Presets (TArray<EFilterPreset>): List of presets
└─ Output
   └─ Filter Chain (UFilterChain*): Chain instance
```

---

### Process Through Chain

Processes a value through multiple filters in sequence.

```
Process Through Chain
├─ Input
│  ├─ Target (UFilterChain*): Chain instance
│  ├─ Raw Value (float): Input value
│  └─ Delta Time (float): Time delta
└─ Output
   └─ Filtered Value (float): Final result
```

---

## 🛠️ Utility Nodes

### Reset Filter

Resets filter to initial state.

```
Reset Filter
├─ Input
│  └─ Target (UBaseFilterObject*): Filter to reset
└─ Output
   └─ Success (bool): True if reset
```

---

### Get Current Value

Gets the current filtered value without updating.

```
Get Current Value
├─ Input
│  └─ Target (UBaseFilterObject*): Filter instance
└─ Output
   └─ Current Value (float): Last filtered value
```

---

### Is Filter Initialized

Checks if filter has been initialized.

```
Is Filter Initialized
├─ Input
│  └─ Target (UBaseFilterObject*): Filter to check
└─ Output
   └─ Is Initialized (bool): True if ready
```

---

### Get Kalman Gain

Gets current Kalman gain value (diagnostic).

```
Get Kalman Gain
├─ Input
│  └─ Target (UKalmanFilter*): Kalman filter
└─ Output
   └─ Kalman Gain (float): Current gain (0-1)
```

**Interpretation:**
- Near 0 = Trusting prediction
- Near 1 = Trusting measurement

---

### Get Error Covariance

Gets current error covariance (uncertainty).

```
Get Error Covariance
├─ Input
│  └─ Target (UKalmanFilter*): Kalman filter
└─ Output
   └─ Error Covariance (float): Current uncertainty
```

---

### Clear All Filters

Removes all cached filter instances.

```
Clear All Filters
└─ Output
   └─ Cleared Count (int32): Number of filters removed
```

**Use Cases:**
- Level transitions
- Memory cleanup
- Testing

---

### Get Filter Memory Usage

Reports total memory used by all filters.

```
Get Filter Memory Usage
└─ Output
   ├─ Filter Count (int32): Number of active filters
   └─ Memory Bytes (int32): Total memory usage
```

---

### Start Filter Profiling

Begins performance profiling for a filter.

```
Start Filter Profiling
├─ Input
│  └─ Target (UBaseFilterObject*): Filter to profile
└─ Output
   └─ Success (bool): True if started
```

---

### Stop Filter Profiling

Stops profiling and returns performance data.

```
Stop Filter Profiling
├─ Input
│  └─ Target (UBaseFilterObject*): Filter being profiled
└─ Output
   ├─ Average Time MS (float): Average update time
   ├─ Peak Time MS (float): Maximum update time
   └─ Update Count (int32): Total updates
```

---

## 📊 Data Types

### UBaseFilterObject

Base class for all filter types.

**Properties:**
- `bIsInitialized`: Whether filter is ready for use
- `CurrentValue`: Last filtered value
- `UpdateCount`: Total number of updates

**Blueprint Accessible:** Read-only

---

### UKalmanFilter

Kalman filter implementation.

**Additional Properties:**
- `StateEstimate`: Current state estimate
- `ErrorCovariance`: Current uncertainty
- `ProcessNoise`: Q parameter
- `MeasurementNoise`: R parameter
- `KalmanGain`: Current gain

**Blueprint Accessible:** Read-only

---

### UOneEuroFilter

One Euro filter implementation.

**Additional Properties:**
- `MinCutoff`: Minimum cutoff frequency
- `Beta`: Speed coefficient  
- `DCutoff`: Derivative cutoff
- `LastTime`: Last update timestamp

**Blueprint Accessible:** Read-only

---

## 🔤 Enumerations

### EFilterType

Specifies the type of filter to create.

```cpp
enum class EFilterType : uint8
{
    Kalman      UMETA(DisplayName = "Kalman Filter"),
    OneEuro     UMETA(DisplayName = "One Euro Filter")
};
```

---

### EFilterPreset

Predefined filter configurations.

```cpp
enum class EFilterPreset : uint8
{
    Low         UMETA(DisplayName = "Low (Fast Response)"),
    Medium      UMETA(DisplayName = "Medium (Balanced)"),
    High        UMETA(DisplayName = "High (Maximum Smoothing)")
};
```

---

## 💡 Performance Notes

### Computational Complexity

| Operation | Kalman | One Euro |
|-----------|--------|----------|
| Update (Float) | O(1) | O(1) |
| Update (Vector) | O(3) | O(3) |
| Memory per Instance | ~100 bytes | ~150 bytes |

### Threading

- All nodes are thread-safe
- Filter instances can be shared between threads
- One-click macros use internal locking

### Best Practices

1. **Reuse Filter IDs** - Avoids creating duplicate instances
2. **Batch Updates** - Process multiple values in one frame
3. **Profile Performance** - Use profiling nodes in development
4. **Clear Unused Filters** - Free memory when changing levels

---

## 📝 Example Code

### Basic Kalman Filtering
```blueprint
// Begin Play
Create Filter (Kalman) → Initialize (Medium) → Set Variable (MyFilter)

// Event Tick  
Get Variable (MyFilter) → Update Filter Float (Sensor Value) → Set Actor Location
```

### Advanced One Euro with Custom Preset
```blueprint
// Begin Play
Create Custom Preset ("VR_Hand", 0.0, 0.0, 0.3, 0.0001, 1.0)
Create Filter (OneEuro) → Apply Custom Preset ("VR_Hand") → Set Variable

// Event Tick
Get Variable → Update Filter Vector (Controller Position, Delta Time) → Set Hand Mesh Location
```

---

For practical examples, see [Blueprint Examples](Examples.md) →