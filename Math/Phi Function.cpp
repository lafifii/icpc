//phi(ab) = phi(a)*phi(b)*(d/phi(d))
//    d = gcd(a, b)
long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if(n > 1) result -= result / n;
    return result;
}
