#!/bin/bash

OUTPUT_FILE="main"

CC="gcc"
FILE="$1"
OUTPUT="-o $OUTPUT_FILE"

set -xe
$CC $FILE $OUTPUT
./$OUTPUT_FILE
rm $OUTPUT_FILE
