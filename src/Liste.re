/**
 * @name printList
 * @ Fonction affichant les éléments d'une liste 1 à 1 a  -> b  -> x  -> []
 * @param l string list Liste de chaînes de charactère à afficher
 * @print List element in the format E  -> E  -> E  -> ...  -> []
 */
let rec printList = fun 
    | [] => print_string "[]"
    | [t, ...q] => {
        print_string (t ^ " -> ");
        printList q
    };

/**
 * @name estDans
 * @ Fonction permettant de savoir si un élement E est dans une liste L
 * @param e 'a Paramètre de type quelconque 
 * @param l 'a list List d'élément du même type que e
 * @return true si e in list, false else
 */
let rec estDans e => fun
    |[] => false
    |[t, ...q] => t == e || estDans e q;

/**
 * @name doublonsSk
 * @ Fonction retirant les doublons d'une liste
 * @param l 'a list list d'élément.
 * @return liste l sans doublons
 */
let rec doublonsSk = fun
    |[] => []
    |[t, ...q] => estDans t q ? doublonsSk q : [t, ...(doublonsSk q)];

/**
 * @name nbDe
 * @ Fonction permettant de calculer le nombre d'occurence d'un élément dans une liste
 * @param e 'a élément de type quelconque
 * @param l 'a list Liste d'élément du même type
 * @return nb d'occurence de e dans a
 */
let rec nbDe e => fun
    |[] => 0
    |[t, ...q] => t == e ? 1 + nbDe e q : nbDe e q;

/**
 * Test
 */
let aList = ["a", "a", "a", "a"];
let stringListNoDuplicates = ["a", "d", "b", "e", "c", "f", "n", "l"];
let stringListDuplicates = ["a", "d", "a", "e", "b", "c", "e", "a", "f", "a", "n", "l", "l", "l"];

print_newline ();
printList aList;
print_newline ();
printList stringListDuplicates;
print_newline ();
printList stringListNoDuplicates;
print_newline ();
printList (doublonsSk aList);
print_newline ();
printList (doublonsSk stringListNoDuplicates);
print_newline ();
printList (doublonsSk stringListDuplicates);
print_newline ();
print_int (nbDe "a" aList);
print_newline ();
print_int (nbDe "b" aList);
print_newline ();
print_int (nbDe "d" stringListNoDuplicates);
print_newline ();
print_int (nbDe "a" stringListDuplicates);
print_newline ();
print_int (nbDe "l" stringListDuplicates);
print_newline ();
print_int (nbDe "n" stringListDuplicates);
print_newline ();
print_int (nbDe "z" stringListDuplicates);
print_newline ();
estDans "a" stringListDuplicates ? print_string "true" : print_string "false";
print_newline ();
estDans "z" stringListDuplicates ? print_string "true" : print_string "false";
print_newline ();
