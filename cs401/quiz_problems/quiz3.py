#!/usr/bin/env python3
assignments = ["quiz1", "quiz2", "lab1"]
grades = [88.3, 92.8, 93.1]

print({(k, v + 5) for k in assignments for v in grades})
print({assignments[i]: grades[i] + 5 for i in range(len(grades))})
