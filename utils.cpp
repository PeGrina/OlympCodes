class Utils {
public:
    class Modular {
    private:
        int n, md;
    public:
        Modular (): n(0), md(mod){}
        Modular (int n): md(mod) {
            this->n = normalize(n);
        }
        Modular (int n, int md): md(md) {
            this->n = normalize(n);
        }
        int normalize (int x) {
            if (abs(x) >= md) x %= md;
            if (x < 0) return x + md;
            return x;
        }
        Modular& operator = (int &x) {
            this->n = normalize(x);
            return *this;
        }
        Modular& operator += (const Modular &b) {return *this = *this + b;}
        Modular& operator -= (const Modular &b) {return *this = *this - b;}
        Modular& operator *= (const Modular &b) {return *this = *this * b;}
        Modular& operator /= (const Modular &b) {return *this = *this / b;}
        friend const Modular operator + (const Modular &a, const Modular &b) {
            assert(a & b);
            return Modular(a.n + b.n, a.md);
        }
        friend const Modular operator - (const Modular &a, const Modular &b) {
            assert(a & b);
            return Modular(a.n - b.n, a.md);
        }
        friend const Modular operator * (const Modular &a, const Modular &b) {
            assert(a & b);
            return Modular(a.n * b.n, a.md);
        }
        friend const Modular operator / (const Modular &a, const Modular &b) {
            assert(a & b);
            return Modular(a.n * Utils::Numbers::inverse(b.n, b.md), a.md);
        }
        friend ostream& operator << (ostream &os, const Modular& b) {
            return os << b.n;
        }
        friend istream& operator >> (istream &os, Modular& b) {
            os >> b.n;
            b = Modular(b.n, b.md);
            return os;
        }
        bool operator == (const Modular &b) const {
            return n == b.n;
        }
        bool operator != (const Modular &b) const {
            return !(*this == b);
        }
        friend bool operator & (const Modular &a, const Modular &b) {
            return a.md == b.md;
        }
    };
    class Numbers {
    public:
        using mint = Utils::Modular;
        int static gcd (int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
        int static lcm (int a, int b) {
            if (a == 0 && b == 0) return 0;
            return a / Utils::Numbers::gcd(a, b) * b;
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
        mint static bin_pow (mint a, int b, int m) {
            mint res(1, m);
            while (b) {
                if (b & 1)
                    res *= a;
                a *= a;
                b >>= 1;
            }
            return res;
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
        using mint = Utils::Modular;
        int maxn, mod;
        vc <mint> fact, inv;
        Combinatoric(int maxn, int mod = 1e9 + 7): maxn(maxn), mod(mod) {
            fact.resize(maxn + 1, mint(0, mod));
            inv.resize(maxn + 1, mint(0, mod));
            fact[0] = fact[1] = mint(1, mod);
            for (int i = 2; i <= maxn; ++i) {
                fact[i] = fact[i - 1] * mint(i, mod);
            }
            inv[maxn] = mint(1, mod) / fact[maxn];
            for (int i = maxn; i >= 1; --i) {
                inv[i - 1] = inv[i] * mint(i, mod);
            }
        }
        mint C (int n, int k) {
            if (k > n) return 1;
            if (k == 0) return 1;
            return fact[n] * inv[n - k] * inv[k];
        }
        mint F (int n) {
            return fact[n];
        }
        mint InvF (int n) {
            return inv[n];
        }
    };
    class bitset {
    private:
        using T = unsigned long long;
        T SZ = 6;
        T base = 1ll << SZ;
        T mod = base - 1;
        T n;
    public:
        vc <T> t;
        bitset (T n) {
            this->n = n;
            t.resize((n + base - 1) / base);
        }
        T operator [](T i) {
            return t[i >> SZ] & (1 << (i & mod));
        }
        void set (T i, T val) {
            if ((*this)[i] == val) return;
            t[i >> SZ] ^= 1 << (i & mod);
        }
    };
    class Geometric {
    public:
        /* Point (and vector) */
        class pt {
        public:
            ld x, y;
            int i = -1;
            pt (ld x = 0, ld y = 0, int i = -1): x(x), y(y), i(i){}
            pt operator - () const {return pt(-x, -y);}
            pt operator + (pt &b) const {return pt(x + b.x, y + b.y);}
            pt operator - (pt &b) const {return pt(x - b.x, y - b.y);}
            pt& operator = (pt &b) {this->x = b.x, this->y = b.y;}
            ld operator * (pt &b) const {return x * b.x + y * b.y;}
            ld operator ^ (pt &b) const {return x * b.y - b.x * y;}
            bool operator == (pt &b) const {return x == b.x && y == b.y;}
            bool operator != (pt &b) const {return !(*this == b);}
            bool operator < (pt &b) const {return x == b.x ? y < b.y : x < b.x;}
            bool operator <= (pt &b) const {return *this < b || *this == b;}
            bool operator > (pt &b) const {return !(*this <= b);}
            bool operator >= (pt &b) const {return *this > b || *this == b;}
            friend ostream& operator << (ostream &os, pt &a) {return os << a.x << ' ' << a.y;}
            friend istream& operator >> (istream &os, pt &a) {return os >> a.x >> a.y;}
            ld operator [](int j) {return j == 0 ? x : y;}
            ld angle () {
                if (x == 0 && y == 0) return -1;
                if (x == 0)
                    return y > 0 ? 90 : 270;
                ld t = atan(y / x) * (360 );
                if (x > 0)
                    return y >= 0 ? t : t + 360;
                return t + 180;
            }
            ld len_sq () {return x * x + y * y;}
            ld length () {return sqrtl(this->len_sq());}
        };
        using pt = Utils::Geometric::pt;
        ld orientation (pt a, pt b, pt c) {
            pt ab = b - a, ac = c - a;
            ld sa = ab ^ ac;
            if (sa > 0) return 1;
            if (sa == 0) return 0;
            if (sa < 0) return -1;
        }
    };
    class SegTree {
    private:
        vc <int> a;
        int n;
        struct item {
            int sum = 0;
            void upd (int x) {
                sum = x;
            }
            friend item operator + (item a, item b) {
                item c;
                c.sum = a.sum + b.sum;
                return c;
            }
        };
        struct node {
            node *l, *r;
            item t;
            node () {
                l = r = nullptr;
            }
            void upd (int x) {
                t.upd(x);
            }
        };
        node *root;
        void create (node *&t) {
            if (!t) t = new node;
        }
        void apply (node *t) {
            t->t = t->l->t + t->r->t;
        }
        void build (node *t, int tl, int tr) {
            create(t);
            if (tr - tl == 1) {
                t->upd(a[tl]);
                return;
            }
            int tm = (tl + tr) >> 1;
            build(t->l, tl, tm);
            build(t->r, tm, tr);
            apply(t);
        }
        void update (node *t, int tl, int tr, int pos, int val) {
            if (tr - tl == 1) {
                t->upd(val);
                return;
            }
            int tm = (tl + tr) >> 1;
            if (pos < tm) update(t->l, tl, tm, pos, val);
            else update(t->r, tm, tr, pos, val);
            apply(t);
        }
        item get (node *t, int tl, int tr, int l, int r) {
            if (r <= tl || tr <= l) return {0};
            if (l <= tl && tr <= r) return t->t;
            int tm = (tl + tr) >> 1;
            return get(t->l, tl, tm, l, r) + get(t->r, tm, tr, l, r);
        }
    public:
        SegTree(vc <int> &a) {
            this->n = sz(a);
            this->a = a;
            root = new node;
            build(root, 0, n);
        }
        void upd (int i, int v) {
            this->update(root, 0, n, i, v);
        }
        /* [l, r) */
        int get (int l, int r) {
            return this->get(root, 0, n, l, r).sum;
        }
    };
};
