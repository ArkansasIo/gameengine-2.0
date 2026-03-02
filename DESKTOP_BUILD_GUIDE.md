# LunaLite API GUI - Desktop Application Build Guide

## Overview

The LunaLite API GUI is now available as a native desktop C++ application using the Qt framework. This provides a cross-platform, native-looking application with RPG Maker MZ styling.

## System Requirements

### Windows
- Windows 7 or later
- Visual Studio 2015 or later, OR MinGW 5.3+
- Qt 5.12 or later
- CMake 3.16+

### macOS
- macOS 10.12 or later
- Xcode 9.0 or later
- Qt 5.12 or later
- CMake 3.16+

### Linux (Ubuntu/Debian)
- Qt 5.12 or later
- CMake 3.16+
- GCC 5.0+ or Clang 3.5+

## Installation & Building

### Prerequisites

#### Qt Installation
1. Download Qt from: https://www.qt.io/download
2. Install Qt 5.15 or later (open-source version recommended)
3. During installation, ensure you select:
   - Qt 5.15.x or later
   - MSVC 2019 (Windows) or GCC (Linux) or Clang (macOS)
   - Qt Tools (CMake, Qt Creator optional)

#### CMake Installation
- **Windows**: Download from https://cmake.org/download/
- **macOS**: `brew install cmake`
- **Linux**: `sudo apt-get install cmake`

### Building on Windows

#### Using Visual Studio (MSVC)

```bash
# Navigate to project directory
cd d:\New_folder_5\LunaLite\cpp_src

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH="C:\Qt\5.15.2\msvc2019_64" ..

# Build
cmake --build . --config Release

# Run
.\Release\LunaLiteAPIGUI.exe
```

#### Using MinGW

```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:\Qt\5.15.2\mingw81_64" ..
cmake --build .
.\LunaLiteAPIGUI.exe
```

### Building on macOS

```bash
# Navigate to project directory
cd /path/to/LunaLite/cpp_src

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/qt5 ..

# Build
cmake --build . --config Release

# Run
./LunaLiteAPIGUI.app/Contents/MacOS/LunaLiteAPIGUI
```

### Building on Linux

```bash
# Navigate to project directory
cd ~/LunaLite/cpp_src

# Install dependencies (Ubuntu/Debian)
sudo apt-get install qt5-default libqt5core5a libqt5gui5 cmake

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Run
./LunaLiteAPIGUI
```

## Application Features

### Main Features
- **Browse API Classes**: View all available classes with documentation
- **Search Functionality**: Find classes and methods quickly
- **Category Filtering**: Filter by Graphics, Audio, Input, etc.
- **Export to JSON**: Save API reference as JSON file
- **Print Documentation**: Print selected documentation
- **Native GUI**: Windows-native, macOS-native, and Linux-native look and feel

### RPG Maker MZ Styling
- Authentic color palette (gold, purple, blue)
- 3D window frames with beveled borders
- Professional typography and spacing
- Smooth hover and click animations
- Status bar with real-time information

## Project Structure

```
cpp_src/
├── main.cpp                 # Application entry point
├── APIGUIWindow.h          # Main window header
├── APIGUIWindow.cpp        # Main window implementation
├── CMakeLists_APIGui.txt   # CMake build configuration
└── resources.qrc           # Qt resource file (optional)
```

## File Descriptions

### APIGUIWindow.h
- Header file defining the main application window
- Contains slots for UI interactions
- Defines data structures for API information

### APIGUIWindow.cpp
- Implementation of the main window
- Sets up UI layout with Qt widgets
- Handles all user interactions
- Implements search, filter, and export functionality
- Applies RPG Maker MZ stylesheet

### main.cpp
- Application entry point
- Creates QApplication instance
- Initializes and displays main window

### CMakeLists_APIGui.txt
- CMake configuration for building the application
- Specifies Qt dependencies
- Sets compiler options for different platforms

## Configuration

### Using Qt Creator (Recommended)

1. Open Qt Creator
2. File → Open File or Project
3. Navigate to `cpp_src/CMakeLists_APIGui.txt`
4. Configure project:
   - Select your Qt Kit
   - Choose build folder
   - Click "Configure Project"
5. Build: Ctrl+B
6. Run: Ctrl+R

### Using Command Line

```bash
cmake -B build -DCMAKE_PREFIX_PATH=$QT_PATH
cmake --build build --config Release
```

## Troubleshooting

### Qt Not Found
```
CMake Error: "Could not find Qt5"
```
**Solution**: Ensure Qt is installed and set CMAKE_PREFIX_PATH correctly:
```bash
cmake -DCMAKE_PREFIX_PATH=/path/to/qt/installation ..
```

### Build Fails with Visual Studio
```
error: moc failed
```
**Solution**: Ensure CMAKE_AUTOMOC is enabled in CMakeLists.txt (it is by default)

### Application Won't Start
- Check that all Qt libraries are in PATH
- On Linux: `ldd ./LunaLiteAPIGUI` to check dependencies
- On Windows: Use Dependency Walker to check DLL dependencies

## Development

### Adding New Features

1. Add UI elements in `APIGUIWindow::initializeUI()`
2. Create slots in APIGUIWindow.h for event handling
3. Connect signals to slots in `setupConnections()`
4. Update stylesheet in `setupStylesheet()`

### Modifying Styling

Edit the stylesheet string in `setupStylesheet()` method:
```cpp
QString stylesheet = R"(
    // Your QSS stylesheet here
)";
```

### Loading API Data

Edit `loadAPIData()` to load from definition files:
```cpp
void APIGUIWindow::loadAPIData() {
    // Parse definitions/lunalite-globals.d.ts
    // Load class information
}
```

## Distribution

### Creating Installers

#### Windows (NSIS)
```powershell
windeployqt.exe LunaLiteAPIGUI.exe
# Create NSIS installer script
makensis setup.nsi
```

#### macOS (DMG)
```bash
macdeployqt LunaLiteAPIGUI.app -dmg
```

#### Linux (AppImage)
```bash
# Use linuxdeployqt
linuxdeployqt LunaLiteAPIGUI -appimage
```

## Performance Optimization

- Application compiled with Release mode for optimal performance
- Lazy loading of API data for faster startup
- Efficient search with indexed classes
- Smooth animations (GPU-accelerated when available)

## Security

- No network connections by default
- Local file operations only
- No telemetry or tracking
- Open-source code available for review

## License

LunaLite API GUI is licensed under the MIT License.

## Support

For issues and feature requests, visit:
https://github.com/LunaTechsDev/LunaLite

## Version History

### v1.0.0 (Initial Release)
- Complete API reference browser
- Search and filter functionality
- Export to JSON
- Print support
- RPG Maker MZ styling
- Cross-platform support
