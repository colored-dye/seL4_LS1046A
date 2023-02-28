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

mkdir -p $DIFFS

for proj in `ls $TOP_DIR/projects`
do
    cd $TOP_DIR/projects/$proj
    git diff > $DIFFS/$proj
done
