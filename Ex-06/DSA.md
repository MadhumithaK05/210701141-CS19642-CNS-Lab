# IMPLEMENT THE SIGNATURE SCHEME USING DSA
## AIM:
To write a C program to implement a digital signature scheme.
## ALGORITHM:
1. Get the prime number p and its divisor q from the user.
2. Get the value of h from the user.
3. Compute the value of g.
4. Get the private key xa from the user.
5. Compute the user&#39;s public key y.
6. Get the per-message secret key k and hash value of message M.
7. Compute the value of z using g, k &amp; p
8. Compute z % q to get the value of r
9. Compute the multiplicative inverse.
10. Compute the value of s.
11. Print the signature (r, s).
