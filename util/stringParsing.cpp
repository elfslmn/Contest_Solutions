"String as a Char Array"
char a[max_n];
scanf("%s", a);

strlen(s1);			// Returns length of string s1.
strcpy(s1, s2);		// Copies s2 into s1.
strcat(s1, s2);		// Concatenates s2 onto the end of s1.
strcmp(s1, s2);		// Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.
____________________________________________________________________________________________________________

"String as a Class"
#include <string>
string a;
getline(cin ,a);
a[i] -> ith char of string a

s1.size();   	// Returns length of string s1.
s1 = s2;		// Copies s2 into s1.
s3 = s1 + s2; 	// Concatenates s1 and s2
s1.c_str()		// Returns char array equivalent
s1.swap(s2); 
s.erase(5,3)	// 5den başla 3 char sil

s1.push_back('c');	// can be used like vectors
s1.pop_back();

insert(pos_to_begin, string_to_insert)
erase(pos_to_begin, char_count_to_erase)

stoi(s)		// Converts s to integer
stoll(s)	// Converts s to long long

  string base="this is a test string.";
  string str2="n example";
  string str3="sample phrase";
  string str4="useful.";

  string str = base;				// "this is a test string."
  str.replace(9,5,str2);          	// "this is an example string."  -> 9 dan başla 5 char sil yerine str2 yi koy
  str.replace(19,6,str3,7,6);     	// "this is an example phrase."  -> 19dan başla 6 char sil yerine str3 un 7sinden 																			başlayarak 6 charı alıp str ye koy  
_________________________________________________________________________________________________________________________

//Read multiple ints in same line
string input;
getline(cin, input);
stringstream stream(input);

while(1) {
   int n;
   stream >> n;
   if(!stream) break;
   cout << "Found integer: " << n << endl;
}
____________________________________________________________________________________

// Substrings
	string res = s.substr( start index(included) , number of chars )  
	
	string str="We think in generalities, but we live in details.";
	string str2 = str.substr (3,5);     	// "think"
	size_t pos = str.find("live");      	// position of "live" in str (index of "l")
	string str3 = str.substr (pos);     	// get from "live" to the end
	cout << str2 << ' ' << str3 << '\n';	// think live in details.

_____________________________________________________________________________________

// Split a string into parts with a delimeter
void split(const string &txt, vector<string> &words, string delim)
{
    size_t end = txt.find(delim);
    size_t start = 0;
    words.clear();

    while( end != string::npos ) { // string::npos indicates no matches
        words.push_back( txt.substr( start, end - start ) );
        start = end + 1;

        end = txt.find(delim, start );
    }

    words.push_back( txt.substr( start, min( end, txt.size() ) - start + 1 ) );
}

_____________________________________________________________________________________
