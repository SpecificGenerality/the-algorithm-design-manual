// 3-3
// a)
// 1. Fill the array
// 2. Insert an element, triggering an expansion
// 3. Delete an element, triggering a shrinking
// 4. Repeat, leading to linear time amortized cost for insert/delete
// b) TODO: more rigorous analysis of how this gives constant amortized cost
// 1. Double when the array is full
// 2. Halve when the array is quarter full