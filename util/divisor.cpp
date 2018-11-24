// Function to print the divisors 
void printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    for (int i=1; i*i<= n ; i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                printf("%d ", i); 
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    } 
} 
   Time Complexity : O(sqrt(n))
   Auxiliary Space : O(1)
   the output is not in a sorted fashion
   
   FOR prime divisors only -> go to prime.cpp prime factorization
