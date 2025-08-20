# Check if we are in the right directory
if [ ! -f "src/CMakeLists.txt" ]; then
    echo "Error: CMakeLists.txt not found. Please run this script from the project root directory."
    exit 1
fi

# Update
git pull origin main