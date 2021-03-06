#include <bits/stdc++.h>
 
using namespace std;
 
 
 
static struct IO {
	char tmp[1 << 10];
 
	// fast input routines
	char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }
 
	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
	inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }
 
	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
	// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
 
 
 
typedef struct ele {
	int num,two,three,five;
}node;
 
typedef struct element {
	int two,three,five;
}nodeone;
 
#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)
 
#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)
 
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007
 
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;
 
int two[35],three[21],five[15];
int bsize,tot,n,m,tmp,type,L,d,l,r,lb,rb,p;
 
node a[100005];
nodeone block[320];
 
 
void init() {
	five[0] = two[0] = three[0] = 1;
	for (int i = 1; i <= 14; ++i) five[i] = five[i-1]*5;
	for (int i = 1; i <= 20; ++i) three[i] = three[i-1]*3;
	for (int i = 1; i <= 31; ++i) two[i] = two[i-1]*2;
	for (int i = 0; i <= 100001; ++i) a[i].two = a[i].three = a[i].five = 0;
	for (int i = 0; i <= 319; ++i) block[i].two = block[i].three = block[i].five = 0;
	return;
}
 
 
// main code begins now
 
 
int main()
{
	init();
	cin >> n ;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		a[i].num = tmp;
		while(tmp%5 == 0) {
			tmp /= 5;
			a[i].five++;
		}
		while(tmp%2 == 0) {
			tmp /= 2;
			a[i].two++;
		}
		while(tmp%3 == 0) {
			tmp /= 3;
			a[i].three++;
		}
	}
	bsize = ceil(sqrt(n));
	tot = Ceil(n,bsize);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> type;
		if(type == 1) {
			cin >> l >> r >> p;
			lb = Ceil(l,bsize);
			rb = Ceil(r,bsize);
			if(lb == rb) {
				for (int j = l; j <= r; ++j) {
					if(p == 2 && a[j].num % 2 == 0) {
						a[j].num /= 2;
						a[j].two--;
					}
					if(p == 3 && a[j].num % 3 == 0) {
						a[j].num /= 3;
						a[j].three--;
					}
					if(p == 5 && a[j].num % 5 == 0) {
						a[j].num /= 5;
						a[j].five--;
					}
				}
			}
			else {
				for (int j = l; j <= lb*(bsize); ++j) {
					if(p == 2 && a[j].num % 2 == 0) {
						a[j].num /= 2;
						a[j].two--;
					}
					if(p == 3 && a[j].num % 3 == 0) {
						a[j].num /= 3;
						a[j].three--;
					}
					if(p == 5 && a[j].num % 5 == 0) {
						a[j].num /= 5;
						a[j].five--;
					}
				}
				lb++;
				for (int j = r; j >= 1+(rb-1)*(bsize); --j) {
					if(p == 2 && a[j].num % 2 == 0) {
						a[j].num /= 2;
						a[j].two--;
					}
					if(p == 3 && a[j].num % 3 == 0) {
						a[j].num /= 3;
						a[j].three--;
					}
					if(p == 5 && a[j].num % 5 == 0) {
						a[j].num /= 5;
						a[j].five--;
					}
				}
				rb--;
				if(lb <= rb) {
					if(p == 2) {
    					for (int j = lb; j <= rb; ++j) block[j].two++;
					}
					else if(p == 3) {
						for (int j = lb; j <= rb; ++j) block[j].three++;
					}
					else {
						for (int j = lb; j <= rb; ++j) block[j].five++;
					}
				}
			}
		}
		else {
			cin >> L >> d;
			lb = Ceil(L,bsize);
			for (int j = 1 + (lb-1)*(bsize); j <= lb*(bsize); ++j) {
				a[j].num /= two[min(a[j].two,block[lb].two)];
				a[j].two -= min(a[j].two,block[lb].two);
				a[j].num /= three[min(a[j].three,block[lb].three)];
				a[j].three -= min(a[j].three,block[lb].three);
				a[j].num /= five[min(a[j].five,block[lb].five)];
				a[j].five -= min(a[j].five,block[lb].five);
			}
			block[lb].two = block[lb].three = block[lb].five = 0;
			a[L].num = d;
			a[L].two = a[L].three = a[L].five = 0;
			tmp = a[L].num;
			while(tmp % 2 == 0) {
				a[L].two++;
				tmp /= 2;
			}
			while(tmp % 3 == 0) {
				a[L].three++;
				tmp /= 3;
			}
			while(tmp % 5 == 0) {
				a[L].five++;
				tmp /= 5;
			}
		}
	}
	for (int i = 1; i <= tot; ++i) {
		for (int j = 1+(i-1)*bsize; j <= i*bsize && j <= n; ++j) {
			a[j].num /= two[min(a[j].two,block[i].two)];
			a[j].num /= three[min(a[j].three,block[i].three)];
			a[j].num /= five[min(a[j].five,block[i].five)];
		}
	}
	for (int i = 1; i <= n; ++i) cout << a[i].num << " ";
    return 0;
} 
