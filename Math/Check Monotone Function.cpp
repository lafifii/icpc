enum monotonic_e {
    MONOTONIC_INCREASE, /* function is monotonically increasing */
    MONOTONIC_DECREASE, /* function is monotonically decreasing */
    MONOTONIC_CONSTANS, /* function is constant */
    MONOTONIC_NOT       /* function is not monotonic */   
};
double sign(double x) {
    return x < 0 ? -1. : (x > 0 ? 1. : 0.);
}
monotonic_e monotonic(const function< double(double) >& f,
                      double a, double b, double eps) {
    double x = a, y1 = f(x), y2 = f(x + eps);
    double d = y2 - y1;
    double s = sign(d);
    while( x < b ) {
        x += eps;
        y1 = y2;
        y2 = f(x + eps);
        d = y2 - y1;
        if( s == 0. ) {
            s = sign(d);
        }
        if( s * d < 0 ) {
            return MONOTONIC_NOT;
        }
    }
    return s > 0 ? MONOTONIC_INCREASE :
          (s < 0 ? MONOTONIC_DECREASE :
                   MONOTONIC_CONSTANS);
}
