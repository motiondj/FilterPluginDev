# Troubleshooting Guide

*Read this in other languages: [English](Troubleshooting.md), [한국어](Troubleshooting_KR.md)*

Common issues and solutions for Advanced Filters Plugin

## 📍 Navigation

- [← Back: Performance Guide](Performance.md)
- [← Back to README](../README.md)

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
  - **Troubleshooting** (You are here)

---

## 📋 Table of Contents

1. [Installation Issues](#installation-issues)
2. [Blueprint Node Issues](#blueprint-node-issues)
3. [Runtime Errors](#runtime-errors)
4. [Performance Problems](#performance-problems)
5. [Filter Behavior Issues](#filter-behavior-issues)
6. [Platform-Specific Issues](#platform-specific-issues)

---

## 🔧 Installation Issues

### Plugin Not Visible in Plugins Menu

**Symptoms:**
- Plugin doesn't appear in Edit → Plugins
- Can't find "Advanced Filters" in plugin list

**Solutions:**

1. **Check folder structure:**
   ```
   YourProject/Plugins/AdvancedFilters/
   ├── AdvancedFilters.uplugin  ← Must exist
   ├── Source/
   └── Resources/
   ```

2. **Verify plugin file:**
   - Open `AdvancedFilters.uplugin` in text editor
   - Check `"EngineVersion": "5.5"` matches your engine

3. **Refresh plugin list:**
   - Close Unreal Engine
   - Delete `YourProject/Saved/` folder
   - Restart and check again

4. **Manual registration:**
   ```json
   // In YourProject.uproject, add:
   "Plugins": [
     {
       "Name": "AdvancedFilters",
       "Enabled": true
     }
   ]
   ```

---

### Compilation Errors

**Symptoms:**
- "Failed to compile plugin" error
- Missing module errors
- Link errors

**Solutions:**

1. **Check engine version:**
   - Must be Unreal Engine 5.5 or higher
   - Check: Help → About Unreal Engine

2. **Regenerate project files:**
   ```bash
   # Windows
   Right-click .uproject → Generate Visual Studio project files
   
   # Mac
   Right-click .uproject → Generate Xcode project files
   ```

3. **Clear intermediate files:**
   ```
   Delete these folders:
   - Plugins/AdvancedFilters/Binaries/
   - Plugins/AdvancedFilters/Intermediate/
   - Rebuild
   ```

4. **Check build tools:**
   - Windows: Visual Studio 2022 with C++ tools
   - Mac: Latest Xcode with command line tools
   - Linux: GCC 11+ or Clang 13+

---

## 🎯 Blueprint Node Issues

### Nodes Not Appearing

**Symptoms:**
- Can't find filter nodes in Blueprint
- Search returns no results
- Category missing

**Solutions:**

1. **Enable plugin:**
   - Edit → Plugins → Search "Advanced Filters"
   - Ensure checkbox is checked
   - Restart editor

2. **Check context:**
   - Some nodes only appear in certain contexts
   - Try in Actor or Character Blueprint

3. **Search variations:**
   ```
   Try searching:
   - "Kalman"
   - "One Euro"
   - "Filter Value"
   - "Advanced Filters"
   ```

4. **Compile Blueprint:**
   - Click Compile button
   - Check for errors in compiler results

---

### Nodes Showing Errors

**Symptoms:**
- Red error on nodes
- "Node impure" warnings
- Missing pin connections

**Solutions:**

1. **Refresh nodes:**
   - Right-click node → Refresh Node
   - Or delete and re-add

2. **Check execution pins:**
   - Ensure white execution pins are connected
   - One-click macros don't need execution pins

3. **Validate inputs:**
   - Delta Time required for One Euro
   - Filter ID must be non-empty string
   - Preset must be valid enum value

---

## ⚠️ Runtime Errors

### Filter Not Smoothing

**Symptoms:**
- Output same as input
- No filtering effect
- Jumpy values

**Common Causes & Solutions:**

1. **Inconsistent Filter ID:**
   ```blueprint
   // Bad - Creates new filter each frame
   Filter ID: "Filter_" + Random Int
   
   // Good - Reuses same filter
   Filter ID: "PlayerPosition"
   ```

2. **Missing initialization:**
   - 3-node system: Must call Initialize
   - One-click: Automatic (check ID consistency)

3. **Wrong preset:**
   - Low preset = minimal filtering
   - Try Medium or High for more smoothing

4. **Frame-dependent values:**
   - Ensure Delta Time is connected (One Euro)
   - Don't use fixed time values

---

### Excessive Lag/Delay

**Symptoms:**
- Filter output lags behind input
- Slow response to changes
- Feels "floaty"

**Solutions:**

1. **Switch filter type:**
   - Kalman → One Euro for lower latency
   - One Euro typically 3-5x faster response

2. **Adjust preset:**
   - High → Medium or Low
   - Lower preset = faster response

3. **Custom parameters:**
   ```blueprint
   // For Kalman - Increase Q
   Set Process Noise (0.1 → 1.0)
   
   // For One Euro - Increase Min Cutoff
   Set Min Cutoff (0.1 → 1.0)
   ```

---

### Memory Leaks

**Symptoms:**
- Increasing memory usage over time
- Editor becomes slow
- Crashes after extended use

**Solutions:**

1. **Clear unused filters:**
   ```blueprint
   // On level end or state change
   Clear All Filters
   ```

2. **Reuse Filter IDs:**
   - Don't create unique IDs unnecessarily
   - Use consistent naming scheme

3. **Check filter count:**
   ```blueprint
   // Debug - Log filter count
   Get Filter Memory Usage
   → Print String (Filter Count)
   ```

---

## 🐌 Performance Problems

### Low Frame Rate

**Symptoms:**
- FPS drops when using filters
- Stuttering or hitching
- Performance warnings

**Solutions:**

1. **Implement LOD:**
   ```blueprint
   Distance = Get Distance to Camera
   If Distance > 50
       Skip Filter Update
   ```

2. **Reduce update frequency:**
   ```blueprint
   // Update every N frames
   If Frame Counter % 3 == 0
       Update Filter
   ```

3. **Use conditional updates:**
   ```blueprint
   If Abs(New - Old) > Threshold
       Update Filter
   ```

4. **Profile performance:**
   ```
   Console commands:
   stat Filter
   stat FilterDetailed
   ```

---

### High CPU Usage

**Symptoms:**
- CPU usage spikes
- Thermal throttling
- Battery drain (mobile)

**Solutions:**

1. **Batch processing:**
   - Group similar filters
   - Update in batches

2. **Optimize filter count:**
   - Audit all filters in use
   - Remove redundant filters

3. **Platform-specific settings:**
   - Mobile: Use Low presets
   - VR: Limit to 50 filters per eye

---

## 🔍 Filter Behavior Issues

### Output Oscillating

**Symptoms:**
- Filter output swings back and forth
- Unstable values
- Overcorrection

**Solutions:**

1. **Check input stability:**
   - Ensure input isn't switching rapidly
   - Add input validation

2. **Adjust parameters:**
   ```blueprint
   // Kalman - Reduce Q
   Set Process Noise (0.01)
   
   // One Euro - Reduce Beta
   Set Beta (0.0001)
   ```

3. **Use different filter:**
   - Switch to other filter type
   - Try different preset

---

### No Prediction (Kalman)

**Symptoms:**
- Kalman filter not predicting
- Acts like simple smoothing
- No anticipation of movement

**Solutions:**

1. **Verify filter type:**
   - Ensure using Kalman, not One Euro
   - Check Create Filter node

2. **Consistent updates:**
   - Update every frame
   - Don't skip frames

3. **Appropriate parameters:**
   - Medium or High preset
   - Avoid excessive R values

---

## 🖥️ Platform-Specific Issues

### Mobile Performance

**Issue:** Poor performance on mobile devices

**Solutions:**
1. Use Low presets exclusively
2. Limit to 50-100 filters max
3. Implement aggressive LOD
4. Consider float16 precision

### VR Comfort

**Issue:** Motion sickness from filtering

**Solutions:**
1. Use One Euro for controllers
2. Low preset for minimal latency
3. Never filter head tracking
4. Test with various users

### Console Compatibility

**Issue:** Plugin not working on console

**Solutions:**
1. Rebuild for target platform
2. Check platform-specific code
3. Verify shader compilation
4. Contact support for console SDK

---

## 🔧 Debug Commands

### Useful Console Commands

```
// Show filter statistics
stat Filter

// Detailed performance
stat FilterDetailed

// Memory usage
ShowFlag.FilterMemory 1

// Debug visualization
r.Filter.ShowDebug 1

// Reset all filters
Filter.ClearAll
```

### Blueprint Debug Nodes

```blueprint
// Log filter state
Get Filter Statistics → Print String

// Performance check
Start/Stop Filter Profiling

// Memory audit
Get Filter Memory Usage → Log
```

---

## 📞 Getting More Help

If issues persist:

1. **Search existing issues:**
   - [GitHub Issues](https://github.com/yourusername/AdvancedFilters/issues)
   - Check closed issues too

2. **Create detailed report:**
   - Unreal Engine version
   - Plugin version
   - Steps to reproduce
   - Error messages/logs
   - Screenshots/videos

3. **Contact support:**
   - Discord: [Join our server](https://discord.gg/yourserver)
   - Email: support@yourcompany.com
   - Include project files if possible

---

## 📋 Quick Reference

### Most Common Fixes

| Problem | Quick Fix |
|---------|-----------|
| Nodes not found | Enable plugin & restart |
| No smoothing | Check Filter ID consistency |
| Too much lag | Switch to One Euro or Low preset |
| Performance issues | Implement LOD system |
| Compilation errors | Regenerate project files |
| Memory leaks | Call Clear All Filters |

---

Remember: Most issues have simple solutions. Check the basics first! 🎯