#ifndef EINES_H
#define EINES_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

     string token ( const string & s , char separador , bool cometes , long & primer , long & ultim );
     // pre : --
     // post : excepcions : si cometes ´e s cert , el primer car`a cter ´e s " i no hi ha unes segones " que tanquin ,
     // es genera una excepci´o
     // retorna : cadena entre posici´o primer i seg¨uent separador o final de l´ı nia . Si cometes ´e s cert , quan el
     // token comen¸c a per " busca la " que ho tanca i les elimina del token ( si despr´e s de les " inicials
     // es troba "" , ´e s a dir , dues " seguides , s' ignoren ).


     vector <string> tokens ( const string & s , char separador = ',', bool cometes = false );
     // pre : --
     // post : --
     // retorna : vector < string > amb tots els components d'una l´ı nia CSV b`a sica ( nom´e s tractant separadors ).
     // Un component est`a format per tots els car`a cters entre dos separadors , excepte el primer i l'´u ltim .
     // El primer component est`a format per tots els car`a cters abans del primer separador . L'´u ltim component
     // est`a format per tots els car`a cters despr´e s de l'´u ltim separador .

#endif // EINES_H
