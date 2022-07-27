using cd = complex <double>;
 
const double pi = acos(-1);
 
const BIT = 17; // Uses 2 ^ (BIT + 1) > n
const int N = 1 << mx;
cd w[N + 1];
int ret[N];
 
struct FFT {
    FFT () {
     w[0] = cd(1, 0);
     double tmp = 2 * pi / N;
     w[1] = cd(cos(tmp), sin(tmp));
     for (int i = 2; i <= N; ++i) {
      w[i] = w[i - 1] * w[1];
     }
    }
    vc <cd> fft (vc <cd> &a) {
        int n = sz(a);
        vc <int> rev(n);
        int k = 0;
        int bit = __lg(n);
        for (int i = 1; i < n; ++i) {
            if (i == (2 << k)) ++k;
            rev[i] = rev[i ^ (1 << k)] | (1 << (bit - k - 1));
        }
        vc <vc <cd>> f(2, vc <cd> (n));
        for (int i = 0; i < n; ++i) {
            f[0][i] = a[rev[i]];
        }
        for (int lvl = 0; lvl < bit; ++lvl) {
            int cur = lvl & 1;
            int to = cur ^ 1;
            for (int block = 0; block < n; block += (2 << lvl)) {
                for (int i = 0; i < (1 << lvl); ++i) {
                    int j = i + block;
                    f[to][j] = f[cur][j] + w[i << (BIT - 1 - lvl)] * f[cur][j + (1 << lvl)];
                    f[to][j + (1 << lvl)] = f[cur][j] - w[i << (BIT - 1 - lvl)] * f[cur][j + (1 << lvl)];
                }
            }
        }
        return f[bit & 1];
    }
    vc <int> mul (vc <int> &a, vc <int> &b) {
        vc <cd> a1, b1;
        int k = 1;
        while (k < max(sz(a), sz(b))) {
            k *= 2;
        }
        k *= 2;
        while (sz(a) < k) a.pb(0);
        while (sz(b) < k) b.pb(0);
        for (int i = 0; i < k; ++i) {
            a1.pb(cd(a[i], 0));
            b1.pb(cd(b[i], 0));
        };
        a1 = fft(a1);
        b1 = fft(b1);
        for (int i = 0; i < sz(a1); ++i) {
            a1[i] *= b1[i];
        }
        a1 = fft(a1);
        for (int i = 0; i < sz(a); ++i) {
            a1[i] /= sz(a);
        }
        reverse(a1.begin() + 1, a1.end());
        vc <int> ans;
        for (int i = 0; i < sz(a1); ++i) {
            ret[i] += round(a1[i].real());
        }
        return ans;
    }
};
