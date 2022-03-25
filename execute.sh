#!/bin/bash

clear
cp -r data/ build/data/
cd build/
cmake ..
if eval cmake --build .; then
    if [ "$#" -ge 1 ]; then
	exec "./ColonialSpace" "$1"
    else
	exec "./ColonialSpace"
    fi
    cd ..
else
    cd ..
fi
    
