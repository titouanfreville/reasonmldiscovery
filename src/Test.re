/**
 * Welcome to Reason.
 */

let rec pow a b => {
    (b == 0) ? 1 : a * pow a (b-1);
};

let rec factorielle a => {
    a == 0 ? 1 : a * factorielle (a - 1);
};

print_string "!!!!!!\n";
let msg = "Hello Reason!";
print_string msg;
print_newline ();
print_string "!!!!!!\n";
print_newline ();
print_string "3 ^ 2 : ";  print_int (pow 3 2);
print_newline ();
print_string "Factorielle de 3 : ";  print_int (factorielle 4);
print_newline ();

