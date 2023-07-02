#!/usr/bin/python3
import sys

def is_prime(number):
  if number <= 1:
    return False
  for i in range(2, int(number ** 0.5) + 1):
    if number % i == 0:
      return False
  return True

file = open(sys.argv[1], "r")
readed = file.read().split("\n")
for line in readed:
    if line == "":
        break
    line = int(line)
    for q in range(2, line):
        if not is_prime(q):
            continue
        if line % q == 0:
            p = line // q
            if not is_prime(p):
                continue
            print(f"{line}={p}*{q}")
            break
