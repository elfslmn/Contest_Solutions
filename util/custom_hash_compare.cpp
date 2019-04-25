"Custom hash for pair<int,int>
struct pair_hash
{
   size_t operator()(const pair<int,int>&x)const{
      size_t seed = 0;
      std::hash<int> hasher;
      seed ^= hasher(x.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      seed ^= hasher(x.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      return seed;
   }
};

"usage"
unordered_set<pair<int,int>, pair_hash> set;
std::unordered_map<pair<int,int>, int, pair_hash>;
________________________________________________________________________________

"For more general"

template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}
____________________________________________________________________________

"Custom compare"
bool cmp(int a, int b){
	if(a<b) return true;
	else return false;
}

sort(arr, arr+n, cmp)  -> küçükten buyuge sıralar
== sort(arr, arr+n , greater<int> ) 
priority_queue<int, vector<int>, greater<int>> q;
_____________________________________________________________

bool cmp(int a, int b){
	if(a>b) return true;
	else return false;
}

sort(arr, arr+n, cmp)  -> buyukten kuçüğe sıralar
_____________________________________________________________

"Strick weak ordering rules"
//1-Irreflexivity
	cmp(x, x) = False.
//2-Antisymmetry
	If cmp(x, y) then !cmp(y, x).
//3-Transitivity
	If f(x, y) ve f(y, z) then f(x, z).








