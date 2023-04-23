#!/bin/bash

OUTPUT_FILE="main"

CC="gcc"
FILE="$1"
OUTPUT="-o $OUTPUT_FILE"
CFLAGS='-std=c89'

set -xe
$CC $FILE $OUTPUT $CFLAGS
./$OUTPUT_FILE
rm $OUTPUT_FILE
