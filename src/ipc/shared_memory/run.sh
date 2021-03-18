#!/bin/bash
# https://gist.github.com/garcia556/8231e844a90457c99cc72e5add8388e4

function is_linux() {
    if [[ "$(uname)" == "Linux" ]]; then
        echo 1
        return
    fi

    echo 0
}

SET="set"
GET="get"
CFLAGS=""
if [[ "$(is_linux)" == "1" ]]; then
    CFLAGS="-lrt"
fi

cc ${SET}.c -o ${SET} ${CFLAGS}
cc ${GET}.c -o ${GET} ${CFLAGS}

./${SET} &
sleep 1
./${GET}
if [[ "$(is_linux)" == "1" ]]; then
    echo "/dev/shm:"
    ls -l /dev/shm
fi
sleep 1

rm ${SET} ${GET}
