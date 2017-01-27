/** 
 * Some basic sort functions
*/

/**
 * @name printIntList
 * @ Fonction affichant les éléments d'une liste 1 à 1 a  -> b  -> x  -> []
 * @param l string list Liste de chaînes de charactère à afficher
 * @print List element in the format E  -> E  -> E  -> ...  -> []
 */
let rec printIntList = fun 
    | [] => print_string "[]"
    | [t, ...q] => {
        print_int t;
        print_string " -> ";
        printIntList q
    };

/**
 * @name insert_nt
 * @ Fonction permettant d'insérent un élément dans une liste triée.
 * @param e 'a Élément du type de la liste
 * @param comp 'a ->'a -> bool fonction de comparaison
 * @param l 'a list Liste d'élément triée
 * @return e inséré dans l triée.
 */
let rec insert_nt e comp => fun
  |[] => [e]
  |[t, ...q]  => comp e t ? [e, t, ...q] : [t, ...insert_nt e comp q];

/**
 * @name tri_bulle_nt
 * @ Fonction permettant de trier une liste
 * @param comp 'a -> 'a -> bool fonction de comparaison
 * @param l 'a list Liste d'élément
 * @return l trié
 */
let rec tri_bulle_nt comp => fun
  |[] => []
  |[t, ...q]  => insert_nt t comp (tri_bulle_nt comp q);

/**
 * @name insert
 * @ Fonction permettant d'insérent un élément dans une liste triée.
 * @param e 'a Élément du type de la liste
 * @param acc 'a list Accumulateur. '
 * @param comp 'a -> 'a -> bool fonction de comparaison
 * @param l 'a list Liste d'élément triée
 * @return e inséré dans l triée.
*/
let rec insert e acc comp => fun
  |[] => List.append acc [e]
  |[t, ...q]  => comp e t ? List.append acc [e, t, ...q] : insert e (List.append acc [t]) comp q;
/**
 * @name tri_bulle
 * @ Fonction permettant de trier une liste
 * @param l 'a list Liste d'élément
 * @param acc 'a list Accumulateur. '
 * @param comp 'a -> 'a -> bool fonction de comparaison
 * @return l trié
*/
let rec tri_bulle acc comp => fun
  |[] => acc
  |[t, ...q]  => tri_bulle (insert t [] comp acc) comp q ;

/**
 * @name divise
 * @ Fonction permettant de diviser une liste
 * @param l 'a list Liste d'élément
 * @return ('a list, 'a list) liste l divisée en 2.
 */
let rec divise a1 a2 => fun
  |[]  => (a1, a2)
  |[t, ...[]]  => ([t, ...a1], a2)
  |[t1,t2, ...q]  => divise [t1, ...a1] [t2, ...a2] q;
/**
 * @name fusion
 * @ Fonction permettant de fusionner une liste
 * @param comp 'a ->'a ->bool fonction de comparaison
 * @param l1 'a list Liste d'élément triée selon comp
 * @param l2 'a list Liste d'élément triée selon comp
 * @return 'a list Liste l1 &amp;&amp; l2 fusionnée et triée selon comp'
*/
let rec fusion acc comp => fun
  |([], l2)  => List.append acc l2
  |(l1 ,[])  => List.append acc l1
  |([t1, ...q1], [t2, ...q2])  => comp t1 t2 ? fusion(List.append acc [t1]) comp  (q1,[t2, ...q2]) : fusion (List.append acc [t2]) comp  ([t1, ...q1],q2);
/**
 * @name order
 * @ Fonction permettant de trier une liste
 * @param comp 'a ->'a ->bool fonction de comparaison
 * @param l 'a list Liste d'élément
 * @return l trié
*/
let rec order comp => fun
  |[]  => []
  |[t, ...[]]  => [t]
  |l  => {
    let (l1,l2) = divise [] [] l; 
    fusion [] comp ((order comp l1), (order comp l2))
  };

/** 
 * Tests
*/
let ltrie = [1,2,3,4,5,6,7,8,9];
let lntrie = [1,4,9,8,6,4,22,3,10,2,4,7,52,6,8,1,39,12,4,6,8,5,2,31,87581651,115614,6,845,3,7];

let lower a b => {
  a < b
};

print_newline ();
printIntList (ltrie);
print_newline ();
printIntList (tri_bulle_nt lower ltrie);
print_newline ();
printIntList (tri_bulle [] lower ltrie);
print_newline ();
printIntList (order lower ltrie);
print_newline ();
printIntList (lntrie);
print_newline ();
printIntList (tri_bulle_nt lower lntrie);
print_newline ();
printIntList (tri_bulle [] lower lntrie);
print_newline ();
printIntList (order lower lntrie);
print_newline ();