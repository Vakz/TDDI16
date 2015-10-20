/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

/**********************************************************************
 *  Ge en högnivåbeskrivning av ditt program decrypt.c.
 **********************************************************************/
Vi delar upp lösenordet i två delar, lower_half och higher_half. Vi 
itererar sedan över alla kombinationer som kan göras av lower_halfs längd,
och sparar alla dessa kombinationer, krypterade, i en map. Key i denna mappen
är det krypterade lösenorden, subtraherat med den krypterade kombinationen.
Detta gör att keyn är den summan som "återstår" att hitta, för att vi ska ha den totala
summan av det krypterade lösenordet.

Sedan körs en mer eller mindre vanlig bruteforce. Vi itererar över alla kombinationer
av higher_half, och ser om den summan som fås ut när denna kombination krypteras finns
i den map vi skapade tidigare. Om summan finns, så har vi nu båda delsummor som behövdes.

/**********************************************************************
 *  Beskriv symboltabellen du använt för decrypt.c.
 **********************************************************************/
Vi använder en map, där key är återstående summa och value är en lista
med alla kombinationer som krypteras till samma summa.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         10 bokstäver
-----------         ------------
congrats	    completely
youfound	    unbreakabl
theright	    cryptogram
solution	    ormaybenot

/****************************************************************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ***************************************************************************/
HUr lång bruteforce tar beror såklart på vilket lösenord som väljs. Ett
lösenord som aaaaaa skulle matcha på första försöket, medan zzzzzz inte skulle matcha
förrän sista. Tiden bruteforce tar varierar därför så mycket att vi inte riktigt är säkra
på hur en uppskattning skulle göras.
Lösenordet som testades här var asda, asdas och asdasd, vilket är relativt enkla. Däremot
tar asdasdas längre tid än vad vi kan vänta.
Char     Brute     
--------------
 4	 <1
 5	 <2 
 6	 12
 8	  -


/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	< 1			-
8	5			148MB
10	280			7GB
12	              ---------
Programmet krashar när minnet tar slut, och ingen egentligen "progress update"
ges av programmet, vilket gör det svårt att gissa hur länge det skulle tagit
om programmet kunde kört klart.

/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/
Brute: O(2^N)
Decrypt: O(2^(N/2))
