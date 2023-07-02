#!/usr/bin/python3
import sys

file = open(sys.argv[1], "r")
readed = file.read().split("\n")
for line in readed:
    if line == "":
        break
    line = int(line)
    for q in range(2, line):
        if line % q == 0:
            p = line // q
            print(f"{line}={p}*{q}")
            break
