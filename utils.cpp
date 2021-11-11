class Utils {
public:
    class Numbers {
    public:
        int static gcd (int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
        int static gcdex (int a, int b, int &x, int &y) {
            if (b == 0) {
                x = 1; y = 0;
                return a;
            }
            int x1, y1;
            int d = gcdex(b, a % b, x1, y1);
            x = y1;
            y = x1 - (a / b) * y1;
            return d;
        }
        int static inverse (int a, int m) {
            int x, y;
            int g = Utils::Numbers::gcdex(a, m, x, y);
            assert(g == 1);
            return (x % m + m) % m;
        }
        int static bin_pow (int a, int b, int m) {
            int res = 1;
            while (b) {
                if (b & 1)
                    res = res * a % m;
                a = a * a % m;
                b >>= 1;
            }
            return res;
        }
        int static g (int n) {
            return n ^ (n >> 1);
        }
        int static rev_g (int n) {
            int f = 0;
            for (; n; n >>= 1) f ^= n;
            return f;
        }
        int static phi (int n) {
            int f = n;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    while (n % i == 0) n /= i;
                    f -= f / i;
                }
            }
            if (n > 1) f -= f / n;
            return f;
        }
    };
    class Combinatoric {
    public:
        int maxn, mod;
        vc <int> fact, inv;
        Combinatoric(int maxn, int mod = 1e9 + 7): maxn(maxn), mod(mod) {
            fact.resize(maxn + 1);
            inv.resize(maxn + 1);
            fact[0] = fact[1] = 1;
            for (int i = 2; i <= maxn; ++i) {
                fact[i] = fact[i - 1] * i % mod;
            }
            inv[maxn] = Utils::Numbers::inverse(fact[maxn], mod);
            for (int i = maxn; i >= 1; --i) {
                inv[i - 1] = inv[i] * i % mod;
            }
        }
        int C (int n, int k) {
            return fact[n] * inv[k] % mod * inv[n - k] % mod;
        }
        int F (int n) {
            return fact[n];
        }
        int InvF (int n) {
            return inv[n];
        }
    };
};
Utils::Combinatoric Comb(1e5);
