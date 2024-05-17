# RSA Algorithm

## AIM:
To write a program to implement RSA cryptosystem.
## ALGORITHM:
1. Select two large prime numbers p and q
2. Compute n=p*q
3. Choose system modulus: Ø(n)=(p-1)*(q-1)
4. Select a random encryption key e such that gcd(e,Ø(n))=1
5. Decrypt by computing de=1 mod Ø(n)
6. Print the public key{e,n}
7. Print the private key{d,n}
8. Do the encryption and decryption
- Encryption is given as, c = t^ e mod n
- Decryption is given as, t = c ^d mod n
