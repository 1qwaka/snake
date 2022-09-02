#!/bin/bash

gcc -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c ./*.c && \
gcc ./*.o -o app.exe -lm && \
./app.exe
