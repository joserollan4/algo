// given an integer n, return the right-most nonzero digit of n!
int bpow(int a, int b) { // take*
    if (b == 0) return 1;
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % 10;
        }    
        a = a * a % 10;
        b >>= 1;
    }   
    return res;
}   

int nonzero(int n) {
  if (n == 0) {
    return 1;
  }  else if (n == 1) {
    return 1;
  }  else if (n == 2) {
    return 2;
  }  else if (n == 3) {
    return 6;
  }  else if (n == 4) {
    return 4;
  }  else {
    int A = n/5, B = n%5;
    return (bpow(2,A) * nonzero(A) * nonzero(B)) % 10; 
  }  
}
