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

PROJECTS_DIR="$TOP_DIR/projects"
BACKUP_PROJECTS_DIR="$TOP_DIR/backup/projects"

for proj in `ls $PROJECTS_DIR`
do
    echo $proj
    diff -Nur --exclude=.git $BACKUP_PROJECTS_DIR/$proj $PROJECTS_DIR/$proj > $DIFFS/$proj
done
