// SPOJ VFMUL - AC
// http://www.spoj.com/problems/VFMUL/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

#define MAXN (1<<20)

// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
//#define MOD 2305843009255636993
//#define RT 5
// struct for FFT, for NTT is simple (ll with mod operations)
struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0); // FFT
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
//CD root(int n, bool inv){ // NTT
//	ll r=pm(RT,(MOD-1)/n); // pm: modular exponentiation
//	return CD(inv?pm(r,MOD-2):r);
//}
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n; // FFT
	//if(inv){ // NTT
	//	CD z(pm(n,MOD-2)); // pm: modular exponentiation
	//	fore(i,0,n)a[i]=a[i]*z;
	//}
}
vector<int> multiply(vector<int>& p1, vector<int>& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	vector<int> res;
	n-=2;
	fore(i,0,n)res.pb((ll)floor(cp1[i].real()+0.5)); // change for NTT
	return res;
}

char s[MAXN],t[MAXN],r[MAXN];

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		vector<int> a,b,c;
		scanf("%s%s",s,t);
		for(int i=0;s[i];++i)a.pb(s[i]-'0');reverse(a.begin(),a.end());
		for(int i=0;t[i];++i)b.pb(t[i]-'0');reverse(b.begin(),b.end());
		c=multiply(a,b);
		while(!c.empty()&&!c.back())c.pop_back();
		if(c.empty()){puts("0");continue;}
		int n=0;
		ll x=0;
		fore(i,0,c.size()){
			x+=c[i];
			r[n++]=x%10;
			x/=10;
		}
		while(x){
			r[n++]=x%10;
			x/=10;
		}
		reverse(r,r+n);
		bool p=false;
		fore(i,0,n){
			putchar(r[i]+'0');
		}
		puts("");
	}
	return 0;
}
