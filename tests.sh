#!/bin/bash
sudo apt-get install -y valgrind

expected="units/expected.txt"
results="results.txt"

valgrind ./output

while IFS= read line
do
    ent1=`echo "$line" | cut -d ';' -f 1`
    ent2=`echo "$line" | cut -d ';' -f 2`
    outcome=`echo "$line" | cut -d ';' -f 3`

    output="$(./output units/$ent1.json units/$ent2.json)"
    echo "$ent1;$ent2;$output" >> $results
done < "$expected"

different="$(diff $expected $results)"

if grep -q "(warning)" "./cppcheck_report.txt"; then
  exit 1
fi

if grep -q "(error)" "./cppcheck_report.txt"; then
  exit 1 
fi

if [ -z "$different" ]; then
    echo "Successful test."
    exit 0
else
    echo "Unsuccessful test."
    exit 1
fi
