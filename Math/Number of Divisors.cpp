// mult of (exp + 1) or prime factors
long long numdiv(long long n) { 
    long long result = 1;
    for (long long i = 2; i * i <= n; i++) {
        int e = 0;
        if(n % i == 0) {
            while(n % i == 0) e++, n /= i;
            result*= (e + 1);
        }
    }
    if(n > 1) result*=2;
    return result;
}
