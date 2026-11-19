#! /usr/bin/env bash

tmpfile="/tmp/bytedump-tmp"

file=$1
while IFS= read -r line; do
    for ((i=0; i<${#line}; i+=2)); do 
        echo "offset:"$((i/2))
        subline=$(echo "${line:i}")
        bytes=$(echo $subline | sed 's/../\\x&/g')
        echo -ne $bytes > $tmpfile
        objdump  -D -b binary -m i386:x86-64 $tmpfile
    done
done < $file

