#!/bin/bash
expected="units/expected.txt"
results="results.txt"

while IFS= read line
do
    ent1=`echo "$line" | cut -d ';' -f 1`
    ent2=`echo "$line" | cut -d ';' -f 2`
    outcome=`echo "$line" | cut -d ';' -f 3`

    output="$(./output units/$ent1.json units/$ent2.json)"
    echo "$ent1;$ent2;$output" >> $results
done < "$expected"

echo "Expected OUTPUT"
cat $expected
echo "Real OUTPUT"
cat $results

different="$(diff $expected $results)"

if [ -z "$different" ]; then
    echo "Successful test."
    exit 0
else
    echo "Unsuccessful test."
    exit 1
fi
