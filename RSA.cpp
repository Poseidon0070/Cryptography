#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}

double find(int phi){
    for(int i = phi-1;i >= 1; i--){
        if(gcd(phi,i) == 1) return i;
    }
}

int main()
{
    double p1,p2;
    cout << "Enter the first prime number p1 : ";  // 13
    cin >> p1; 
    cout << "Enter the second prime number p2 : ";  // 11
    cin >> p2;

    // calculating value of n
    double n = p1 * p2;

    // calculating the phi value of n;
    double phi = (p1-1) * (p2-1);

    // calculating value of e : 1 <= e < phi && gcd(e,p) = 1; i.e., e and phi(n) are coprime.
    double e = find(phi);

    // find d such that e * d = 1 mod phi 
    double d = fmod((double)1/e,phi);

    double M;
    cout << "Enter value for message M : ";
    cin >> M;

    // Encryption
    double a = pow(M,e);
    double E = fmod(a,n);
    // Decryption
    double b = pow(a,d);
    double D = fmod(b,n);

    cout << "Original Message : " << M << "\n";
    cout << "Encrypted Message : " << E << "\n";
    cout << "Decrypted Message : " << D << "\n";
    return 0;
}