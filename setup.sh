git submodule init && git submodule update # Get and update submodules (SDL)
mkdir -p build && cd build # Make and cd into the directory
cmake .. && cd .. # Create the build structure
cmake --build build && .'./build/Debug/CSDLBoiled.exe' # Build and run