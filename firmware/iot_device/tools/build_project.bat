cd ..
cd "bsp_stm32f401ccu6_blackpill"
rd /s /q "build"
mkdir "build"
cd "build"
cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=../bsp_stm32f401ccu6_blackpill/CMakeToolchain.cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -- -j 4
