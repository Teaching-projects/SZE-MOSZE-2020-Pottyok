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
    del listOfLineExpected[:2]

    actualRawText = subprocess.check_output("echo 'east' | .././output " + scenario, text=True, shell=True)
    listOfLinesActual = actualRawText.splitlines(keepends=True)
    print("The Expected OUTPUT")
    print(listOfLineExpected)
    print("The Actual OUTPUT")
    print(listOfLinesActual)
    if listOfLineExpected == listOfLinesActual: 
        print("they are indetical") 
        os._exit(0)
    else: 
        print("not identical") 
        exit(1)
