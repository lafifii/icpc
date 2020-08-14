const double EM =  0.5772156649015328606065;		//Euler-Mascheroni constant
const double E = 2.7182818284590452354; 		//Euler's constant
const double goldRatio = 1.6180339887498948482; 	//Golden ratio
const double pi = 3.1415926535897932385;		//Pi

double HarmonicNumber(long long N){ 			// H(N) = H(N-1) + 1/N
	if (N<=1e4) return Harmonic[n]; 		//Precompute for small N (recommend N<=1e4)
	return log(N) + EM + (1.00/double(N+N)) - (1.00/double(12ll*N*N)); 
}
