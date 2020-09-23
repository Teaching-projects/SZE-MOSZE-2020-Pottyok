#!/bin/bash

expected="units/expected.txt"
results="results.txt"

if test -f "$results"; then
    rm "$results"
fi

$(g++ -std=c++17 *.cpp -o output)

while IFS= read line
do
    ent1="$(cut -d';' -f1 <<<"$line")"
    ent2="$(cut -d';' -f2 <<<"$line")"
    outcome="$(cut -d';' -f3 <<<"$line")"
    output="$(./output $ent1.json  $ent2.json)"
    echo "$ent1;$ent2;$output" >> $results
done < "$expected"

different="$(diff $expected $results)"

if [ -z "$different" ]; then
    echo "Successful test."
    exit 0
else
    echo "Unsuccessful test."
    exit 1
fi