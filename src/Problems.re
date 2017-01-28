/**
 * Here are some simple problem resolutions
 */

/**
 * @name fibo
 * Fonction that will calculate the Nth term of fibonnacci serie.
 * @param n int Range where you want to calculate
 * @return finbonnacci value @ Nth poosition
 */
let rec fibo n =>
  n == 0 ? 0 : (n == 1 ? 1 : fibo (n-1) + fibo (n-2));

/**
 * @name hanoi
 * fonction affichant la combinaison d'étape à faire pour résoudre le problème.
 * @param n int nombre de disque 
 * @para d string pique de départ
 * @para a string pique intermédiaire
 * @para i string pique d'arrivée $
*/
let rec hanoi n d a i =>
  n == 0 ? "" : (n == 1 ? d ^ a : (hanoi (n-1) d i a) ^ "- " ^ (hanoi 1 d a i) ^ " - " ^ (hanoi (n-1) i a d));
          
/**
 * Test
 */
print_newline ();
print_int (fibo 0);
print_newline ();
print_int (fibo 1);
print_newline ();
print_int (fibo 2);
print_newline ();
print_int (fibo 3);
print_newline ();
print_int (fibo 4);
print_newline ();
print_int (fibo 5);
print_newline ();
print_int (fibo 10);
print_newline ();
print_newline ();
print_string (hanoi 3 "D" "A" "I");
print_newline ();