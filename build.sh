#!/bin/bash

# LunaLite API GUI - Build Script for macOS and Linux
# This script automates the build process for the desktop application

set -e

# Colors for output
RED='\033[0;91m'
GREEN='\033[0;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
RESET='\033[0m'

# Configuration
PROJECT_NAME="LunaLiteAPIGUI"
BUILD_TYPE="Release"

echo ""
echo "=========================================================="
echo "   LunaLite API GUI - Desktop Application Build"
echo "=========================================================="
echo ""

# Detect OS
OS_TYPE="$(uname -s)"
case "$OS_TYPE" in
    Darwin*)
        OS="macOS"
        ;;
    Linux*)
        OS="Linux"
        ;;
    *)
        OS="Unknown"
        ;;
esac

echo -e "${BLUE}[*]${RESET} Detected OS: $OS"

# Check for required tools
echo -e "${BLUE}[*]${RESET} Checking for required tools..."

if ! command -v cmake &> /dev/null; then
    echo -e "${RED}[!]${RESET} CMake not found. Please install CMake:"
    if [ "$OS" = "macOS" ]; then
        echo "    brew install cmake"
    else
        echo "    sudo apt-get install cmake"
    fi
    exit 1
fi
echo -e "${GREEN}[+]${RESET} CMake found"

if ! command -v qmake &> /dev/null; then
    echo -e "${YELLOW}[!]${RESET} Qt not found in PATH. Please ensure Qt is installed."
    echo "    Set QT_PATH environment variable if Qt is not in default location."
fi

# Get Qt path
if [ -z "$QT_PATH" ]; then
    if [ "$OS" = "macOS" ]; then
        QT_PATH="/usr/local/opt/qt5"
    else
        QT_PATH="/usr/lib/x86_64-linux-gnu"
    fi
fi

if [ ! -d "$QT_PATH" ]; then
    echo -e "${YELLOW}[?]${RESET} Qt not found at: $QT_PATH"
    echo "    Please enter Qt installation path:"
    read -r QT_PATH
fi

if [ ! -d "$QT_PATH" ]; then
    echo -e "${RED}[!]${RESET} Qt path not found: $QT_PATH"
    exit 1
fi

echo -e "${GREEN}[+]${RESET} Qt found at: $QT_PATH"

# Create build directory
echo ""
echo -e "${BLUE}[*]${RESET} Setting up build environment..."

if [ ! -d "build" ]; then
    mkdir -p build
    echo -e "${GREEN}[+]${RESET} Created build directory"
fi

cd build

# Configure with CMake
echo ""
echo -e "${BLUE}[*]${RESET} Configuring project with CMake..."

cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_PREFIX_PATH="$QT_PATH" ../cpp_src

if [ $? -ne 0 ]; then
    echo -e "${RED}[!]${RESET} CMake configuration failed."
    exit 1
fi

echo -e "${GREEN}[+]${RESET} Configuration complete"

# Build project
echo ""
echo -e "${BLUE}[*]${RESET} Building project (this may take a few minutes)..."

cmake --build . --config $BUILD_TYPE

if [ $? -ne 0 ]; then
    echo -e "${RED}[!]${RESET} Build failed."
    exit 1
fi

echo -e "${GREEN}[+]${RESET} Build successful"

# Show results
echo ""
echo -e "${GREEN}[+]${RESET} Build complete!"

if [ "$OS" = "macOS" ]; then
    echo -e "${GREEN}[+]${RESET} Application: $PROJECT_NAME.app/Contents/MacOS/$PROJECT_NAME"
else
    echo -e "${GREEN}[+]${RESET} Application: ./$PROJECT_NAME"
fi

echo ""
read -p "[?] Do you want to run the application now? (y/n) " -n 1 -r
echo ""

if [[ $REPLY =~ ^[Yy]$ ]]; then
    echo -e "${BLUE}[*]${RESET} Starting application..."
    if [ "$OS" = "macOS" ]; then
        ./$PROJECT_NAME.app/Contents/MacOS/$PROJECT_NAME &
    else
        ./$PROJECT_NAME &
    fi
else
    echo -e "${BLUE}[*]${RESET} To run the application manually, execute:"
    if [ "$OS" = "macOS" ]; then
        echo "    ./$PROJECT_NAME.app/Contents/MacOS/$PROJECT_NAME"
    else
        echo "    ./$PROJECT_NAME"
    fi
fi

cd ..

echo ""
echo -e "${GREEN}[+]${RESET} Build script completed successfully!"
echo ""
