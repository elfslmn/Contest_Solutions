
// recursive
//returns location of x in given array arr[l..r] is present, otherwise -1
// arr is SORTED increasing order 
// binarySearch(arr, 0, n-1, x);

int binarySearch(int arr[], int l, int r, int x)
{
   if (l <= r){
        int mid = (l+r) /2;
        
        if (arr[mid] == x)  return mid;	
		// search left
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);       
        // search right
        else return binarySearch(arr, mid+1, r, x);
   }   
   // not contain
   return -1;
}

____________________________________________________________________________________

// iterative binary search
int l = 0, r = n-1;

while (l <= r) {
	int mid = (l+r) /2;
	if (arr[mid] == x) {
		// x found at index k
	}
	if (arr[mid] > x) r = mid-1;
	else l = mid+1;
}

_____________________________________________________________________________________

// iterative binary search 2
int cur = 0;
//d : distance of the jump
for (int d = n/2; d >= 1; d /= 2) {
	while (cur+d < n && arr[cur+d] <= x) {
		cur += d; // jump to right
	}
	
}
if (arr[cur] == x) {
	// x found at index cur
}

_____________________________________________________________________________________-

//Finding the smallest solution

// x	0	1	2	k-1	 k	k+1
//f(x)	f	f	f	 f	 t	 t ...
// z : choose a very big number such that f(z) = true

int cur = -1;
for (int d = z; d >= 1; d /= 2) {
	while (f(cur+d) == false) cur += d;
}

int k = cur+1; 
// k is the smallest index that makes f function true
// cur is the biggest index that makes f function false
_____________________________________________________________________________________

//Finding the maximum value
// f is first increase, then decrease
// k : index of max value
// f(x) < f(x+1) when x < k 
// f(x) > f(x+1) when k <= x 
// z : choose a very big number

int cur = -1;
for (int d = z; d >= 1; d /= 2) {
	while (f(cur+d) < f(cur+d+1)) cur += d;
}
int k = cur+1;

______________________________________________________________________________________

upper_bound(arr, arr+size, value)

Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 30 40 50
Output : upper_bound for element 45 is at index 5

Input : 10 20 30 30 40 50
Output : upper_bound for element 60 is at index 6
_______________________________________________________________________________________

lower_bound(arr, arr+size, value)

Input : 10 20 30 30 40 50
Output : lower_bound for element 30 is at index 2

Input : 10 20 30 30 40 50
Output : lower_bound for element 35 is at index 4

Input : 10 20 30 30 40 50
Output : lower_bound for element 60 is at index 6








