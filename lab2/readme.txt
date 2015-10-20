/**********************************************************************
 *  Kn�cka l�senord readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

/**********************************************************************
 *  Ge en h�gniv�beskrivning av ditt program decrypt.c.
 **********************************************************************/
Vi delar upp l�senordet i tv� delar, lower_half och higher_half. Vi 
itererar sedan �ver alla kombinationer som kan g�ras av lower_halfs l�ngd,
och sparar alla dessa kombinationer, krypterade, i en map. Key i denna mappen
�r det krypterade l�senorden, subtraherat med den krypterade kombinationen.
Detta g�r att keyn �r den summan som "�terst�r" att hitta, f�r att vi ska ha den totala
summan av det krypterade l�senordet.

Sedan k�rs en mer eller mindre vanlig bruteforce. Vi itererar �ver alla kombinationer
av higher_half, och ser om den summan som f�s ut n�r denna kombination krypteras finns
i den map vi skapade tidigare. Om summan finns, s� har vi nu b�da delsummor som beh�vdes.

/**********************************************************************
 *  Beskriv symboltabellen du anv�nt f�r decrypt.c.
 **********************************************************************/
Vi anv�nder en map, d�r key �r �terst�ende summa och value �r en lista
med alla kombinationer som krypteras till samma summa.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla l�senord med 8 och 10
 *  bokst�ver i uppgiften du lyckades kn�ca med DIN kod.
 **********************************************************************/


8 bokst�ver         10 bokst�ver
-----------         ------------
congrats	    completely
youfound	    unbreakabl
theright	    cryptogram
solution	    ormaybenot

/****************************************************************************
 *  Hur l�ng tid anv�nder brute.c f�r att kn�cka l�senord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ***************************************************************************/
HUr l�ng bruteforce tar beror s�klart p� vilket l�senord som v�ljs. Ett
l�senord som aaaaaa skulle matcha p� f�rsta f�rs�ket, medan zzzzzz inte skulle matcha
f�rr�n sista. Tiden bruteforce tar varierar d�rf�r s� mycket att vi inte riktigt �r s�kra
p� hur en uppskattning skulle g�ras.
L�senordet som testades h�r var asda, asdas och asdasd, vilket �r relativt enkla. D�remot
tar asdasdas l�ngre tid �n vad vi kan v�nta.
Char     Brute     
--------------
 4	 <1
 5	 <2 
 6	 12
 8	  -


/******************************************************************************
 *  Hur l�ng tid anv�nder decrypt.c f�r att kn�cka l�senord av en viss storlek?
 *  Hur mycket minne anv�nder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	< 1			-
8	5			148MB
10	280			7GB
12	              ---------
Programmet krashar n�r minnet tar slut, och ingen egentligen "progress update"
ges av programmet, vilket g�r det sv�rt att gissa hur l�nge det skulle tagit
om programmet kunde k�rt klart.

/*************************************************************************
 * Hur m�nga operationer anv�nder brute.c f�r ett N-bitars l�senord?
 * Hur m�nga operationer anv�nder din decrypt.c f�r ett N-bitars l�senord?
 * Anv�nd ordo-notation.
 *************************************************************************/
Brute: O(2^N)
Decrypt: O(2^(N/2))
