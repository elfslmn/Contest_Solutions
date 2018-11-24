"LONGEST PREFIX WHICH IS ALSO SUFFIX ( NO OVERLAP !!) "

/*Simple Solution : 
Since overlapping of prefix and suffix is not allowed, we break the string from middle and start matching left and right string. If they are equal return size of any one string else try for shorter lengths on both sides. */

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
            // This is tricky. Consider
            // the example. AAACAAAA
            // and i = 7. The idea is
            // similar to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do
                // not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    int res = lps[n-1];
 
    // Since we are looking for
    // non overlapping parts.
    return (res > n/2)? n/2 : res;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
