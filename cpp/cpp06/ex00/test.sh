#!/bin/bash

while read line; do echo ""; echo "[input] $line"; echo "[output]"; ./convert "$line"; done < test_ch > test_ch_result
while read line; do echo ""; echo "[input] $line"; echo "[output]"; ./convert "$line"; done < test_int > test_int_result
while read line; do echo ""; echo "[input] $line"; echo "[output]"; ./convert "$line"; done < test_flt > test_flt_result