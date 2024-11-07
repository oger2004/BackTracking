// Roger Costa Maubens
// u1987277
// p2

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>

#include "eines.h"
#include "Candidats.h"

using namespace std;


#ifndef SOLUCIO_H
#define SOLUCIO_H


class Solucio
{
    struct Aplic{
        Aplic();
/**<
        * @brief s'inicialitzen els atributs amb valors per defecte
        * @pre -
        * @post s'inicialitzen els atributs amb valors per defecte
        * @param -
        * @return una Aplic amb els atributs amb valors per defecte
*/
        Aplic(long long im,string codi,char iDa,string capi);
/**<
        * @brief s'inicialitzen els atributs amb valors entrats
        * @pre capi string que valor entre [0..9], iDa valors I o D
        * @post s'inicialitzen els atributs amb valors entrats
        * @param un long long, dos string i un char
        * @return s'inicialitzen els atributs amb valors entrats
*/

        bool operator<(const Aplic &o);
/**<
        * @brief retorna si this es mes petit que o tinguent encompte el cod i iD
        * @pre Aplic inicialitzat
        * @post retorna si this es mes petit que o tinguent encompte el cod i iD
        * @param una variable tipus Apli
        * @return retorna si this es mes petit que o tinguent encompte el cod i iD
*/

        long long imp;
        string cod;
        char iD;
        int cap;
    };
    public:
        Solucio();
/**<
        * @brief s'inicialitzen tots els atributs amb els valors per defecte
        * @pre -
        * @post s'inicialitzen tots els atributs amb els valors per defecte
        * @param -
        * @return retorna tots els atributs inicialitzats amb els valors per defecte
*/
      //  Solucio(const Solucio &o);
     //   ~Solucio();
        Solucio & operator=(const Solucio &o);
/**<
        * @brief retorna un punter a this
        * @pre la Solucio esta inicialitzda
        * @post retorna un punter a this
        * @param una variable Solucio
        * @return retorna un punter a this
*/
        bool operator==(const Solucio &o);
/**<
        * @brief retorna true si this es igual que o
        * @pre la Solucio esta inicialitzda
        * @post retorna true si this es igual que o
        * @param una variable Solucio
        * @return retorna true si this es igual que o
*/
        Candidats inicialitzarCandidats() const;
/**<
        * @brief retorna una variable candidats inicialitzats segons la sol actual
        * @pre -
        * @post retorna una variable candidats inicialitzats segons la sol actual
        * @param -
        * @return retorna una variable candidats inicialitzats segons la sol actual
*/
        bool acceptable(const Candidats &iCan,bool iD,bool Cap) const;
/**<
        * @brief retorna true si es pot afegir una aplicacio al candidat actual seguint les restriccions del problema i iD, Cap false altrament
        * @pre iCan representa el candidat actual ha destar inicialitzat, iD i Cap han de ser true si es volen afegir restriccions al construir solucio
        * @post retorna true si es pot afegir una aplicacio al candidat actual seguint les restriccions del problema i iD, Cap false altrament
        * @param una variable Candidats i dos bool
        * @return retorna true si es pot afegir una aplicacio al candidat actual seguint les restriccions del problema i iD, Cap false altrament
*/
        void anotar(const Candidats &iCan,bool iD,bool Cap);
/**<
        * @brief anota una aplicacio a la solucio
        * @pre iCan representa el candidat actual ha destar inicialitzat, iD i Cap han de ser true si es volen afegir restriccions al construir solucio
        * @post anota una aplicacio a la solucio
        * @param una variable Candidats i dos bool
        * @return -
*/
        void desanotar(const Candidats &iCan,bool iD,bool Cap);
/**<
        * @brief desanota una aplicacio de la solucio
        * @pre iCan representa el candidat actual ha destar inicialitzat, iD i Cap han de ser true si es volen afegir restriccions al construir solucio
        * @post desanota una aplicacio de la solucio
        * @param una variable Candidats i dos bool
        * @return -
*/
        bool completa() const;
/**<
        * @brief retorna true si la solucio es completa
        * @pre -
        * @post retorna true si la solucio es completa
        * @param -
        * @return retorna true si la solucio es completa
*/
        bool millor_optima(Solucio& opt);
/**<
        * @brief retorna true si la solucio es millor que la Solucio opt
        * @pre la solucio opt ha de estar inicialitzada
        * @post retorna true si la solucio es millor que la Solucio opt
        * @param una variable Solucio
        * @return retorna true si la solucio es millor que la Solucio opt
*/
        bool posSolMillor(Solucio& opt,Candidats& iCan,bool iD,bool Cap);
/**<
        * @brief retorna true si la solucio pot arribar a ser millor que Solucio opt
        * @pre la solucio opt ha de estar inicialitzada i iCan representa el candidat actual ha destar inicialitzat, iD i Cap han de ser true si es volen afegir restriccions al construir solucio
        * @post retorna true si la solucio pot arribar a ser millor que Solucio opt
        * @param una variable Solucio, una de Candidats i dos bool
        * @return retorna true si la solucio pot arribar a ser millor que Solucio opt
*/
        void ordenar();
/**<
        * @brief ordena les aplicacions que hi ha a apl_aud
        * @pre -
        * @post ordena les aplicacions que hi ha a apl_aud
        * @param -
        * @return -
*/
        void mostrar();
/**<
        * @brief mostra les aplicacions que hi ha a apl_aud la desviacio estandar el nombre d'auditors i la suma total d'imports
        * @pre -
        * @post mostra les aplicacions que hi ha a apl_aud la desviacio estandar el nombre d'auditors i la suma total d'imports
        * @param -
        * @return -
*/
        void mostrar_unica();
/**<
        * @brief mostra les aplicacions que hi ha a apl_aud la desviacio estandar el nombre d'auditors i la suma total d'imports
        * @pre -
        * @post mostra les aplicacions que hi ha a apl_aud la desviacio estandar el nombre d'auditors i la suma total d'imports
        * @param -
        * @return -
*/
        pair<int,pair<int,long long>> llegirDades(const string& path,int any, long long impMax,bool iD,bool Cap,int nAuditMax);
/**<
        * @brief llegeix les dades del fitxer path tenint encompte les restriccions, retorna un pair amb el nombre daplicacions de linies llegides i la suma de imports
        * @pre estan tots els valors inicialitzats
        * @post llegeix les dades del fitxer path tenint encompte les restriccions, retorna un pair amb el nombre daplicacions de linies llegides i la suma de imports
        * @param un string, dos int, un long long, un char i un bool
        * @return retorna un pair amb el nombre daplicacions de linies llegides i la suma de imports
*/

    private:

        void allibera();
/**<
        * @brief allibra els valors que treballen amb memoria dinamica de this sense tenir encompte els de llibreria STL
        * @pre una Solucio inicialitzada
        * @post allibra els valors que treballen amb memoria dinamica de this sense tenir encompte els de llibreria STL
        * @param una variable tipus Solucio
        * @return -
*/
        void copia(const Solucio& o);
/**<
        * @brief copia els valors de o a this
        * @pre una Solucio inicialitzada
        * @post copia els valors de o a this
        * @param una variable tipus Solucio
        * @return -
*/
        bool unaBuida(Candidats& iCan,bool iD,bool Cap);
/**<
        * @brief retorna true si nomes hi ha un candidat sense aplicacions, false altrament
        * @pre iCan representa el candidat actual ha destar inicialitzat, iD i Cap han de ser true si es volen afegir restriccions al construir solucio
        * @post retorna true si nomes hi ha un candidat sense aplicacions, false altrament
        * @param una variable Candidats i dos bool
        * @return retorna true si nomes hi ha un candidat sense aplicacions, false altrament
*/
        long long calcImport(vector<string> items);
/**<
        * @brief retorna un long long que inclou la part decimal de l'import
        * @pre el vector conte un numero decimal al index 31
        * @post retorna un long long que inclou la part decimal de l'import
        * @param un vector tipus string string
        * @return retorna un long long que inclou la part decimal de l'import
*/
        void afegir_fila_fixer(vector<string> i,int& nFiles);
/**<
        * @brief afegeix una aplicacio a la estructura Aplicacions i incrementa nFiles en 1 si la aplicacio es nova
        * @pre el vector conte tota la informacio necessaria per afegir una Aplic i nFiles inicialitzat
        * @post afegeix una aplicacio a la estructura Aplicacions i incrementa nFiles en 1 si la aplicacio es nova
        * @param un vector de string i un int
        * @return -
*/
        long long impMax;
/**<
* @brief un long long que representa el import maxim per cada auditor
        * @param un long long que representa el import maxim per cada auditor
*/
        vector<int> auditors;
/**<
* @brief vector de int que guarda el numero de auditor
        * @param vector de int que guarda el numero de auditor
*/
        vector<long long> sum_aud;
/**<
* @brief vector de long long que guarda la suma per cada auditor
        * @param vector de long long que guarda la suma per cada auditor
*/
        vector<vector<Aplic>> apl_aud;
/**<
* @brief vector de vectors de Aplic que guarda les aplicacions per cada auditor
        * @param vector de vectors de Aplic que guarda les aplicacions per cada auditor
*/
        Aplic* aplicacions;
/**<
* @brief una estructura dinamica que guarda totes les Aplic
        * @param una estructura dinamica que guarda totes les Aplic
*/
        int n_Apl;
/**<
* @brief el numero de aplicacions
        * @param el numero de aplicacions
*/
        long long sum;
/**<
* @brief la suma total de imports de totes les aplicacions
        * @param la suma total de imports de totes les aplicacions
*/
        long long desv;
/**<
* @brief la desviacio estandar de les sumes dels imports als auditors
        * @param la desviacio estandar de les sumes dels imports als auditors
*/
        int nBuits;
/**<
* @brief numero d'auditors que no tenen aplicacions assignades
        * @param numero d'auditors que no tenen aplicacions assignades
*/
        long long restant;
/**<
* @brief suma d'imports restants que falten per emplenar
        * @param suma d'imports restants que falten per emplenar
*/
        long long restantI;
/**<
* @brief suma d'imports associats a una aplicacio d'ingres restants que falten per emplenar
        * @param suma d'imports associats a una aplicacio d'ingres restants que falten per emplenar
*/
        long long restantD;
/**<
* @brief suma de imports associats a una aplicacio de despesa restants que falten per emplenar
        * @param suma de imports associats a una aplicacio de despesa restants que falten per emplenar
*/
        vector<long long> restCap;
/**<
* @brief guarda la suma dels imports restants per a cada aplicacio que tinguin el mateix capitol
        * @param guarda la suma dels imports restants per a cada aplicacio que tinguin el mateix capitol
*/
        vector<long long> restCapI;
/**<
* @brief guarda la suma dels imports restants per a cada aplicacio que sigui de tipus ingres i tinguin el mateix capitol
        * @param guarda la suma dels imports restants per a cada aplicacio que sigui de tipus ingres i tinguin el mateix capitol
*/
        vector<long long> restCapD;
/**<
* @brief guarda la suma dels imports restants per a cada aplicacio que sigui de tipus despesa i tinguin el mateix capitol
        * @param guarda la suma dels imports restants per a cada aplicacio que sigui de tipus despesa i tinguin el mateix capitol
*/
        const int iImportCons=30;
/**<
* @brief index en fitxer csv entrada on hi ha l'import
        * @param index en fitxer csv entrada on hi ha l'import
*/
        const int iIngresDespesa=2;
/**<
* @brief index en fitxer csv entrada on hi ha el tipus de la Aplic
        * @param index en fitxer csv entrada on hi ha el tipus de la Aplic
*/
        const int iAny=1;
/**<
* @brief index en fitxer csv entrada on hi ha l'any de la Aplic
        * @param index en fitxer csv entrada on hi ha l'any de la Aplic
*/
        const int iCodiAplicacio=21;
/**<
* @brief index en fitxer csv entrada on hi ha el codi de la Aplic
        * @param index en fitxer csv entrada on hi ha el codi de la Aplic
*/
        const int iCodiCapitol=15;
/**<
* @brief index en fitxer csv entrada on hi ha el codi del capitol de la Aplic
        * @param index en fitxer csv entrada on hi ha el codi del capitol de la Aplic
*/

        const string INGR="I";
/**<
* @brief posible valor del tipus de la Aplic
        * @param posible valor del tipus de la Aplic
*/
        const string DESP="D";
/**<
* @brief posible valor del tipus de la Aplic
        * @param posible valor del tipus de la Aplic
*/

};

#endif // SOLUCIO_H
