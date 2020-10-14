#!/usr/bin/env python3

import crypto_util

# Get Key Data
key_data = crypto_util.readfile("crypto_key")

# Parse Key Data into dict
crypto_key = crypto_key.parse2CharCryptoString(key_data)

# Get the Message Data
message_data = crypto_util.readfile("message.txt")

# Encrypt
results = crypto_util.dictionaryTranslator(message_data, crypto_key)

# Output to File
crypto_util.writefile("encrypted.txt")
