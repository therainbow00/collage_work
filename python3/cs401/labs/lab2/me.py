#!/usr/bin/env python3

import json
me = {
    "first": "Matthew",
    "last": "Mokrzycki",
    "account": "cs40115",
    "birthMonth": 4,
    "birthDay": 27
}

json_object = json.dumps(me, indent = 4)
with open("me.json", "w") as outfile:
    outfile.write(json_object)
