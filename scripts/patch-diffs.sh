#!/usr/bin/sh

if [ -e "$PWD/scripts/common-env.sh" ]; then
    TOP_DIR=$PWD
elif [ -e "$PWD/common-env.sh" ] || [ -d "../kernel" ]; then
    TOP_DIR=`dirname $PWD`
else
    echo "Please run this script in top directory or any directory one level deeper than top"
    exit 1
fi

DIFFS="$TOP_DIR/diffs"
PROJECTS="$TOP_DIR/projects"

for proj in `ls $DIFFS`
do
    cd $PROJECTS/$proj
    patch -p 1 < $DIFFS/$proj
done
