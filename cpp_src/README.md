# LunaLite C++ Port

This directory contains C++ header and source files converted from the TypeScript definitions in the LunaLite project.

## Structure

- **Point.h/cpp** - 2D point class with coordinate operations
- **Rectangle.h/cpp** - Rectangle geometry class with collision detection
- **Bitmap.h/cpp** - Image/bitmap handling with drawing operations
- **Graphics.h/cpp** - Graphics rendering system
- **Input.h/cpp** - Keyboard and gamepad input handling
- **CacheEntry.h/cpp** - Resource cache entry management
- **CacheMap.h/cpp** - Resource caching system
- **JsonEx.h/cpp** - JSON serialization utilities

## Building

### Using CMake:

```bash
mkdir build
cd build
cmake ..
make
```

### Manual compilation:

```bash
g++ -std=c++11 -c *.cpp
ar rcs liblunalite.a *.o
```

## Classes Overview

### Point
- Represents a 2D coordinate
- Methods: copyFrom, copyTo, equals, set

### Rectangle
- Represents a rectangular area
- Methods: clone, copy, contains, pad, fit, enlarge

### Bitmap
- Image manipulation and drawing
- Methods: resize, blt, fillRect, drawText, drawCircle, etc.

### Graphics
- Static graphics system
- Methods: initialize, render, tickStart, tickEnd

### Input
- Static input handling
- Methods: isPressed, isTriggered, isRepeated, isLongPressed

### CacheMap/CacheEntry
- Resource caching with TTL support
- Methods: getItem, setItem, checkTTL, update

### JsonEx
- JSON utilities
- Methods: makeDeepCopy, stringify, parse

## Notes

This is a minimal implementation based on the TypeScript definitions. Many methods contain stub implementations that would need to be filled in for a complete port.
