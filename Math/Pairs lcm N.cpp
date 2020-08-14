long long solve(long long n) { // number of pairs (i,j) where lcm = n
    long long result = 1;
    for (long long i = 2; i * i <= n; i++) {
        int e = 0;
        if(n % i == 0) {
            while(n % i == 0) e++, n /= i;
            result*= (2*e + 1);
        }
    }
    if(n > 1) result*=(2 + 1);
    return (result + 1)/2;
}
