const long long M = 1000000007;

long long modexp(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % M;
        b >>= 1;
        a = (a*a) % M;
    }
    return res;
}

