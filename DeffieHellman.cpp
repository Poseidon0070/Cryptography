#include <bits/stdc++.h>
#define int long long
using namespace std;

int binpow(int a,int b,int M){
    if(b == 0) return 1;
    int p = binpow(a,b/2,M)%M;
    if(b&1) return (((p*p)%M)*a)%M; 
    return (p*p)%M;
}

signed main()
{
    int p,g;
    cout << "Enter the prime number accepted by both parties : ";
    cin >> p;
    cout << "Enter the root modulo accepted by both parties : ";
    cin >> g;

    int a,b;
    cout << "Enter the private key of A : ";
    cin >> a;
    cout << "Enter the private key of B: ";
    cin >> b;

    // Creating public key
    int A,B;
    A = binpow(g,a,p) % p;
    B = binpow(g,b,p) % p;

    // Sending A to Bob and B to Alice
    // Calculating Secret key K

    int K1,K2;
    K1 = binpow(B,a,p) % p;
    K2 = binpow(A,b,p) % p;

    cout << "Secret Key\n" << "k1 : " << K1 << "\nk2 : " << K2 << "\n";
    return 0;
}