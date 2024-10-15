#!/bin/bash

libs="-luser32 -lopengl32 -lgdi32 "
warnings=-Wno-writable-strings
includes="-Ithird_party -Ithird_party/include"

clang++ $includes -g src/main.cpp -oschnitzel.exe $libs $warnings