# Check if we are in the right directory
if [ ! -f "src/CMakeLists.txt" ]; then
    echo "Error: CMakeLists.txt not found. Please run this script from the project root directory."
    exit 1
fi

# Defines
SCRIPT_DIR=src
BUILD_DIR=build
BIN_DIR=dist
TARGET_PLATFORM_MCU=simActuator
TARGET_PLATFORM_OS=posix
BIN_NAME=fw-crux

# Enter in src
cd "$SCRIPT_DIR" || exit

# Build the project
cd build || exit
cmake -DTARGET_PLATFORM_MCU="$TARGET_PLATFORM_MCU" -DTARGET_PLATFORM_OS="$TARGET_PLATFORM_OS" ..
make -j
cd ..

# Run the build
./"$BIN_DIR"/"$BIN_NAME"