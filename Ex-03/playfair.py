def generate_key_square(key):
    key = key.replace("J", "I").upper()  # Replace 'J' with 'I' and convert to uppercase
    key_square = []
    used_chars = set()

    for char in key:
        if char not in used_chars and char.isalpha():
            key_square.append(char)
            used_chars.add(char)

    for char in "ABCDEFGHIKLMNOPQRSTUVWXYZ":  # 'J' is omitted
        if char not in used_chars:
            key_square.append(char)
            used_chars.add(char)

    return key_square

def find_position(char, key_square):
    index = key_square.index(char)
    row = index // 5
    col = index % 5
    return row, col

def playfair_encrypt(plaintext, key):
    key_square = generate_key_square(key)
    plaintext = plaintext.replace("J", "I").upper()
    plaintext_pairs = []
    i = 0

    while i < len(plaintext):
        a = plaintext[i]
        b = plaintext[i + 1] if i + 1 < len(plaintext) else "X"

        if a == b:
            b = "X"

        plaintext_pairs.append((a, b))
        i += 2 if a != b else 1

    ciphertext = ""

    for a, b in plaintext_pairs:
        row1, col1 = find_position(a, key_square)
        row2, col2 = find_position(b, key_square)

        if row1 == row2:
            ciphertext += key_square[row1 * 5 + (col1 + 1) % 5]
            ciphertext += key_square[row2 * 5 + (col2 + 1) % 5]
        elif col1 == col2:
            ciphertext += key_square[((row1 + 1) % 5) * 5 + col1]
            ciphertext += key_square[((row2 + 1) % 5) * 5 + col2]
        else:
            ciphertext += key_square[row1 * 5 + col2]
            ciphertext += key_square[row2 * 5 + col1]

    return ciphertext

def playfair_decrypt(ciphertext, key):
    key_square = generate_key_square(key)
    ciphertext_pairs = []
    i = 0
    while i < len(ciphertext):
        a = ciphertext[i]
        b = ciphertext[i + 1] if i + 1 < len(ciphertext) else "X"
        ciphertext_pairs.append((a, b))
        i += 2

    plaintext = ""

    for a, b in ciphertext_pairs:
        row1, col1 = find_position(a, key_square)
        row2, col2 = find_position(b, key_square)

        if row1 == row2:
            plaintext += key_square[row1 * 5 + (col1 - 1) % 5]
            plaintext += key_square[row2 * 5 + (col2 - 1) % 5]
        elif col1 == col2:
            plaintext += key_square[((row1 - 1) % 5) * 5 + col1]
            plaintext += key_square[((row2 - 1) % 5) * 5 + col2]
        else:
            plaintext += key_square[row1 * 5 + col2]
            plaintext += key_square[row2 * 5 + col1]

    return plaintext


key = input("Enter key: ")
plaintext = input("Enter PlainText: ")
ciphertext = playfair_encrypt(plaintext, key)
decrypted_text = playfair_decrypt(ciphertext, key)

print(f"Key: {key}")
print(f"Plaintext: {plaintext}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted Text: {decrypted_text}")

