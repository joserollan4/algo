#include "dna.h"
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
 
const int N = 100009;
 
vector<int> A0(N,0), A1(N,0);
vector<int> T0(N,0), T1(N,0);
vector<int> C0(N,0), C1(N,0);
vector<int> AC(N,0), CA(N,0), AT(N,0), TA(N,0), TC(N,0), CT(N,0);
 
void init(string a, string b) {
    int sz = (int)a.size();
    for (int i=0; i<sz; i++) {
        if (i > 0) {
            A0[i] = A0[i - 1];
            C0[i] = C0[i - 1];
            T0[i] = T0[i - 1];
        }   
        if (a[i] == 'A') A0[i]++;
        if (a[i] == 'T') T0[i]++;
        if (a[i] == 'C') C0[i]++;
    }
    for (int i=0; i<sz; i++) {
        if (i > 0) {
            A1[i] = A1[i - 1];
            C1[i] = C1[i - 1];
            T1[i] = T1[i - 1];
        }   
        if (b[i] == 'A') A1[i]++;
        if (b[i] == 'T') T1[i]++;
        if (b[i] == 'C') C1[i]++;
    }    
    for (int i=0; i<sz; i++) {
        if (i > 0) {
            AC[i] = AC[i - 1];
            CA[i] = CA[i - 1];
            CT[i] = CT[i - 1];
            TC[i] = TC[i - 1];
            AT[i] = AT[i - 1];
            TA[i] = TA[i - 1];
        }    
        if (a[i] == 'A' && b[i] == 'C') AC[i]++;
        if (a[i] == 'C' && b[i] == 'A') CA[i]++;
        if (a[i] == 'C' && b[i] == 'T') CT[i]++;
        if (a[i] == 'T' && b[i] == 'C') TC[i]++;
        if (a[i] == 'A' && b[i] == 'T') AT[i]++;
        if (a[i] == 'T' && b[i] == 'A') TA[i]++;
    }   
}   
 
int get_distance(int x, int y) {
    int ans = 0;
 
    bool yes = true;
    if (x == 0) {
        if ((A0[y] != A1[y]) || (T0[y] != T1[y]) || (C0[y] != C1[y])) yes = false;
    }   
    else {
        if ((A0[y] - A0[x-1] != A1[y] - A1[x-1]) || (T0[y] - T0[x-1] != T1[y] - T1[x-1]) || (C0[y] - C0[x-1] != C1[y] - C1[x-1])) yes = false;
    }   
    
    int ac, ca, at, ta, ct, tc;
    if (x == 0) {
        ac = AC[y], ca = CA[y];
        at = AT[y], ta = TA[y];
        ct = CT[y], tc = TC[y];
    }   
    else {
        ac = AC[y] - AC[x-1], ca = CA[y] - CA[x-1];
        at = AT[y] - AT[x-1], ta = TA[y] - TA[x-1];
        ct = CT[y] - CT[x-1], tc = TC[y] - TC[x-1];
    }
    
    int a = min(ac,ca);
    int b = min(at,ta);
    int c = min(ct,tc);
    ans = ans + a + b + c;
    ac -= a;
    ca -= a;
    at -= b;
    ta -= b;
    ct -= c;
    tc -= c;
    
    int d = min(ac,min(ta,ct));
    ans = ans + (2*d);
    ac -= d;
    ta -= d;
    ct -= d;
    
    int e = min(ca,min(at,tc));
    ans = ans + (2*e);
    ca -= e;
    at -= e;
    tc -= e;
    
    
    
    if (yes) {
        return ans;
    }   
    else {
        return -1;
    }   
}   
