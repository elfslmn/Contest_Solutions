"REGEX"
// How to use ? 
// 1 - Pattern and Matcher class ( java.util.*) 
String EXAMPLE_TEST = "This is my small example string to use for pattern matching.";

Pattern pattern = Pattern.compile("\\w+");
Matcher matcher = pattern.matcher(EXAMPLE_TEST);

while (matcher.find())
{
    System.out.print("Start index: " + matcher.start());
    System.out.print(" End index: " + matcher.end() + " ");
    System.out.println(matcher.group());
}
___________________________________________________________________________________________
// 2- With String methods

(bool) 		s.matches("regex")	Returns true if the WHOLE string matched.
(string[])	s.split("regex")	Creates an array with substrings, regex not included!
			s.replaceFirst("regex", "replacement")
			s.replaceAll("regex", "replacement")
_______________________________________________________________________________________

// Definitions
	.			Matches any character
	^regex		Regex must be at the BEGINNING of the line.
	regex$		Regex must be at the END of the line.
	
	[abc]		Can match the letter a or b or c.
	[abc][vz]	Can match a OR b or c followed by either v or z.
	[^abc]		Negation : matches any character EXCEPT a or b or c.
	[a-d1-7]	Ranges: matches a letter between a and d or 1 to 7
	
	X|Z			Finds X or Z.
	XZ			Finds X directly followed by Z.
	$			Checks if a line end follows.

	"Meta characters"
	\\d		Any digit
	\\D		A non-digit
	\\s		A whitespace character
	\\S		A non-whitespace character
	\\w		A word character
	\\W		A non-word character
	\\S+	Several non-whitespace characters
	\\b		Matches a word boundary where a word character is [a-zA-Z0-9_]
	
	"Quantifiers"
	*		Occurs zero or more times {0,}
	+		Occurs one or more times {1,}
	?		Occurs no or one times {0,1}.
	{X}		Occurs X number of times
	{X,Y}	Occurs between X and Y times,
	*?		It tries to find the smallest match. Regex stop at the first match.
_______________________________________________________________________________________________
	
// EXAMPLES

s.matches("[a-zA-Z]{3}");	true if the s contains of three letters
s.matches("^[^\\d].*");		true if the string not have a number at the beginning
"\\d\\d\\d([,\\s])?\\d\\d\\d\\d";	phone number xxxxxxx or xxx xxxx
_______________________________________________________________________________________

"GREP"
grep [options] pattern [files]

Options Description
-c : This prints only a count of the lines that match a pattern
-h : Display the matched lines, but do not display the filenames.
-i : Ignores, case for matching
-l : Displays list of a filenames only.
-n : Display the matched lines and their line numbers.
-v : This prints out all the lines that do not matches the pattern
-e exp : Specifies expression with this option. Can use multiple times.
-f file : Takes patterns from file, one per line.
-E : Treats pattern as an extended regular expression (ERE)
-w : Match whole word
-o : Print only the matched parts of a matching line














