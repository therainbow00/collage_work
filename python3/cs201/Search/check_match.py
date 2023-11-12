#!/usr/bin/env python3

def check_match(data, index, pattern):
    for i in range(len(pattern)):
        if pattern[i] != data[index + i]:
            return False
    return True


if __name__ == "__main__":
    print(f"Running test for \"{__file__}\"...")

    print(check_match("data", 1, "ata"), "Should be True")
    print(check_match("date", 1, "ata"), "Should be False")
    print(check_match("ratatat", 1, "ata"), "Should be True")
    print(check_match("ratatat", 3, "ata"), "Should be True")
    # print(check_match("rat", 1, "ata"), "Should be False")
