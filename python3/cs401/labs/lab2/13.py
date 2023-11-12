#!/usr/bin/env python3

import json, re
from lab import lab

with open("me.json", "r") as f:
    data = f.read()

me = json.loads(data)

a, b, c = me["account"][-2:], me["birthMonth"], me["birthDay"]

r = rf"^({a}|{b}|{c} )"
r = re.compile(r, re.I)

start = 1
end = 0

print("Number of matches:", lab(r, start, end))
