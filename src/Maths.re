/**
 * Here are some quick and simple mathematical functions
 */
/** 
 * @pow
 * Small function to calculate pow of an integer.
 * @param a int integer to get pow from
 * @param b int>0 power wanted
 * @return a^b
*/
let rec pow a b => {
    (b == 0) ? 1 : a * pow a (b-1);
};

/** 
 * @factorielle
 * Small function to calculate factorielle of an integer.
 * @param a int>0 integer to get factorielle from
 * @return !a
*/
let rec factorielle a => {
    a == 0 ? 1 : a * factorielle (a - 1);
};

/**
 * @printMathsFuncResult
 * Small function to help outputting result of functions on integers.
 * @param funcName string name of the function used
 * @param funcParameter string parameter passed to the function
 * @param funcResult int result of function call 
 */
let printMathsFuncResult funcName funcParameter funcResult => {
    print_string ("Result of functions " ^ funcName ^ " using args " ^ funcParameter ^ " is : ");
    print_int funcResult;
    print_newline ();
};

/**
 * Testing calls
 */
printMathsFuncResult "pow" "a-3, b-4"  (pow 3 4);
printMathsFuncResult "factorielle" "10"  (factorielle 10);