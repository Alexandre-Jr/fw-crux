# Check if we are in the right directory
if [ ! -f "src/CMakeLists.txt" ]; then
    echo "Error: CMakeLists.txt not found. Please run this script from the project root directory."
    exit 1
fi

# Defines
SCRIPT_DIR=src
THIRDPARTY=3rdparty
TARGET_PLATFORM_MCU=simActuator
TARGET_PLATFORM_OS=posix
BIN_NAME=fw-crux


# Install submodules
git submodule update --init --recursive

echo "Submodules updated."

# Enter in src
cd "$SCRIPT_DIR" || exit
cd "$THIRDPARTY" || exit
cd  pico-sdk || exit

git submodule update --init --recursive

echo "Pico SDK submodules updated."