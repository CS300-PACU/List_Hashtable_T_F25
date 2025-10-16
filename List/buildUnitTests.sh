export CXX=`which clang++-16`;
echo $CXX;
cmake -S . -B ./build;
cmake --build build --target clean;
cmake --build build;
