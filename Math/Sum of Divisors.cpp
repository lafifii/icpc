long long numdiv(long long n) { 
    long long result = 1;
    for (long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
        	int e = i;
            while(n % i == 0) e*=i, n /= i;
            result*= (e - 1)/(i - 1);
        }
    }
    if(n > 1) result*= (n*n - 1)/(n - 1);
    return result;
}
