import os
import subprocess

expected_file = "expected.txt"

scenario = ""
actualRawText = ""
listOfLinesActual = []
listOfLineExpected = []
with open(expected_file, 'r', encoding="UTF-8") as e_file:
    scenario = e_file.readline().replace(';','').strip()
    e_file.readline()

    listOfLineExpected = e_file.readlines()
    del listOfLineExpected[:1]

    actualRawText = subprocess.check_output("cd ../ && echo 'east' | ./output " + scenario, shell=True).decode("UTF-8")
    listOfLinesActual = actualRawText.splitlines(keepends=True)
    print("The Expected OUTPUT")
    print("".join(listOfLineExpected).encode("UTF-8"))
    print("The Actual OUTPUT")
    print("".join(listOfLinesActual).encode("UTF-8"))
    if listOfLineExpected == listOfLinesActual: 
        print("they are indetical") 
        os._exit(0)
    else: 
        print("not identical") 
        exit(1)
