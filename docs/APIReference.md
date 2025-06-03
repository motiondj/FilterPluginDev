# API Reference (Improved)

*Read this in other languages: [English](APIReference.md), [한국어](APIReference_KR.md)*

Complete technical reference for all nodes and functions in Advanced Filters Plugin

## 📍 Navigation

- [← Back: User Manual](UserManual.md)
- [→ Next: Blueprint Examples](Examples.md)

---

## 🗂️ Node Category Guide

When looking for nodes in Blueprint, check these categories:

| Category | Included Nodes | Purpose |
|----------|----------------|---------|
| **Advanced Filters > Core** | Create Filter, Initialize Filter, Update Filter | Core functionality for 3-node system |
| **Advanced Filters > One-Click** | Kalman/OneEuro Filter Value/Vector | One-click macros |
| **Advanced Filters > Utility** | Reset, Get Current Value, Cleanup | Utility functions |
| **Advanced Filters > Advanced** | Compare Outputs, Auto Tune | Advanced features |
| **Advanced Filters > Chain** | Create Chain, Process Through Chain | Filter chaining |
| **Advanced Filters > Custom Preset** | Create/Apply Custom Preset | Custom presets |
| **Advanced Filters > Performance** | Start/Stop Profiling | Performance measurement |
| **Advanced Filters > Debug** | Get Statistics, Response Curve | Debugging tools |
| **Advanced Filters > Recommendation** | Recommend Filter Type | Filter recommendation |

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
**Category:** Advanced Filters > Core

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
**Category:** Advanced Filters > Core

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
**Category:** Advanced Filters > Core

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
**Category:** Advanced Filters > Core

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
**Category:** Advanced Filters > One-Click

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
**Category:** Advanced Filters > One-Click

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
**Category:** Advanced Filters > One-Click

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
**Category:** Advanced Filters > One-Click

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
**Category:** Advanced Filters > Advanced

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
- Higher Q = Trust measurements more
- Lower Q = Trust predictions more

---

### Set Measurement Noise (Kalman)
**Category:** Advanced Filters > Advanced

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
**Category:** Advanced Filters > Advanced

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
**Category:** Advanced Filters > Advanced

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
**Category:** Advanced Filters > Custom Preset

Creates a custom filter preset with specific parameters.

```
Create Custom Preset
├─ Input
│  ├─ Preset Name (FString): Unique name
│  ├─ Filter Type (EFilterType): Kalman or OneEuro
│  ├─ Process Noise/Min Cutoff (float): 
│  │   - When Kalman selected: Process Noise (Q)
│  │   - When OneEuro selected: Min Cutoff
│  ├─ Measurement Noise/Beta (float):
│  │   - When Kalman selected: Measurement Noise (R)
│  │   - When OneEuro selected: Beta
│  └─ DCutoff (float): OneEuro only (default: 1.0)
└─ Output
   └─ Custom Preset (FCustomFilterPreset): Created preset
```

⚠️ **IMPORTANT NOTE:**
- Parameter meanings change based on filter type!
- Kalman Filter: 1st = Process Noise (Q), 2nd = Measurement Noise (R)
- OneEuro Filter: 1st = Min Cutoff, 2nd = Beta
- DCutoff is only used for OneEuro filters

**Usage Examples:**
```blueprint
// Creating Kalman preset
[Create Custom Preset]
├─ Preset Name: "MyKalmanPreset"
├─ Filter Type: Kalman
├─ Process Noise/Min Cutoff: 0.05 (used as Q)
├─ Measurement Noise/Beta: 0.1 (used as R)
└─ DCutoff: 1.0 (ignored)

// Creating OneEuro preset
[Create Custom Preset]
├─ Preset Name: "MyOneEuroPreset"
├─ Filter Type: OneEuro
├─ Process Noise/Min Cutoff: 0.5 (used as Min Cutoff)
├─ Measurement Noise/Beta: 0.001 (used as Beta)
└─ DCutoff: 1.5 (used)
```

---

### Apply Custom Preset
**Category:** Advanced Filters > Custom Preset

Applies a previously created custom preset to a filter.

```
Apply Custom Preset
├─ Input
│  ├─ Target (UBaseFilterObject*): Filter instance
│  └─ Preset (FCustomFilterPreset): Preset to apply
└─ Output
   └─ Success (bool): True if applied successfully
```

⚠️ **Note:**
- Filter type must match preset type
- Kalman presets only work with Kalman filters
- OneEuro presets only work with OneEuro filters

---

### Create Filter Chain
**Category:** Advanced Filters > Chain

Creates a chain of multiple filters for sequential processing.

```
Create Filter Chain
├─ Input
│  ├─ Filter Types (TArray<EFilterType>): List of filter types
│  └─ Presets (TArray<EFilterPreset>): List of presets
└─ Output
   └─ Filter Chain (TArray<FFilterChainNode>): Chain array
```

---

### Process Through Chain
**Category:** Advanced Filters > Chain

Processes a value through multiple filters in sequence.

```
Process Through Chain
├─ Input
│  ├─ Filter Chain (TArray<FFilterChainNode>): Chain array
│  ├─ Raw Value (float): Input value
│  └─ Delta Time (float): Time delta (unused)
└─ Output
   └─ Filtered Value (float): Final result
```

---

## 🛠️ Utility Nodes

### Reset Filter
**Category:** Advanced Filters > Utility

Resets filter to initial state.

```
Reset Filter
├─ Input
│  └─ Target (UBaseFilterObject*): Filter to reset
└─ Output
   └─ (none)
```

---

### Get Current Value
**Category:** Advanced Filters > Utility

Gets the current filtered value without updating.

```
Get Current Value (Float)
├─ Input
│  └─ Target (UBaseFilterObject*): Filter instance
└─ Output
   └─ Current Value (float): Last filtered value
```

---

### Is Filter Initialized
**Category:** Advanced Filters > Utility

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
**Category:** Advanced Filters > Advanced

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
**Category:** Advanced Filters > Advanced

Gets current error covariance (uncertainty).

```
Get Error Covariance
├─ Input
│  └─ Target (UKalmanFilter*): Kalman filter
└─ Output
   └─ Error Covariance (float): Current uncertainty
```

---

### Cleanup All Filters
**Category:** Advanced Filters > Utility

Removes all cached filter instances.

```
Cleanup All Filters
└─ Output
   └─ (none)
```

**Use Cases:**
- Level transitions
- Memory cleanup
- Testing

---

### Get Filter Memory Usage
**Category:** Advanced Filters > Performance

Reports total memory used by all filters.

```
Get Filter Memory Usage
└─ Output
   ├─ Filter Count (int32): Number of active filters
   └─ Memory Bytes (int32): Total memory usage
```

---

### Start Filter Profiling
**Category:** Advanced Filters > Performance

Begins performance profiling for a filter.

```
Start Filter Profiling
├─ Input
│  └─ Profile ID (FString): Profile identifier
└─ Output
   └─ (none)
```

---

### Stop Filter Profiling
**Category:** Advanced Filters > Performance

Stops profiling and returns performance data.

```
Stop Filter Profiling
├─ Input
│  └─ Profile ID (FString): Profile identifier
└─ Output
   ├─ Average Time MS (float): Average update time
   ├─ Peak Time MS (float): Maximum update time
   └─ Update Count (int32): Total updates
```

---

## 🔍 Debug and Recommendation Nodes

### Recommend Filter Type
**Category:** Advanced Filters > Recommendation

Recommends the best filter type based on use case.

```
Recommend Filter Type
├─ Input
│  ├─ Needs Fast Response (bool): Fast response needed
│  ├─ Needs Precise Prediction (bool): Precise prediction needed
│  ├─ Is VR/AR Input (bool): Is VR/AR input
│  └─ Has Variable Frame Rate (bool): Variable frame rate
└─ Output
   └─ Filter Type (EFilterType): Recommended filter type
```

---

### Get Filter Statistics
**Category:** Advanced Filters > Debug

Get detailed filter information for debugging.

```
Get Filter Statistics
├─ Input
│  └─ Target (UBaseFilterObject*): Filter instance
└─ Output
   └─ Statistics (FString): Detailed statistics string
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

### FCustomFilterPreset

Custom filter preset structure.

**Properties:**
- `PresetName`: Preset name
- `FilterType`: Filter type (Kalman/OneEuro)
- `ProcessNoise`: Kalman Q parameter
- `MeasurementNoise`: Kalman R parameter
- `MinCutoff`: OneEuro minimum cutoff
- `Beta`: OneEuro speed coefficient
- `DCutoff`: OneEuro derivative cutoff

---

### FFilterChainNode

Filter chain node structure.

**Properties:**
- `Filter`: Filter instance
- `Weight`: Blending weight (0.0 - 1.0)

---

### FFilterPerformanceData

Performance data structure.

**Properties:**
- `AverageProcessingTime`: Average processing time
- `MaxProcessingTime`: Maximum processing time
- `UpdateCount`: Update count
- `TotalProcessingTime`: Total processing time

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

## 🚧 Not Yet Implemented Features

### Prediction Features (In documentation but not in code)

The following features are planned for future updates:

```
// Planned features
Predict Next State (Kalman Filter)
├─ Input
│  ├─ Target (UKalmanFilter*): Kalman filter
│  └─ Steps Ahead (int32): Number of steps to predict
└─ Output
   └─ Predicted Value (float): Predicted value

Get Predicted Value (Kalman Filter)
├─ Input
│  └─ Target (UKalmanFilter*): Kalman filter
└─ Output
   └─ Predicted Value (float): Current prediction
```

---

## 📝 Example Code

### Basic Kalman Filtering (Using Advanced Filters > Core)
```blueprint
// Begin Play
Create Filter (Kalman) → Initialize (Medium) → Set Variable (MyFilter)

// Event Tick
Get Variable (MyFilter) → Update Filter Float (Sensor Value) → Set Actor Location
```

### Advanced One Euro with Custom Preset
```blueprint
// Begin Play - Kalman Custom Preset
Create Custom Preset
├─ Preset Name: "VR_Hand_Kalman"
├─ Filter Type: Kalman
├─ Process Noise/Min Cutoff: 0.05 (used as Q)
├─ Measurement Noise/Beta: 0.02 (used as R)
└─ DCutoff: 1.0 (ignored)

// Begin Play - OneEuro Custom Preset
Create Custom Preset
├─ Preset Name: "VR_Hand_OneEuro"
├─ Filter Type: OneEuro
├─ Process Noise/Min Cutoff: 0.3 (used as Min Cutoff)
├─ Measurement Noise/Beta: 0.0001 (used as Beta)
└─ DCutoff: 1.0 (used)

// Create filter and apply preset
Create Filter (OneEuro) → Apply Custom Preset ("VR_Hand_OneEuro") → Set Variable

// Event Tick
Get Variable → Update Filter Vector (Controller Position, Delta Time) → Set Hand Mesh Location
```

---

For practical examples, see [Blueprint Examples](Examples.md) →