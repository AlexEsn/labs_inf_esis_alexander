!/bin/bash

mkdir cmake-build
cd cmake-build
cmake ..
make
cd ..
mv cmake-build/lab1 .
rm -rf cmake-build/