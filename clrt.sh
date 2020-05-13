#! /bin/bash

rm -rf *.o
for i in "$@"
do
  gcc -c $i
done

gcc -c *.c
gcc -o main *.o
./main
rm -rf *.o main