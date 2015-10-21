/**********************************************************************
 *  Mönsterigenkänning readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga körtider i sekunder
 *  analys      när det känns vettigt att vänta på hela beräkningen.
 *              Ge uppskattningar av körtiden i övriga fall.
 *
 **********************************************************************/

      N       brute       sortering
 ----------------------------------
    150       <1          <1
    200       <1          <1
    300       <1          <1
    400       1           <1
    800       9           <1
   1600       70          2
   3200       565         10
   6400       4552        41
  12800                   174


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck för värstafallstiden för programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: O(N^4). Algoritmen består av fyra loopar. Det fjärde loopen körs
       visserligen endast då if-satsen är sann, men eftersom det handlar om
       värstafallet, räknar vi med att if-satsen är sann varje gång (i.e. alla
       punkterna är på en lång rad)

Sortering: O(N^2). Algoritmen består av en yttre loop, med två inre loopar. Eftersom
                   de två inre är seriella och inte rekursiva blir deras komplexitet
                   2N och inte N^2. Funktionen blir därmed N(N + N) = 2*N^2, vilket blir O(N^2)
