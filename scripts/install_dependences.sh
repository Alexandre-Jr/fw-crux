# Check if we are in the right directory
if [ ! -f "src/CMakeLists.txt" ]; then
    echo "Error: CMakeLists.txt not found. Please run this script from the project root directory."
    exit 1
fi

# Defines
SCRIPT_DIR=src
3RDPARTY_DIR=3rdparty
TARGET_PLATFORM_MCU=simActuator
TARGET_PLATFORM_OS=posix
BIN_NAME=fw-crux

# Enter in src
cd "$SCRIPT_DIR" || exit
cd "$3RDPARTY_DIR" || exit

# Install dependencies
git clone git@github.com:raspberrypi/pico-sdk.git
git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git


# Run the build
./"$BIN_DIR"/"$BIN_NAME"