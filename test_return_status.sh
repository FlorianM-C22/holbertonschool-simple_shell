#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 <shell_executable>"
	exit 1
fi

echo "       " | ./$1 >/dev/null 2>&1
echo "\"       \"" $? "the result should be 0"
echo " "
echo "ls" | ./$1 >/dev/null 2>&1
echo "\"ls\"" $? "the result should be 0"
echo " "
echo "ls /aaaaaa" | ./$1 >/dev/null 2>&1
echo "\"ls /aaaaaaa\"" $? "the result should be 2"
echo " "
echo "thiscommanddoesntexist" | ./$1 >/dev/null 2>&1
echo "\"thiscommanddoesntexist\"" $? "the result should be 127"
echo " "
echo "exit" | ./$1 >/dev/null 2>&1
echo "\"exit\"" $? "the result should be 0"
echo " "
echo "/bin/ls /var" | ./$1 >/dev/null 2>&1
echo "\"/bin/ls /var\"" $? "the result should be 0"
