#!/usr/bin/bash

rm -f .fetch-log
CLONING=1

TOP_DIR=$PWD
while IFS=" " read -r path url branch commit; do
    if test $CLONING -eq 1; then
        if [ $path == "---" ]; then
            # Stop cloning repos
            if test $CLONING -eq 1; then
                CLONING=0
            fi
        else
            printf "%s | %s | %s | %s -- " $url $path $branch $commit
            if ! test -d $path || ! test -d $path/.git; then
                git clone $url $path -b $branch >>.fetch-log 2>&1
                if test $? -ne 0; then
                    echo -e "\e[31mFailed\e[0m"
                else
                    cd $path
                    git checkout $commit >>"$TOP_DIR.fetch-log" 2>&1
                    cd $TOP_DIR
                    echo -e "\e[32mFinished\e[0m"
                fi
            else
                echo -e "\e[33mSkipped\e[0m"
            fi
        fi
    else
        # Execute commands below the "---" line
        $path $url $branch $commit
    fi
done < $1
