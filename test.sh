#!/bin/zsh

filepath=/home/peterm/code/cLuhnCheck/tmp/
input="${filepath}testdata.txt"
valid="${filepath}valid.txt"
invalid="${filepath}invalid.txt"


touch $input

echo "generating numbers to check."
start=$SECONDS
for i in {1..31660024}; do
	echo "$(( $RANDOM % 9999 ))$(( $RANDOM % 9999 ))$(( $RANDOM % 9999 ))$(( $RANDOM % 9999 ))" >> $input
done

duration=$(( SECONDS - start ))
echo "generating numbers took: ${duration} seconds"

start=$SECONDS
echo "chekcing numbers"
./a.out ${input} ${valid} ${invalid}

duration=$(( SECONDS - start ))
echo "checking numbers took: ${duration} seconds"

echo "complete"
