#!/bin/bash
# USAGE: ./stretch_demo ORIGINAL_TEXT P STRETCH_LEN

SEED=178

echo -e "\x1b[1;33mOriginal text:\x1b[0m\n"
cat $1

echo -e "\x1b[1;33m\nWithout encoding:\x1b[0m\n"
./scramble $2 $SEED < $1

echo -e "\x1b[1;33m\nWith encoding:\x1b[0m\n"
./stretch $3 < $1 | ./scramble $2 $SEED | ./stretch $3 --decode
