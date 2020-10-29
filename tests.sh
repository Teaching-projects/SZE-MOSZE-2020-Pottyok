#!/bin/bash
expected="units/expected.txt"
results="results.txt"

while IFS= read line
do
    if [[ $line =~ ";" ]]; then
        scenario=`echo "$line" | cut -d ';' -f 1`
        output="$(./output $scenario)"
        echo "$scenario;" >> $results;
        echo "$output" >> $results;
    fi

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
