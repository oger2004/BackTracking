// Roger Costa Maubens
// u1987277
// p2

#include <iostream>
#include<list>
#include <chrono>
#include "Solucio.h"

using namespace std;


#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H


class Solucionador
{
    public:
        Solucionador();
        /**<
        * @brief inicialitza tots els atributs amb valors per defecte
        * @pre -
        * @post tots els atributs inicialitzats amb valors per defecte
        * @param -
        * @return un valor Solucionador inicialitzat amb valors per defecte
*/
        Solucio solucionar(Solucio& ini,bool iD, bool Cap);
/**<
        * @brief retorna i mostra la primera solucio trobada per el metode privat trobarUnaSolucio();
        * @pre  la Solucio conte els valors de les aplicacions inicialotzats, iD i Cap inicialitzats segons les restriccions demanades
        * @post retorna i mostra la primera solucio trobada per el metode privat trobarUnaSolucio();
        * @param una variable tipus Solucio, dos bool
        * @return retorna la primera solucio trobada per el metode privat trobarUnaSolucio();
*/
        Solucio solucionar_mill(Solucio& ini,bool iD, bool Cap);
/**<
        * @brief retorna i mostra la millor solucio trobada per el metode privat trobarMillorSolucio();
        * @pre  la Solucio conte els valors de les aplicacions inicialotzats, iD i Cap inicialitzats segons les restriccions demanades
        * @post retorna i mostra la millor solucio trobada per el metode privat trobarMillorSolucio();
        * @param una variable tipus Solucio, dos bool
        * @return retorna la millor solucio trobada per el metode privat trobarMillorSolucio();
*/

    private:
        void trobarUnaSolucio();
/**<
        * @brief busca la primera solucio seguint les restriccions dels atributs
        * @pre -
        * @post busca la primera solucio seguint les restriccions dels atributs
        * @param -
        * @return -
*/
        void trobarMillorSolucio();
/**<
        * @brief busca la millor solucio seguint les restriccions dels atributs
        * @pre -
        * @post busca la primera solucio seguint les restriccions dels atributs
        * @param -
        * @return -
*/

        bool encertat;
/**<
* @brief true si hem trobat una solucio false altrament (en cas que busquem una solucio)
        * @param true si hem trobat una solucio false altrament (en cas que busquem una solucio)
*/
        bool iD;
/**<
* @brief si es true afegeix restriccio del problema si es false s'actua segons restriccions problema
        * @param si es true afegeix restriccio del problema si es false s'actua segons restriccions problema
*/
        bool Cap;
/**<
* @brief si es true afegeix restriccio del problema si es false s'actua segons restriccions problema
        * @param si es true afegeix restriccio del problema si es false s'actua segons restriccions problema
*/
        Solucio sol;
/**<
* @brief Solucio amb la que anem trobant totes les solucions o la primera
        * @param Solucio amb la que anem trobant totes les solucions o la primera
*/
        Solucio opt;
/**<
* @brief Solucio que guada la optima
        * @param Solucio que guada la optima
*/
};

#endif // SOLUCIONADOR_H
