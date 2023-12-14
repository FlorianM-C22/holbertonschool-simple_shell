#!/bin/bash
echo "=== GENERAL ==="
echo
echo "---Typing special characters---"
echo
echo "echo {{[~#{}]}}" | ./shell
echo
echo "=== COMMANDS ==="
echo
echo "--- ls ---"
echo
echo "/bin/ls" | ./shell
echo
echo "--- cat ---"
echo
echo "/bin/cat betty" | ./shell
echo
echo "--- pwd ---"
echo
echo "/bin/pwd" | ./shell
