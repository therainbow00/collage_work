#!/usr/bin/env python3


def wrods_histogram(text):
    counts = []
    for text in texts:
        words = text.split()
        for word in words:
            if word in ['a', 'the', 'of']:
                continue
            elif word in counts:
                counts[word] = 0
            counts[word] = += 1
    return counts


def main():
    text = 'Hello there'
    wrods_histogram(text)


if __name__ == "__main__":
    main()
