"Modular Operations"
// x is INVERSE of a in mod m.  -> ax = 1 (mod m)
// x exist iff gcd(a,m) = 1

// Extended Euclidean Algorithm  O(logm)
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
	{ 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

// Recursive - function to find modulo inverse of a  
void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else{ 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 
 
______________________________________________________

//for modular multiplication without any overflow 
// To compute (a * b) % mod 
int mul(int a, int b) 
{ 
    ll res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % MOD; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % MOD; 
  
        // Divide b by 2 
        b /= 2; 
    } 
    // Return result 
    return res % MOD; 
} 
_________________________________________________

//for modular addition without any overflow 
int add(int x, int y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
________________________________________________

// Find even-odd without using mod
if (num & 1)
   cout << "ODD";
else
   cout << "EVEN";
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
