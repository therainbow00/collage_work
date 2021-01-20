
# a >= 0, b > 0

a0 = 6475566067978806192067593014888500403734149837672028290697869
b0 = 2248165830212856236971484909139735123

a = a0
b = b0
r = a % b
steps = 0
while r > 0:
    a = b
    b = r
    r = a % b
    steps += 1
print(b)
print(a0 % b)
print(b0 % b)
print("num of steps = ", steps )
