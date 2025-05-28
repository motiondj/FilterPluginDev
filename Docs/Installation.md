# Installation Guide

*Read this in other languages: [English](Installation.md), [한국어](Installation_KR.md)*

Step-by-step guide to install and set up the Advanced Filters Plugin

## 📍 Navigation

- [← Back: Quick Start Guide](QuickStart.md)
- [→ Next: User Manual](UserManual.md)

### 📖 All Documentation
- **Getting Started**
  - [Quick Start Guide](QuickStart.md)
  - **Installation Guide** (You are here)
- **User Guides**
  - [User Manual](UserManual.md)
  - [Blueprint Examples](Examples.md)
  - [Best Practices](BestPractices.md)
- **Technical Documentation**
  - [API Reference](APIReference.md)
  - [Performance Guide](Performance.md)
  - [Troubleshooting](Troubleshooting.md)

---

## 📋 Table of Contents

1. [System Requirements](#system-requirements)
2. [Installation Methods](#installation-methods)
3. [Plugin Activation](#plugin-activation)
4. [Verification](#verification)
5. [Troubleshooting Installation](#troubleshooting-installation)
6. [Updating the Plugin](#updating-the-plugin)

---

## 💻 System Requirements

### Minimum Requirements

- **Unreal Engine**: 5.5 or higher
- **Operating System**: 
  - Windows 10/11 (64-bit)
  - macOS 12.0 or later
  - Linux (Ubuntu 20.04 LTS or later)
- **Development Tools**:
  - Visual Studio 2022 (Windows)
  - Xcode 14+ (macOS)
  - GCC 11+ (Linux)
- **RAM**: 8GB minimum (16GB recommended)
- **Storage**: 500MB free space

### Supported Platforms

| Platform | Support Status | Notes |
|----------|---------------|-------|
| Windows | ✅ Full Support | Primary development platform |
| macOS | ✅ Full Support | Intel and Apple Silicon |
| Linux | ✅ Full Support | Tested on Ubuntu |
| Android | ⚠️ Experimental | Performance may vary |
| iOS | ⚠️ Experimental | Requires additional setup |
| Console | ❌ Not Tested | May work with modifications |

---

## 📦 Installation Methods

### Method 1: Pre-packaged Plugin (Recommended)

The easiest way to install for most users.

#### Step 1: Download the Plugin

1. Go to the [Releases Page](https://github.com/yourusername/AdvancedFilters/releases)
2. Download the latest version:
   - `AdvancedFilters_v1.0.0_UE5.5.zip`
3. Verify the download:
   - Check file size matches the release notes
   - Optional: Verify SHA256 checksum

#### Step 2: Extract the Plugin

1. **Create Plugins folder** (if it doesn't exist):
   ```
   YourProject/
   ├── Content/
   ├── Config/
   └── Plugins/    ← Create this folder
   ```

2. **Extract the ZIP file**:
   - Right-click the downloaded file
   - Select "Extract All" (Windows) or double-click (macOS)
   - Extract to `YourProject/Plugins/`

3. **Verify folder structure**:
   ```
   YourProject/Plugins/AdvancedFilters/
   ├── Source/
   ├── Resources/
   └── AdvancedFilters.uplugin
   ```

#### Step 3: Enable the Plugin

1. Open your project in Unreal Engine
2. Go to **Edit → Plugins**
3. Search for "Advanced Filters"
4. Check the box to enable
5. Click "Restart Now" when prompted

---

### Method 2: Installation from Source

For developers who want to modify the plugin.

#### Step 1: Clone the Repository

```bash
# Navigate to your project's Plugins folder
cd YourProject/Plugins

# Clone the repository
git clone https://github.com/yourusername/AdvancedFilters.git

# Or download as ZIP and extract
```

#### Step 2: Generate Project Files

**Windows:**
1. Right-click your `.uproject` file
2. Select "Generate Visual Studio project files"

**macOS:**
1. Right-click your `.uproject` file
2. Select "Generate Xcode project files"

**Linux:**
```bash
# In project root directory
./GenerateProjectFiles.sh
```

#### Step 3: Compile the Plugin

**Option A: Using IDE**
1. Open the generated solution/project file
2. Build the project in Development Editor configuration
3. Run the editor from IDE

**Option B: Using Unreal Engine**
1. Open the project in Unreal Engine
2. When prompted to compile, click "Yes"
3. Wait for compilation to complete

---

### Method 3: Engine Plugin Installation

Install for all projects on your machine.

#### Step 1: Locate Engine Plugins Folder

**Windows:**
```
C:\Program Files\Epic Games\UE_5.5\Engine\Plugins\
```

**macOS:**
```
/Users/Shared/Epic Games/UE_5.5/Engine/Plugins/
```

**Linux:**
```
~/UnrealEngine/Engine/Plugins/
```

#### Step 2: Copy Plugin

1. Create a new folder: `Engine/Plugins/Marketplace/AdvancedFilters`
2. Copy all plugin files to this folder
3. Restart Unreal Engine

#### Step 3: Enable for Project

1. Open your project
2. Go to **Edit → Plugins**
3. Find "Advanced Filters" under Marketplace
4. Enable the plugin

---

## ✅ Plugin Activation

### First Time Setup

1. **Open Plugin Settings**:
   - Edit → Plugins
   - Search: "Advanced Filters"

2. **Enable the Plugin**:
   - Check the box next to plugin name
   - Click "Restart Now"

3. **Verify Installation**:
   - After restart, check plugin is still enabled
   - No error messages in Output Log

### Blueprint Node Visibility

1. **Open any Blueprint**:
   - Create or open existing Blueprint

2. **Right-click in Event Graph**:
   - Search for "Kalman"
   - Should see filter nodes

3. **Check Categories**:
   - Look under "Advanced Filters" category
   - All nodes should be visible

---

## 🔍 Verification

### Quick Test

1. **Create Test Blueprint**:
   ```
   Content Browser → Blueprint Class → Actor → "BP_FilterTest"
   ```

2. **Add Simple Filter**:
   ```blueprint
   Event BeginPlay
   → Print String "Plugin Loaded Successfully!"
   
   Event Tick
   → Random Float in Range (0, 100)
   → Kalman Filter Value (Preset: Medium, ID: "Test")
   → Print String
   ```

3. **Run Test**:
   - Place actor in level
   - Press Play
   - Check output log for filtered values

### Verification Checklist

- [ ] Plugin shows as "Enabled" in Plugins menu
- [ ] No compilation errors
- [ ] Blueprint nodes are visible
- [ ] Basic filtering works
- [ ] No performance warnings

---

## 🚨 Troubleshooting Installation

### Common Issues and Solutions

#### Plugin Not Visible

**Problem**: Plugin doesn't appear in Plugins menu

**Solutions**:
1. Check folder structure is correct
2. Verify `.uplugin` file exists
3. Try refreshing plugin list:
   ```
   Edit → Plugins → Click refresh icon
   ```

#### Compilation Errors

**Problem**: "Failed to compile plugin" error

**Solutions**:
1. Verify Unreal Engine version (5.5+)
2. Install required development tools
3. Check build log for specific errors:
   ```
   Window → Developer Tools → Output Log
   ```

#### Nodes Not Appearing

**Problem**: Can't find filter nodes in Blueprint

**Solutions**:
1. Ensure plugin is enabled
2. Restart editor after enabling
3. Check Blueprint context:
   - Some nodes only appear in certain contexts
4. Try searching for specific node names:
   - "Kalman Filter Value"
   - "One Euro Filter Value"

#### Performance Issues

**Problem**: Editor runs slowly after installation

**Solutions**:
1. Check system requirements
2. Disable other plugins temporarily
3. Clear derived data cache:
   ```
   Edit → Editor Preferences → Derived Data Cache → Clear
   ```

---

## 🔄 Updating the Plugin

### Update Process

1. **Backup Current Version**:
   ```
   Rename: Plugins/AdvancedFilters → Plugins/AdvancedFilters_backup
   ```

2. **Download New Version**:
   - Get latest from releases page
   - Check compatibility notes

3. **Replace Files**:
   - Delete old plugin folder (except backup)
   - Extract new version

4. **Clean and Rebuild**:
   - Delete Binaries and Intermediate folders
   - Regenerate project files
   - Recompile

### Migration Notes

**From v0.x to v1.0**:
- API changes: None (first release)
- Blueprint compatibility: N/A

**Future Updates**:
- Check release notes for breaking changes
- Test in separate project first

---

## 📝 Platform-Specific Notes

### Windows

- Use Visual Studio 2022 or later
- Install "Game Development with C++" workload
- Run as Administrator if permission issues

### macOS

- Xcode Command Line Tools required
- For Apple Silicon: Universal Binary support included
- Grant full disk access if needed

### Linux

- Install development packages:
  ```bash
  sudo apt-get install build-essential
  sudo apt-get install mono-complete
  ```
- Use clang++ for better compatibility

---

## 🆘 Getting Help

If you encounter issues during installation:

1. **Check the FAQ**: [Troubleshooting Guide](Troubleshooting.md)
2. **Search Issues**: [GitHub Issues](https://github.com/yourusername/AdvancedFilters/issues)
3. **Ask Community**: [Discord Server](https://discord.gg/yourserver)
4. **Contact Support**: support@yourcompany.com

---

## ✅ Next Steps

Congratulations! The Advanced Filters Plugin is now installed.

**Ready to start filtering?**
- [Quick Start Guide](QuickStart.md) - Learn basics in 5 minutes
- [User Manual](UserManual.md) - Explore all features
- [Blueprint Examples](Examples.md) - See practical uses

---

Happy Filtering! 🎉