#!/bin/bash
if ! [ -d "../stress_tests" ]
then
mkdir stress_tests
fi
cd ../stress_tests
cmake ..
make
if ! [ -d "tests/stress_tests/texts" ]
then
mkdir tests/stress_tests/texts
fi
cd tests/utils/
echo "Started file generation"
./file_gen 100000000 221 ./../stress_tests/texts/text.txt
echo "Ended file generation"
cd ../stress_tests/async
async_output=$(./stress_async_test)
echo "Async output is: $async_output"
cd ../sync
sync_output=$(./stress_sync_test)
echo "Sync output is: $sync_output"
if (( $(echo "$async_output > $sync_output" |bc -l) ));
then
  echo "Async is slower, than sync"
else
  echo "Sync is slower, than async"
fi