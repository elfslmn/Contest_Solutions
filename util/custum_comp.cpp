
bool cmp(int a, int b){
	if(a<b) return true;
	else return false;
}

sort(arr, arr+n, cmp)  -> küçükten buyuge sıralar
_____________________________________________________________

bool cmp(int a, int b){
	if(a>b) return true;
	else return false;
}

sort(arr, arr+n, cmp)  -> buyukten kuçüğe sıralar
_____________________________________________________________

Bu sekilde baska comparator functionlar tanımlayabilirsin
 
!! a nın b den önce geldiği duruma true donmen lazım
!! cmp(x,x) -> false olmalı
_____________________________________________________________

"Strick weak ordering rules"
//1-Irreflexivity
	cmp(x, x) = False.
//2-Antisymmetry
	If cmp(x, y) then !cmp(y, x).
//3-Transitivity
	If f(x, y) ve f(y, z) then f(x, z).
