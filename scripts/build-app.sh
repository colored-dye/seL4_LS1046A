#!/usr/bin/bash

if [ -e "$PWD/scripts/build-kernel.sh" ]; then
    TOP_DIR=$PWD
elif [ -e "$PWD/build-kernel.sh" ] || [ -d "../kernel" ]; then
    TOP_DIR=`dirname $PWD`
else
    echo "Please run this script in top directory or \`kernel\' directory"
    exit 1
fi


BUILD_DIR="$TOP_DIR/build"
APP_DIR="$TOP_DIR/apps/hello"
BUILD_APP_DIR="$BUILD_DIR/apps/hello"

echo "TOP_DIR: $TOP_DIR"
echo "App build directory: $BUILD_KERNEL_DIR"

rm -rf $BUILD_APP_DIR
mkdir -p $BUILD_APP_DIR
cd $BUILD_APP_DIR

cmake "$APP_DIR" \
    -GNinja \
    -DSEL4_CACHE_DIR="$TOP_DIR/.sel4_cache" \
    -DKernelArchARM=1 \
    -DKernelSel4ArchAarch64=1 \
    -DKernelWordSize=64 \
    -DKernelArmCortexA72=1 \
    -DKernelArchArmV8a=1 \
    -Darch=aarch64 \
    -DCMAKE_TOOLCHAIN_FILE="$TOP_DIR/kernel/gcc.cmake" \
    -DPLATFORM=ls1046a \
    -DTUT_BOARD=ls1046a \
    -DCROSS_COMPILER_PREFIX=aarch64-linux-gnu- \
    -DSEL4_TUTORIALS_DIR="$TOP_DIR/projects/sel4-tutorials"
