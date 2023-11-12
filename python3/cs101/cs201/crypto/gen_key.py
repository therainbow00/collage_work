#!/usr/bin/env python3

import random

chrs = []

for i in range(32,127):
    chrs.append(chr(i))
print(chrs)

crypto_key = {}

# for i in range(0, 5 * len(chrs), 5):
#     c = chrs[i]
#     j = (i + 1) % len(chrs)
#     c2 = chrs[j]
#     print(c, c2)
#     crypto_key[c] = c2

random_chrs = list(chrs)
random.shuffle(random_chrs)

for i in range(len(chrs)):
    c = chrs[i]
    c2 = random_chrs[i]
    crypto_key[c] = c2

# print(crypto_key)
# print(len(crypto_key))

s = ""
for key in crypto_key.keys():
    val = crypto_key[key]
    s += key + val + "\n"
print(s)

f = open("crypto.key", "w")
f.write(s)
f.close()


# li = ["kv", "a!", "~A"].split("\n"
# di = {}


# --------------------------
# argument = sys.argv[1:]

# message = open(argument, "w")
# message.write()
# message.close()

# print(message)
