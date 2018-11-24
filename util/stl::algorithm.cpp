	"Useful built-in functions"

	sort(first_iterator, last_iterator) 							– To sort the given vector.
	reverse(first_iterator, last_iterator) 							– To reverse a vector.
	
	*max_element (first_iterator, last_iterator) 					– To find the maximum element of a vector.
	*min_element (first_iterator, last_iterator) 					– To find the minimum element of a vector.
	
	accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements 
	count(first_iterator, last_iterator,x) 							– To count the occurrences of x in vector.
	
	
	// Use with sorted arrays
	binary_search(first_iterator, last_iterator, x) 				– Tests whether x exists in sorted vector.
	
	lower_bound(first_iterator, last_iterator, x) 					– returns an iterator pointing to the first element in the 																		range [first,last) which has a value not less than ‘x’.
	
	upper_bound(first_iterator, last_iterator, x) 					– returns an iterator pointing to the first element in the 																		range [first,last) which has a value greater than ‘x’. 
	
	arr.erase(position to be deleted) 								– This erases selected element in vector and shifts and 																	resizes the vector elements accordingly.
	
	next_permutation(first_iterator, last_iterator) 				- Give a permutation of the array elements 
																	(bkz. combinatorics.cpp)

