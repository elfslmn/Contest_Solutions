"LONGEST COMMON SUBSTRING" DP - O(m*n)

Create a table to store lengths of longest common suffixes of substrings.
The first row and first column entries have no logical meaning, they are used only  simplicity of program

// mat[i][j] contains length of lcsstr of a[0..i-1] and b[0..j-1] if a[i-1] == b[j-1], 0 otherwise
int mat[m+1][n+1];
int len = 0;  // To store length of the longest common substring
int row, col; // index of last char matched in table

//Following steps build mat[m+1][n+1] in bottom up fashion.
for (int i=0; i<=m; i++){
     for (int j=0; j<=n; j++){
         if (i == 0 || j == 0){
             mat[i][j] = 0;
         }

         // If last chars are equal, increase the corner value by one
         else if (a[i-1] == b[j-1])
         {
             mat[i][j] = mat[i-1][j-1] + 1;
             if (len < mat[i][j]) {
                len = mat[i][j];
                row = i;  col = j;
           }
         }
         else mat[i][j] = 0;
     }
}

printf("Length of longest common substr. %d\n", len);

// Print the sequence itself
char str[len+1];
int index = len-1;
while(mat[row][col] != 0){
    str[index--] = a[row-1];
    // move diagonally up to previous cell
    row--;
    col--;
}
str[len] = '\0';
printf("%s\n",str);

// Output for
int m = 6, n=7;
string a="BTXAGX";
string b= "GXTXAYB";

Length of longest common substr. 3
mat:
     G X T X A Y B
 : 0 0 0 0 0 0 0 0
B: 0 0 0 0 0 0 0 1
T: 0 0 0 1 0 0 0 0
X: 0 0 1 0 2 0 0 0
A: 0 0 0 0 0 3 0 0
G: 0 1 0 0 0 0 0 0
X: 0 0 2 0 1 0 0 0

Str: TXA
____________________________________________________________________________________________________________

"LONGEST COMMON SUBSEQUENCE" DP - O(m*n)

// mat[i][j] contains length of LCS of a[0..i-1] and b[0..j-1]
int mat[m+1][n+1];

FOR(i,0,m){
   FOR(j,0,n){
       if (i == 0 || j == 0){
         mat[i][j] = 0;
      }
      else if (a[i-1] == b[j-1]){
         mat[i][j] = mat[i-1][j-1] + 1;
      }
      else{
         mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
      }
   }
}

printf("Length of longest common subseq. %d\n", mat[m][n]);

// Print the sequence itself
int len = mat[m][n];
char seq[len+1];
int i = m;
int j = n;
int index = len-1;
while(i >0 && j>0){
   // If current character in X[] and Y[] are same, then current character is part of LCS
   if(a[i-1] == b[j-1]){
      seq[index--] = a[i-1];
      i--;
      j--;
   }
   // If not same, then find the larger of two and go in the direction of larger value
   else{
      if(mat[i-1][j] > mat[i][j-1]) i--;
      else j--;
   }
}
seq[len] = '\0';
printf("%s\n",seq);

// Output for
int m = 6, n=7;
string a="AGGTAB";
string b= "GXTXAYB";
Length of longest common subseq. 4
mat:
   - G X T X A Y B
-: 0 0 0 0 0 0 0 0
A: 0 0 0 0 0 1 1 1
G: 0 1 1 1 1 1 1 1
G: 0 1 1 1 1 1 1 1
T: 0 1 1 2 2 2 2 2
A: 0 1 1 2 2 3 3 3
B: 0 1 1 2 2 3 3 4
Seq: GTAB
_______________________________________________________________________________________________________

"LONGEST INCREASING SUBSEQUENCE" DP -O(n^2)
We’ll keep an array lis, 
lis[i] will contain the length of the longest increasing subsequence "ending" at "i".

   int lis[n];
   // fill up lis by starting form 0
   FOR(i,0,n-1){
      lis[i] = 1; // every element is a increadsing subseq by itself, so initialize to 1. 
      // look previously found increasing subseqs
      FOR(j,0,i-1){
      	 // if my current element a[i] is bigger than previous value a[j], 
      	 // I can add the cur. element end of the seq finished at j, if it creates a bigger subseq
         if(a[i] > a[j]){
            lis[i] = max(lis[i], lis[j]+1);
         }
      }
   }
   
   int res = 0;
   FOR(i,0,n-1){
      res = max(res, lis[i]);
   }
   printf("Length of longest inc. subseq is %d\n", res);
_______________________________________________________________________________________________________

"LONGEST PREFIX WHICH IS ALSO SUFFIX ( NO OVERLAP !!) "

/*Simple Solution :
Since overlapping of prefix and suffix is not allowed,
we break the string from middle and start matching left and right string. If they are equal return size of any one string else try for shorter lengths on both sides. */

int largest_prefix_suffix(const std::string &str) {

  int n = str.length();

  if(n < 2) {
    return 0;
  }

  int len = 0;
  int i = n/2;

  while(i < n) {
    if(str[i] == str[len]) {
      ++len;
      ++i;
    } else {
      if(len == 0) { // no prefix
        ++i;
      } else { // search for shorter prefixes
        --len;
      }
    }
  }

  return len;
}

/*Efficient Solution : O(n)
 The idea is to use preprocessing algorithm of KMP search. In the preprocessing algorithm,
 we build lps array which stores following values.
  lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i].    */

 int longestPrefixSuffix(string s)
{
    int n = s.length();

    int lps[n];
    lps[0] = 0; // lps[0] is always 0

    // length of the previous
    // longest prefix suffix
    int len = 0;

    // the loop calculates lps[i]
    // for i = 1 to n-1
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example. AAACAAAA
            // and i = 7. The idea is similar to search step.
            if (len != 0)
            {
                len = lps[len-1];
                // Note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int res = lps[n-1];

    // Since we are looking for non overlapping parts.
    return (res > n/2)? n/2 : res;
}
