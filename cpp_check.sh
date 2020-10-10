#!/bin/bash

cppcheck --enable=all ./*.cpp 2> cppcheck_report.txt

if grep -q "warning:" "./cppcheck_report.txt"; then
  exit 1
fi

if grep -q "error:" "./cppcheck_report.txt"; then
  exit 1 
fi