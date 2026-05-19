def xor_crypt(text, key):
    return [ord(c) ^ key for c in text]

print("Encoded:", xor_crypt("Secret", 42))
